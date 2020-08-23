---
layout: page
title: 
subtitle: 
cover-img: "/pages/Projects/itree-mapper/logo.png"
---
<div style="text-align: justify ">
This is an intelligent farming project about a real-scaled point cloud representation of an individual tree built from an RGB monocular camera using computer vision techniques such as structure from motion and point cloud processing. It is composed of 3 modules: 

-	3D Mapping
-	Scale factor estimation
-	Segmentation
-	Features estimation
</div>

<img src="/pages/Projects/itree-mapper/pipeline.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />

## 3D Mapping

<img src="/pages/Projects/itree-mapper/mapping.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" /> 
     
<div style="text-align: justify ">
 This stage is responsible for generating the structural geometry of the tree in a digital 3D representation. OpenMVG (Open Multiple View Geometry) is an Open Source library of SFM-MVS which is quite optimized with multiprocessing algorithms. It has an integrated thread optimization system that allows the execution of multiple processes, making it a fairly robust and efficient program. 

 CMVS / PMVS is an Open Source library that allows densifying a 3D point cloud. Densify means increasing the number of 3D points, in order to have a more complete and better structured 3D model. Once the 3D mapping has been completed, OpenMVG generates a file sfm_data.bin that contains all the relevant information of the project: the list of images used in the process, the internal parameters of the camera (matrix K), the projection matrices image (rotation and translation) and the 2D observations of each 3D point. This file is converted into a PMVS project using an OpenMVG application called: openMVG_main_ConvertSfM_DataFormat. PMVS uses images and projection matrices to increase the number of points in the model, reflecting a larger amount of data.
</div>



