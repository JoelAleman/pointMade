#define AMOUNT_OF_KEYS 10
#define LENGTH_OF_KEYS 20
#include <stdio.h>
#include <string.h>

typedef struct keyword
{
	char key[20];
} Keyword;

void getKeywords(Keyword allKeywords[]);
int myArrLength(char speechArr[]);
int messageMade(int keyWordInstances);
int displayOptions();

int search_sentence(char line[], char *key_words[], int str_length); //search line for key words

int determine_point(char word[], char *key_words[], int *keyCount);

int strlen_custom(char str[]);

void feedback(int qualityLevel);

void organizeFile(FILE *inFile, FILE *outFile);
