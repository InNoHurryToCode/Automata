#ifndef AUTOMATA_WINDOW_H
#define AUTOMATA_WINDOW_H

/* data structures */
typedef struct AutomataImage {
	unsigned char *pixels;
	int width;
	int height;
	int channels;
} AutomataImage;

/* functions */
AutomataImage *automataImageLoad(const char *filePath);
void automataImageUnload(AutomataImage *image);

#endif