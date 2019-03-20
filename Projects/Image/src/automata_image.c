#define STB_IMAGE_IMPLEMENTATION

#include <stdlib.h>
#include <stb/stb_image.h>
#include "../include/automata/automata_image.h"

AutomataImage *automataImageLoad(const char *filePath) {
	AutomataImage *image = malloc(sizeof(AutomataImage *));
	
	if (!image) {
		return NULL;
	}

	image->pixels = stbi_load(filePath, &image->width, &image->height, &image->channels, 0);

	if (!image->pixels) {
		return NULL;
	}

	return image;
}

void automataImageUnload(AutomataImage *image) {
	if (!image) {
		return;
	}

	/* unload the image */
	stbi_image_free(image->pixels);
	free(image);
}