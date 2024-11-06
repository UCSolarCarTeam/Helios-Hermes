// #ifndef Wiegand34_h
// #define Wiegand34_h

// #include <stdint.h>
// #include <pigpio.h>

// // Settings
// #define MAX_BITS      34
// #define KEY_BITS      8
// #define TIMEOUT       20
// #define TIMEOUTKEY    5000

// // Wiegand34 Class
// class Wiegand34 {

// public:
//     Wiegand34() { }
//     Wiegand34(uint8_t pinData0, uint8_t pinData1, bool status=true, bool swapData=false) {
//         begin(pinData0, pinData1);
//     }

//     void begin(uint8_t pinData0, uint8_t pinData1, bool status=true, bool swapData=false);
//     void readData(void);

//     void onData(void (*func)(unsigned long data)) {
//         function_data = (callback_data)func;
//     }

//     typedef void (*callback_data)(unsigned long data);

// private:
//     unsigned long _timestamp;
//     uint8_t _pinData0, _pinData1;
//     uint8_t _bitCnt;
//     bool _bitData[MAX_BITS];
//     unsigned long _data;
//     bool _swapData;

//     void reset(void);
//     void emitData(void);

//     static void data0ISR(int gpio, int level, uint32_t tick, void *userdata);

//     static void data1ISR(int gpio, int level, uint32_t tick, void *userdata);

//     Wiegand34::callback_data function_data;

// };

// #endif
