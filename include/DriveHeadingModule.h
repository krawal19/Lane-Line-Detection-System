/**
 *  @file    DriveHeadingModule.h
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
 *  This program calculates the drive heading
 */

#ifndef LANE_LINE_DETECTION_SYSTEM_INCLUDE_DRIVEHEADINGMODULE_H_
#define LANE_LINE_DETECTION_SYSTEM_INCLUDE_DRIVEHEADINGMODULE_H_

#include <math.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

/**
 *  @brief   Class for DriveHeading
 */
class DriveHeadingModule{
 public:
  /**
   *  @brief   Constructor
   */
  DriveHeadingModule();

  /**
   *  @brief   Destroys the object.
   */
  ~DriveHeadingModule();

  /**
   *  @brief   Calculates center lane value
   *
   *  @param   sample image to calculate centre lane value
   */
  void setCentreLaneValue(const cv::Mat);

 /**
  *  @brief   Outputs the stored centre lane value
  *  @return  stored centre lane value
  */
  int getCentreLaneValue();

 /**
  * @brief   Calculates drive heading
  *
  * @param   point1 The 1st end point of line 1
  *
  * @param   point2 The 2nd end point of line 1
  *
  * @param   point3 The 1st end point of line 2
  *
  * @param   point4 The 2nd end point of line 2
  *
  * @return  Drive heading error
  */
  float findDriveHeading(const int, const int, const int, const int);

 private:
  int centreLaneValue_;
};
#endif  //  LANE_LINE_DETECTION_SYSTEM_INCLUDE_DRIVEHEADINGMODULE_H_
