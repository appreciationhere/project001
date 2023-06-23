#include<stdio.h>
typedef  unsigned short int uint16_t;
typedef  unsigned char uint8_t;

const uint16_t crctalbeabs[] = {
      0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 0x3C00, 0x2800, 0xE401,
      0xA001, 0x6C00, 0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 0x4400
};

uint16_t crc16tablefast(uint8_t *ptr, uint16_t len) {
     uint16_t crc = 0xffff;
     uint16_t i;
     uint8_t ch;
     uint8_t ret1;

     for (i = 0; i < len; i++) {
         ch = *ptr++;
         crc = crctalbeabs[(ch ^ crc) & 15] ^ (crc >> 4);
         crc = crctalbeabs[((ch >> 4) ^ crc) & 15] ^ (crc >> 4);
     }
     return crc;
 }

int main(int argc, char *argv[])
{
    uint8_t buf[10] = {0x01 ,0x03 ,0x02,0x00, 0x17, 0xf8, 0x4a};
    uint16_t crc=crc16tablefast(buf,5);
    printf("crc:%02x\n",crc);
    printf("crc:%04x\n",((uint16_t)buf[6]<<8 | buf[5]));
    uint8_t a = 0xff;
    uint16_t b = 0xff00;
    uint8_t c = b>>8;
    return 0;
}