#include "pointMade.h"
int displayOptions()
{
	int option = 0;
	printf("Enter an option:\n");
	printf("1. Speaker\n2. Audient\n");
	scanf("%d", &option);
	return option;
}

void getKeywords(Keyword allKeywords[])
{
	

	for (int i = 0; i < 10; ++i)
	{
		printf("Please enter a keyword that categorizes your overall message.\n You will enter 10 in total.\n");
		scanf("%s", allKeywords[i].key);
		printf("Keyword # %d :", i, allKeywords[i].key);
		
	}
	

}
int myArrLength(char speechArr[])
{
	int length = 0;

	while (speechArr[length] != '\0')
	{
		++length;
	}
	return length;
}

int search_sentence(char sentence[], char *keywords[], int str_length) //search line for key words
{
	int count = 0; //how many key words match
	char word[20] = "";
	int track = 0; //for tracking length til end of sentence

	strcpy(word, strtok(sentence, " ,"));
	track = strlen_custom(word);
	str_length -= track;
	count += determine_point(word, keywords);

	while (str_length > 0)
	{
		strcpy(word, strtok(NULL, " ,"));
		track = strlen_custom(word);
		str_length -= track;
		count += determine_point(word, keywords);
	}
	if (count >= 2)
	{
		return 1;
	}
	return 0;
}

int determine_point(char word[], char *keywords[], int *keyCount[]) //parameter change
{
	for (int i = 0; i < 10; ++i) // 10 to custom
	{
		if (strcmp(word, keywords[i]) == 0)
		{
			++keyCount[i];
			return 1;
		}
	}
	return 0;
}

int strlen_custom(char str[])
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if ((str[i] != ' ') && (str[i] != ',') && (str[i] != '.'))
		{
			count += 1;
		}
	}
	return count;
}

int messageMade(int keyWordInstances)
{

	if (keyWordInstances == 0)
	{
		return 1;
	}
	else if (keyWordInstances > 7)
	{
		return 2;
	}
	else if ((keyWordInstances > 0) && (keyWordInstances <= 4))
	{
		return 3;
	}
	else if ((keyWordInstances > 4) && (keyWordInstances <= 7))
	{
		return 4;
	}
}

void feedback(int qualityLevel)
{

	if (qualityLevel == 1)
	{
		printf("None of your keywords were used. Revise your speech immediately.\n");
	}
	else if (qualityLevel == 2)
	{
		printf("Keywords are used redundantly and excessively. Revise your speech immediately.\n");
	}
	else if (qualityLevel == 3)
	{
		printf("Keywords are rarely used.\n There is room for improvement!\n");

	}
	else if (qualityLevel == 4)
	{
		printf("Keywords are used greatly!\nSpot on!\n");
	}
}

void organizeFile(FILE *inFile, FILE *outFile)
{
	char line[1200] = " ";
	char sent[1200] = " ";
	int length = 0, track = 0;

	while (!feof(inFile))
	{
		strcpy(line, fgets(line, 1200, inFile));
		length = strlen_custom(line) - 1;

		strcpy(sent, strtok(line, "."));
		track = strlen_custom(sent);
		length -= track;
		fprintf(outFile, "%s.\n", sent);

		while (length > 0)
		{
			strcpy(sent, strtok(NULL, "."));
			track = strlen_custom(sent);
			length -= track;
			fprintf(outFile, "%s.\n", sent);
		}
	}
}