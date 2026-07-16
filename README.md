# Tetris game






> Built in [Breadboard](https://breadboard.hackclub.com), a Hack Club program. This project took ~6.6 hours of work.



## What It Does

A Tetris game that you play by tilting the hardware. If you tilt it you can move the blocks left or right.

NOTE: The project says "ESP32" but I hit Ctrl+Z and it deleted everything, then I realised the stuff in the Arduino kit might be a better fit anyways. So can I please get an Arduino kit?


## How It Works

The circuit is captured in `breadboard-project.json`, and the firmware that runs it is in the `firmware/` folder.


## How To Use It

You need a LCD1602, a breadboard and an Arduino Uno, which are all in the kit. You also need a tilt switch, which you'll need to source from Aliexpress yourself. It's an IC with three pins: VCC, GND and OUT.

It's a Tetris game. Press the button to start the game and see the score on the LCD. Move the blocks with the tilt switch.

Currently, the firmware isn't fully done, because two vital components I wanted to use seem to malfunction in the simulator; namely the 8x8 matrix and the tilt switch. I will finish the firmware up when I receive the kit.


## Demo

- **Simulate it live:** [https://breadboard.hackclub.com/share/44](https://breadboard.hackclub.com/share/44), runs the firmware in the Breadboard simulator
- **View the design:** [https://taniwankenobi.github.io/breadboard-plays/p/44/](https://taniwankenobi.github.io/breadboard-plays/p/44/)


## Schematic

The editor snapshot is in `breadboard-project.json`.


## Bill of Materials

| Part | Quantity |
| --- | --- |
| breadboard-full | 1 |
| dot-matrix-8x8 | 1 |
| lcd1602 | 1 |
| lcd1602-i2c | 1 |
| pushbutton | 1 |
| tilt-switch | 1 |


## Firmware

Firmware files are in the `firmware/` folder.


## Build Journal

Build journal entries are kept in [`journals.md`](journals.md).


---



*Made in [Breadboard](https://breadboard.hackclub.com) — 6.6h of work*



<p align="center"><img src="https://cdn.hackclub.com/019efae7-6857-75a2-8bc1-2618087b4eae/a%20bred%20tanuki%20(3).png" width="64" alt="Breadboard mascot" /></p>