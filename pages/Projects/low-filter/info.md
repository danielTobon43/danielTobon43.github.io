---
layout: page
title: Embedded low filter in an atmega 2560 microcontroller
subtitle: 
cover-img: "/pages/Projects/low-filter/banner.png"
---
<div style="text-align: justify ">
The present project is the implementation of a LOW FILTER using the Atmega 2560 microcontroller. Based on the theory of microprocessors, it is intended to sample the voltage values ​​of a seinusoidal signal from a function generator every 1 ms, through a analog-digital converter integrated in the microcontroller itself; then, discretize, quantize and encode the input data in its binary representation where the signal is processed digitally by applying a low-pass filter with a cut-off frequency of 300 Hz. Then, the filtered signal is output to a digital-analog converter in where the continuous signal is observed on a UTD2102CEL oscilloscope. The aim is to develop understanding of signal converters using the AVR family microcontrollers and Atmel Studio 7.0 simulation software. The circuit simulation was carried out with the Proteus 8.4 program. Finally, the frequency response of the low pass filter was plotted in Matlab mathematical software.<br><br>

Source code: <a href="https://github.com/danielTobon43/danielTobon43.github.io/blob/master/pages/Projects/low-filter/source_code.txt?raw=true">here</a><br>
paper: <a href="https://github.com/danielTobon43/danielTobon43.github.io/blob/master/pages/Projects/low-filter/paper.docx?raw=true">here</a><br><br>

<img src="/pages/Projects/low-filter/chip.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />
<div style="text-align: justify ">
This project introduces the topic of how to integrate a Low filter with ATMEGA 2560 MICROCONTROLLER of the AVR family. The Atmega 2560 [1] is a low-power electronic device that uses the RISC architecture and can achieve throughputs of up to 16 million instructions per second operating with supply voltages 4.5 - 5 V. Figure 1 shows the 100 pins that make up the Atmega 2560 microcontroller indicating the functions they can perform, analog to digital signal converters, PWM, timers, counters, etc.
</div>

<img src="/pages/Projects/low-filter/dac.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />
<div style="text-align: justify ">
The microprocessor has its set of instructions or programming codes for the assembly language; Atmel Studio 7.0 [2] software allows simulating code programming in an integrated development environment that involves each control and status register.<br><br>

In general, the input and output ports of the microcontroller were defined; port F receives the sine signal from the function generator and port B outputs the digital signal to a digital-analog converter. It should be emphasized that this microcontroller does not have an integrated DAC converter, so the DAC0808 [3] was used externally. Figure 2 shows the typical connection of the DAC0808 digital-analog converter taken from the device's datasheet.
</div>

<b>Pipeline</b>
<div style="text-align: justify ">
The first step is to configure the micro so that it receives the input voltage values ​​and converts them to a digital signal where it can then be processed or transmitted. The datasheet shows the control and status registers in the ADC section. The images to be shown below are taken from the AVR device datasheet.<br><br>

The ADCSRB register allows you to select the ADC to use in the mic. In this case, ADC0 will be used, so the bits ADTS0 = 0, ADTS1 = 0 and ADTS2 = 0 are set to zero. By default, registers are initialized with zero, so it is not necessary to load data to this register. It is only meant to imply that you are going to work with the ADC0.
</div>

<img src="/pages/Projects/low-filter/p1.png" align="center"><br>

<div style="text-align: justify ">
Now, once the ADC to be used has been selected, we proceed to handle the register that enables the use of the ADC, since by default and due to energy consumption, it is disabled.
The ADCSRA register controls the enablement of the ADC, the data conversion start, the prescaler, it contains the end of conversion flag, interrupt for end of conversion and a control bit for auto conversion.
</div>

<img src="/pages/Projects/low-filter/p2.png" align="center"><br>

The bits ADPS0, ADPS1 and ADPS2 correspond to the prescaler of the ADC, that is, the division factor that divides the working frequency of the micro. The table in the following figure shows the combination of bits, to select a factor of 2, 4, 8, 16, 32, 64 and 128.

<img src="/pages/Projects/low-filter/p3.png" align="center"><br>

<div style="text-align: justify ">
The micro has a 16 MHz quartz crystal, that is, the frequency or speed with which it executes the instructions is 16 million per second. The ADC needs a suitable working frequency or speed for two reasons; a high frequency for the ADC implies that the data conversion is very fast, but the digital value may not be very reliable. Now, a low frequency implies that the digital value is reliable, but the data conversion time is delayed. The manufacturer's datasheet indicates the ADC's range between 50 and 200 KHz, this means that putting the ADC to work at an intermediate frequency between that range is optimal, since the data is reliable and the conversion is not slow. It is at this point where the importance of the prescaler comes in, since it is the factor that determines the working speed of the ADC. The frequency or working speed of the ADC is defined as:<br><br>

<img src="https://render.githubusercontent.com/render/math?math=f_ADC =(f_{CPU}/prescaler)"><br><br>

where:<br>
<img src="https://render.githubusercontent.com/render/math?math=f_{ADC}"> -->	freq ADC<br>
<img src="https://render.githubusercontent.com/render/math?math=f_{CPU}"> --> 	Freq micro<br><br>

For this case, the frequency of the microprocessor is 16 MHz. The working frequency of the ADC should be approximately half the range, that is, 125 KHz. Replacing these values ​​in equation (1) and clearing the prescaler would give:<br><br>

<img src="https://render.githubusercontent.com/render/math?math=prescaler =(f_{CPU}/f_{ADC})=(16 MHz)/(125 KHz)=128"><br><br>

This indicates that, from the previous table, using a 16 MHz crystal and selecting a 128 prescaler will guarantee that the conversion speed of the ADC will be 125 KHz, an intermediate value of the speed range, which, it is optimal. Taking this into account, the three least significant bits of the ADCSRA register are loaded with 1 to select the prescaler of 128.<br><br>

On the other hand, in this application the ADC end-of-conversion interrupt is not needed, so the ADIE bit is kept at zero. In the same way, the ADATE bit that is the autotrigger is not used, it is also kept at zero.<br><br>

The remaining three bits are important; bit 7, ADEN enables the ADC. This bit is set to 1, then the ADIF bit is the flag bit that indicates the end of conversion. When this bit is set to 1 it indicates that the conversion has finished. Lastly, the ADSC bit is the conversion start bit. In other words, for this particular case, the register is loaded with the binary number (0B11000111). The last control register for the ADC is the ADMUX; In this register the reference voltage of the ADC is selected, if it will be from an external source, AVCC of 5V or the internal sources of the 1.1V or 2.5V micro.
</div>

<img src="/pages/Projects/low-filter/p4.png" align="center"><br>

The combination of bits shown in the following table describe the selection of the reference voltage. AVCC was selected for this application.

<img src="/pages/Projects/low-filter/p5.png" align="center"><br>

Finally, the ADLAR bit was loaded at 1 to select the left justification of the converted data and save it in ADCH.

