---
layout: page
title: 
subtitle: 
cover-img: "/pages/Projects/itree-mapper/logo.png"
---
<div style="text-align: justify ">
This is an intelligent farming project about a real-scaled point cloud representation of an individual tree built from an RGB monocular camera using computer vision techniques such as structure from motion and point cloud processing. It is composed of 3 modules: 
</div>

1.	3D Mapping
2.	Scale factor estimation
3.	Segmentation
4.	Features estimation

<img src="/pages/Projects/itree-mapper/pipeline.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />

## 1. 3D Mapping
<div style="text-align: justify ">
 This stage is responsible for generating the structural geometry of the tree in a digital 3D representation. OpenMVG (Open Multiple View Geometry) is an Open Source library of SFM-MVS which is quite optimized with multiprocessing algorithms. It has an integrated thread optimization system that allows the execution of multiple processes, making it a fairly robust and efficient program. <br><br>

 CMVS / PMVS is an Open Source library that allows densifying a 3D point cloud. Densify means increasing the number of 3D points, in order to have a more complete and better structured 3D model. Once the 3D mapping has been completed, OpenMVG generates a file sfm_data.bin that contains all the relevant information of the project: the list of images used in the process, the internal parameters of the camera (matrix K), the projection matrices image (rotation and translation) and the 2D observations of each 3D point. This file is converted into a PMVS project using an OpenMVG application called: openMVG_main_ConvertSfM_DataFormat. PMVS uses images and projection matrices to increase the number of points in the model, reflecting a larger amount of data.
</div>

<img src="/pages/Projects/itree-mapper/mapping.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 

 ## 2.	Scale factor estimation
<div style="text-align: justify ">
The calculation of the scale factor is crucial for dendrometric estimation, since the objective of this project is to directly use the 3D model of a tree to calculate these characteristics. This factor is a quantity that allows you to transform the size of the 3D map to a real size. The procedure is similar to that proposed <a href="https://openmvg.readthedocs.io/en/latest/software/ui/SfM/control_points_registration/GCP/">Your link</a> with the difference that the scale factor is obtained automatically and not using a graphical interface.
</div>

<div style="text-align: justify ">
In geometry, a scale factor is obtained by dividing two straight line segments of two figures with different sizes. Following this logic, it is necessary to obtain two segments to estimate a scale factor; a known segment in the 3D model and another in the real object. Considering that the tree trunk is usually straight, a relationship can be established between a segment of the real trunk and a segment in the 3D model.
The proposed method uses a circular pattern that relates the length of a 3D model to a real-world measurement.
</div>

<img src="/pages/Projects/itree-mapper/scale-factor-relation.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 

<div style="text-align: justify ">
The scale pattern was used during the image capture process relating the 3D model to each photograph. Therefore, a pixel reference can be found that allows a known distance from the real world to be related to the 3D model. SFM relates each 3D point to its corresponding 2D point in each image. Based on that, it is possible to relate the coordinates of a pixel (u, v, 1) of an image with its corresponding 3D coordinate (X, Y, Z, 1) in the real world.
</div>

<img src="/pages/Projects/itree-mapper/scale.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 

<div style="text-align: justify ">
To achieve 3D-2D projection in the image plane of interest, it is necessary to convert the extrinsic matrix of the camera pose from the global plane to the image plane. This is because OpenMVG has defined a reference to the real world for each camera. Then we will have the relationship between the two points in the image and the pointcloud representation.
</div>

<img src="/pages/Projects/itree-mapper/scale-result.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 