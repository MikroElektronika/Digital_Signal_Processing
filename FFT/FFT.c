/*
 * Project name:
     FFT (Fft library test example)
 * Copyright:
     (c) MikroElektronika, 2011.
 * Revision History:
     20110524:
       - Initial release
 * Description:
     This is a simple demonstration on Fft library functions.
     The examples should be self-explanatory, for more information
     please take a look at mikroC's Help.
 * Test configuration:
     MCU:             P32MX795F512L
                      http://ww1.microchip.com/downloads/en/DeviceDoc/61156G.pdf
     Dev.Board:       EasyPIC Fusion v7
                      http://www.mikroe.com/easypic-fusion/
     Oscillator:      XT-PLL, 80.000MHz
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC32
                      http://www.mikroe.com/mikroc/pic32/
 * NOTES:
     - None.
*/

// 8 pairs of [Re, Im] values
int inputSamples[16] = { 0x4000, 0, 0x4000, 0, 0x4000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Twiddle factors for 8 pairs complex input values.
const int Wn[8]      = {0x7fff, 0, 0x5A82, 0xA57E, 0, 0x8000, 0xA57E, 0xA57E};
unsigned int log2N   = 3;


void main() {
  // We will calculate FFT for input array:
  //   Re                Im
  //   0.5 (0x4000)      0
  //   0.5 (0x4000)      0
  //   0.5 (0x4000)      0
  //   0                 0
  //   0                 0
  //   0                 0
  //   0                 0
  //   0                 0
  FFT(inputSamples, Wn, log2N);
  BitReverseComplex(inputSamples, log2N);
  // As a result we obtain (elements are scaled with 1/8):
  //   Re                                 Im
  //   0x1800   (0.1875)                  0
  //   0x0DA8   (0.106689453125)          0xF2 57   (-0.106719970703125)
  //   0                                  0xF8 00   (-0.0625)
  //   0x0257   (0.018280029296875)       0x02 58   (0.018310546875)
  //   0x0800   (0.0625)                  0
  //   0x0258   (0.018310546875)          0xFDA9    (-0.018280029296875)
  //   0                                  0x0800    (0.0625)
  //   0x0DA9   (0.106719970703125)       0x0D A8   (0.106689453125)
}