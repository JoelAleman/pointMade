#include "pointMade.h"

int main(void)
{
	FILE *inFile = NULL;
	FILE *outFile = NULL;
	FILE *resultFile = NULL;
	inFile = fopen("speech.txt", "r");
	outFile = fopen("output.txt", "w");
	resultFile = fopen("feedback.txt", "w");

	Keyword keywords[AMOUNT_OF_KEYS] = { {" "} };
	int keyCount[AMOUNT_OF_KEYS] = { 0 };
	//char keywords[10] = { "equal", "race" ,"freedom" ,"dream" ,"black" ,"white" ,"rights" ,"treatment" ,"family" ,"people" }; //assuming already have keywords
	char line[1200] = "";		//max line length
	char temp_line[1200] = "";	//to store initial line for multiple sentences
	char sentence[1200] = "";	//max sentence length in case line is 1 sentence
	int check = 0;				//for determination of key word find
	int length = 0;				//length of string without space or comma
	int line_length = 0;		//for line check for multiple sentence
	int sent_counter = 0;       //for having correct sentence when looping
	int option = 0;				//boolean type variable
	int keysUsed = 0;			//boolean type 1 is yes the keywords were used at least twice and 0 the booleans were not used at all
	int qualityLevel = 0;

	organizeFile(inFile, outFile);
	option = displayOptions(); //prompts the user to see which code to implement first

	if (option == 1)
	{
		printf("Welcome Speaker!"); //welcoming code to the speaker portion of the website
		system("pause");
		system("cls");

		getKeywords(keywords);

		//count of variables
		keysUsed = search_sentence(sentence, keywords, strlen(sentence));

		//
		while (!feof(inFile))	    //runs until all lines are read
		{
			strcpy(line, fgets(line, 1200, inFile)); //get the one line
													 //strcpy(temp_line, line);
													 //line_length = strlen_custom(line);

													 //seperate sentence, check, loop
			strcpy(sentence, strtok(line, "."));
			length = strlen_custom(sentence); //gets length of sentence without spaces and commas - reason is for loop later
											  //line_length -= length;//decrease length til end of line
			check = search_sentence(line, keywords, length);
			if (check == 1)
			{
				printf("%s\n", sentence);
			}
			else
			{
				printf("No keyword found\n");
			}

		}
		fclose(inFile);
		fclose(outFile);

		qualityLevel = messageMade(keysUsed);
		feedback(qualityLevel);




	}
	else
	{
		while (!feof(inFile))	    //runs until all lines are read
		{
			strcpy(line, fgets(line, 1200, inFile)); //get the one line
													 //strcpy(temp_line, line);
													 //line_length = strlen_custom(line);

													 //seperate sentence, check, loop
			strcpy(sentence, strtok(line, "."));
			length = strlen_custom(sentence); //gets length of sentence without spaces and commas - reason is for loop later
											  //line_length -= length;//decrease length til end of line
			check = search_sentence(line, keywords, length);
			if (check == 1)
			{
				printf("%s.\n", sentence);
			}

		}
		fclose(inFile);
		fclose(outFile);
	}
	
	return 0;
}

//comments:

/*sent_counter += 1;*/

/*int length = 0, lengthOfLine = 0, sentences = 0;

while (sentence[lengthOfLine] != '/0')
{
if (lengthOfLine == ".")
{
++sentences;
}
}

for (int i = 0; i < sentences; ++i)
{
while (sentence[length] != ".")
{
++length;
}

for (int i = 0; i < length; ++i)
{
strcpy(sentence, strtok(NULL, "."));
}
}
*/

/*strcpy(sentence, strtok(line, "."));*/ //sentence is words until first period (for first sentence in line)

										 //if (sent_counter == 1)
										 //{
										 //	strcpy(sentence, strtok(line, ".")); //sentence is words until first period (for first sentence in line)
										 //}
										 /*else
										 {
										 strcpy(sentence, strtok(line + (length + 1), "\0"));
										 }
										 */
