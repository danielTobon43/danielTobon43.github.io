---
layout: page
title: URDF model and Gazebo simulation of a 7DOF robot using ROS and Moveit
subtitle: 
cover-img: 
---
<img src="/pages/Projects/urdf-sim/banner.png" align="center"><br>

Shenzhen Yueliang Technology [1] is a company dedicated to development robot arm solution in China. Dobot is the first generation of robot arm debuted in 2015 in the worldwide. <br><br>

Dobot Magician (see figure 1) integrates 3D printing, laser engraving, painting and writing. Dobot Magician in Rviz
The Dobot Magician manual contains the technical specifications, as the material and the turning speed of each joint. Table 1 shows the most important technical specifications, including the selection of the pen for drawing and writing as final effector.
The objective of modeling the robot in urdf format is to be able to visualize the robot in Rviz.<br><br>

The Dobot Magician manipulator has 6 degrees of freedom; That is, in 3D modeling of the robot it is necessary to generate 6 links with their respective dimensions in the archive urdf that describes the robot. The first step is to create the robot package in the catkin_ws folder. To do this, in the terminal of ubuntu catkin_create_pkg "package name" is used to create the package associated with the Dobot Magician Robot. Once the package is created, it must be built in the workspace catkin_ws; the catkin_make command allows you to build the Dobot Magician Robot package in catkin_ws. The figure 5 shows the package dobot_magician_pkg with the urdf, meshes and launch folders. <br><br>

<b> example code</b>
```xml

<!--- ________________________________________________________-->
<!--- ____________________LINK 0 - BASE_LINK__________________-->
<!--- ________________________________________________________--> 

 <link name="base_link">    
    <inertial>
      <mass value="4" />
      <inertia ixx="0.0085988" ixy="5.4719E-20" ixz="6.3149E-19" 
               iyy="0.014441" iyz="-9.7318E-20"izz="0.0085988" />
    </inertial>
    <visual>
      <origin xyz="0 0 0" rpy="0 0 0" />
      <geometry>
        <box size="0.15 0.15 0.065"/>
      </geometry>
      <material name="Aluminum 6061-1">
        <color rgba="0 1 0 1"/>
      </material>
    </visual>
    <collision>
      <origin xyz="0 0 0" rpy="0 0 0" />
      <geometry>
        <box size="0.20 0.20 0.0"/>          
      </geometry>
    </collision>
  </link>
<!--- ________________________________________________________-->
<!--- ____________________JOINT 1_____________________________-->
<!--- ________________________________________________________--> 
  <joint name="joint_1" type="revolute">
    <parent link="base_link"/>
    <child link="link_1"/>
      <origin xyz="0 0 0.1"/>
      <axis xyz="0 0 1" />
        <limit effort="300" velocity="0.1" lower="-3.14" upper="3.14"/>
        <dynamics damping="50" friction="1"/>
  </joint>
<!--- ________________________________________________________-->
<!--- ____________________LINK 1______________________________-->
<!--- ________________________________________________________--> 
  <link name="link_1">
    <visual>
      <geometry>
         <box size="0.0495 0.06 0.104"/>
      </geometry>
      <origin rpy="0 0 0" xyz="0 0 -0.025"/>
      <material name="Aluminum 6061-2">
        <color rgba="1 0 0 1"/>
      </material>
    </visual>
    <collision>
      <geometry>
        <box size="0.06 0.08 0.2"/>
      </geometry>
      <origin rpy="0 0 0" xyz="0 0 -0.025"/>
    </collision>
    <inertial>
      <mass value="0.096"/>
    <inertia  ixx="0.00011245" ixy="-6.1285E-12" 
              ixz="-2.3175E-12" iyy="3.1935E-05" 
              iyz="7.882E-06" izz="0.00013863"/>
    </inertial>  </link> </robot>
```

Source code: <a href="https://github.com/danielTobon43/danielTobon43.github.io/blob/master/pages/Projects/urdf-sim/source_code.zip?raw=true">here</a><br>

<b>Documentation:</b>
<div style="text-align: center; margin-top: 90px;">
  <iframe src="/pages/Projects/urdf-sim/doc/paper.pdf" scrolling="no" width="850px" height="2200px" frameBorder="0"></iframe>
</div>

