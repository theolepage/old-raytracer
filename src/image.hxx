#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace raytracer
{
class Image
{
  public:
    explicit Image(uint w, uint h);

    virtual ~Image() = default;

    uint  get_width() const;
    uint  get_height() const;
    Color get_pixel(uint x, uint y) const;

    void set_pixel(uint x, uint y, Color color);

    void save(const std::string& path);

  private:
    uint               width_;
    uint               height_;
    std::vector<Color> data_;
};

Image::Image(uint w, uint h)
    : width_(w)
    , height_(h)
    , data_(w * h, Color(0.9f, 0.9f, 0.9f))
{
}

uint Image::get_width() const { return width_; }

uint Image::get_height() const { return height_; }

Color Image::get_pixel(uint x, uint y) const
{
    return data_.at(x + y * width_);
}

void Image::set_pixel(uint x, uint y, Color color)
{
    data_[x + y * width_] = color;
}

void Image::save(const std::string& path)
{
    std::ofstream output;
    output.open(path);

    output << "P3\n" << width_ << " " << height_ << "\n255\n";

    for (uint y = 0; y < height_; y++)
    {
        for (uint x = 0; x < width_; x++)
        {
            Color color = get_pixel(x, y);
            output << static_cast<int>(color.get_x() * 255.0f) << " ";
            output << static_cast<int>(color.get_y() * 255.0f) << " ";
            output << static_cast<int>(color.get_z() * 255.0f) << " ";
            output << "\n";
        }
    }

    output.close();
}

} // namespace raytracer