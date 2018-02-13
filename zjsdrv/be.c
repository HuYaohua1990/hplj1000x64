#include "zjs_private.h"


typedef unsigned __int16 UINT16;
typedef unsigned __int32 UINT32;



// �����ʹ�С�˻���
#define BigLittleSwap16(A)  ((((UINT16)(A) & 0xff00) >> 8) | (((UINT16)(A) & 0x00ff) << 8))
// �����ʹ�С�˻���

#define BigLittleSwap32(A)  ((((UINT32)(A) & 0xff000000) >> 24) |	(((UINT32)(A) & 0x00ff0000) >> 8) |	(((UINT32)(A) & 0x0000ff00) << 8) |	(((UINT32)(A) & 0x000000ff) << 24))

	// ������˷���1��С�˷���0
	int checkCPUendian()
{
	union{
		unsigned long int i;
		unsigned char s[4];
	}c;

	c.i = 0x12345678;
	return (0x12 == c.s[0]);
}

// ģ��htonl�����������ֽ���ת�����ֽ���
unsigned long int t_htonl(unsigned long int h)
{
	// ������Ϊ��ˣ��������ֽ���ͬ��ֱ�ӷ���
	// ������ΪС�ˣ�ת���ɴ���ٷ���
	return checkCPUendian() ? h : BigLittleSwap32(h);
}

// ģ��ntohl�����������ֽ���ת�����ֽ���
unsigned long int t_ntohl(unsigned long int n)
{
	// ������Ϊ��ˣ��������ֽ���ͬ��ֱ�ӷ���
	// ������ΪС�ˣ���������ת����С���ٷ���
	return checkCPUendian() ? n : BigLittleSwap32(n);
}

// ģ��htons�����������ֽ���ת�����ֽ���
unsigned short int t_htons(unsigned short int h)
{
	// ������Ϊ��ˣ��������ֽ���ͬ��ֱ�ӷ���
	// ������ΪС�ˣ�ת���ɴ���ٷ���
	return checkCPUendian() ? h : BigLittleSwap16(h);
}

// ģ��ntohs�����������ֽ���ת�����ֽ���
unsigned short int t_ntohs(unsigned short int n)
{
	// ������Ϊ��ˣ��������ֽ���ͬ��ֱ�ӷ���
	// ������ΪС�ˣ���������ת����С���ٷ���
	return checkCPUendian() ? n : BigLittleSwap16(n);
}


uint32_t 	be32(uint32_t dword)
{
	return t_htonl(dword);
}
uint16_t 	be16(uint16_t word)
{
	return t_htons(word);
}