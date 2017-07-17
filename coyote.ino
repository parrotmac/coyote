/***
* Arduino Serial to Seeedstudio CAN Bus Shield interface
*
* Hardware needed:
* Arduino UNO: https://www.sparkfun.com/products/11021 (Or similar, 5V tolerant likely needed)
* Seeedstudio CAN Bus Shield: https://www.amazon.com/dp/B00T3XPH6C/
* 
* Based on examples from https://github.com/Seeed-Studio/CAN_BUS_Shield
***/


#include <SPI.h>
#include "mcp_can.h"

const int SPI_CS_PIN = 9;

MCP_CAN CAN(SPI_CS_PIN);

void setup()
{
    Serial.begin(115200);

    volitile int retryCount = 1;
    while (CAN_OK != CAN.begin(CAN_500KBPS)) // 500Kbps is works well for 2nd and 3rd Gen Priuses
    {
        Serial.print("Initialization failed! Retry ");
        Serial.println(retryCount++);
        delay(100);
    }
    Serial.println("CAN BUS Shield Initialized");
}


void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned int canId = CAN.getCanId();
        
        Serial.print(canId, HEX);

        Serial.print(":");

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i], HEX);
            Serial.print("");
        }
        Serial.println();
    }
}

