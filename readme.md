<h1 align=center> ENPM808X Mid-Term Project- Lane-Line Detection System </h1>

[![Build Status](https://travis-ci.org/hrishikeshtawade04/Lane-Line-Detection-System.svg?branch=master)](https://travis-ci.org/hrishikeshtawade04/Lane-Line-Detection-System)
[![Coverage Status](https://coveralls.io/repos/github/hrishikeshtawade04/Lane-Line-Detection-System/badge.svg?branch=master)](https://coveralls.io/github/hrishikeshtawade04/Lane-Line-Detection-System?branch=master)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

</p>
<p align="center">
<img src="/images_for_readme/lane_line_detection.jpg">
</p>
</p>
<p align="center">
Reference for image: <a href='https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.kdnuggets.com%2Fwp-content%2Fuploads%2Froad-line-detection.gif&imgrefurl=https%3A%2F%2Fwww.kdnuggets.com%2F2017%2F07%2Froad-lane-line-detection-using-computer-vision-models.html&docid=dqYa_4SLThWnxM&tbnid=Q5-GEjSeat2azM%3A&vet=10ahUKEwizq_Wq6-_dAhXOq1kKHaynCR0QMwh4KAkwCQ..i&w=360&h=202&bih=623&biw=1301&q=lane%20line%20detection&ved=0ahUKEwizq_Wq6-_dAhXOq1kKHaynCR0QMwh4KAkwCQ&iact=mrc&uact=8'>link</a>
</p>

## Project Overview

  The Lane line detection system developed for Acme Robotics is targeted for their upcoming venture in self-driving cars. It has following features.
  - Taking RGB image as input from a camera mounted at the front of the car.
  - Taking RGB video stream as input in recorded from a camera mounted at the front of the car.
  - Outputs the drive heading error which can be fed to the steering control algorithm.
  - Outputs a video stream or image to assist the user to know its output.

The lane detection module has 3 submodules

#### 1) Camera Module
This module interacts with the camera fitted on the front of the car and takes in image or video as per instructed by user. It has following features :
- Storing an image from a given address of the image.
- Storing a video from a given address of the video.
- Sharing image to other modules.
- Sharing any frame of the video to other modules.

#### 2) Image Processing Module
This module is at the heart of the lane line detection system. It performs selected computer vision operations on the image passed by the lane line detection system. Its features are listed as follows :
- Convert RGB image to grayscale image.
- Applying gaussian blur of desired kernel size to a image.
- Applying Canny filter to a image and settings its parameters as desired.
- Masking a region from the camera image, which is set to find lane lines in a specific region, but can be changed by exploring the code.
- Drawing lines on an image of desired color and thickness from desired points.
- Finding Hough lines from a given image and access to set desired parameters.
- Summing up two images or merging them. The weights are fixed but can be changed by exploring the code.
- Adding text to a image.

#### 3) Drive Heading Module
Assuming the car's camera module is along the center of the car's axis and located at front of the car, the center of the image then acquired is expected to match the center axis of the lane the car is travelling. The drive heading module basically finds the error between the ideal central axis of the lane and the observed central axis of the lane. Following are the features of the drive heading module :  
- Set the ideal lane center values and then obtain it in calculations.
- Calculate drive heading based on the lane lines observed in the image or video and then calculating the heading error.

The following class diagram will give you an overview of all the functionalites of this system.

<p align="center">
<img src = "/images_for_readme/class_diagram.png">
</p>

## Lane Line Detection Output Flow

The following process will guide you through the complete process of lane line detection, beginning from taking an image input to creating an image with the lane lines drawn and heading error written. It will also guide you the intuition behind the usage of the image processing steps taken.

#### 1) Taking Image input
When the application is run, it will first promppt the user to select whether the he wants to input an image or video. The user can select it by entering '1' for image and '2' for the video. The second option is just the first algorithm run for multiple frames, so we will discuss only the option '1' here.

So when user the user selects option '1', the following call to the following method, stores the test_image1.jpg image, situated in the test_images folder.
```
camera_.setImage(pathToImage)
```
This function returns 0 or false if the image is correctly loaded otherwise returns a 1 or true.
The image is then loaded for further processing by folllowing code.
```
cv::Mat colorImage = camera_.getImage();
```
If the colorImage variable is displayed then it would return following.

<p align="center">
<img src = "/images_for_readme/colorImage.jpg">
</p>

#### 2) Converting to Grayscale image
Further the image is converted to a grayscale image wherein the 3-channels of the RGB image is converted to only 1 channel since it easier to use 1 channel and the processing greatly decreases. The individual pixel values here range from 0 to 255. It is done by the following code snippet.

```
cv::Mat nonBlurImage = imageProcessor_.applyGrayScale(colorImage);
```

The nonBlurImage variable stores the converted gray scale image and if displayed it will show below image.

<p align="center">
<img src = "/images_for_readme/nonBlurImage.jpg">
</p>

#### 3)  Blurring image
Now the grayscale image which we got has certain amount of noise. To remove the noise or to speak more specifically, to average out the noise we apply a Guassian blur filter of size 5, which was acquired through trial and error. The code snippet for it is below.
```
cv::Mat nonCannyImage = imageProcessor_.applyGaussianBlur(nonBlurImage, 5);
```
The blurred image is stored in the nonCannyImage variable. If you display it following image will be seen.

<p align="center">
<img src = "/images_for_readme/nonCannyImage.jpg">
</p>

#### 4)  Finding edges in image
Now that we have removed the noise, its time to  find the lane lines, which generally speaking are of different color then the main road e.g. white or yellow. We would be able to differentiate them if we could find the edges in the image, which is exactly what Canny filter does. Here we use the canny filter of kernel 3 and we set the low and high threshold value of the gradient to 50 and 100 based on trial and error. Following is the code snippet for it.
```
cv::Mat cannyImage = imageProcessor_.applyCanny(nonCannyImage, 50, 100, 3);
```
If you display the cannyImage variable it will show following image.

<p align="center">
<img src = "/images_for_readme/cannyImage.jpg">
</p>

#### 5)  Masking the region of lane
Now from canny as you can see we have got edges in all of the image but we don't need all the edges. From the sample image we in general have an idea that the lane would appear only in specific region of the image and hence we will mask it out to lower our scope of work. So we create a blank image of zero intensity and create a white polygon of the size of the region we want to mask. The mask is shown below.

<p align="center">
<img src = "/images_for_readme/mask.jpg">
</p>

 The following code snippet is then used to mask the region of interest from canny image.

```
cv::Mat maskedGrayImage = imageProcessor_.getRegionOfInterest(cannyImage);
```
If you display the maskedGrayImage variable it will show following image.

<p align="center">
<img src = "/images_for_readme/maskedGrayImage.jpg">
</p>

#### 6)  Finding the Hough lines
The problem with the masked image is that the lane lines look broken and don't gives us the full extent of the lanes. So we need to join the points and that lie in one line which is basically found by Hough lines function. The Hough function internally converts the image into the Hough space wherein if the lines are colinear, their hough transforms intersect at one point and the set of points is returned by the function. Following image demonstrates the concept.

<p align="center">
<img src = "/images_for_readme/houghSpace.png">
</p>
<p align="center">
Reference for image: <a href='https://www.google.com/imgres?imgurl=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2Fa%2Faf%2FHough_space_plot_example.png&imgrefurl=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FHough_transform&docid=IzT855o7Tf4JFM&tbnid=ZdzTvC84CYKR2M%3A&vet=10ahUKEwj1-JuH54feAhVGwVkKHf9sCykQMwhCKAowCg..i&w=441&h=359&bih=672&biw=1301&q=hough%20space%20lines&ved=0ahUKEwj1-JuH54feAhVGwVkKHf9sCykQMwhCKAowCg&iact=mrc&uact=8'>link</a>
</p>

The code snippet for the hough lines is given below. The paramters are selected by trial and error.
```
std::vector < cv::Vec4i > lines = imageProcessor_.getHoughLines(maskedGrayImage, 1, 3.14 / 180, 30, 5, 50);
```
#### 7)  Drawing lines
We have coordinate for the lines but we still don't know which belong to the left lane and right lane. Therefore, we first find the slope of the lines we get from the lines vector and then bifurcate it to left and right lanes. Then we record the lowest and highest points of a lane and extend the lower ones to the bottom by setting their y coordinates based on the average slope. Finally we draw the lines on a blank image whose code snippet is below. Here we have selected color to blue and the thickness to 8.
```
cv::Mat newImage = imageProcessor_.getDrawLines(zerosImage, lines, color,
                                                    8);
```
After drawing lines the new image will look as below.
<p align="center">
<img src = "/images_for_readme/newImage.jpg">
</p>

#### 8)  Adding drawn lines to original image
In this step we add the above image with blue lines with 100% weight to the original image with 80% weight and gamma correction is set to zero. Following is the code snipped that does that.

```
cv::Mat image = imageProcessor_.getWeightedImage(newImage, oldImage);
```
The image with lines drawn is shown below.
<p align="center">
<img src = "/images_for_readme/WeightedImage.jpg">
</p>


#### 8)  Finding drive heading error
The drive heading error is calculated from the points we recorded back in the drawing lines stage. We find the center of the upper two points and then the center of the bottom two points and take an average of the two centers to find the heading direction in the image local frame. Then we subtract it from the image center x-coordinate which is the ideal heading direction. Following is the code snippet that does this.
```
float value = driveHeadingCalculator_.findDriveHeading(imageProcessor_.getImagePoint1(), imageProcessor_.getImagePoint2(), imageProcessor_.getImagePoint3(), imageProcessor_.getImagePoint4());
```   
#### 9) Printing driving head error on the image
Finally after calculating the error we need to put it on the weighted image and the following code snippet does that for you. A positve error means that the car is on the right hand side of the center of the lane and a negative error means that the car is on the left hand side of the center of the lane.
```
imageProcessor_.generateImageWithText(image, value)
```
Following is the final output.
<p align="center">
<img src = "/images_for_readme/FinalOutput.jpg">
</p>

## Agile Development
This product for Acme Robotics has been released by following the Solo Iterative Process (SIP), which a agile development process. You can take a look at the spreadsheet by going on this [LINK](https://drive.google.com/open?id=1TmhDPRmbOyhRb8_S3LrHzESyVktLsutOdXHWmJ--PmU).

#### Sprint 1
- Hrishikesh Tawade (Driver)
- Kapil Rawal (Navigator)

## Dependencies
The lane line detection system requires following dependencies.
- cmake
- googletest
- OpenCV

## Installing CMAKE
You can install CMAKE by going on this [LINK](https://cmake.org/install/).

## Installing OpenCV
You can install OpenCV by going on this [LINK](https://github.com/kyamagu/mexopencv/wiki/Installation-(Linux,-Octave,-OpenCV-3)).

## Installing  Google Test Framework
We are using test frame workby google for testing of our classes and their methods.
You can install Google Test Framework by going on this  [LINK](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/).

## Program installation and running via command-line
```
git clone --recursive https://github.com/hrishikeshtawade04/Lane-Line-Detection-System.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run program: ./app/shell-app
```
## Running tests via command-line
To check the tests you can run following command.
```
Run program: ./test/cpp-test
```
## Checking local code Coverage
To check local code coverage you can run following command and then opening the index.html file generated in the build/coverage,from the web browser.
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
## Generating Doxygen Documentation
```
sudo apt-get install flex
git clone https://github.com/doxygen/doxygen.git
cd doxygen
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```
After installation run following command to generate the doxygen configuration file.
```
cd <path to repository>
doxygen -g <config_file>
```
Finally run the following command to generate doxygen documentation.
```
doxygen <config_file>
```
