/**
 *  @file    ImageProcessingModule.cpp
 *
 *  @author  Hrishikesh Tawade (Driver)
 *           Kapil Rawal (Navigator)
 *
 *  @copyright 3 Clause BSD License
 *
 *  @brief ENPM808X, Mid semester project
 *
 *  @section DESCRIPTION
 *
 *  This module performs user defined computer vision operations on an image.
 */

#include "../include/ImageProcessingModule.h"


/**
 * @brief   Constructs the object
 */
ImageProcessingModule::ImageProcessingModule() {
  int imagePoint1_ = 1;
  int imagePoint2_ = 1;
  int imagePoint3_ = 1;
  int imagePoint4_ = 1;
}

/**
 * @brief   Destroys the object
 */
ImageProcessingModule::~ImageProcessingModule() {
}

/**
 * @brief   Applies the GrayScale filter on an input RGB image
 *
 * @param   colorImage The input color image.
 *
 * @return  GrayScale image
 */
cv::Mat ImageProcessingModule::applyGrayScale(cv::Mat colorImage) {
  return colorImage;
}

/**
 * @brief    Applies the GaussianBlur filter
 *
 * @param    nonBlurImage The input image to be blurred
 *
 * @param    kernel The kernel matrix dimensions
 *
 * @return   blurred image
 */
cv::Mat ImageProcessingModule::applyGaussianBlur(cv::Mat nonBlurImage,
                                                 int kernel) {
  cv::Mat BlurImage = cv::Mat::ones(10, 10, CV_32FC1);
  return BlurImage;
}

/**
 * @brief   Applies the canny filter to an input image
 *
 * @param   nonCannyImage The input image on which canny filter
 *                        is to be applied
 *
 * @param   lowThreshold Canny filter's low threshold parameter
 *
 * @param   highThreshold Canny filter's high threshold parameter
 *
 * @param   kernel The kernel matrix dimensions
 *
 * @return  Image with applied Canny filter
 */
cv::Mat ImageProcessingModule::applyCanny(cv::Mat nonCannyImage,
                                          double lowThreshold,
                                          double highThreshold, int kernel) {

  cv::Mat CannyImage = cv::Mat::ones(10, 10, CV_8UC1);
  return CannyImage;
}

/**
 * @brief   Masks the lane region in the image
 *
 * @param   cannyImage An image, preferably on which Canny filter
 *                     is applied
 *
 * @return  The masked region of interest
 */
cv::Mat ImageProcessingModule::getRegionOfInterest(cv::Mat cannyImage) {

  cv::Mat image = cv::Mat::ones(cannyImage.rows,cannyImage.cols, CV_8UC1);
  return image;
}

/**
 * @brief   Draws lines in an image, finds slopes and sets 4 points.
 *
 * @param   zerosImage A blank image to draw lines on
 *
 * @param   lines The vector of points containing coordinates of lines
 *                to be drawn
 *
 * @param   color The color of line
 *
 * @param   thickness The thickness of lane  line
 *
 * @return  Image with lines drawn of the given color and thickness
 */
cv::Mat ImageProcessingModule::getDrawLines(cv::Mat zerosImage,
                                            std::vector<cv::Vec4i> lines,
                                            cv::Scalar color, int thickness) {

  cv::Mat image = cv::Mat::ones(zerosImage.rows, zerosImage.cols, CV_8UC3);
  return image;

}

/**
 * @brief   Finds Hough lines from the given image
 *
 * @param   maskedGrayImage The input image from which lines is to be found
 *
 * @param   rho The rho paramter of hough line filter
 *
 * @param   theta The theta paramter of hough line filter
 *
 * @param   threshold The threshold paramter of hough line filter
 *
 * @param   minLineLen The minimum line length paramter of hough line filter
 *
 * @param   maxLineGap The maximum line length paramter of hough line filter
 *
 * @return  A vector containing lines found in the image
 */
std::vector<cv::Vec4i> ImageProcessingModule::getHoughLines(
    cv::Mat maskedGrayImage, std::vector<cv::Vec4i> lines, int rho,
    double theta, int threshold, int minLineLen, int maxLineGap) {

  std::vector < cv::Vec4i > line = {0,1,2,3};

  return line;
}

/**
 * @brief   Merges two images in set proportions
 *
 * @param   newImage The image which is going to be in higher percentage
 *
 * @param   image The image which is going to be in lower percentage
 *
 * @param   Merged image
 */
cv::Mat ImageProcessingModule::getWeightedImage(cv::Mat newImage,
                                                cv::Mat image) {
  return image;

}

/**
 * @brief   Puts text in an image corresponding to a given value
 *
 * @param   image The image on which text is  to be written
 *
 * @param   value The value which is to be written on the image
 *
 * @return  The image with text added
 */
cv::Mat ImageProcessingModule::generateImageWithText(cv::Mat image,
                                                     float value) {

  cv::Mat image1 = cv::Mat::ones(image.rows, image.cols, CV_8UC3);
  return image1;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point
 */
int ImageProcessingModule::getImagePoint1() {
  return 1;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point
 */
int ImageProcessingModule::getImagePoint2() {
  return 1;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point
 */
int ImageProcessingModule::getImagePoint3() {
  return 1;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point
 */
int ImageProcessingModule::getImagePoint4() {
  return 1;
}


