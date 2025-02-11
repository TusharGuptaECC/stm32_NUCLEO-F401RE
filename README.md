# Line Drawing Algorithm Performance Test on HDG12864L-6 GLCD using STM32 Nucleo-F401RE

This project is focused on testing the efficiency of various line-drawing algorithms on a low-resolution graphical display. It implements multiple line-drawing techniques on the **HDG12864L-6** graphical LCD using an **STM32 Nucleo-F401RE** microcontroller.

## Project Overview

The primary goal of this project is to analyze and compare the performance of different line-drawing algorithms on a **low-resolution display (128x64 pixels)**. The implemented algorithms include:

- **Bresenham's Line Algorithm**
- **DDA (Digital Differential Analyzer) Algorithm**
- **Custom Line Algorithm(experimental)**

These algorithms are tested by drawing lines on the **HDG12864L-6 GLCD** via **GPIO interfacing**, using **STM32 Nucleo-F401RE** as the microcontroller.

## Features

- Implements multiple line-drawing algorithms for performance testing.
- Uses **GPIO** to interface with the **HDG12864L-6** GLCD.
- Supports **coordinate-based pixel plotting** for testing.
- Allows easy modification to test different algorithms.
- Uses **STM32 HAL-based register-level programming**.

## How It Works

1. **GLCD Initialization**
   - The `glcdInit()` function initializes the **HDG12864L-6** graphical LCD.
2. **Line Drawing Algorithms**
   - The project includes different line-drawing techniques to render straight lines between given coordinate points.
3. **Performance Testing**
   - By executing each algorithm under the same conditions, their execution time and visual performance can be compared.

## Code Structure

```
📂 Project Directory
├── first.c                  # Main firmware containing algorithm implementations
├── HDG12864L6.h            # GLCD header file for display functions
├── HDG12864L6.c            # GLCD source file for display functions
├── README.md               # Project documentation
```

## Scope for Improvement

- **Optimize Performance**: Improve the execution speed by modifying data transfer methods (SPI/I2C instead of GPIO toggling).
- **Benchmarking**: Add execution time measurement to compare the efficiency of each algorithm.
- **Advanced Algorithms**: Implement **Wu’s anti-aliased line algorithm** for smoother rendering.
- **Expand Functionality**: Add support for **circles, rectangles, and other shapes** for further graphical tests.

## Requirements

- **Microcontroller**: STM32 Nucleo-F401RE
- **Display**: HDG12864L-6 GLCD
- **Development Environment**: Keil
- **Programming Language**: C

## Conclusion

This project serves as a **benchmarking tool** for evaluating line-drawing algorithms on a low-pixel graphical display. It is useful for embedded graphics development and performance analysis of **efficient rendering techniques**.

---

Feel free to contribute or suggest improvements! 

