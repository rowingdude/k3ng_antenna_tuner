# K3NG Arduino Antenna Tuner

An automatic antenna tuner controller for Arduino Mega, designed by Anthony Good, K3NG.

## Overview

This project implements an automatic antenna tuner using switched inductors and capacitors controlled by an Arduino Mega. The tuner automatically matches antenna impedance to minimize SWR (Standing Wave Ratio) for optimal power transfer.

## Features

- Automatic SWR-based tuning algorithm
- Support for High-Z and Low-Z matching networks
- Tune memory buffer to quickly recall previous tuning solutions
- Serial command line interface
- LCD display support (parallel or I2C)
- Frequency counter integration
- Rig control interface (Yaesu protocol)
- Sleep mode for power saving
- Receive bypass mode

## Hardware Requirements

- **Arduino Mega 2560** (required - Uno no longer supported as of version 2023.10.10)
- SWR bridge/directional coupler with forward and reverse voltage outputs
- Relays for switching capacitors and inductors
- Capacitor bank (8 binary-weighted capacitors recommended)
- Inductor bank (8 binary-weighted inductors recommended)
- Optional: LCD display (16x2 or 20x4)
- Optional: Frequency counter input
- Optional: I2C relay expander (MCP23008 or MCP23017)

## Installation

1. Clone or download this repository
2. Copy the configuration template files:
   - `tuner_config_pins.h` - Configure your hardware pin connections
   - `tuner_config_features.h` - Enable/disable features
   - `tuner_config_settings.h` - Adjust operating parameters
   - `tuner_debug.h` - Debug settings (normally all disabled)
   - `tuner_dependencies.h` - Library dependencies
   - `tuner_config_tuner_hardware.h` - Hardware-specific settings
3. Install required libraries:
   - FreqCount (included in libraries folder)
   - k3ng_rig_control (included in libraries folder) 
   - Adafruit_MCP23017 (if using I2C LCD)
   - Adafruit_RGBLCDShield (if using I2C LCD)
4. Configure the header files for your hardware
5. Upload to Arduino Mega

## Configuration

### Pin Configuration (tuner_config_pins.h)

Edit this file to match your hardware connections:
- Control buttons (manual tune, tune lock)
- Relay control pins for capacitors and inductors
- SWR measurement analog inputs
- LED indicators
- LCD connections
- Rig interface pins

### Feature Configuration (tuner_config_features.h)

Enable or disable features by commenting/uncommenting defines:
- `FEATURE_SERIAL` - Serial port communication
- `FEATURE_DISPLAY` - LCD display support
- `FEATURE_LCD_I2C` - Use I2C LCD instead of parallel
- `FEATURE_FREQ_COUNTER` - Frequency counter support
- `FEATURE_RIG_INTERFACE` - Rig control interface
- And more...

### Settings (tuner_config_settings.h)

Adjust operational parameters:
- SWR thresholds and targets
- Timing parameters
- Component values (capacitance/inductance)
- Calibration factors

## Usage

### Basic Operation

1. Connect the tuner between your transmitter and antenna
2. Power on the Arduino
3. The tuner will automatically tune when it detects:
   - High SWR during transmission
   - Manual tune button press
   - Serial command

### LED Indicators

- **Tuned** (Green): SWR is acceptable
- **Tuning** (Yellow): Tuning in progress
- **Untunable** (Red): Unable to achieve acceptable SWR

### Serial Commands

Connect via serial terminal at 9600 baud:
- `?` - Display help menu
- `T` - Manual tune
- `L` - Lock tuner (disable auto-tune)
- `U` - Unlock tuner
- `S` - Display status
- `D` - Toggle debug mode

## Tuning Algorithm

The tuner uses a multi-phase approach:
1. **Straight Through** - Try antenna without matching
2. **Tune Buffer Check** - Look for previous solutions
3. **High-Z Scan** - Series L, shunt C configuration
4. **Low-Z Scan** - Shunt C, series L configuration
5. **Extended Scans** - Try with maximum inductance
6. **Last Resort** - Accept higher SWR if necessary

## Troubleshooting

- **Won't compile**: Ensure all configuration header files are present
- **No SWR reading**: Check forward/reverse voltage connections and calibration
- **Won't tune**: Verify relay connections and component values
- **False tuning**: Update to latest version (fixes bug #4 with receive signals)

## Bug Fixes in This Version

- Fixed SWR reading bug when signals come down the antenna but TX isn't on (GitHub Issue #4)
- Added transmit detection logic using either dedicated TX sense pin or forward/reverse voltage ratio
- Updated TODO items and marked completed features

## License

Copyright 2013 and onwards, Anthony Good, K3NG. See LICENSE file for details.

## Contributing

Bug reports and contributions welcome via GitHub issues and pull requests.

## References

- Schematics available in `/schematics` folder
- Original project page: [K3NG Arduino Antenna Tuner](https://blog.radioartisan.com/arduino-antenna-tuner/)