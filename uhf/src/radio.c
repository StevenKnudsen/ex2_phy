/*!
 * @file radio.c
 * @author Steven Knudsen
 * @date January 22, 2023
 *
 * @details UHF radio utility methods, specific to the Endurosat UHF Type II
 *
 * @copyright AlbertaSat 2023
 *
 * @license
 * This software may not be modified or distributed in any form, except as described in the LICENSE file.
 */
#include "radio.h"
 

uint16_t getBitRate(rfmode_t rfmode) {
  uint32_t bitRate = 0;
  switch (rfmode) {
    case RF_MODE_0:
      bitRate = 1200;
    break;
    case RF_MODE_1:
      bitRate = 2400;
    break;
    case RF_MODE_2:
      bitRate = 4800;
    break;
    case RF_MODE_3:
    case RF_MODE_4:
      bitRate = 9600;
    break;
    case RF_MODE_5:
    case RF_MODE_6:
    case RF_MODE_7:
      bitRate = 19200;
    break;
    default :
    break;
  }
  return bitRate;
}

uint16_t getFrequencyDeviation(rfmode_t rfmode) {
  uint32_t fdev = 0;
  switch (rfmode) {
    case RF_MODE_0:
    case RF_MODE_1:
      fdev = 600;
    break;
    case RF_MODE_2:
      fdev = 1200;
    break;
    case RF_MODE_3:
      fdev = 2400;
    break;
    case RF_MODE_4:
    case RF_MODE_5:
      fdev = 4800;
    break;
    case RF_MODE_6:
      fdev = 9600;
    break;
    case RF_MODE_7:
      fdev = 19200;
    break;
    default :
    break;
  }
  return fdev;
}

double getModulationIndex(rfmode_t rfmode) {
  double modInd = 0.0;
  switch (rfmode) {
    case RF_MODE_0:
      modInd = 1.0;
    break;
    case RF_MODE_1:
    case RF_MODE_2:
    case RF_MODE_3:
      modInd = 0.5;
    break;
    case RF_MODE_4:
      modInd = 1.0;
    break;
    case RF_MODE_5:
      modInd = 0.5;
    break;
    case RF_MODE_6:
      modInd = 1.0;
    break;
    case RF_MODE_7:
      modInd = 2.0;
    break;
    default :
    break;
  }
  return modInd;
}