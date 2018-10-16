/**
 *  @file    CameraModule.h
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
 *  This program rakes input image or video from user and stores it and then returns
 *  the stored image and video on demand of the user.
 *
 */

#ifndef INCLUDE_CAMERAMODULE_H_
#define INCLUDE_CAMERAMODULE_H_

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

/**
 *  @brief   Class for camera module.
 */
class CameraModule {
 public:
  /**
   *  @brief   Constructor
   */
  CameraModule();

  /**
   *  @brief   Destroys the object
   */
  ~CameraModule();

  /**
   *  @brief  Stores image
   *
   *  @param  path to the image
   *
   *  @return number that denotes whether image opened
   */
  int setImage(const std::string &);

  /**
   *  @brief  Stores video
   *
   *  @param  path to the video
   *
   *  @return number that denotes whether video opened
   */
  int setVideo(const std::string &);

  /**
   *  @brief  Gives stored image to user
   *
   *  @return stored image
   */
  cv::Mat getImage();

  /**
   *  @brief  Input video from user
   *
   *  @param  Video frame number
   *
   *  @return stored video frame
   */
  cv::Mat getVideo(int);

 private:
  std::vector<cv::Mat> video_;
  cv::Mat image_;
  int videoSize_;
};
#endif  // INCLUDE_CAMERAMODULE_H_
