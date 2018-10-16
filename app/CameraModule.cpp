/**
 *  @file    CameraModule.cpp
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
 *  This program rakes input image or video from user and stores it and then 
 *  returns the stored image and video on demand of the user.
 *
 */

#include "CameraModule.h"
using cv::Mat;

/**
 *  @brief   Constructs the object
 */
CameraModule::CameraModule() {
  cv::Mat image_ = cv::Mat::ones(10, 10, CV_8UC3);  /// Assigning default value
  videoSize_ = 0;  /// Assigning default value
}

/**
 * @brief   Destroys the object.
 */
CameraModule::~CameraModule() {
}

/**
 *  @brief  Stores image from input link
 *
 *  @param  pathToImage The input image link
 *
 *  @return Value if the image is valid
 */
int CameraModule::setImage(const std::string &pathToImage) {
  /// Reading the image from path provided of source
  image_ = cv::imread(pathToImage, CV_LOAD_IMAGE_COLOR);
  int opened = image_.empty();  /// if image is valid opened is 0 else 1.

  return opened;
}

/**
 *  @brief  Stores video from input link
 *
 *  @param  pathToVideo The input video link
 *
 *  @return number that denotes whether video opened
 */
int CameraModule::setVideo(const std::string &pathToVideo) {
  cv::VideoCapture cap(pathToVideo);
  if (!cap.isOpened()) {  /// checks if the video is opened
    return -1;
  } else {
    cv::Mat frame;
    int i=0;
    while (1) {
      cap >> frame;
      if (frame.empty() == 1) {  /// Check for empty frames
        break;
      }
      video_.emplace_back(frame[i]);  /// copy structure of data
   i++;  
  }
    return 0;
}
}

/**
 * @brief   Gets the input video
 *
 * @param   frameNumber The frame number of a video
 *
 * @return  stored video frame
 */
cv::Mat CameraModule::getVideo(const int frameNumber) {
  return video_[frameNumber];
  }

/**
 * @brief   Gets the input image
 *
 * @return  stored image
 */
cv::Mat CameraModule::getImage() {
  return image_;
}
