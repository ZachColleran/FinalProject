Our final project was the PCB synthesizer. We used Altium to create a one layer PCB that housed 
5 buttons and resistors that simulated the first 5 keys of a piano. These buttons are connected to header pins 
that can be connected to our MSP via flywires. Each button triggers a pullup pin, which generates a PWM signal of
varying frequency depending on the button pressed. This PWM is outputed to a speaker, completing our PCB synth. 
We calculated the different CCR[0] values of the fundamental pitches A, A#/Bb, B, C, C#/Db and converted them to TICKS. 
If 2 or more buttons are pressed at the same time, we take the average frequency and output it.

<img width="855" alt="Shematic" src="https://user-images.githubusercontent.com/111935446/207152267-ba5aabce-eeae-41d8-b5f9-84932462b03e.png">
<img width="893" alt="PCB" src="https://user-images.githubusercontent.com/111935446/207152289-b4e2bd23-c125-4530-b4ce-9c8e6531b9f7.png">

