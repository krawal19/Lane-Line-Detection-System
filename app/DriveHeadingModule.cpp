/**
 *  @file    DriveHeadingModule.cpp
 *
 *  @author  Hrishikesh Tawade(Driver)
 *           Kapil Rawal(Navigator)
 *
 *  @copyright 3 Clause BSD License
 *
 *  @brief ENPM808X, Mid semester project
 *
 *  @section DESCRIPTION
 *
 *  This program calculates the drive heading
 */

#include "../include/DriveHeadingModule.h"
#include <vector>
#include <iostream>

/**
 * @brief   Constructs the object
 */
DriveHeadingModule::DriveHeadingModule() {
    centreLaneValue_=0;
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
void DriveHeadingModule::setCentreLaneValue(cv::Mat image) {


}

/**
 *  @brief   Outputs the stored centre lane value
 *  
 *  @return  stored centre lane value
*/
int DriveHeadingModule::getCentreLaneValue(){
 
  return 0;
}



/**
 * @brief Calculates drive heading
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
float DriveHeadingModule::findDriveHeading(int point1, int point2, int point3,
                                            int point4) {


  return 0.0;

}
