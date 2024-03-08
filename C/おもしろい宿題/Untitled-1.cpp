#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

std::string decode64(const std::string &val)
{
    using namespace boost::archive::iterators;
    using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;
    return std::string(It(std::begin(val)), It(std::end(val)));
}

void saveImage(const std::string &base64, const std::string &path)
{
    std::string decoded = decode64(base64);
    std::vector<uchar> data(decoded.begin(), decoded.end());
    cv::Mat img = cv::imdecode(data, cv::IMREAD_UNCHANGED);
    cv::imwrite(path, img);
}

int main()
{
    std::string smallIcon = "..."; // Your base64 encoded image
    std::string largeIcon = "..."; // Your base64 encoded image

    saveImage(smallIcon, "smallIcon.png");
    saveImage(largeIcon, "largeIcon.png");

    return 0;
}