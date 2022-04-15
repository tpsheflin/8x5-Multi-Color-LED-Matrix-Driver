# 8x5-Multi-Color-LED-Matrix-Driver-Code
8x5-Mulit-Color-LED-Matrix-Driver-Code for Arduino (UNO)

I purchased this 8 x 5 LED Matrix Display, CSM-58261EG-21, at a Hamfest several years ago (2017) and finally had the time to hook it up and make it work.
The display has two LED's per "pixel" Red and Green and when both are enabled the color is Amber.   
Something I've always wanted to do was to create my own character/number set, this was the perfect opportunity to do just that.  See screen shot of excel sheet used to plot the bits.
Arduino code was developed to drive the LED Matrix with minimal flicker while scrolling characters typed into an array across the display.  The color of the message is changed each time through the main loop.

Parts: Arduino UNO, 10 390 Ohm resistors, 36 jumper wires, CSM-58261EG-21 Display, large bread board, small bread board, difuser (cut piece of paper).

![image](https://user-images.githubusercontent.com/6855662/148662460-bd8c46db-d8b1-4205-8944-06f440bce074.png)

![image](https://user-images.githubusercontent.com/6855662/148178383-02bbf0e9-bb36-4192-aa8f-75309694f5ff.png)
