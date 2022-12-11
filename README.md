Our final project was the PCB synthesizer. We used Altium to create a one layer PCB that housed 
5 buttons and resistors that simulated the first 5 keys of a piano. These buttons are connected to header pins 
that can be connected to our MSP via flywires. Each button triggers a pullup pin, which generates a PWM signal of
varying frequency depending on the button pressed. This PWM is outputed to a speaker, completing our PCB synth. 
We calculated the different CCR[0] values of the fundamental pitches A, A#/Bb, B, C, C#/Db and converted them to TICKS. 
If 2 or more buttons are pressed at the same time, we take the average frequency and output it.
