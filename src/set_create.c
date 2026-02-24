#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fptr;
	char fileDir[] = "./src/sample.text";

	// set[] -> line[] -> word[] -> char
	char *word;
	char **line;
	char ***set;

	// adding words to lines and lines to sets
	fptr = fopen(fileDir, "r");	

	// heading = [{}] pauses playback
	// all punctuation is removed
	// . , ; ? ! are slight pauses
	// new lines/paragraphs are a pause

}
