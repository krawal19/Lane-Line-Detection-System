/**
 *  @file    LaneLineDetectionSystem.h
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

#ifndef LANE_LINE_DETECTION_SYSTEM_INCLUDE_LANELINEDETECTIONSYSTEM_H_
#define LANE_LINE_DETECTION_SYSTEM_INCLUDE_LANELINEDETECTIONSYSTEM_H_

#include <string>
#include <iostream>
#include "../include/CameraModule.h"
#include "../include/ImageProcessingModule.h"
#include "../include/DriveHeadingModule.h"

/**
 *  @brief   Class for camera module.
 */
class LaneLineDetectionSystem {
 public:
  /**
   *  @brief   Constructor
   */
  LaneLineDetectionSystem();

  /**
   *  @brief   Destroys the object
   */
  ~LaneLineDetectionSystem();

  /**
   *  @brief  Detects lane line in an image of a car driving on
   *          a highway
   *
   *  @param  path to the image
   */
  void detectLaneLineForImage(const std::string &);

  /**
   *  @brief  Detects lane line in a video of a car driving on
   *          a highway
   *
   *  @param  path to the video
   */
  void detectLaneLineForVideo(const std::string &);

 private:
  CameraModule camera_;
  ImageProcessingModule imageProcessor_;
  DriveHeadingModule driveHeadingCalculator_;
};

#endif  //  LANE_LINE_DETECTION_SYSTEM_INCLUDE_LANELINEDETECTIONSYSTEM_H_
