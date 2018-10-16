/**
 *  @file    ImageProcessingModule.cpp
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

#include "ImageProcessingModule.h"

using cv::Mat;
using cv::Size;
using cv::Point;
using cv::Scalar;
using cv::Point2i;
using cv::FONT_HERSHEY_TRIPLEX;
using std::string;


/**
 * @brief   Constructs the object
 */
ImageProcessingModule::ImageProcessingModule() {
  imagePoint1_ = 0;  /// Assigning default value
  imagePoint2_ = 0;  /// Assigning default value
  imagePoint3_ = 0;  /// Assigning default value
  imagePoint4_ = 0;  /// Assigning default value
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
cv::Mat ImageProcessingModule::applyGrayScale(const cv::Mat colorImage) {
  Mat GrayScaleimg;
  /// Converts color image to gray scale image
  cvtColor(colorImage, GrayScaleimg, CV_RGB2GRAY);

  return GrayScaleimg;
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
cv::Mat ImageProcessingModule::applyGaussianBlur(const cv::Mat nonBlurImage,
                                                 const int kernel) {
  Mat GaussianBlurimg = Mat::ones(nonBlurImage.rows, nonBlurImage.cols,
                                  nonBlurImage.type());
  /// Converts gray scale image to gaussian blur image
  GaussianBlur(nonBlurImage, GaussianBlurimg, Size(kernel, kernel), 0,
                       0);

  return GaussianBlurimg;
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
  cv::Mat ImageProcessingModule::applyCanny(const cv::Mat nonCannyImage,
                                            const double lowThreshold,
                                            const double highThreshold,
                                            const int kernel) {
  cv::Mat CannyImg = Mat::ones(nonCannyImage.rows, nonCannyImage.cols,
                               nonCannyImage.type());
  /// Converts a non canny image to canny image
  Canny(nonCannyImage, CannyImg, lowThreshold, highThreshold, kernel);

  return CannyImg;
}

/**
 * @brief   Masks the lane region in the image
 *
 * @param   cannyImage An image, preferably on which Canny filter
 *                     is applied
 *
 * @return  The masked region of interest
 */
cv::Mat ImageProcessingModule::getRegionOfInterest(const cv::Mat cannyImage) {
  Mat mask = Mat::zeros(cannyImage.rows, cannyImage.cols, CV_8UC1);
  Point polygonPoints[1][20];
  /// Get points with which the quadilater forms
  polygonPoints[0][0] = Point(0.08 * cannyImage.cols, cannyImage.rows);
  polygonPoints[0][1] = Point(0.47 * cannyImage.cols, 0.6 * cannyImage.rows);
  polygonPoints[0][2] = Point(0.55 * cannyImage.cols, 0.6 * cannyImage.rows);
  polygonPoints[0][3] = Point(0.95 * cannyImage.cols, cannyImage.rows);

  const Point* ppt[1] = { polygonPoints[0] };
  int npt[] = { 4 };
  fillPoly(mask, ppt, npt, 1, Scalar(255));
  Mat maskedimg;
  bitwise_and(cannyImage, mask, maskedimg);

  return maskedimg;
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
  cv::Mat ImageProcessingModule::getDrawLines(
      cv::Mat zerosImage, const std::vector<cv::Vec4i> &lines,
      const cv::Scalar color, const int thickness) {
  bool toggleLeft = true, toggleRight = true;
  double leftLaneSlopeSum = 0, rightLaneSlopeSum = 0;
  int leftLineCount = 0, rightLineCount = 0;
  float highestY1Point = 0, highestX1Point = 0, lowestY1Point = 0,
      lowestX1Point = 0, highestX2Point = 0, highestY2Point = 0, lowestY2Point =
          0, lowestX2Point = 0;
  for (auto line : lines) {
    float x1 = line[0];
    float x2 = line[2];
    float y1 = line[1];
    float y2 = line[3];
    float slope = ((y1 - y2) * 1.0 / (x2 - x1));

    if (slope < 0) {  /// calculating right side slope
      rightLaneSlopeSum += slope;
      ++rightLineCount;
      /// locating points in the right region of interest
      if ((zerosImage.rows - y2) < (zerosImage.rows - y1)) {
        if (toggleRight) {
          toggleRight = false;
          highestY1Point = zerosImage.rows - y1;
          highestX1Point = x1;
          lowestY1Point = zerosImage.rows - y2;
          lowestX1Point = x2;
        } else {
          if ((zerosImage.rows - y1) > highestY1Point) {
            highestY1Point = zerosImage.rows - y1;
            highestX1Point = x1;
          }
        }
      }
    } else {  /// calculating left side slope
      leftLaneSlopeSum += slope;
      ++leftLineCount;
      /// locating points in the left region of interest
      if ((zerosImage.rows - y2) > (zerosImage.rows - y1)) {
        if (toggleLeft) {
          toggleLeft = 0;
          highestY2Point = zerosImage.rows - y2;
          highestX2Point = x2;
          lowestY2Point = zerosImage.rows - y1;
          lowestX2Point = x1;
        } else {
          if ((zerosImage.rows - y2) > highestY2Point) {
            highestY2Point = zerosImage.rows - y2;
            highestX2Point = x2;
          }
        }
      }
    }
  }

  double leftLaneSlopeAvg = leftLaneSlopeSum * 1.0 / leftLineCount;
  /// finding left line constant C
  double leftLaneC = lowestY2Point - lowestX2Point * leftLaneSlopeAvg;
  double lowestPointLeftX = (0 - leftLaneC) / leftLaneSlopeAvg;

  double rightLaneSlopeAvg = rightLaneSlopeSum * 1.0 / rightLineCount;
  /// finding right line constant C
  double rightLaneC = lowestY1Point - lowestX1Point * rightLaneSlopeAvg;
  double lowestPointRightX = (0 - rightLaneC) * 1.0 / rightLaneSlopeAvg;
  /// Saving four X coordinates of region of interest to calculate drive heading
  Point2i rightLaneHigherPoint(highestX2Point,
                               zerosImage.rows - highestY2Point);
  Point2i rightLaneLowerPoint(lowestPointLeftX, zerosImage.rows);
  Point2i leftLaneHigherPoint(highestX1Point, zerosImage.rows - highestY1Point);
  Point2i leftLaneLowerPoint(lowestPointRightX, zerosImage.rows);

  imagePoint1_ = highestX2Point;
  imagePoint2_ = highestX1Point;
  imagePoint3_ = lowestPointLeftX;
  imagePoint4_ = lowestPointRightX;
  line(zerosImage, rightLaneHigherPoint, rightLaneLowerPoint, color, thickness);
  line(zerosImage, leftLaneHigherPoint, leftLaneLowerPoint, color, thickness);

  return zerosImage;
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
      const cv::Mat maskedGrayImage, const int rho, const double theta,
      const int threshold, const int minLineLen, const int maxLineGap) {
  std::vector<cv::Vec4i> lines;
  /// Converting masked gray image points into hough lines
  HoughLinesP(maskedGrayImage, lines, rho, theta, threshold, minLineLen,
              maxLineGap);

  return lines;
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
cv::Mat ImageProcessingModule::getWeightedImage(const cv::Mat newImage,
                                                const cv::Mat image) {
  const double a = 0.8;
  const double b = 1.0;
  const double c = 0.0;
  Mat wetImage = Mat::ones(newImage.rows, newImage.cols, newImage.type());
  /// Merges newImage on image
  addWeighted(newImage, a, image, b, c, wetImage);

  return wetImage;
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
                                                     const float value) {
  string textToAdd = "Heading Error = " + std::to_string(value) + " meter";
  /// Adding text to image
  putText(image, textToAdd, cvPoint(30, 30), FONT_HERSHEY_TRIPLEX, 0.8,
          cvScalar(0, 0, 0), 1);
  return image;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point 1
 */
int ImageProcessingModule::getImagePoint1() {
  return imagePoint1_;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point 2
 */
int ImageProcessingModule::getImagePoint2() {
  return imagePoint2_;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point 3
 */
int ImageProcessingModule::getImagePoint3() {
  return imagePoint3_;
}

/**
 * @brief   Gives the value of a point stored during draw lines function
 *
 * @return  The value of a point 4
 */
int ImageProcessingModule::getImagePoint4() {
  return imagePoint4_;
}
