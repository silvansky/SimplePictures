#include "bmp.h"

#include <math.h>

#define IMG_WIDTH	640
#define IMG_HEIGHT	480
#define DATA_SIZE	(IMG_HEIGHT * IMG_WIDTH * 3)
#define IMG_SIZE	(IMG_HEIGHT * IMG_WIDTH)

main()
{
	initHeaders(IMG_WIDTH, IMG_HEIGHT);

	int i, x;
	RGBQUAD quad;
	memset(&quad, 0, sizeof(RGBQUAD));
#if 0
	for (i = 0; i < IMG_SIZE; i++)
	{
		quad.rgbRed = (int)(1000 * sin(i / 0.04));
		quad.rgbGreen = (int)(255 * cos(i / 0.013));
		quad.rgbBlue = (int)(20 * tanh(i / 0.04));
		fwrite(&quad, sizeof(RGBQUAD), 1, stdout);
	}
#else
	for (i = 0; i < DATA_SIZE; i++)
	{
		x = (int)(255 * sin(i / 0.04) + log(i * 1000));
		fputc(x, stdout);
	}
#endif
}
