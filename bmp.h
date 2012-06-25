#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */

typedef unsigned char		BYTE;
typedef unsigned int		DWORD;
typedef int			LONG;
typedef unsigned int		UINT;
typedef unsigned short int	WORD;

typedef struct tagBITMAPFILEHEADER {
  WORD    bfType;
  DWORD   bfSize;
  WORD    bfReserved1;
  WORD    bfReserved2;
  DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
  DWORD  biSize;
  LONG   biWidth;
  LONG   biHeight;
  WORD   biPlanes;
  WORD   biBitCount;
  DWORD  biCompression;
  DWORD  biSizeImage;
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
  BYTE    rgbBlue;
  BYTE    rgbGreen;
  BYTE    rgbRed;
  BYTE    rgbReserved;
} RGBQUAD;

#pragma pack(pop)   /* restore original alignment from stack */

inline void initHeaders(LONG width, LONG height)
{
	BITMAPFILEHEADER *bmpHeader = malloc(sizeof(BITMAPFILEHEADER));
	BITMAPINFOHEADER *infoHeader = malloc(sizeof(BITMAPINFOHEADER));

	memset(bmpHeader, 0, sizeof(BITMAPFILEHEADER));
	bmpHeader->bfType = 0x4d42;
	bmpHeader->bfSize = 70;
	bmpHeader->bfReserved1 = 0;
	bmpHeader->bfReserved2 = 0;
	bmpHeader->bfOffBits = 54;

	memset(infoHeader, 0, sizeof(BITMAPINFOHEADER));
	infoHeader->biSize = sizeof(BITMAPINFOHEADER);
	infoHeader->biWidth = width;
	infoHeader->biHeight = height;
	infoHeader->biPlanes = 1;
	infoHeader->biBitCount = 24;
	infoHeader->biCompression = 0;
	infoHeader->biSizeImage = 0;
	infoHeader->biXPelsPerMeter = 2835;
	infoHeader->biYPelsPerMeter = 2835;
	infoHeader->biClrUsed = 0;
	infoHeader->biClrImportant = 0;

	fwrite(bmpHeader, sizeof(BITMAPFILEHEADER), 1, stdout);
	free(bmpHeader);
	fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, stdout);
	free(infoHeader);
}

#endif // BMP_H
