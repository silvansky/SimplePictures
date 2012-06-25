#include "bmp.h"

#include <math.h>

#define IMG_WIDTH	640
#define IMG_HEIGHT	480
#define DATA_SIZE	(IMG_HEIGHT * IMG_WIDTH * 3)

main()
{
	initHeaders(IMG_WIDTH, IMG_HEIGHT);

	int i, x;
	for (i = 0; i < DATA_SIZE; i++)
	{
		x = (int)(i >> 1 | i ^ 3);
		fputc(x, stdout);
	}
}
