#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include <stb/stb_image.h>
#include "automata_image.h"

AutomataImage *automataImageLoad(const char *filePath) {
	AutomataImage *image = malloc(sizeof(AutomataImage *));
	
	if (!image) {
		return NULL;
	}

	image->pixels = stbi_load(filePath, &image->width, &image->height, &image->channels, 0);

	if (!image->pixels) {
		return NULL;
	}
}

void automataImageUnload(AutomataImage *image) {
	if (!image) {
		return;
	}

	/* unload the image */
	stbi_image_free(image->pixels);
	free(image);
}