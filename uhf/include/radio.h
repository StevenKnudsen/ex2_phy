/*!
 * @file radio.h
 * @author Steven Knudsen
 * @date January 22, 2023
 *
 * @details Define constants related to the UHF radio, specifically the Endurosat UHF Type II
 *
 * @copyright AlbertaSat 2023
 *
 * @license
 * This software may not be modified or distributed in any form, except as described in the LICENSE file.
 */


#ifndef EX2_PHY_UHF_RADIO_H_
#define EX2_PHY_UHF_RADIO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Radio Packet format
// +----------+-----------+--------------+--------------+-------+
// | Preamble | sync word | data field 1 | data field 2 | crc16 |
// +----------+-----------+--------------+--------------+-------+
#define UHF_PREAMBLE_FIELD_LENGTH 5     // bytes
#define UHF_SYNC_WORD_LENGTH 1          // byte
#define UHF_DATA_FIELD_1_LENGTH 1       // byte
#define UHF_DATA_FIELD_2_MAX_LENGTH 128 // bytes
#define UHF_CRC16_LENGTH 2              // bytes

// Transparent Mode Field lengths
// (Data field 2 is set always to the maximum length)
#define UHF_TRANSPARENT_MODE_DATA_FIELD_1_LENGTH 1   // byte
#define UHF_TRANSPARENT_MODE_DATA_FIELD_2_LENGTH 128 // bytes

/****************************************************************/
/* RF Mode                                                      */
/****************************************************************/

typedef enum {
  RF_MODE_0 = 0x00,    // 2GFSK, 1200 bps,  Fdev 600Hz,   ModInd 1
  RF_MODE_1 = 0x01,    // 2GFSK, 2400 bps,  Fdev 600Hz,   ModInd 0.5
  RF_MODE_2 = 0x02,    // 2GFSK, 4800 bps,  Fdev 1200Hz,  ModInd 0.5
  RF_MODE_3 = 0x03,    // 2GFSK, 9600 bps,  Fdev 2400Hz,  ModInd 0.5
  RF_MODE_4 = 0x04,    // 2GFSK, 9600 bps,  Fdev 4800Hz,  ModInd 1
  RF_MODE_5 = 0x05,    // 2GFSK, 19200 bps, Fdev 4800Hz,  ModInd 0.5
  RF_MODE_6 = 0x06,    // 2GFSK, 19200 bps, Fdev 9600Hz,  ModInd 1
  RF_MODE_7 = 0x07,    // 2GFSK, 19200 bps, Fdev 19200Hz, ModInd 2
  RF_MODE_END = 0xFF
} rfmode_t;

/*!
* @brief Return the bit rate.
* 
* @details For this radio bit rate and baud are the same since the
* modulation is always 2GFSK
* 
* @param[in] rfmode The RF Mode
* @return The bit rate for valid RF Modes, otherwise 0
*/
uint16_t getBitRate(rfmode_t rfmode);

/*!
* @brief Return the frequency deviation
* 
* @param[in] rfmode The RF Mode
* @return The frequency deviation for valid RF Modes, otherwise 0
*/
uint16_t getFrequencyDeviation(rfmode_t rfmode);

/*!
* @brief Return the modulation index
* 
* @param[in] rfmode The RF Mode
* @return The modulation index for valid RF Modes, otherwise 0.0
*/
double getModulationIndex(rfmode_t rfmode);

#ifdef __cplusplus
}
#endif

#endif /* EX2_PHY_UHF_RADIO_H_ */
