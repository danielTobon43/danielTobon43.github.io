---
layout: page
title: Embedded control atmega 2560
subtitle: 
cover-img: "/pages/Projects/chocolate-project/model.JPG"
---
<div style="text-align: justify ">
A chocolate injection line was implemented for a scale-size cupcake, using sequential
logic in an Atmel micro-controller. Proximity sensors for measure distances, an
solenoid valve for the chocolate injection and a 12V fan for cooling stage. The
cupcake was located in an initial stage and then, it moves through a conveyor belt
for each phase: chocolate injection, cooling and deposit. The micro-controller was
programmed using c++.<br><br>

Source code: [here](https://github.com/danielTobon43/danielTobon43.github.io/blob/master/pages/Projects/chocolate-project/source_code?raw=true)

This project introduces the topic of how to integrate MICROPROCESSORS FROM AN INDUSTRIAL PROCESS APPLICATION IN THE PREPARATION OF A CHOCOLATE MIXTURE. Starting from the theory of microprocessors, the design process begins with the selection of the appropriate inputs for the elaboration of the chocolate-flavored mixture; Then, the stages that make up the process are defined, being the supply of the paper cup to the production line where the mass of the mixed content is poured, the start-up of the oven, which must heat the mixture to a temperature and adequate time and finally, the process of cooling the chocolate for its subsequent packaging and distribution.
</div>

<b> Production line</b>
<img src="/pages/Projects/chocolate-project/block.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />
<div style="text-align: justify ">
The procedure for preparing the mixture consists mainly of four stages [4]; 1) the introduction of ingredients, 2) the cooking of the mixture in an oven at the appropriate temperature and time, 3) the pouring of the mixture into the paper cup molds and, finally, 4) the final cooling of the product for its subsequent shipment.<br><br>

The ingredients enter a system where they are mixed and a mass of thick consistency is generated. If the melting furnace is considered as a plant, the process variables involved in the system can be established in the following way.
The consistency of the dough must be liquid, so the controlled variable of the plant would be the speed of rotation or mixing of the system and the temperature of the same. A sensor measures the process variable, which compares with a standardized reference established by the operator, where the error is compensated through a controller (microprocessor) that compares the values ​​defining the deviation with respect to the desired value in the system and generates a control signal that enters the final control element that, of course, modifies the behavior of the plant. The following figure shows the closed-loop control diagram of the "Melter Furnace" plant for the ingredients of the mixture.
</div>

<img src="/pages/Projects/chocolate-project/loop.png" align="center"><br>

<div style="text-align: justify ">
As can be seen, the manipulated variable is the voltage applied to the plant, modifying its behavior, that is, the variable that is controlled is the mixing speed of the system.
On the other hand, the appropriate temperature that the melting furnace must have is analyzed in the same way: the temperature of the melting furnace is defined as a controlled variable, so a sensor must measure the process variable and deliver that value to the microprocessor which , compares with a reference established by the operator how deviated it is from the real value of the system. Then, the microprocessor determines instructions where it generates a control signal that modifies and compensates the action of the plant to correct the error produced.
</div>


