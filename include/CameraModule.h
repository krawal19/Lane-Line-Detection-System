/**
 *  @file    CameraModule.h
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

#ifndef Camera_Module_H
#define Camera_Module_H

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
  int setImage(std::string);

  /**
   *  @brief  Stores video
   *
   *  @param  path to the video
   *
   *  @return number that denotes whether video opened
   */
  int setVideo(std::string);

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
  cv::Mat getVideo(int );

 private:
  std::vector<cv::Mat> video_;
  cv::Mat image_;
};


#endif

