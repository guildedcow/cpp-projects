#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>


using namespace std;

string selectWord();
string createFoundLettersString(string word);
void printHangman(int attempts, string word);
void printWords(string foundWord);
char enterLetter();
void updateWord(char letter, string word, string& foundWord, int &attempts);
bool gameCheck(string word, string foundWord, int attempts);


int main()
{
	int attempts = 0;
	bool gameEnded = false;
	
	string word = selectWord();
	string foundWord = createFoundLettersString(word);

	while (!gameEnded)
	{
		printHangman(attempts, word);
		printWords(foundWord);
		char letter = enterLetter();
		updateWord(letter, word, foundWord, attempts);
		gameEnded = gameCheck(word, foundWord, attempts);
	}
	system("PAUSE");
}


string selectWord()
{
	string word;
	cout << "Enter a word: ";
	getline(cin, word);
	//cin >> word;
	transform(word.begin(), word.end(), word.begin(), ::tolower); // for some reason doesnt accept more than one word ???
	return word;
}


string createFoundLettersString(string word)
{
	string foundWord = word;
	for (int i = 0; i < word.length(); i++)
	{
		int asciiChar = (int)word[i];
		if (asciiChar != 32)
		{
			foundWord[i] = '_';
		}
	}
	return foundWord;
}

void printHangman(int attempts, string word)
{
	system("CLS");
	if (attempts == 0)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\n\n\n\n");
	}
	else if (attempts == 1)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\n\n\n");
	}
	else if (attempts == 2)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\t   |   \n");
		printf("\n\n");
	}
	else if (attempts == 3)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\t  /|   \n");
		printf("\n\n");
	}
	else if (attempts == 4)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\t  /|\\   \n");
		printf("\n\n");
	}
	else if (attempts == 5)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\t  /|\\   \n");
		printf("\t   |    \n");
		printf("\n");
	}
	else if (attempts == 6)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\t  /|\\   \n");
		printf("\t   |    \n");
		printf("\t  /   \n");
		printf("\n");
	}
	else if (attempts == 7)
	{
		printf("\t   _____\n");
		printf("\t   |    \n");
		printf("\t   O    \n");
		printf("\t  /|\\   \n");
		printf("\t   |    \n");
		printf("\t  / \\  \n");
		printf("\n");
	}
}


void printWords(string foundWord)
{
	cout << "The word: " << foundWord << "\n";
}


char enterLetter()
{
	char letter;
	cout << "Enter letter: ";
	cin >> letter;
	return letter;
}


void updateWord(char letter, string word, string &foundWord, int &attempts)
{
	bool ifwordwasfound = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == letter)
		{
			foundWord[i] = word[i];
			ifwordwasfound = true;
		}
	}
	if (!ifwordwasfound)
	{
		attempts++;
	}
}


bool gameCheck(string word, string foundWord, int attempts)
{
	if (word.compare(foundWord) == 0)
	{
		printHangman(attempts, word);
		printWords(foundWord);
		cout << "\nThe game has ended, the speller has won.\n";
		return true;
	}
	else if (attempts == 7)
	{
		printHangman(attempts, word);
		printWords(foundWord);
		cout << "\nThe game has ended, the speller has lost.\n";
		return true;
	}
	else
	{
		return false;
	}
}