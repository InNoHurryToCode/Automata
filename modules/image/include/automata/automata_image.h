#ifndef AUTOMATA_IMAGE_H
#define AUTOMATA_IMAGE_H

/* data structures */
typedef struct AutomataImage {
	unsigned char *pixels;
	int width;
	int height;
	int channels;
} AutomataImage;

/* functions */
void automataImageLoad(AutomataImage *image, const char *filePath);
void automataImageUnload(AutomataImage *image);

#endif