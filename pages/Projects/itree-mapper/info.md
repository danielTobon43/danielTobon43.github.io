---
layout: page
title: 
subtitle: 
cover-img: "/pages/Projects/itree-mapper/logo.png"
---
<div style="text-align: justify ">
This is an intelligent farming project to estimate <a href="https://en.wikipedia.org/wiki/Dendrometry">dendometric</a> features of a tree from a real-scale pointcloud representation built from an RGB monocular camera using computer vision techniques such as structure from motion, segmentation, clustering and pointcloud processing. <br><br>

Source code: <a href="https://github.com/danielTobon43/iTree3DMap">iTree3DMap</a> 
</div>

---

1.	[3D mapping](#3d-mapping)
2.	[Scale factor estimation](#scale-factor-estimation)
3.	[Segmentation](#segmentation)
4.	[Features estimation](#features-estimation)
5.  [Results](#results)

<img src="/pages/Projects/itree-mapper/pipeline.png" align="center">
<hr> 

## 3D mapping
<div style="text-align: justify ">
 This stage is responsible for generating the structural geometry of the tree in a digital 3D representation. <a href="https://openmvg.readthedocs.io/en/latest/">OpenMVG</a> (Open Multiple View Geometry) is an Open Source library of SFM-MVS which is quite optimized with multiprocessing algorithms. It has an integrated thread optimization system that allows the execution of multiple processes, making it a fairly robust and efficient program. <br><br>

<a href="https://www.di.ens.fr/cmvs/">CMVS/PMVS</a> is an Open Source library that allows densifying a 3D point cloud. Densify means increasing the number of 3D points, in order to have a more complete and better structured 3D model. Once the 3D mapping has been completed, OpenMVG generates a file <i>sfm_data.bin</i> that contains all the relevant information of the project: the list of images used in the process, the internal parameters of the camera (<a href="http://www.cs.cmu.edu/~16385/s17/Slides/11.1_Camera_matrix.pdf">matrix K</a>), the projection matrices (rotation and translation) and the 2D observations of each 3D point. This file is converted into a PMVS project using an OpenMVG application called: <i>openMVG_main_ConvertSfM_DataFormat</i>. PMVS uses images and projection matrices to increase the number of points in the model, reflecting a larger amount of data.
</div>

<img src="/pages/Projects/itree-mapper/mapping.png" align="center">
<hr> 

## Scale factor estimation
<div style="text-align: justify ">
The calculation of the scale factor is crucial for dendrometric estimation, since the objective of this project is to directly use the 3D model of a tree to calculate these characteristics. This factor is a quantity that allows you to transform the size of the 3D map to a real size. The procedure is similar to that proposed <a href="https://openmvg.readthedocs.io/en/latest/software/ui/SfM/control_points_registration/GCP/">here:</a> with the difference that the scale factor is obtained automatically and not using a graphical interface.<br><br>

In geometry, a scale factor is obtained by dividing two straight line segments of two figures with different sizes. Following this logic, it is necessary to obtain two segments to estimate a scale factor; a known segment in the 3D model and another in the real object. Considering that the tree trunk is usually straight, a relationship can be established between a segment of the real trunk and a segment in the 3D model.
The proposed method uses a circular pattern that relates the length of a 3D model to a real-world measurement.
</div>

<img src="/pages/Projects/itree-mapper/scale-factor-relation.png" align="center">

<div style="text-align: justify ">
The scale pattern was used during the image capture process relating the 3D model to each photograph. Therefore, a pixel reference can be found that allows a known distance from the real world to be related to the 3D model. SFM relates each 3D point to its corresponding 2D point in each image. Based on that, it is possible to relate the coordinates of a pixel (u,v,1) of an image with its corresponding 3D coordinate (X,Y,Z,1) in the real world.
</div><br>

<img src="/pages/Projects/itree-mapper/scale.png" align="center">

<div style="text-align: justify ">
To achieve 3D-2D projection in the image plane of interest, it is necessary to convert the extrinsic matrix of the camera pose from the global plane to the image plane. This is because OpenMVG has defined a reference to the real world for each camera. Then we will have the relationship between the two points in the image and the pointcloud representation.
</div>

<img src="/pages/Projects/itree-mapper/scale-result.png" align="center">
<hr> 

## Segmentation
<div style="text-align: justify ">
In this stage, we seek to classify the 3D points associated with the trunk and crown of the tree in such a way that there are two representations of point clouds. <a href="https://openmvg.readthedocs.io/en/latest/software/ui/SfM/control_points_registration/GCP/">PCL</a> is an open source library for pointcloud management and processing with a wide variety of tools and algorithms specialized in 3D point segmentation.<br><br>

The segmentation procedure consists of two steps: the segmentation of the trunk and the segmentation of the crown of the tree. There is a segmentation algorithm for cylindrical objects called: <a href="http://vml.sakura.ne.jp/koeda/PCL/tutorials/html/cylinder_segmentation.html">Cylinder Model Segmentation</a> that allows you to find and classify the points of the trunk that are in the 3D model. This algorithm is an iterative method used to estimate the parameters of a mathematical model from a set of data containing outliers. This algorithm is based on the one published by Fischler and Bolles in 1981; Using <a href="https://en.wikipedia.org/wiki/Random_sample_consensus#:~:text=Random%20sample%20consensus%20(RANSAC)%20is,as%20an%20outlier%20detection%20method.">RANSAC</a>, it assumes that all the data we are analyzing is made up of typical values ​​and outliers. Typical or normal values ​​can be grouped by a model with a particular set of parameters, such as: search radius limit, normal distance, number of iterations, among others, while outliers do not fit that model under no circumstances. For this reason, those points that share a set of characteristics within a "cylindrical" model will be considered as points of the tree trunk.<br><br>

Now, since the crown of the tree is at a certain height from the ground, it is possible to define a break value that allows separating its location. This threshold value was derived based on the mean value of the total trunk height. PassThrough filter allows you to remove points that are inside or outside a user-defined range. According to this, all points that are below the average height of the trunk will be eliminated, which allows to eliminate the ground plane. In addition, an outlier filter (<a href="https://pointclouds.org/documentation/tutorials/statistical_outlier.html">StatisticalOutlierRemoval filter</a>) was used to remove noisy data sets using statistical analysis techniques.<br><br>

Even after removing the soil, the model is still noisy, for this reason, the crown of the tree is completely extracted using Density based spatial clustering of applications with noise (<a href="https://www.kdnuggets.com/2020/04/dbscan-clustering-algorithm-machine-learning.html">DBscan</a>), a segmentation algorithm based on Euclidean distances. It was proposed by Martin Ester, Hans-Peter Kriegel, Jörg Sander and Xiaowei Xu in 1996 and what it does is a density-based grouping: given a set of points in some space, it groups the points that are closely grouped (points with many neighbors nearby), marking as atypical points, those that are found alone in low-density regions.
</div>

<hr> 

## Features estimation
<div style="text-align: justify ">
The main objective of this work is to automatically measure the diameter at breast height (DBH), the total height, the height of the base of the cup, the volume of the crown and the percentage of crown loss.
</div>

<img src="/pages/Projects/itree-mapper/dendrometric.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 

<div style="text-align: justify ">
Each axis of the coordinate system associated with the 3D model represents a property of the tree: the X axis defines the width of the trunk, the Y axis the height, and the Z axis the depth. To achieve this coordinate association to a measurement characteristic, it was necessary to perform an alignment process between the global coordinate system and the trunk coordinate system; The idea is to find a unit normal vector that allows determining the angle of rotation between both axes and thus, apply a homogeneous transformation matrix that allows correcting the lag. SACModel_Plane is an algorithm for plane surface segmentation; It is available in the PCL library and allows finding the coefficients of the normal vector of the soil (flat surface of the 3D model) based on the points associated with the trunk. With a vector normal to the XY plane, where (x=0,y=0,z=1), the cross product is made between the normal vector of the ground and the vector normal to the plane to obtain the rotation vector of the axes, which is unitary. Then the angle of rotation is calculated, which is the angle between the two planes, that is, the angle between the two normal vectors. 
</div>

<img src="/pages/Projects/itree-mapper/percentage-canopy.png" align="center">
<hr> 

## Results
<div style="text-align: justify ">
The system was evaluated using data collected from 5 trees with a single stem in a rural area of ​​the city of Cali, Colombia. For tree 1 80 photographs were taken, for tree 2 66 photographs were taken; From tree 3, 74 photographs were taken and from trees 4 and 5, 65 and 94 photographs were taken respectively. In terms of precision, each characteristic of interest was evaluated with data measured in the field (ground truth). All the images were captured with a Motorola C6 phone, whose camera has a resolution of 3264x2448 pixels. The focal length and exposure parameters were set using an Android application called: OpenCamera, in such a way that they were not automatically modified by the camera. The average 3D reconstruction time was 50 minutes per tree, including the densification process. The chamber calibration parameters were obtained using a checkerboard pattern. For the data collection process, the standard techniques of forest censuses were used: the diameter at breast height (DBH) was taken at 1.33 m above the ground. A distance measuring laser was used to measure trunk height and total height. All results in this document were generated on a 2-core HP Pavillion al005la running Ubuntu LTS 16.04.3. The libraries were used: PCL version 1.8.1.99, OpenCV version 3.4.1, TinyXML2, DBScan, CMVS-PMVS, OpenMVG and the entire system was programmed in the C ++ language. The results obtained in the experimental procedure are detailed below.
</div>

<img src="/pages/Projects/itree-mapper/dataset.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 

<img src="/pages/Projects/itree-mapper/results.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 

<img src="/pages/Projects/itree-mapper/last_res.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 