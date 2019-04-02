#ifndef AUTOMATA_FILE_H
#define AUTOMATA_FILE_H

/* data structures */
typedef struct AutomataTextFile {
	char *text;
	long size;
} AutomataTextFile;

typedef struct AutomataImageFile {
	int width;
	int height;
	int channels;
	unsigned char *pixels;
} AutomataImageFile;

/* functions */
void automataFileLoadImage(AutomataImageFile *file, const char *filePath);
void automataFileLoadText(AutomataTextFile *file, const char *filePath);
void automataFileUnloadImage(AutomataImageFile *file);
void automataFileUnloadText(AutomataTextFile *file);

#endif