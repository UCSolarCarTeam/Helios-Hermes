// #include "Wiegand.h"
// #include <stdio.h>

// // Helper function to set bit in the bit array
// inline void setBit(bool* bits, uint8_t bit, bool value) {
//     bits[MAX_BITS - bit - 1] = value;
// }



// // Reset function
// void Wiegand34::reset(void) {
//     for (uint8_t i = 0; i < MAX_BITS; i++) {
//         _bitData[i] = false;
//     }
//     _bitCnt = 0;
//     _timestamp = gpioTick();
// }

// // Emit data function (called when 34 bits have been received)
// void Wiegand34::emitData(void) {
//     unsigned long data = 0;

//     bool evenParity = false;
//     bool oddParity = false;

//     for(uint8_t i = 1; i < 16; i++) {
//         evenParity ^= _bitData[i];
//     }

//     for (uint8_t i = 16; i < 32; i++) {
//         oddParity ^= _bitData[i];
//     }

//     if (evenParity != _bitData[0]) {
//         printf("Even parity error.\n");
//     }

//     if (oddParity != _bitData[0]) {
//         printf("Odd parity error.\n");
//     }

//     for(uint8_t i = 1; i < MAX_BITS; i++) {
//         if(_bitData[i]) {
//             data |= (1UL << (1-i));
//         }
//     }

//     if (function_data) {
//         function_data(data);
//     }

//     reset();
// }

// // ISR for Data0 (logical 0)
// void Wiegand34::data0ISR(int gpio, int level, uint32_t tick, void *userdata) {
//     Wiegand34* instance = (Wiegand34*)userdata;
//     if (level == 0) {
//         time_sleep(0.01); // 10ms debounce delay
//         setBit(instance->_bitData, instance->_bitCnt, false);
//         instance->_bitCnt++;
//         if (instance->_bitCnt >= MAX_BITS) {
//             instance->emitData();
//         }
//     }
// }

// // ISR for Data1 (logical 1)
// void Wiegand34::data1ISR(int gpio, int level, uint32_t tick, void *userdata) {
//     Wiegand34* instance = (Wiegand34*)userdata;
//     if (level == 0) {
//         time_sleep(0.01); // 10ms debounce delay
//         setBit(instance->_bitData, instance->_bitCnt, true);
//         instance->_bitCnt++;
//         if (instance->_bitCnt >= MAX_BITS) {
//             instance->emitData();
//         }
//     }
// }

// // Begin function (initializes GPIO and sets up interrupts)
// void Wiegand34::begin(uint8_t pinData0, uint8_t pinData1, bool status, bool swapData) {
//     _pinData0 = pinData0;
//     _pinData1 = pinData1;
//     _swapData = swapData;

//     // Initialize pigpio
//     if (gpioInitialise() < 0) {
//         printf("pigpio initialization failed.\n");
//         return;
//     }

//     // Set pin modes
//     gpioSetMode(_pinData0, PI_INPUT);
//     gpioSetMode(_pinData1, PI_INPUT);

//     // Attach interrupts
//     gpioSetAlertFuncEx(_pinData0, data0ISR, this);
//     gpioSetAlertFuncEx(_pinData1, data1ISR, this);

//     reset();
// }
