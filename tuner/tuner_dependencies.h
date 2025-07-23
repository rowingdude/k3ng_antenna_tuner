/*
  tuner_dependencies.h - Library dependencies for K3NG Arduino Antenna Tuner
  
  This file includes required libraries based on enabled features.
  The actual library includes are handled in the main .ino file.
*/

#ifndef TUNER_DEPENDENCIES_H
#define TUNER_DEPENDENCIES_H

// Check for required features and set dependencies

// LCD Display dependencies
#if defined(FEATURE_DISPLAY) && !defined(FEATURE_LCD_I2C)
  // Standard parallel LCD - requires LiquidCrystal library
  #define DEPENDENCY_LIQUIDCRYSTAL
#endif

#if defined(FEATURE_DISPLAY) && defined(FEATURE_LCD_I2C)
  // I2C LCD - requires Adafruit libraries
  #define DEPENDENCY_ADAFRUIT_MCP23017
  #define DEPENDENCY_ADAFRUIT_RGBLCDSHIELD
#endif

// Frequency counter dependency
#ifdef FEATURE_FREQ_COUNTER
  #define DEPENDENCY_FREQCOUNTER
#endif

// Rig interface dependency
#ifdef FEATURE_RIG_INTERFACE
  #define DEPENDENCY_SOFTWARESERIAL
  #define DEPENDENCY_K3NG_RIG_CONTROL
#endif

// I2C expander dependencies
#ifdef IO_EXPANDER_MCP23008
  #define DEPENDENCY_WIRE
  #define DEPENDENCY_MCP23008
#endif

#ifdef IO_EXPANDER_MCP23017
  #define DEPENDENCY_WIRE
  #define DEPENDENCY_MCP23017
#endif

// Always required dependencies
#define DEPENDENCY_EEPROM
#define DEPENDENCY_WIRE
#define DEPENDENCY_AVR_SLEEP
#define DEPENDENCY_AVR_WDT
#define DEPENDENCY_AVR_PGMSPACE

/*
  Library installation notes:
  
  1. FreqCount library - included in libraries folder
  2. k3ng_rig_control - included in libraries folder
  3. Adafruit_MCP23017 - install from Library Manager
  4. Adafruit_RGBLCDShield - install from Library Manager
  5. Other libraries (Wire, EEPROM, etc.) are included with Arduino IDE
*/

#endif // TUNER_DEPENDENCIES_H