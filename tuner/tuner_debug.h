/*
  tuner_debug.h - Debug configuration for K3NG Arduino Antenna Tuner
  
  This file controls debug output and testing features.
  Normally all debug features should be commented out for production use.
*/

#ifndef TUNER_DEBUG_H
#define TUNER_DEBUG_H

// Set the default debug mode (0 = off, 1 = on)
#define DEBUG_MODE_DEFAULT 0

// Debug features - uncomment to enable
// #define DEBUG_RELAY_TEST                 // Test all relays at startup
// #define DEBUG_DONT_TUNE                  // Disable actual tuning (for UI testing)
// #define DEBUG_NO_FREQ                    // Disable frequency measurement
// #define DEBUG_CHECK_STATE                // Debug state machine transitions
// #define DEBUG_SERVICE_TUNING             // Debug tuning algorithm
// #define DEBUG_SERVICE_TUNING_VERBOSE_FREQ // Very verbose frequency debugging
// #define DEBUG_STATUS_DUMP                // Periodic status information dump
// #define DEBUG_REAL_DEEP_STUFF            // Extremely verbose debug output
// #define DEBUG_I2C_PIN_WRITE              // Debug I2C communication
// #define DEBUG_SERIAL                     // Debug serial communication
// #define DEBUG_COMMAND_BUFFER             // Debug command processing
// #define DEBUG_SWR_MEASURE                // Debug SWR measurements
// #define DEBUG_RELAY_CONTROL              // Debug relay switching
// #define DEBUG_EEPROM                     // Debug EEPROM operations
// #define DEBUG_FREQ_COUNTER               // Debug frequency counter
// #define DEBUG_DISPLAY                    // Debug LCD display operations
// #define DEBUG_RIG_INTERFACE              // Debug rig control interface
// #define DEBUG_TUNE_BUFFER                // Debug tune buffer operations
// #define DEBUG_SLEEP_MODE                 // Debug sleep mode

// Test modes
// #define TEST_RELAY_SEQUENCE              // Run relay test sequence
// #define TEST_SWR_SIMULATION              // Simulate SWR readings
// #define TEST_FREQ_SIMULATION             // Simulate frequency readings

// Performance monitoring
// #define MONITOR_LOOP_TIME                // Monitor main loop execution time
// #define MONITOR_TUNE_TIME                // Monitor tuning cycle time
// #define MONITOR_MEMORY_USAGE             // Monitor RAM usage

#endif // TUNER_DEBUG_H