#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <netpbm/pam.h>

namespace raytracer
{
class Image
{
  public:
    explicit Image(float w, float h);

    virtual ~Image() = default;

    void save(const std::string& path) const;

  private:
    float              width_;
    float              height_;
    std::vector<float> data_;
};

Image::Image(float w, float h)
    : width_(w)
    , height_(h)
    , data_(w * h)
{
}

void Image::save(const std::string& path) const
{
    // Export to ppm format
    // P3 width height 255
    // FIXME: write in binary

    std::ofstream output;
    output.open(path);

    output << "P3 " << width_ << " " << height_ << " 255" << std::endl;

    for (uint i = 0; i < width_; i++)
    {
        for (uint j = 0; j < height_; j++)
        {
            output << data_[i + j * width_] << " ";
        }
        output << std::endl;
    }

    output.close();
}

} // namespace raytracer