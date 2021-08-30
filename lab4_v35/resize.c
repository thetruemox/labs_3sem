#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void resize(unsigned char* img, unsigned char* out, const int w_new, const int h_new, const int w_old, const int h_old, const int ch)
{
	float x_ratio = (float)w_old / (float)w_new;
	float y_ratio = (float)h_old / (float)h_new;

	if (ch == 4)
	{
		unsigned int* i_img = (unsigned int*)img;

		unsigned int* i_out = (unsigned int*)out;
		for (int x = 0; x < w_new; ++x)
		{
			for (int y = 0; y < h_new; ++y)
			{
				i_out[x + y * w_new] = i_img[(int)floor(x * x_ratio) + (int)floor(y * y_ratio) * w_old];
			}
		}
	}
	else
	{
		for (int x = 0; x < w_new; ++x)
		{
			for (int y = 0; y < h_new; ++y)
			{
				for (int c = 0; c < ch; ++c)
				{
					out[(x + y * w_new) * ch + c] = img[((int)floor(x * x_ratio) + (int)floor(y * y_ratio) * w_old) * ch + c];
				}
			}
		}
	}
}

const int TST_CNT = 100;

int main(int argc, const char* argv[]) //input, output, w_new, h_new
{
	if (argc != 5)
	{
		printf("not enough args!\n");
		return 1;
	}

	int width_old, height_old, chnls;
	int width_new = atoi(argv[3]), height_new = atoi(argv[4]);

	unsigned char* img = stbi_load(argv[1], &width_old, &height_old, &chnls, 0);

	if (!img)
	{
		printf("cant read file!\n");
		return 1;
	}

	unsigned char* out = (unsigned char*)malloc(width_new * height_new * chnls);
	clock_t start, time = 0;
	for (int i = 0; i < TST_CNT; ++i)
	{
		start = clock();
		resize(img, out, width_new, height_new, width_old, height_old, chnls);
		//as_resize(img, out, width_new, height_new, width_old, height_old, chnls);
		time += (clock() - start);
	}

	printf("Number of tests: %i \nAverage work time: %f ms \n", TST_CNT, 1000.0 * (time) / TST_CNT / CLOCKS_PER_SEC);

	stbi_write_png(argv[2], width_new, height_new, chnls, out, width_new * chnls);

	free(out);
	stbi_image_free(img);
	return 0;
}
