/**
 *  @file    DriveHeadingModule.cpp
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

#include "DriveHeadingModule.h"
#include <iostream>
#include <vector>

/**
 * @brief   Constructs the object
 */
DriveHeadingModule::DriveHeadingModule() {
    centreLaneValue_ = 0;  /// Assigning default value
}

/**
 * @brief   Destroys the object.
 */
DriveHeadingModule::~DriveHeadingModule() {
}

/**
 * @brief   Sets the central lane value
 *
 * @param   input vertices vector
 *
 * @return  void
*/
void DriveHeadingModule::setCentreLaneValue(const cv::Mat image) {
  centreLaneValue_ = image.rows / 2;  /// Calculates centre lane value
}

/**
 *  @brief   Outputs the stored centre lane value
 *
 *  @return  stored centre lane value
*/
int DriveHeadingModule::getCentreLaneValue() {
  return centreLaneValue_;
}

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
 * @return Drive heading error
 */
float DriveHeadingModule::findDriveHeading(const int point1, const int point2,
    const int point3, const int point4) {
  int a = (point2 - point1) / 2 + point1;
  int b = (point4 - point3) / 2 + point3;
  /// calculating deviation from original in meters
  double error = (((a + b) * 1.0 / 2) - 480) * 0.00524;
  return error;
}
