#include <stdio.h>

int main()
{
	const char *output_path = "output.ppm";
	FILE *f = fopen(output_path, "wb");
	
	unsigned char width = 255;
	unsigned char height = 255;
	
	fprintf(f, "P6\n");
	fprintf(f, "%d %d\n", width, height);
	fprintf(f, "255\n");
	
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			
			// Current Pixel at x, y
			
			unsigned char r = width - x;
			unsigned char g = height - y;
			unsigned char b = x;
			unsigned char pixel[3] = {r, g, b};
			
			//printf("x: %i, y: %i\npixel_rgb: 0x%x\n", x, y, pixel_rgb);
			
			fputc(pixel[0], f); // R
			fputc(pixel[1], f); // G
			fputc(pixel[2], f); // B
		}
	}
	
	fclose(f);
	printf("Generated %s\n", output_path);
	return 0;
}