/**
 * \file pros/ext_adi.h
 * \ingroup ext-adi
 *
 * Contains prototypes for interfacing with the 3-Wire Expander.
 *
 * This file should not be modified by users, since it gets replaced whenever
 * a kernel upgrade occurs.
 *
 * \copyright (c) 2017-2023, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 * 
 * \defgroup ext-adi ADI Expander C API
 * \note The internal ADI API can be found [here.](@ref c-adi)
 */

#ifndef _PROS_EXT_ADI_H_
#define _PROS_EXT_ADI_H_

#include <stdbool.h>
#include <stdint.h>

#include "adi.h"
#include "pros/adi.h"
#ifndef PROS_ERR
#define PROS_ERR (INT32_MAX)
#endif

#ifdef __cplusplus
extern "C" {
namespace pros {
#endif

#ifdef __cplusplus
namespace c {
#endif

/**
 * \ingroup ext-adi
 */

/**
 * \addtogroup ext-adi
 *  @{
 */

/******************************************************************************/
/**                         General ADI Use Functions                        **/
/**                                                                          **/
/**       These functions allow for interaction with any ADI port type       **/
/******************************************************************************/

/**
 * Gets the configuration for the given ADI port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *        The ADI port number (from 1-8, 'a'-'h', 'A'-'H') for which to return
 *        the configuration
 *
 * \return The ADI configuration for the given port
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   ext_adi_port_set_config(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT, E_ADI_ANALOG_IN);
 *   // Displays the value of E_ADI_ANALOG_IN
 *   printf("Port Type: %d\n", ext_adi_port_get_config(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT));
 * }
 * \endcode
 */
adi_port_config_e_t ext_adi_port_get_config(uint8_t smart_port, uint8_t adi_port);

/**
 * Gets the value for the given ADI port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port number (from 1-8, 'a'-'h', 'A'-'H') for which to return
 *        the configuration
 *
 * \return The value stored for the given port
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   ext_adi_port_set_config(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT, E_ADI_ANALOG_IN);
 *   printf("Port Value: %d\n", ext_adi_get_value(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT));
 * }
 * \endcode
 */
int32_t ext_adi_port_get_value(uint8_t smart_port, uint8_t adi_port);

/**
 * Configures an ADI port to act as a given sensor type.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port number (from 1-8, 'a'-'h', 'A'-'H') to configure
 * \param type
 *        The configuration type for the port
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   ext_adi_port_set_config(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT, E_ADI_ANALOG_IN);
 * }
 * \endcode
 */
int32_t ext_adi_port_set_config(uint8_t smart_port, uint8_t adi_port, adi_port_config_e_t type);

/**
 * Sets the value for the given ADI port.
 *
 * This only works on ports configured as outputs, and the behavior will change
 * depending on the configuration of the port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port number (from 1-8, 'a'-'h', 'A'-'H') for which the value
 *        will be set
 * \param value
 *        The value to set the ADI port to
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define DIGITAL_SENSOR_PORT 1
 * 
 * void initialize() {
 *   ext_adi_port_set_config(ADI_EXPANDER_PORT, DIGITAL_SENSOR_PORT, E_ADI_DIGITAL_OUT);
 *   ext_adi_set_value(ADI_EXPANDER_PORT, DIGITAL_SENSOR_PORT, HIGH);
 * }
 * \endcode
 */
int32_t ext_adi_port_set_value(uint8_t smart_port, uint8_t adi_port, int32_t value);

/**
 * Calibrates the analog sensor on the specified port and returns the new
 * calibration value.
 *
 * This method assumes that the true sensor value is not actively changing at
 * this time and computes an average from approximately 500 samples, 1 ms apart,
 * for a 0.5 s period of calibration. The average value thus calculated is
 * returned and stored for later calls to the adi_analog_read_calibrated() and
 * adi_analog_read_calibrated_HR() functions. These functions will return
 * the difference between this value and the current sensor value when called.
 *
 * Do not use this function when the sensor value might be unstable
 * (gyro rotation, accelerometer movement).
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port to calibrate (from 1-8, 'a'-'h', 'A'-'H')
 *
 * \return The average sensor value computed by this function
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void initialize() {
 *   ext_adi_analog_calibrate(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT);
 *   printf("Calibrated Reading: %d\n",
 *     ext_adi_analog_read_calibrated(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT));
 *   // All readings from then on will be calibrated
 * }
 * \endcode
 */
int32_t ext_adi_analog_calibrate(uint8_t smart_port, uint8_t adi_port);

/**
 * Gets the 12-bit value of the specified port.
 *
 * The value returned is undefined if the analog pin has been switched to a
 * different mode.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an analog input
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port (from 1-8, 'a'-'h', 'A'-'H') for which the value will be
 *        returned
 *
 * \return The analog sensor value, where a value of 0 reflects an input voltage
 * of nearly 0 V and a value of 4095 reflects an input voltage of nearly 5 V
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     printf("Sensor Reading: %d\n", ext_adi_analog_read(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_analog_read(uint8_t smart_port, uint8_t adi_port);

/**
 * Gets the 12 bit calibrated value of an analog input port.
 *
 * The adi_analog_calibrate() function must be run first. This function is
 * inappropriate for sensor values intended for integration, as round-off error
 * can accumulate causing drift over time. Use adi_analog_read_calibrated_HR()
 * instead.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an analog input
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port (from 1-8, 'a'-'h', 'A'-'H') for which the value will be
 *        returned
 *
 * \return The difference of the sensor value from its calibrated default from
 * -4095 to 4095
 * 
 * \b Example
 * \code
 *
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     printf("Sensor Reading: %d\n", ext_adi_analog_read_calibrated(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_analog_read_calibrated(uint8_t smart_port, uint8_t adi_port);

/**
 * Gets the 16 bit calibrated value of an analog input port.
 *
 * The adi_analog_calibrate() function must be run first. This is intended for
 * integrated sensor values such as gyros and accelerometers to reduce drift due
 * to round-off, and should not be used on a sensor such as a line tracker
 * or potentiometer.
 *
 * The value returned actually has 16 bits of "precision", even though the ADC
 * only reads 12 bits, so that error induced by the average value being between
 * two values when integrated over time is trivial. Think of the value as the
 * true value times 16.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an analog input
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port (from 1-8, 'a'-'h', 'A'-'H') for which the value will be
 *        returned
 *
 * \return The difference of the sensor value from its calibrated default from
 * -16384 to 16384
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     ext_adi_analog_calibrate(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT);
 * 
 *     printf("Sensor Reading: %d\n", ext_adi_analog_read_calibrated_HR(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_analog_read_calibrated_HR(uint8_t smart_port, uint8_t adi_port);

/**
 * Gets the digital value (1 or 0) of a port configured as a digital input.
 *
 * If the port is configured as some other mode, the digital value which
 * reflects the current state of the port is returned, which may or may not
 * differ from the currently set value. The return value is undefined for ports
 * configured as any mode other than a Digital Input.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a digital input
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port to read (from 1-8, 'a'-'h', 'A'-'H')
 *
 * \return True if the pin is HIGH, or false if it is LOW
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define DIGITAL_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     printf(“Sensor Value: %dn”, 
 *       ext_adi_digital_read(ADI_EXPANDER_PORT, DIGITAL_SENSOR_PORT)); 
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_digital_read(uint8_t smart_port, uint8_t adi_port);

/**
 * Gets a rising-edge case for a digital button press.
 *
 * This function is not thread-safe.
 * Multiple tasks polling a single button may return different results under the
 * same circumstances, so only one task should call this function for any given
 * button. E.g., Task A calls this function for buttons 1 and 2. Task B may call
 * this function for button 3, but should not for buttons 1 or 2. A typical
 * use-case for this function is to call inside opcontrol to detect new button
 * presses, and not in any other tasks.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a digital input
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port to read (from 1-8, 'a'-'h', 'A'-'H')
 *
 * \return 1 if the button is pressed and had not been pressed
 * the last time this function was called, 0 otherwise.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define DIGITAL_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     if (ext_adi_digital_get_new_press(ADI_EXPANDER_PORT, DIGITAL_SENSOR_PORT)) {
 *       // Toggle pneumatics or other state operations
 *     }
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_digital_get_new_press(uint8_t smart_port, uint8_t adi_port);

/**
 * Sets the digital value (1 or 0) of a port configured as a digital output.
 *
 * If the port is configured as some other mode, behavior is undefined.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a digital output
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port number (from 1-8, 'a'-'h', 'A'-'H') to configure
 * \param value
 *        An expression evaluating to "true" or "false" to set the output to
 *        HIGH or LOW respectively, or the constants HIGH or LOW themselves
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define DIGITAL_SENSOR_PORT 1
 * 
 * void opcontrol() {
 *   bool state = LOW;
 *   while (true) {
 *     state != state;
 *     ext_adi_digital_write(ADI_EXPANDER_PORT, DIGITAL_SENSOR_PORT, state);
 * 
 *     pros::delay(5); // toggle the sensor value every 50ms
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_digital_write(uint8_t smart_port, uint8_t adi_port, bool value);

/**
 * Configures the port as an input or output with a variety of settings.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port number (from 1-8, 'a'-'h', 'A'-'H') to configure
 * \param mode
 *        One of INPUT, INPUT_ANALOG, INPUT_FLOATING, OUTPUT, or OUTPUT_OD
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define ANALOG_SENSOR_PORT 1
 * 
 * void initialize() {
 *   ext_adi_pin_mode(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT, INPUT_ANALOG);
 * }
 * \endcode
 */
int32_t ext_adi_pin_mode(uint8_t smart_port, uint8_t adi_port, uint8_t mode);

/**
 * Sets the speed of the motor on the given port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an motor
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port number (from 1-8, 'a'-'h', 'A'-'H') to configure
 * \param speed
 *        The new signed speed; -127 is full reverse and 127 is full forward,
 *        with 0 being off
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define MOTOR_PORT 1
 * 
 * void opcontrol() {
 *   ext_adi_motor_set(ADI_EXPANDER_PORT, MOTOR_PORT, 127); // Go full speed forward
 *   pros::delay(1000);
 *   ext_adi_motor_set(ADI_EXPANDER_PORT, MOTOR_PORT, 0); // Stop the motor
 * }
 * \endcode
 */
int32_t ext_adi_motor_set(uint8_t smart_port, uint8_t adi_port, int8_t speed);

/**
 * Gets the last set speed of the motor on the given port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an motor
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port to get (from 1-8, 'a'-'h', 'A'-'H')
 *
 * \return The last set speed of the motor on the given port
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20 #
 * define MOTOR_PORT 1
 * 
 * void opcontrol() {
 *   ext_adi_motor_set(ADI_EXPANDER_PORT,
 *     MOTOR_PORT, 127); // Go full speed forward 
 *   printf(“Commanded Motor Power: %dn”,
 *     ext_adi_motor_get(ADI_EXPANDER_PORT, MOTOR_PORT)); // Will display 127
 *   pros::delay(1000); 
 *   ext_adi_motor_set(ADI_EXPANDER_PORT, MOTOR_PORT, 0); // Stop the motor
 * }
 * \endcode
 */
int32_t ext_adi_motor_get(uint8_t smart_port, uint8_t adi_port);

/**
 * Stops the motor on the given port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an motor
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *	      The ADI port to set (from 1-8, 'a'-'h', 'A'-'H')
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define MOTOR_PORT 1
 * 
 * void opcontrol() {
 *   ext_adi_motor_set(ADI_EXPANDER_PORT, MOTOR_PORT, 127); // Go full speed forward
 *   pros::delay(1000);
 *   ext_adi_motor_set(ADI_EXPANDER_PORT, MOTOR_PORT, 0); // Stop the motor
 *   ext_adi_motor_stop(ADI_EXPANDER_PORT, MOTOR_PORT); // use this instead
 * }
 * \endcode
 */
int32_t ext_adi_motor_stop(uint8_t smart_port, uint8_t adi_port);

/**
 * Reference type for an initialized encoder.
 *
 * This merely contains the port number for the encoder.
 */
typedef int32_t ext_adi_encoder_t;

/**
 * Gets the number of ticks recorded by the encoder.
 *
 * There are 360 ticks in one revolution.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an encoder
 *
 * \param enc
 *        The adi_encoder_t object from adi_encoder_init() to read
 *
 * \return The signed and cumulative number of counts since the last start or
 * reset
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20 
 * #define PORT_TOP 1 #define PORT_BOTTOM 2
 * 
 * void opcontrol() {
 *   ext_adi_encoder_t enc = ext_adi_encoder_init(ADI_EXPANDER_PORT,
 *     PORT_TOP, PORT_BOTTOM, false); 
 *   while (true) {
 *     printf(“Encoder Value: %dn”,
 *       ext_adi_encoder_get(enc));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_encoder_get(ext_adi_encoder_t enc);

/**
 * Creates an encoder object and configures the specified ports accordingly.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an encoder
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port_top
 *        The "top" wire from the encoder sensor with the removable cover side
 *        up. This should be in port 1, 3, 5, or 7 ('A', 'C', 'E', or 'G').
 * \param adi_port_bottom
 *        The "bottom" wire from the encoder sensor
 * \param reverse
 *        If "true", the sensor will count in the opposite direction
 *
 * \return An adi_encoder_t object to be stored and used for later calls to
 * encoder functions
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define PORT_TOP 1
 * #define PORT_BOTTOM 2
 * 
 * void opcontrol() {
 *   ext_adi_encoder_t enc = ext_adi_encoder_init(ADI_EXPANDER_PORT, PORT_TOP, PORT_BOTTOM, false);
 *   while (true) {
 *     printf("Encoder Value: %d\n", ext_adi_encoder_get(enc));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
ext_adi_encoder_t ext_adi_encoder_init(uint8_t smart_port, uint8_t adi_port_top, uint8_t adi_port_bottom, bool reverse);

/**
 * Sets the encoder value to zero.
 *
 * It is safe to use this method while an encoder is enabled. It is not
 * necessary to call this method before stopping or starting an encoder.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an encoder
 *
 * \param enc
 *        The adi_encoder_t object from adi_encoder_init() to reset
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define PORT_TOP 1
 * #define PORT_BOTTOM 2
 * 
 * void opcontrol() {
 *   ext_adi_encoder_t enc = ext_adi_encoder_init(ADI_EXPANDER_PORT, PORT_TOP, PORT_BOTTOM, false);
 *   pros::delay(1000); // Move the encoder around in this time
 *   ext_adi_encoder_reset(enc); // The encoder is now zero again
 * }
 * \endcode
 */
int32_t ext_adi_encoder_reset(ext_adi_encoder_t enc);

/**
 * Disables the encoder and voids the configuration on its ports.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an encoder
 *
 * \param enc
 *        The adi_encoder_t object from adi_encoder_init() to stop
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define ADI_EXPANDER_PORT 20
 * #define PORT_TOP 1
 * #define PORT_BOTTOM 2
 * 
 * void opcontrol() {
 *   ext_adi_encoder_t enc = ext_adi_encoder_init(ADI_EXPANDER_PORT, PORT_TOP, PORT_BOTTOM, false);
 *   // Use the encoder
 *   ext_adi_encoder_shutdown(enc);
 * }
 * \endcode
 */
int32_t ext_adi_encoder_shutdown(ext_adi_encoder_t enc);

/**
 * Reference type for an initialized ultrasonic.
 *
 * This merely contains the port number for the ultrasonic.
 */
typedef int32_t ext_adi_ultrasonic_t;

/**
 * Gets the current ultrasonic sensor value in centimeters.
 *
 * If no object was found, zero is returned. If the ultrasonic sensor was never
 * started, the return value is undefined. Round and fluffy objects can cause
 * inaccurate values to be returned.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an ultrasonic
 *
 * \param ult
 *        The adi_ultrasonic_t object from adi_ultrasonic_init() to read
 *
 * \return The distance to the nearest object in m^-4 (10000 indicates 1 meter),
 * measured from the sensor's mounting points.
 * 
 * \b Example
 * \code
 * 
 * #define PORT_PING 1
 * #define PORT_ECHO 2
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_ultrasonic_t ult = ext_adi_ultrasonic_init(ADI_EXPANDER_PORT, PORT_PING, PORT_ECHO);
 *   while (true) {
 *     // Print the distance read by the ultrasonic
 *     printf("Distance: %d\n", ext_adi_ultrasonic_get(ult));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_ultrasonic_get(ext_adi_ultrasonic_t ult);

/**
 * Creates an ultrasonic object and configures the specified ports accordingly.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an ultrasonic
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port_ping
 *        The port connected to the orange OUTPUT cable. This should be in port
 *        1, 3, 5, or 7 ('A', 'C', 'E', 'G').
 * \param adi_port_echo
 *        The port connected to the yellow INPUT cable. This should be in the
 *        next highest port following port_ping.
 *
 * \return An adi_ultrasonic_t object to be stored and used for later calls to
 * ultrasonic functions
 * 
 * \b Example
 * \code
 * 
 * #define PORT_PING 1
 * #define PORT_ECHO 2
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_ultrasonic_t ult = ext_adi_ultrasonic_init(ADI_EXPANDER_PORT, PORT_PING, PORT_ECHO);
 *   while (true) {
 *     // Print the distance read by the ultrasonic
 *     printf("Distance: %d\n", ext_adi_ultrasonic_get(ult));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
ext_adi_ultrasonic_t ext_adi_ultrasonic_init(uint8_t smart_port, uint8_t adi_port_ping, uint8_t adi_port_echo);

/**
 * Disables the ultrasonic sensor and voids the configuration on its ports.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as an ultrasonic
 *
 * \param ult
 *        The adi_ultrasonic_t object from adi_ultrasonic_init() to stop
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define PORT_PING 1
 * #define PORT_ECHO 2
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_ultrasonic_t ult = ext_adi_ultrasonic_init(ADI_EXPANDER_PORT, PORT_PING, PORT_ECHO);
 *   while (true) {
 *     // Print the distance read by the ultrasonic
 *     printf("Distance: %d\n", ext_adi_ultrasonic_get(ult));
 *     pros::delay(5);
 *   }
 *   ext_adi_ultrasonic_shutdown(ult);
 * }
 * \endcode
 */
int32_t ext_adi_ultrasonic_shutdown(ext_adi_ultrasonic_t ult);

/**
 * Reference type for an initialized gyroscope.
 *
 * This merely contains the port number for the gyroscope.
 *
 * (Might Be useless with the wire expander.)
 */
typedef int32_t ext_adi_gyro_t;

/**
 * Gets the current gyro angle in tenths of a degree. Unless a multiplier is
 * applied to the gyro, the return value will be a whole number representing
 * the number of degrees of rotation times 10.
 *
 * There are 360 degrees in a circle, thus the gyro will return 3600 for one
 * whole rotation.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a gyro
 *
 * \param gyro
 *        The adi_gyro_t object for which the angle will be returned
 *
 * \return The gyro angle in degrees.
 * 
 * \b Example
 * \code
 * 
 * #define GYRO_PORT 1
 * #define GYRO_MULTIPLIER 1 // Standard behavior
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_gyro_t gyro = ext_adi_gyro_init(ADI_EXPANDER_PORT, GYRO_PORT, GYRO_MULTIPLIER);
 *   while (true) {
 *     // Print the gyro's heading
 *     printf("Heading: %lf\n", ext_adi_gyro_get(gyro));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
double ext_adi_gyro_get(ext_adi_gyro_t gyro);

/**
 * Initializes a gyroscope on the given port. If the given port has not
 * previously been configured as a gyro, then this function starts a 1300 ms
 * calibration period.
 *
 * It is highly recommended that this function be called from initialize() when
 * the robot is stationary to ensure proper calibration.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a gyro
 *
 * \param smart_port
 *        The smart port number that the ADI Expander is in
 * \param adi_port
 *        The ADI port to initialize as a gyro (from 1-8, 'a'-'h', 'A'-'H')
 * \param multiplier
 *        A scalar value that will be multiplied by the gyro heading value
 *        supplied by the ADI
 *
 * \return An adi_gyro_t object containing the given port, or PROS_ERR if the
 * initialization failed.
 * 
 * \b Example
 * \code
 * 
 * #define GYRO_PORT 1
 * #define GYRO_MULTIPLIER 1 // Standard behavior
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_gyro_t gyro = ext_adi_gyro_init(ADI_EXPANDER_PORT, GYRO_PORT, GYRO_MULTIPLIER);
 *   while (true) {
 *     // Print the gyro's heading
 *     printf("Heading: %lf\n", ext_adi_gyro_get(gyro));
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
ext_adi_gyro_t ext_adi_gyro_init(uint8_t smart_port, uint8_t adi_port, double multiplier);

/**
 * Resets the gyroscope value to zero.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a gyro
 *
 * \param gyro
 *        The adi_gyro_t object for which the angle will be returned
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define GYRO_PORT 1
 * #define GYRO_MULTIPLIER 1 // Standard behavior
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_gyro_t gyro = ext_adi_gyro_init(ADI_EXPANDER_PORT, GYRO_PORT, GYRO_MULTIPLIER);
 *   uint32_t now = millis();
 *   while (true) {
 *     // Print the gyro's heading
 *     printf("Heading: %lf\n", ext_adi_gyro_get(gyro));
 *     
 *     if (millis() - now > 2000) {
 *       // Reset the gyro every 2 seconds
 *       ext_adi_gyro_reset(gyro);
 *       now = millis();
 *     }
 * 
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_gyro_reset(ext_adi_gyro_t gyro);

/**
 * Disables the gyro and voids the configuration on its port.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - Either the ADI port value or the smart port value is not within its
 *	   valid range (ADI port: 1-8, 'a'-'h', or 'A'-'H'; smart port: 1-21).
 * EADDRINUSE - The port is not configured as a gyro
 *
 * \param gyro
 *        The adi_gyro_t object to be shut down
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * #define GYRO_PORT 1
 * #define GYRO_MULTIPLIER 1 // Standard behavior
 * #define ADI_EXPANDER_PORT 20
 * 
 * void opcontrol() {
 *   ext_adi_gyro_t gyro = ext_adi_gyro_init(ADI_EXPANDER_PORT, GYRO_PORT, GYRO_MULTIPLIER);
 *   uint32_t now = millis();
 *   while (true) {
 *     // Print the gyro's heading
 *     printf("Heading: %lf\n", ext_adi_gyro_get(gyro));
 *     
 *     if (millis() - now > 2000) {
 *       ext_adi_gyro_shutdown(gyro);
 *       // Shut down the gyro after two seconds
 *       break;
 *     }
 * 
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_gyro_shutdown(ext_adi_gyro_t gyro);

/**
 * Reference type for an initialized potentiometer.
 *
 * This merely contains the port number for the potentiometer.
 */
typedef int32_t ext_adi_potentiometer_t;

/**
 * Initializes a potentiometer on the given port. 
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EADDRINUSE - The port is not configured as a potentiometer
 *
 * \param port
 *        The ADI port to initialize as a gyro (from 1-8, 'a'-'h', 'A'-'H')
 * \param potentiometer_type
 *        An adi_potentiometer_type_e_t enum value specifying the potentiometer version type
 *
 * \return An adi_potentiometer_t object containing the given port, or PROS_ERR if the
 * initialization failed.
 */
ext_adi_potentiometer_t ext_adi_potentiometer_init(uint8_t smart_port, uint8_t adi_port, adi_potentiometer_type_e_t potentiometer_type); 

/**
 * Gets the current potentiometer angle in tenths of a degree.
 *
 * The original potentiometer rotates 250 degrees thus returning an angle between 0-250 degrees.
 * Potentiometer V2 rotates 333 degrees thus returning an angle between 0-333 degrees.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EADDRINUSE - The port is not configured as a potentiometer
 *
 * \param potentiometer
 *        The adi_potentiometer_t object for which the angle will be returned
 *
 * \return The potentiometer angle in degrees.
 */
double ext_adi_potentiometer_get_angle(ext_adi_potentiometer_t potentiometer);

/**
 * Reference type for an initialized addressable led.
 *
 * This merely contains the port number for the led, unlike its use as an
 * object to store led data in the C++ API.
 */
typedef int32_t ext_adi_led_t;

/**
 * Initializes a led on the given port. 
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EINVAL - A given value is not correct, or the buffer is null
 * EADDRINUSE - The port is not configured for ADI output
 * 
 * \param smart_port
 *        The smart port with the adi expander (1-21)
 * \param adi_port
 *        The ADI port to initialize as a led (from 1-8, 'a'-'h', 'A'-'H')
 *
 * \return An ext_adi_led_t object containing the given port, or PROS_ERR if the
 * initialization failed.
 * 
 * \b Example:
 * \code
 * #define SMART_PORT 1
 * #define ADI_PORT 'A'
 * 
 * void opcontrol() {
 *   // Initialize a led on smart port 1 and adi port A
 *   ext_adi_led_t led = ext_adi_led_init(SMART_PORT, ADI_PORT);
 *   // Initialize a buffer with a single color of red
 *   uint32_t buffer[1] = {0xFF0000};
 * 
 *   while (true) {
 *    // Set the led to colors in the buffer
 *    ext_adi_led_set(led, buffer, 1);
 *    pros::delay(5);
 *   }
 * }
 * \endcode
 */
ext_adi_led_t ext_adi_led_init(uint8_t smart_port, uint8_t adi_port);

/**
 * @brief Clear the entire led strip of color
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EINVAL - A given value is not correct, or the buffer is null
 * EADDRINUSE - The port is not configured for ADI output
 *
 * @param led port of type adi_led_t
 * @param buffer array of colors in format 0xRRGGBB, recommended that individual RGB value not to exceed 0x80 due to current draw
 * @param buffer_length length of buffer to clear
 * @return PROS_SUCCESS if successful, PROS_ERR if not
 * 
 * \b Example:
 * \code
 * #define SMART_PORT 1
 * #define ADI_PORT 'A'
 *  
 * void opcontrol() {
 *   // Initialize a led on smart port 1 and adi port A
 *   ext_adi_led_t led = ext_adi_led_init(SMART_PORT, ADI_PORT);
 *   // Initialize a buffer with a single color of red
 *   uint32_t buffer[1] = {0xFF0000};
 * 
 *   while (true) {
 *     // Set the led to colors in the buffer
 *     ext_adi_led_set(led, buffer, 1);
 *     pros::delay(5);
 *   
 *     // Clear the led
 *     ext_adi_led_clear_all(led, buffer, 1);
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_led_clear_all(ext_adi_led_t led, uint32_t* buffer, uint32_t buffer_length);

/**
 * @brief Set the entire led strip using the colors contained in the buffer
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EINVAL - A given value is not correct, or the buffer is null
 * EADDRINUSE - The port is not configured for ADI output
 *
 * @param led port of type adi_led_t
 * @param buffer array of colors in format 0xRRGGBB, recommended that individual RGB value not to exceed 0x80 due to current draw
 * @param buffer_length length of buffer to clear
 * @return PROS_SUCCESS if successful, PROS_ERR if not
 * 
 * \b Example:
 * \code
 * #define SMART_PORT 1
 * #define ADI_PORT 'A'
 * 
 * void opcontrol() {
 *   // Initialize a led on smart port 1 and adi port A
 *   ext_adi_led_t led = ext_adi_led_init(SMART_PORT, ADI_PORT);
 *   // Initialize a buffer with a single color of red
 *   uint32_t buffer[1] = {0xFF0000};
 * 
 *   while (true) {
 *     // Set the led to colors in the buffer
 *     ext_adi_led_set(led, buffer, 1);
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_led_set(ext_adi_led_t led, uint32_t* buffer, uint32_t buffer_length);

/**
 * @brief Set the entire led strip to one color
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EINVAL - A given value is not correct, or the buffer is null
 * EADDRINUSE - The port is not configured for ADI output
 *
 * @param led port of type adi_led_t
 * @param buffer array of colors in format 0xRRGGBB, recommended that individual RGB value not to exceed 0x80 due to current draw
 * @param buffer_length length of buffer to clear
 * @param color color to set all the led strip value to
 * @return PROS_SUCCESS if successful, PROS_ERR if not
 *  
 * \b Example:
 * \code
 * #define SMART_PORT 1
 * #define ADI_PORT 'A'
 *  
 * void opcontrol() {
 *   // Initialize a led on smart port 1 and adi port A
 *   ext_adi_led_t led = ext_adi_led_init(SMART_PORT, ADI_PORT);
 *   // Initialize a buffer with a single color of red
 *   uint32_t buffer[1] = {0xFF0000};
 *   
 *   while (true) {
 *     // Set the entire led strip to red
 *     ext_adi_led_set_all(led, buffer, 1, 0xFF0000);
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_led_set_all(ext_adi_led_t led, uint32_t* buffer, uint32_t buffer_length, uint32_t color);

/**
 * @brief Set one pixel on the led strip
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EINVAL - A given value is not correct, or the buffer is null
 * EADDRINUSE - The port is not configured for ADI output
 *
 * @param led port of type adi_led_t
 * @param buffer array of colors in format 0xRRGGBB, recommended that individual RGB value not to exceed 0x80 due to current draw
 * @param buffer_length length of the input buffer
 * @param color color to clear all the led strip to
 * @param pixel_position position of the pixel to clear (0 indexed)
 * @return PROS_SUCCESS if successful, PROS_ERR if not
 * 
 * \b Example:
 * \code
 * #define SMART_PORT 1
 * #define ADI_PORT 'A'
 * 
 * void opcontrol() {
 *   // Initialize a led on smart port 1 and adi port A
 *   ext_adi_led_t led = ext_adi_led_init(SMART_PORT, ADI_PORT);
 *   // Initialize a buffer with multiple colors
 *   uint32_t buffer[3] = {0xFF0000, 0x00FF00, 0x0000FF};
 * 
 *   while (true) {
 *     // Set the first pixel to red
 *     ext_adi_led_set_pixel(led, buffer, 3, 0xFF0000, 0);
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_led_set_pixel(ext_adi_led_t led, uint32_t* buffer, uint32_t buffer_length, uint32_t color, uint32_t pixel_position);

/**
 * @brief Clear one pixel on the led strip
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of ADI Ports
 * EINVAL - A given value is not correct, or the buffer is null
 * EADDRINUSE - The port is not configured for ADI output
 *
 * @param led port of type adi_led_t
 * @param buffer array of colors in format 0xRRGGBB, recommended that individual RGB value not to exceed 0x80 due to current draw
 * @param buffer_length length of the input buffer
 * @param pixel_position position of the pixel to clear (0 indexed)
 * @return PROS_SUCCESS if successful, PROS_ERR if not
 * 
 * \b Example:
 * \code
 * #define SMART_PORT 1
 * #define ADI_PORT 'A'
 *  
 * void opcontrol() {
 *   // Initialize a led on smart port 1 and adi port A
 *   ext_adi_led_t led = ext_adi_led_init(SMART_PORT, ADI_PORT);
 *   // Initialize a buffer with multiple colors
 *   uint32_t buffer[3] = {0xFF0000, 0x00FF00, 0x0000FF};
 * 
 *   while (true) {
 *     // Set the first pixel to red
 *     ext_adi_led_set_pixel(led, buffer, 3, 0xFF0000, 0);
 *     pros::delay(5);
 * 
 *     // Clear the first pixel
 *     ext_adi_led_clear_pixel(led, buffer, 3, 0);
 *     pros::delay(5);
 *   }
 * }
 * \endcode
 */
int32_t ext_adi_led_clear_pixel(ext_adi_led_t led, uint32_t* buffer, uint32_t buffer_length, uint32_t pixel_position);

///@}

#ifdef __cplusplus
}  // namespace c
}  // namespace pros
}
#endif

#endif  // _PROS_ADI_H_
