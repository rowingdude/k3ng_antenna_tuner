/*
  tuner_config_features.h - Feature configuration for K3NG Arduino Antenna Tuner
  
  Comment out features you don't want to use to save memory and processing power.
*/

#ifndef TUNER_CONFIG_FEATURES_H
#define TUNER_CONFIG_FEATURES_H

// Core features
#define FEATURE_SERIAL                    // Serial port communication
#define FEATURE_COMMAND_LINE_INTERFACE    // Command line interface via serial port

// Display features
// #define FEATURE_DISPLAY                // Enable LCD display support
// #define FEATURE_LCD_I2C                // Use I2C LCD instead of parallel LCD

// Measurement features
// #define FEATURE_FREQ_COUNTER           // Enable frequency counter functionality

// Rig interface features
// #define FEATURE_RIG_INTERFACE          // Enable rig control interface

// Operating features
// #define FEATURE_RECEIVE_FREQ_AUTOSWITCH // Auto-switch based on receive frequency
// #define FEATURE_RECEIVE_BYPASS         // Enable receive bypass mode
// #define FEATURE_SLEEP_MODE             // Enable sleep mode to save power

// I2C expander options
// #define IO_EXPANDER_MCP23008           // Use MCP23008 I2C expander for relays
// #define IO_EXPANDER_MCP23017           // Use MCP23017 I2C expander for relays

// Shift register expander options
// #define FEATURE_SHIFT_REGISTER_595     // Use 74HC595 shift registers for relay control

// Advanced options
// #define OPTION_TUNE_BUFFER_ENTRY_USE_ACCEPTABLE_SWR  // Store tune buffer entries with acceptable SWR
// #define OPTION_WRITE_CONFIG_BEFORE_SLEEP              // Write config to EEPROM before sleep

// LCD specific options (if FEATURE_LCD_I2C is defined)
#ifdef FEATURE_LCD_I2C
  #define FEATURE_LCD_I2C_STATUS_COLOR    // Use LCD backlight color to indicate status
#endif

// Debug features (normally disabled)
// #define DEBUG_RELAY_TEST               // Test relay operation at startup
// #define DEBUG_DONT_TUNE                // Disable tuning for testing
// #define DEBUG_NO_FREQ                  // Disable frequency measurement
// #define DEBUG_CHECK_STATE              // Debug state machine
// #define DEBUG_SERVICE_TUNING           // Debug tuning service
// #define DEBUG_SERVICE_TUNING_VERBOSE_FREQ  // Verbose frequency debug
// #define DEBUG_STATUS_DUMP              // Periodic status dump
// #define DEBUG_REAL_DEEP_STUFF          // Very detailed debug output
// #define DEBUG_I2C_PIN_WRITE            // Debug I2C pin writes

#endif // TUNER_CONFIG_FEATURES_H