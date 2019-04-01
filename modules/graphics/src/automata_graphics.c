#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include "../include/automata/automata_graphics.h"

/* code here */

void autmataGraphicsLoadShader(const char *filePath) {
	FILE* file = fopen(filePath, "r");
	int fileSize = 0;
	char *fileContent = NULL;

	/* get file size */
	fseek(file, 0L, SEEK_END);
	fileSize = ftell(file);

	if (fileSize == 0) {
		return;
	}

	/* load the file */
	fseek(file, 0L, SEEK_SET);
	fileContent = (char *)malloc(fileSize);

	if (!fileContent) {
		return;
	}

	/* code here */

	/* deallocate file */
	free(fileContent);
}