/**
 *  @file    ImageProcessingModule.h
 *
 *  @author  Kapil Rawal(Driver)
 *           Hrishikesh Tawade(Navigator)
 *
 *  @copyright 3 Clause BSD License
 *
 *  @brief ENPM808X, Mid semester project
 *
 *  @section DESCRIPTION
 *
 *  This module performs user defined computer vision operations on an image.
 */

#ifndef INCLUDE_IMAGEPROCESSINGMODULE_H_
#define INCLUDE_IMAGEPROCESSINGMODULE_H_

#include<iostream>
#include<vector>
#include<string>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>

/**
 *  @brief   Class for image processing module.
 */
class ImageProcessingModule {
 public:
  /**
   *  @brief   Constructor
   */
  ImageProcessingModule();

  /**
   *  @brief   Destroys the object
   */
  ~ImageProcessingModule();

  /**
   * @brief   Applies the GrayScale filter on an input RGB image
   *
   * @param   The input color image.
   *
   * @return  GrayScale image
   */
  cv::Mat applyGrayScale(const cv::Mat);

  /**
   * @brief    Applies the GaussianBlur filter
   *
   * @param    The input image to be blurred
   *
   * @param    The kernel matrix dimensions
   *
   * @return   blurred image
   */
  cv::Mat applyGaussianBlur(const cv::Mat, const int);

  /**
   * @brief   Applies the canny filter to an input image
   *
   * @param   The input image on which canny filter is to be applied
   *
   * @param   Canny filter's low threshold parameter
   *
   * @param   Canny filter's high threshold parameter
   *
   * @param   The kernel matrix dimensions
   *
   * @return  Image with applied Canny filter
   */
  cv::Mat applyCanny(const cv::Mat, const double, const double, const int);

  /**
   * @brief   Masks the lane region in the image
   *
   * @param   An image, preferably on which Canny filter
   *          is applied
   *
   * @return  The masked region of interest
   */
  cv::Mat getRegionOfInterest(const cv::Mat);

  /**
   * @brief   Draws lines in an image, finds slopes and sets 4 points.
   *
   * @param   A blank image to draw lines on
   *
   * @param   The vector of points containing coordinates of lines
   *          to be drawn
   *
   * @param   The color of line
   *
   * @param   The thickness of lane  line
   *
   * @return  Image with lines drawn of the given color and thickness
   */
  cv::Mat getDrawLines(cv::Mat, const std::vector<cv::Vec4i> &,
                       const cv::Scalar, const int);

  /**
   * @brief   Finds Hough lines from the given image
   *
   * @param   The input image from which lines is to be found
   *
   * @param   The rho paramter of hough line filter
   *
   * @param   The theta paramter of hough line filter
   *
   * @param   The threshold paramter of hough line filter
   *
   * @param   The minimum line length paramter of hough line filter
   *
   * @param   The maximum line length paramter of hough line filter
   *
   * @return  A vector containing lines found in the image
   */
  std::vector<cv::Vec4i> getHoughLines(
      const cv::Mat, const int, double, const int, const int, const int);

  /**
   * @brief   Puts text in an image corresponding to a given value
   *
   * @param   The image on which text is  to be written
   *
   * @param   The value which is to be written on the image
   *
   * @return  The image with text added
   */
  cv::Mat generateImageWithText(cv::Mat, const float);

  /**
   * @brief   Merges two images in set proportions
   *
   * @param   The image which is going to be in higher percentage
   *
   * @param   The image which is going to be in lower percentage
   *
   * @param   Merged image
   */
  cv::Mat getWeightedImage(const cv::Mat, const cv::Mat);

  /**
   * @brief   Gives the value of a point stored during draw lines function
   *
   * @return  The value of a point
   */
  int getImagePoint1();

  /**
   * @brief   Gives the value of a point stored during draw lines function
   *
   * @return  The value of a point
   */
  int getImagePoint2();

  /**
   * @brief   Gives the value of a point stored during draw lines function
   *
   * @return  The value of a point
   */
  int getImagePoint3();

  /**
   * @brief   Gives the value of a point stored during draw lines function
   *
   * @return  The value of a point
   */
  int getImagePoint4();

 private:
  int imagePoint1_, imagePoint2_, imagePoint3_, imagePoint4_;
};

#endif  //  INCLUDE_IMAGEPROCESSINGMODULE_H_
