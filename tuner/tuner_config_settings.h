/*
  tuner_config_settings.h - Operating parameters for K3NG Arduino Antenna Tuner
  
  These settings control the behavior of the antenna tuner.
  Adjust these values based on your antenna system and operating preferences.
*/

#ifndef TUNER_CONFIG_SETTINGS_H
#define TUNER_CONFIG_SETTINGS_H

// SWR thresholds and targets
#define SWR_TRIGGER_TUNE 2.0              // SWR level that triggers automatic tuning
#define SWR_TRIGGER_TIME_MS 2000          // Time in ms above trigger before tuning starts
#define TARGET_SWR_GOOD_SETTING 1.5       // Target SWR for "good" match
#define TARGET_SWR_ACCEPTABLE_SETTING 2.0 // Target SWR for "acceptable" match
#define SWR_OF_LAST_RESORT_CONSIDER_TUNED 3.0  // SWR to consider "tuned" when nothing better found
#define SWR_OF_LAST_RESORT_KHZ_TUNED 50  // Frequency range in kHz for last resort tuning

// Timing parameters
#define TARGET_SWR_GOOD_TIME 15000        // Time in ms to try for good SWR before accepting acceptable
#define TARGET_SWR_ACCEPTABLE_TIME 30000  // Time in ms to try for acceptable SWR before giving up
#define PENDING_IDLE_SWR_OK_TIME 1000     // Time in ms to wait with good SWR before going idle
#define RELAY_SETTLE_TIME 50              // Time in ms to wait after relay switching

// Buffer sizes
#define COMMAND_BUFFER_SIZE 50            // Size of command buffer
#define TUNE_BUFFER_SIZE 100              // Number of tuning solutions to store
#define SWR_HISTORY_CACHE_SIZE 10         // Number of SWR readings to average

// Display parameters
#define LCD_COLUMNS 16                    // Number of LCD columns
#define LCD_ROWS 2                        // Number of LCD rows

// Frequency counter calibration
#define FREQUENCY_COUNTER_CALIBRATION 1.0 // Calibration factor for frequency counter

// Power calibration (example values - calibrate for your directional coupler)
#define FORWARD_POWER_CALIBRATION 0.1     // Calibration factor for forward power
#define REVERSE_POWER_CALIBRATION 0.1     // Calibration factor for reverse power

// Sleep mode
#define SLEEP_INACTIVITY_TIME 600000      // Time in ms before entering sleep mode (10 minutes)

// I2C parameters
#define I2C_POST_WRITE_DELAY 1            // Delay in ms after I2C writes

// SWR measurement parameters
#define SWR_SAMPLE_TIME_MS 100            // Time between SWR samples in milliseconds
#define MINIMUM_SWR_SAMPLE_COUNT 3        // Minimum samples needed for valid SWR reading
#define FORWARD_V_TX_SENSE_THRESH 50      // ADC threshold to detect transmit (0-1023)
#define TRANSMIT_STOP_GOTO_IDLE_TIME_MS 1000  // Time to wait after TX stops before going idle

// EEPROM parameters
#define EEPROM_MAGIC_NUMBER 73            // Magic number to validate EEPROM contents

// Component values (adjust based on your hardware)
// Capacitor values in pF
#define CAPACITOR_VALUE_1 10
#define CAPACITOR_VALUE_2 20
#define CAPACITOR_VALUE_3 40
#define CAPACITOR_VALUE_4 80
#define CAPACITOR_VALUE_5 160
#define CAPACITOR_VALUE_6 320
#define CAPACITOR_VALUE_7 640
#define CAPACITOR_VALUE_8 1280

// Inductor values in nH
#define INDUCTOR_VALUE_1 100
#define INDUCTOR_VALUE_2 200
#define INDUCTOR_VALUE_3 400
#define INDUCTOR_VALUE_4 800
#define INDUCTOR_VALUE_5 1600
#define INDUCTOR_VALUE_6 3200
#define INDUCTOR_VALUE_7 6400
#define INDUCTOR_VALUE_8 12800

// Maximum values
#define MAX_CAPACITANCE 2550              // Maximum capacitance in pF
#define MAX_INDUCTANCE 25500              // Maximum inductance in nH

// Tuning algorithm parameters
#define AUTOTUNE_STEP_SIZE 1              // Step size for tuning algorithm
#define AUTOTUNE_MAX_ITERATIONS 255       // Maximum iterations per tuning phase
#define TUNE_BUFFER_MATCH_THRESH_KHZ 50   // Frequency match threshold for tune buffer
#define UNTUNABLE_RETRY_TIME 45000        // Time in ms before retrying if untunable

// Sleep timer
#define GO_TO_SLEEP_TIMER SLEEP_INACTIVITY_TIME  // Alias for sleep timer

// Frequency counter gate time
#define FREQ_COUNTER_GATE_TIME 100        // Gate time in ms for frequency counter

// Number of components (these will be calculated from arrays)
#define CAPACITORS NUMBER_OF_CAPACITORS
#define INDUCTORS NUMBER_OF_INDUCTORS

// Total component values
#define TOTAL_CAPACITOR_VALUE (CAPACITOR_VALUE_1 + CAPACITOR_VALUE_2 + CAPACITOR_VALUE_3 + CAPACITOR_VALUE_4 + CAPACITOR_VALUE_5 + CAPACITOR_VALUE_6 + CAPACITOR_VALUE_7 + CAPACITOR_VALUE_8)
#define TOTAL_INDUCTOR_VALUE (INDUCTOR_VALUE_1 + INDUCTOR_VALUE_2 + INDUCTOR_VALUE_3 + INDUCTOR_VALUE_4 + INDUCTOR_VALUE_5 + INDUCTOR_VALUE_6 + INDUCTOR_VALUE_7 + INDUCTOR_VALUE_8)

// Increment values for high-L scanning
#define HI_L_C_INCREMENT 10
#define HI_L_L_INCREMENT 100

// Tuning modes
#define TUNING_MODES 3
#define RELAY_SETTLE_TIME_MS RELAY_SETTLE_TIME

// Serial settings
#define SERIAL_BAUD_RATE 9600

// EEPROM settings
#define EEPROM_WRITE_WAIT_MS 5000
#define EEPROM_BYTES 1024  // Arduino Mega has 4096, but we'll use less
#define TUNE_BUFFER_ADD_MATCH_THRESH_KHZ 25

// Display settings
#define DISPLAY_STATIC_SCREEN_UPDATE_MS 250

// Receive bypass
#define RECEIVE_BYPASS_DELAY 2000

// I/O expander settings
#define IO_EXPANDERS 0  // Set to number of I/O expanders used

#endif // TUNER_CONFIG_SETTINGS_H