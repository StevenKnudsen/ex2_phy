/*!
 * @file qa_radio.c
 * @author Steven Knudsen
 * @date January 22, 2023
 *
 * @details Unit test for radio.*.
 *
 * @copyright AlbertaSat 2023
 *
 * @license
 * This software may not be modified or distributed in any form, except as described in the LICENSE file.
 */

#include "radio.h"

#include <gtest/gtest.h>

#define QA_RADIO_DEBUG 0         // set to 1 for debugging output
#define QA_RADIO_VERBOSE_DEBUG 0 // set to 1 for verbose debugging output

/*!
 * @brief Test Accessors
 */
TEST(uhf_radio, Accessors)
{
  /* ---------------------------------------------------------------------
   * Check accessors
   * ---------------------------------------------------------------------
   */

  // Check mapping to bit rate
  ASSERT_TRUE(getBitRate(RF_MODE_0) == 1200) << "RF_MODE_0 does not map to 1200 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_1) == 2400) << "RF_MODE_1 does not map to 2400 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_2) == 4800) << "RF_MODE_2 does not map to 4800 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_3) == 9600) << "RF_MODE_3 does not map to 9600 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_4) == 9600) << "RF_MODE_4 does not map to 9600 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_5) == 19200) << "RF_MODE_5 does not map to 19200 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_6) == 19200) << "RF_MODE_6 does not map to 19200 bps";
  ASSERT_TRUE(getBitRate(RF_MODE_7) == 19200) << "RF_MODE_7 does not map to 19200 bps";

  ASSERT_FALSE(getBitRate(RF_MODE_END) != 0) << "Bad RF_MODE_x should map to 0 bps";

  // Check mapping to frequency deviation
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_0) == 600) << "RF_MODE_0 does not map to freq deviation 600 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_1) == 600) << "RF_MODE_1 does not map to freq deviation 600 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_2) == 1200) << "RF_MODE_2 does not map to freq deviation 1200 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_3) == 2400) << "RF_MODE_3 does not map to freq deviation 2400 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_4) == 4800) << "RF_MODE_4 does not map to freq deviation 4800 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_5) == 4800) << "RF_MODE_5 does not map to freq deviation 4800 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_6) == 9600) << "RF_MODE_6 does not map to freq deviation 9600 Hz";
  ASSERT_TRUE(getFrequencyDeviation(RF_MODE_7) == 19200) << "RF_MODE_7 does not map to freq deviation 19200 Hz";

  ASSERT_FALSE(getFrequencyDeviation(RF_MODE_END) != 0) << "Bad RF_MODE_x should map to freq deviation 0 Hz";

  // Check mapping to modulation index
  ASSERT_TRUE(getModulationIndex(RF_MODE_0) == 1.0) << "RF_MODE_0 does not map to modulation index 1.0";
  ASSERT_TRUE(getModulationIndex(RF_MODE_1) == 0.5) << "RF_MODE_1 does not map to modulation index 0.5";
  ASSERT_TRUE(getModulationIndex(RF_MODE_2) == 0.5) << "RF_MODE_2 does not map to modulation index 0.5";
  ASSERT_TRUE(getModulationIndex(RF_MODE_3) == 0.5) << "RF_MODE_3 does not map to modulation index 0.5";
  ASSERT_TRUE(getModulationIndex(RF_MODE_4) == 1.0) << "RF_MODE_4 does not map to modulation index 1.0";
  ASSERT_TRUE(getModulationIndex(RF_MODE_5) == 0.5) << "RF_MODE_5 does not map to modulation index 0.5";
  ASSERT_TRUE(getModulationIndex(RF_MODE_6) == 1.0) << "RF_MODE_6 does not map to modulation index 1.0";
  ASSERT_TRUE(getModulationIndex(RF_MODE_7) == 2.0) << "RF_MODE_7 does not map to modulation index 2.0";

  ASSERT_FALSE(getModulationIndex(RF_MODE_END) != 0.0) << "Bad RF_MODE_x should map to modulation index 0.0";

} // Accessors
