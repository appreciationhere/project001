#include<stdio.h>
typedef  unsigned short int uint16_t;
typedef  unsigned char uint8_t;
typedef  unsigned short int u16;
typedef  unsigned char u8;

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
u16 data[2][8][6] = {0};
int main(int argc, char *argv[])
{
	u8 mastersend[256];
	int n;
	scanf("%d",&n);
    uint8_t buf[10] = {0x01 ,0x03 ,0x02,0x00, 0x17, 0xf8, 0x4a};
    //printf("crc:%02x\n",crc);
    for (int i = 0; i < 8; ++i)
	    for (int j = 0; j < 6; ++j)
	    	data[0][i][j] = 66 + j * (i + 1);
    for (int i = 0; i < 8; ++i)
	    for (int j = 0; j < 6; ++j)
	    	data[1][i][j] = j * (i + 1);  
	for (int i = 0; i < n; ++i)
		scanf("%x", mastersend + i);
	printf("%04x\n", crc16tablefast(mastersend, n));
//	uint16_t crc1 = crc16tablefast(mastersend,6);
//	mastersend[6] = crc1;
//	mastersend[7] = crc1>>8;
//	if (crc16tablefast(mastersend, 6) == ((u16)mastersend[7]<<8 |mastersend[6])) {
//			u8 sendbuf[256];
//			int i = 0;
//			u16 p;
//			u16 addr = (u16)mastersend[2]<<8 | mastersend[3];
//			u16 len = ((u16)mastersend[4]<<8 | mastersend[5])<<1;
//			sendbuf[0] = mastersend[0];
//			sendbuf[1] = mastersend[1];
//			sendbuf[2] = len;
//			for (i = 0; i < len; i+=2) {
//					sendbuf[i + 3] = *(data[0][0] + addr + i/2)>>8;
//					sendbuf[i + 4] = *(data[0][0] + addr + i/2);
//			}
//			p = crc16tablefast(sendbuf, len + 3);
//			sendbuf[i + 3] = p;
//			sendbuf[i + 4] = p>>8;
//			for (i = 0; i <= len + 4; ++i)
//				printf("%02x ", sendbuf[i]);
//		}
    return 0;
}









