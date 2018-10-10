/**
 *  @file    CameraModule.cpp
 *  @author  Hrishikesh Tawade(Driver)
 *           Kapil Rawal(Navigator)
 *  @copyright 3 Clause BSD License
 *
 *  @brief ENPM808X, Mid semester project
 *
 *  @section DESCRIPTION
 *
 *  This program rakes input image or video from user and stores it and then returns
 *  the stored image and video on demand of the user.
 *
 */

#include "../include/CameraModule.h"


/**
 *  @brief   Constructs the object
 */
CameraModule::CameraModule() {
  
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
int CameraModule::setImage(std::string pathToImage) {

  return 1;
}

/**
 *  @brief  Stores video from input link
 *
 *  @param  pathToVideo The input video link
 *
 *  @return number that denotes whether video opened
 */
int CameraModule::setVideo(std::string pathToVideo) {

  return 1;
}

/**
 * @brief   Gets the input video
 *
 * @param   frameNumber The frame number of a video
 *
 * @return  stored video frame
 */
cv::Mat CameraModule::getVideo(int frameNumber) {
  cv::Mat image;
  return image;
}

/**
 * @brief   Gets the input image
 *
 * @return  stored image
 */
cv::Mat CameraModule::getImage() {
  cv::Mat image;
  return image;
}

