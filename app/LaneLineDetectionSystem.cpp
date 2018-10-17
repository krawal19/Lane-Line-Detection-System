/**
 *  @file    LaneLineDetectionSystem.cpp
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
 *  This program detects the lane line from an image or video
 *
 */

#include "LaneLineDetectionSystem.h"
using std::cout;
using std::endl;

/**
 *  @brief   Constructs the object
 */
LaneLineDetectionSystem::LaneLineDetectionSystem() {
}

/**
 * @brief   Destroys the object.
 */
LaneLineDetectionSystem::~LaneLineDetectionSystem() {
}

/**
 *  @brief  Detects Lane line from an image
 *
 *  @param  pathToImage The input image link
 *
 *  @return void
 */
void LaneLineDetectionSystem::detectLaneLineForImage(
    const std::string &pathToImage, const int showOutput) {
  if (camera_.setImage(pathToImage)) {
    cout << "Image could not be opened" << endl;
  } else {
    /// Getting image
    cv::Mat colorImage = camera_.getImage();
    cv::imwrite("../test_images_output/colorImage.jpg", colorImage);
    /// Converting image to gray scale
    cv::Mat nonBlurImage = imageProcessor_.applyGrayScale(colorImage);
    cv::imwrite("../test_images_output/nonBlurImage.jpg", nonBlurImage);
    /// Blurring image
    cv::Mat nonCannyImage = imageProcessor_.applyGaussianBlur(nonBlurImage, 5);
    cv::imwrite("../test_images_output/nonCannyImage.jpg", nonCannyImage);
    /// applying canny filter
    cv::Mat cannyImage = imageProcessor_.applyCanny(nonCannyImage, 50, 100, 3);
    cv::imwrite("../test_images_output/cannyImage.jpg", cannyImage);
    /// Masking image
    cv::Mat maskedGrayImage = imageProcessor_.getRegionOfInterest(cannyImage);
    cv::imwrite("../test_images_output/maskedGrayImage.jpg", maskedGrayImage);
    /// Find hough lines in the image
    std::vector < cv::Vec4i > lines = imageProcessor_.getHoughLines(
        maskedGrayImage, 1, 3.14 / 180, 30, 5, 50);
    cv::Mat zerosImage = cv::Mat::zeros(maskedGrayImage.rows,
                                        maskedGrayImage.cols, CV_8UC3);
    cv::Scalar color = { 255, 0, 0 };
    /// Drawing lines
    cv::Mat newImage = imageProcessor_.getDrawLines(zerosImage, lines, color,
                                                    8);
    cv::Mat oldImage = colorImage;
    /// Merging images
    cv::Mat image = imageProcessor_.getWeightedImage(newImage, oldImage);
    cv::imwrite("../test_images_output/WeightedImage.jpg", image);
    driveHeadingCalculator_.setCentreLaneValue(image);
    /// Calculating drive heading error
    float value = driveHeadingCalculator_.findDriveHeading(
        imageProcessor_.getImagePoint1(), imageProcessor_.getImagePoint2(),
        imageProcessor_.getImagePoint3(), imageProcessor_.getImagePoint4());
    cv::namedWindow("Final Output", cv::WINDOW_AUTOSIZE);
    /// Putting text on frame
    cv::Mat finalOutput = imageProcessor_.generateImageWithText(image, value);
    if (showOutput == 1) {
      cv::imshow("New Image", finalOutput);
    }
    /// Storing output image
    cv::imwrite("../test_images_output/FinalOutput.jpg",  finalOutput);
    cv::waitKey(2000);
  }
}

/**
 *  @brief   Stores video from input link
 *
 *  @param   pathToVideo The input video link
 *
 *  @return  void
 */
void LaneLineDetectionSystem::detectLaneLineForVideo(
    const std::string &pathToVideo , const int showOutput) {
  if (camera_.setVideo(pathToVideo)) {
    cout << "Video could not be opened" << endl;
  } else {
    int frameNumber = 0;
    /// Saving video format
    cv::VideoWriter video(
        "../test_videos_output/final_video_output.avi",
        CV_FOURCC('M', 'J', 'P', 'G'), 10,
        cv::Size(camera_.getVideo(0).cols, camera_.getVideo(0).rows));
    while (1) {
      /// Getting video frame
      cv::Mat colorImage = camera_.getVideo(frameNumber);
      if (colorImage.empty() == 1) {
        break;
      }
      /// Converting image to gray scale
      cv::Mat nonBlurImage = imageProcessor_.applyGrayScale(colorImage);
      /// Blurring image
      cv::Mat nonCannyImage = imageProcessor_.applyGaussianBlur(nonBlurImage,
                                                                5);
      /// applying canny filter
      cv::Mat cannyImage = imageProcessor_.applyCanny(nonCannyImage, 50, 100,
                                                      3);
      /// Masking image
      cv::Mat maskedGrayImage = imageProcessor_.getRegionOfInterest(cannyImage);
      /// Find hough lines in the image
      std::vector < cv::Vec4i > lines = imageProcessor_.getHoughLines(
          maskedGrayImage, 1, 3.14 / 180, 30, 5, 50);
      cv::Mat zerosImage = cv::Mat::zeros(maskedGrayImage.rows,
                                          maskedGrayImage.cols, CV_8UC3);
      cv::Scalar color = { 255, 0, 0 };
      /// Drawing lines
      cv::Mat newImage = imageProcessor_.getDrawLines(zerosImage, lines, color,
                                                      8);
      cv::Mat oldImage = colorImage;
      /// Merging images
      cv::Mat image = imageProcessor_.getWeightedImage(newImage, oldImage);
      driveHeadingCalculator_.setCentreLaneValue(image);
      /// Calculating drive heading error
      float value = driveHeadingCalculator_.findDriveHeading(
          imageProcessor_.getImagePoint1(), imageProcessor_.getImagePoint2(),
          imageProcessor_.getImagePoint3(), imageProcessor_.getImagePoint4());
      cv::namedWindow("Final Output", cv::WINDOW_AUTOSIZE);
      /// Putting text on frame
      cv::Mat finalOutput = imageProcessor_.generateImageWithText(image, value);
      /// Storing output frame
      video.write(finalOutput);
      ++frameNumber;
      if (showOutput == 1) {
        cv::imshow("New Image", finalOutput);
        if (cv::waitKey(45) >= 0)
          break;
      }
    }
  }
}
