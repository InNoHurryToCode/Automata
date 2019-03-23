#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>
#include "../include/automata/automata_image.h"

void automataImageLoad(AutomataImage *image, const char *filePath) {
	if (!image) {
		return;
	}

	/* load the image */
	image->pixels = stbi_load(filePath, &image->width, &image->height, &image->channels, 0);
}

void automataImageUnload(AutomataImage *image) {
	if (!image) {
		return;
	}

	/* unload the image */
	stbi_image_free(image->pixels);
}