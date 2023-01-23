/*!
 * @file radio.h
 * @author Steven Knudsen
 * @date January 22, 2023
 *
 * @details Define constants related to the S-Band radio
 *
 * @copyright AlbertaSat 2023
 *
 * @license
 * This software may not be modified or distributed in any form, except as described in the LICENSE file.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EX2_PHY_SBAND_RADIO_H_
#define EX2_PHY_SBAND_RADIO_H_

// Transmitter modes
#define SBAND_CONF_MODE 0
#define SBAND_SYNC_MODE 1
#define SBAND_DATA_MODE 2
#define SBAND_TEST_MODE 3

// Power Amplifier status
#define SBAND_PA_DISABLE 0
#define SBAND_PA_ENABLE 1

// Data rates
#define SBAND_RATE_FULL 0
#define SBAND_RATE_HALF 1
#define SBAND_RATE_QUARTER 2

// Modulation type
#define SBAND_MOD_QPSK 0
#define SBAND_MOD_OQPSK 1

// Filter status
#define SBAND_FILTER_ENABLE 0
#define SBAND_FILTER_DISABLE 1

// Scrambler status
#define SBAND_SCRAMBLER_ENABLE 0
#define SBAND_SCRAMBLER_DISABLE 1

// Bit Order
#define SBAND_BIT_ORDER_MSB 0
#define SBAND_BIT_ORDER_LSB 1

// Power Amplifier powers
#define SBAND_PAPWR_24DBM 24
#define SBAND_PAPWR_26DBM 26
#define SBAND_PAPWR_28DBM 28
#define SBAND_PAPWR_30DBM 30

// Frequency maximums/minimums
#define SBAND_FREQ_COMMERCIAL_MAX 2300.0f
#define SBAND_FREQ_COMMERCIAL_MIN 2200.0f
#define SBAND_FREQ_AMATEUR_MAX 2450.0f
#define SBAND_FREQ_AMATEUR_MIN 2400.0f

#ifdef __cplusplus
}
#endif

#endif /* EX2_PHY_SBAND_RADIO_H_ */
