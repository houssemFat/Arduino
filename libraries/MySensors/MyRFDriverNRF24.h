#ifndef MyRFDriverNRF24_h
#define MyRFDriverNRF24_h

#include "MyConfig.h"
#include "MyRFDriver.h"
#include <stdint.h>
#include "utility/RF24.h"
#include "utility/RF24_config.h"

#define TO_ADDR(x) (RF24_BASE_RADIO_ID + x)

#define WRITE_PIPE ((uint8_t)0)
#define CURRENT_NODE_PIPE ((uint8_t)1)
#define BROADCAST_PIPE ((uint8_t)2)

class MyRFDriverNRF24 : public MyRFDriver
{ 
public:
	MyRFDriverNRF24(uint8_t ce=RF24_CE_PIN, uint8_t cs=RF24_CS_PIN, uint8_t paLevel=RF24_PA_LEVEL);
	void init();
	void setAddress(uint8_t address);
	uint8_t getAddress();
	bool send(uint8_t to, const void* data, uint8_t len);
	bool available(uint8_t *to);
	uint8_t receive(void* data);
	void powerDown();
private:
	RF24 rf24;
	uint8_t _address;
	uint8_t _paLevel;
};

#endif
