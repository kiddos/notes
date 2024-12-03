#include <iostream>
#include <opencv2/opencv.hpp>

int main(void) {
  cv::Mat image = cv::imread("robot.png");
  if (image.empty()) {
    std::cerr << "Could not open or find the image!" << std::endl;
    return -1;
  }

  cv::Mat gray_image;
  cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
  cv::imwrite("robot-gray.png", gray_image);
  return 0;
}
