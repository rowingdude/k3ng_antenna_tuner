/*
  tuner_config_pins.h - Pin configuration for K3NG Arduino Antenna Tuner
  
  This file defines the Arduino pins used for various hardware connections.
  Modify these values to match your hardware setup.
*/

#ifndef TUNER_CONFIG_PINS_H
#define TUNER_CONFIG_PINS_H

// Control pins
#define pin_manual_tune 2        // Manual tune button input pin (active low)
#define pin_tune_lock 3          // Tune lock switch input pin (active low)

// Relay control pins for capacitors
#define pin_capacitor_1 22       // Relay for capacitor 1
#define pin_capacitor_2 23       // Relay for capacitor 2
#define pin_capacitor_3 24       // Relay for capacitor 3
#define pin_capacitor_4 25       // Relay for capacitor 4
#define pin_capacitor_5 26       // Relay for capacitor 5
#define pin_capacitor_6 27       // Relay for capacitor 6
#define pin_capacitor_7 28       // Relay for capacitor 7
#define pin_capacitor_8 29       // Relay for capacitor 8

// Relay control pins for inductors
#define pin_inductor_1 30        // Relay for inductor 1
#define pin_inductor_2 31        // Relay for inductor 2
#define pin_inductor_3 32        // Relay for inductor 3
#define pin_inductor_4 33        // Relay for inductor 4
#define pin_inductor_5 34        // Relay for inductor 5
#define pin_inductor_6 35        // Relay for inductor 6
#define pin_inductor_7 36        // Relay for inductor 7
#define pin_inductor_8 37        // Relay for inductor 8

// Mode relay pins
#define pin_relay_network_bypass 38  // Bypass relay
#define pin_relay_network_hiz 39     // High-Z mode relay
#define pin_relay_network_loz 40     // Low-Z mode relay

// SWR measurement pins
#define pin_forward_voltage A0   // Forward power voltage reading
#define pin_reverse_voltage A1   // Reverse power voltage reading

// Alternate names used in code
#define pin_forward_v pin_forward_voltage
#define pin_reflected_v pin_reverse_voltage

// Transmit sense pin
#define pin_transmit_sense 4     // Transmit sense input

// LED indicator pins
#define pin_led_tuned 5          // Tuned status LED
#define pin_led_tuning 6         // Tuning in progress LED
#define pin_led_untunable 7      // Untunable status LED

// Alternate names for LED pins (used in code)
#define pin_tuned pin_led_tuned
#define pin_tune_in_progress pin_led_tuning
#define pin_untunable pin_led_untunable

// LCD display pins (if not using I2C)
// These are example pins - adjust for your LCD connection
#define pin_lcd_rs 12
#define pin_lcd_enable 11
#define pin_lcd_d4 10
#define pin_lcd_d5 9
#define pin_lcd_d6 8
#define pin_lcd_d7 7

// Rig interface pins
#define rig_0_control_rx 14      // Software serial RX for rig control
#define rig_0_control_tx 15      // Software serial TX for rig control

// Frequency counter input pin
#define pin_freq_counter_input 47  // Frequency counter input (must be pin 47 on Mega)

// Power control pins
#define pin_voltage_control 0     // Set to 0 if not used, or actual pin number
#define pin_awake 0               // Set to 0 if not used, or actual pin number
#define pin_wakeup 0              // Set to 0 if not used, or actual pin number

// Optional pins - comment out if not used
// #define pin_capacitor_9 41
// #define pin_capacitor_10 42
// #define pin_inductor_9 43
// #define pin_inductor_10 44

#endif // TUNER_CONFIG_PINS_H