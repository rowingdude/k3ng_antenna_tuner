/*
  tuner_config_tuner_hardware.h - Hardware-specific configuration for K3NG Arduino Antenna Tuner
  
  This file contains hardware-specific definitions and relay mappings.
*/

#ifndef TUNER_CONFIG_TUNER_HARDWARE_H
#define TUNER_CONFIG_TUNER_HARDWARE_H

// Relay pin arrays - map logical relay numbers to physical pins
byte capacitor_pins[] = {
  pin_capacitor_1, pin_capacitor_2, pin_capacitor_3, pin_capacitor_4,
  pin_capacitor_5, pin_capacitor_6, pin_capacitor_7, pin_capacitor_8
};

byte inductor_pins[] = {
  pin_inductor_1, pin_inductor_2, pin_inductor_3, pin_inductor_4,
  pin_inductor_5, pin_inductor_6, pin_inductor_7, pin_inductor_8
};

// Component value arrays - values in pF and nH
unsigned int capacitor_values[] = {
  CAPACITOR_VALUE_1, CAPACITOR_VALUE_2, CAPACITOR_VALUE_3, CAPACITOR_VALUE_4,
  CAPACITOR_VALUE_5, CAPACITOR_VALUE_6, CAPACITOR_VALUE_7, CAPACITOR_VALUE_8
};

unsigned int inductor_values[] = {
  INDUCTOR_VALUE_1, INDUCTOR_VALUE_2, INDUCTOR_VALUE_3, INDUCTOR_VALUE_4,
  INDUCTOR_VALUE_5, INDUCTOR_VALUE_6, INDUCTOR_VALUE_7, INDUCTOR_VALUE_8
};

// Number of components
#define NUMBER_OF_CAPACITORS (sizeof(capacitor_pins)/sizeof(capacitor_pins[0]))
#define NUMBER_OF_INDUCTORS (sizeof(inductor_pins)/sizeof(inductor_pins[0]))

// Tuning network modes
#define TUNING_MODE_NONE 0
#define TUNING_MODE_HIZ 1     // High-Z (series L, shunt C)
#define TUNING_MODE_LOZ 2     // Low-Z (shunt C, series L)

// Relay states
#define RELAY_ON HIGH
#define RELAY_OFF LOW

// For latching relays, define pulse duration
#define LATCHING_RELAY_PULSE_MS 25

// I2C addresses for expanders (if used)
#ifdef IO_EXPANDER_MCP23008
  #define MCP23008_ADDRESS 0x20
#endif

#ifdef IO_EXPANDER_MCP23017
  #define MCP23017_ADDRESS 0x20
#endif

// Antenna and transmitter definitions
#define MAX_ANTENNAS 8
#define MAX_TRANSMITTERS 4

// Calibration structure for power measurements
struct power_calibration_t {
  float frequency;      // Frequency in MHz
  float fwd_cal;        // Forward power calibration factor
  float rev_cal;        // Reverse power calibration factor
};

// Default calibration table (adjust for your directional coupler)
power_calibration_t power_calibration[] = {
  {1.8,   1.0,  1.0},
  {3.5,   1.0,  1.0},
  {7.0,   1.0,  1.0},
  {10.1,  1.0,  1.0},
  {14.0,  1.0,  1.0},
  {18.0,  1.0,  1.0},
  {21.0,  1.0,  1.0},
  {24.5,  1.0,  1.0},
  {28.0,  1.0,  1.0}
};

#define NUMBER_OF_CALIBRATION_POINTS (sizeof(power_calibration)/sizeof(power_calibration[0]))

// Component status arrays (0 = off, 1 = on)
byte capacitor_status[NUMBER_OF_CAPACITORS] = {0};
byte inductor_status[NUMBER_OF_INDUCTORS] = {0};

// Tuning mode status
byte tuning_mode_status[TUNING_MODES] = {0};

// Tuning mode names
const char* tuning_mode_names[] = {"None", "HiZ", "LoZ"};

// Command macros for components
// These define the commands to activate/deactivate each component
// Format: pin number followed by state (1=on, 0=off)

// Capacitor macros
byte capacitor_activate_macros[NUMBER_OF_CAPACITORS][2] = {
  {pin_capacitor_1, 1}, {pin_capacitor_2, 1}, {pin_capacitor_3, 1}, {pin_capacitor_4, 1},
  {pin_capacitor_5, 1}, {pin_capacitor_6, 1}, {pin_capacitor_7, 1}, {pin_capacitor_8, 1}
};

byte capacitor_deactivate_macros[NUMBER_OF_CAPACITORS][2] = {
  {pin_capacitor_1, 0}, {pin_capacitor_2, 0}, {pin_capacitor_3, 0}, {pin_capacitor_4, 0},
  {pin_capacitor_5, 0}, {pin_capacitor_6, 0}, {pin_capacitor_7, 0}, {pin_capacitor_8, 0}
};

// Inductor macros
byte inductor_activate_macros[NUMBER_OF_INDUCTORS][2] = {
  {pin_inductor_1, 1}, {pin_inductor_2, 1}, {pin_inductor_3, 1}, {pin_inductor_4, 1},
  {pin_inductor_5, 1}, {pin_inductor_6, 1}, {pin_inductor_7, 1}, {pin_inductor_8, 1}
};

byte inductor_deactivate_macros[NUMBER_OF_INDUCTORS][2] = {
  {pin_inductor_1, 0}, {pin_inductor_2, 0}, {pin_inductor_3, 0}, {pin_inductor_4, 0},
  {pin_inductor_5, 0}, {pin_inductor_6, 0}, {pin_inductor_7, 0}, {pin_inductor_8, 0}
};

// Tuning mode macros
byte tuning_mode_activate_macros[TUNING_MODES][2] = {
  {0, 0},  // None - no action
  {pin_relay_network_hiz, 1},  // HiZ mode
  {pin_relay_network_loz, 1}   // LoZ mode
};

byte tuning_mode_deactivate_macros[TUNING_MODES][2] = {
  {0, 0},  // None - no action
  {pin_relay_network_hiz, 0},  // HiZ mode off
  {pin_relay_network_loz, 0}   // LoZ mode off
};

// I2C expander addresses (if used)
#if IO_EXPANDERS > 0
byte i2c_expander_addr[IO_EXPANDERS] = {MCP23008_ADDRESS};
#endif

// Shift register variables (74HC595)
#ifdef FEATURE_SHIFT_REGISTER_595
  byte shift_register_state[SHIFT_REGISTER_COUNT] = {0}; // Current state of each shift register
  #define TOTAL_SHIFT_REGISTER_PINS (SHIFT_REGISTER_COUNT * PINS_PER_SHIFT_REGISTER)
#endif

#endif // TUNER_CONFIG_TUNER_HARDWARE_H