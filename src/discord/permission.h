// File name: guild.h
// Author: FiniteReality
// Description: Permissions

#ifndef _permission_h_
#define _permission_h_

struct permission_info
{
	unsigned char byteOne; // 8
	unsigned char byteTwo; // 16
	unsigned char byteThree; // 24
	unsigned char byteFour; // 32
	unsigned char byteFive; // 40
	unsigned char byteSix; // 48
	unsigned char byteSeven; // 56
};

// TODO: what API should we expose for this? 

#endif // _permission_h_