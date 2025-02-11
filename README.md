# STM32F4 GLCD Line Drawing Firmware

## Overview
This repository contains firmware for an STM32F4 microcontroller to control a **128x64 Graphic LCD (GLCD)**. The code includes implementations of various **line-drawing algorithms** such as:

- **Bresenham's Line Algorithm** (`displayLine` function)
- **Digital Differential Analyzer (DDA) Algorithm** (`DDA` function)
- **Optimized Line Drawing** (`DrawLine3` function)

The firmware interfaces with the GLCD using GPIOs and provides basic drawing functionality.

## Features
- **Clock Configuration**: Initializes the STM32F4 clock and GPIO ports.
- **GPIO Control**: Configures GPIOA and GPIOB as output ports.
- **GLCD Initialization**: Calls `glcdInit()` to set up the display.
- **Line Drawing**: Implements multiple algorithms to draw lines on the GLCD.
- **Dot Plotting**: Uses `displayDot(x, y, OT)` to set individual pixels.
- **Delay Function**: Simple loop-based delay for timing control.

## Hardware Requirements
- **Microcontroller**: STM32F4 series (e.g., STM32F407VG)
- **Display**: 128x64 GLCD (e.g., HDG12864L6)
- **Connections**:
  - GPIOA and GPIOB for data/control signals
  - External clock if needed for performance optimization

## How It Works
1. **Clock Initialization**: `provideClock()` enables GPIO clocks.
2. **GPIO Setup**: Configures GPIOA and GPIOB as output push-pull.
3. **GLCD Initialization**: Calls `glcdInit()` to set up the screen.
4. **Drawing Functions**:
   - `displayLine(x0, y0, x1, y1)`: Uses Bresenham’s algorithm to draw lines.
   - `DDA(x0, y0, x1, y1)`: Uses the DDA algorithm for smoother lines.
   - `DrawLine3(x1, y1, x2, y2)`: Alternative optimized algorithm for fast line drawing.
5. **Main Function Execution**: Calls `displayLine(22,11,23,14)` to demonstrate line drawing.

## Scope for Improvement
- **Optimize delay function**: The current loop-based delay is inefficient. Consider using **hardware timers**.
- **Improve display functions**: Add support for **rectangle, circle, and text rendering**.
- **Use DMA for GPIO control**: This will reduce CPU load and improve performance.
- **Enhance modularity**: Separate GLCD control and drawing algorithms into different files.
- **Add touchscreen support**: If the GLCD module supports touch input, implement touch handling.

## Future Enhancements
- **Text rendering functions**
- **Sprite and bitmap support**
- **Dynamic framebuffer for smooth rendering**

## How to Run
1. Flash the firmware onto the STM32F4 microcontroller using **Keil uVision** or **STM32CubeIDE**.
2. Connect the GLCD to the GPIO pins as per the datasheet.
3. Power up the circuit and observe the graphical output on the screen.

## License
This project is open-source and can be modified or improved for educational and personal use.
