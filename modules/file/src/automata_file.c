#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <automata/automata_platform.h>
#include "../include/automata/automata_file.h"

#if defined(AUTOMATA_COMPILER_MSVC) && _MSC_VER < 1400
#include <stringapiset.h>
extern __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int cp, unsigned long flags, const char *str, int cbmb, wchar_t *widestr, int cchwide);
#endif

/* Variant of fopen() with support for unicode
 * Taken from nothings's stb repository, stb_image.h
 * The original code is licensed under Public Domain (www.unlicense.org)
 * https://github.com/nothings/stb/blob/master/stb_image.h
 */
static FILE *automataFileOpen(const char *filePath, const char *mode) {
	FILE *file = 0;

	/* standard compilers */
	#if !defined(AUTOMATA_COMPILER_MSVC)
	file = fopen(filePath, mode);

	/* MSVC++ 8.0 and newer */
	#elif defined(AUTOMATA_COMPILER_MSVC) && _MSC_VER >= 1400
	fopen_s(&file, filePath, mode);

	/* MSVC++ 7.1 and lower */
	#elif defined(AUTOMATA_COMPILER_MSVC) && _MSC_VER < 1400
	wchar_t wMode[64] = { 0 };
	wchar_t wFilePath[1024] = { 0 };

	MultiByteToWideChar(65001 /* UTF8 */, 0, filePath, -1, wFilePath, sizeof(wFilePath));
	MultiByteToWideChar(65001 /* UTF8 */, 0, mode, -1, wMode, sizeof(wMode));

	file = _wfopen(wFilePath, wMode);	
	#endif
	
	return file;
}

void automataFileLoadImage(AutomataImageFile *image, const char *filePath) {
	FILE *f = NULL;
	
	if (!image) {
		return;
	}

	/* load the image */
	image->pixels = stbi_load(filePath, &image->width, &image->height, &image->channels, 0);

	/* close the file */
	automataFileClose(f);
}

void automataFileLoadText(AutomataTextFile *text, const char *filePath) {
	FILE *f = NULL;
	
	if (!text) {
		return;
	}

	/* open the file */
	f = automataFileOpen(filePath, "rb");

	if (!f) {
		return;
	}

	/* get file size */
	fseek(f, 0L, SEEK_END);
	text->size = ftell(f);
	fseek(f, 0L, SEEK_SET);

	if (!text->size) {
		fclose(f);
		return;
	}

	/* allocate memory for the file */
	text->text = malloc(text->size);

	if (!text->text) {
		fclose(f);
		return;
	}

	/* load the file */
	fread(f, 1, text->size, f);

	/* close the file */
	fclose(f);
}

void automataFileUnloadImage(AutomataImageFile *file) {
	if (!file) {
		return;
	}

	/* unload the image */
	stbi_image_free(file->pixels);
}

void automataFileUnloadText(AutomataTextFile *file) {
	if (!file) {
		return;
	}

	/* unload the text */
	free(file->text);
}