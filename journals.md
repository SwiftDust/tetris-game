# Tetris game Build Journal

## Jul 5, 2026, 9:36 PM

Today, I made a more detailed plan for what sensors to use in my project. I found two relatively cheap sensors, they go for 20 eurocent each on Alibaba. For my project idea, which is a tetris motion game, I don't think a standard motion sensor will work well. That's why I use a tilt and a shake sensor. I also learned a bit about the ESP32 and set up a KiCad project. However, I couldn't find out what footprint to use yet. I'm tired now; I will continue tomorrow.

---

## Jul 9, 2026, 2:21 PM

Today, I wired the vibration sensor with the breadboard and wrote the firmware for it. I searched up an Instructables tutorial to find out how to read the output. The code seems to work, but it looks like there's an error with my wiring diagram. I'll ask in the Breadboard channel if anyone can help me with this.

---

## Jul 14, 2026, 9:30 AM

I wired up an Adafruit display. I googled a pinout and used that. Then, I uploaded example code to see if it works. It seems to work, so that's great. Sadly, I couldn't figure out how to use multiple scripts.

---

## Jul 14, 2026, 11:44 AM

Apparently my board got removed. Luckily I still had my code somewhere. I realised the Arduino had stuff that better fitted what I actually wanted to make, so I switched to that. Now the stack is going to be a display for the score and an 8x8 dot matrix for the actual game.

---

## Jul 15, 2026, 9:06 AM

I added a push button that would let the Arduino know the game is started. I filtered the noisy data by adding debounce. I got this information from the Breadboard docs. It works. Currently there is only a Serial.println(), but I'll feed this data to the Arduino to change the LCD and turn on the led matrix.

---

## Jul 15, 2026, 10:10 AM

I wired up the entire 8x8 matrix and wrote code to light up a specific LED in a row or column. This was tedious, since apparently there is no IC included in the kit to make interfacing with this matrix a bit easier. Now, all the pins from my Arduino are used. I also changed the vibration sensor to the tilt switch. First I wanted to use them both, but the vibration sensor didn't really add anything meaningful except speeding up the game, so that's why I left that out. I would add them both if there were enough pins to do so. Of course in a 50% odd I swapped the rows and columns, so now I have to rename all the variables... how nice.

---

## Jul 15, 2026, 8:57 PM

It turned out I wired the matrix wrong. Apparently, the columns and rows are shuffled and not just row 1-8 = pin 1-8. After some scrambling, I found out the right wiring. But the part seems to be broken in the editor. Very great...not. It just displays some random LED sequence whereas it's supposed to display one LED at a time.