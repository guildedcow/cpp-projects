#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>
#include <ctime>

// using namespace std;

char board[3][3] =
{
	{'1', '4', '7'},
	{'2', '5', '8'},
	{'3', '6', '9'},
};

void printBoard(char board[3][3]);
int parseInput(bool plr);
int randomGen();
void updateBoard(int userChoice, char plrThing);
bool gameLogicCheck(char board[3][3]);
bool fullBoard();


int main()
{
	bool gameEnded = false;
	
	printBoard(board); // because reasons
	while (!gameEnded)
	{
		int userChoice = parseInput(true);
		updateBoard(userChoice, 'X');
		userChoice = parseInput(false);
		updateBoard(userChoice, 'O');
		gameEnded = gameLogicCheck(board);
		printBoard(board);
	}

	do {
		std::cout << '\n' << "Press the Enter key to close the program.";
	} while (std::cin.get() != '\n');

	return 0;
}


void printBoard(char board[3][3])
{
	system("CLS");
	printf(" %c | %c | %c \n", board[0][0], board[1][0], board[2][0]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[0][1], board[1][1], board[2][1]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[0][2], board[1][2], board[2][2]);
}


int parseInput(bool plr)
{
	int userChoice;
	if (plr)
	{
		std::cout << "\nEnter a spot: ";
		std::cin >> userChoice;
	}
	else
	{
		userChoice = randomGen();
	}

	bool endLoop = false;
	while (!endLoop)
	{
		// checks to make sure spot isnt filled
		if (userChoice == 1 && board[0][0] == '1')
		{
			endLoop = true;
		}
		else if (userChoice == 2 && board[1][0] == '2')
		{
			endLoop = true;
		}
		else if (userChoice == 3 && board[2][0] == '3')
		{
			endLoop = true;
		}
		else if (userChoice == 4 && board[0][1] == '4')
		{
			endLoop = true;
		}
		else if (userChoice == 5 && board[1][1] == '5')
		{
			endLoop = true;
		}
		else if (userChoice == 6 && board[2][1] == '6')
		{
			endLoop = true;
		}
		else if (userChoice == 7 && board[0][2] == '7')
		{
			endLoop = true;
		}
		else if (userChoice == 8 && board[1][2] == '8')
		{
			endLoop = true;
		}
		else if (userChoice == 9 && board[2][2] == '9')
		{
			endLoop = true;
		}
		// if it isnt valid, try again
		else
		{
			if (plr)
			{
				std::cout << "Try again: ";
				std::cin >> userChoice;
			}
			else
			{
				endLoop = fullBoard();
				userChoice = randomGen();
			}

		}
	}
	return userChoice;
}


int randomGen()
{
	static std::default_random_engine randomGenerator(time(NULL)); //seed the random num gen
	std::uniform_int_distribution<int> arr1(1, 9); // range
	return arr1(randomGenerator);
}


void updateBoard(int userChoice, char symbol)
{
	switch (userChoice)
	{
	case 1:
		board[0][0] = symbol;
		break;
	case 2:
		board[1][0] = symbol;
		break;
	case 3:
		board[2][0] = symbol;
		break;
	case 4:
		board[0][1] = symbol;
		break;
	case 5:
		board[1][1] = symbol;
		break;
	case 6:
		board[2][1] = symbol;
		break;
	case 7:
		board[0][2] = symbol;
		break;
	case 8:
		board[1][2] = symbol;
		break;
	case 9:
		board[2][2] = symbol;
		break;
	}
}


bool gameLogicCheck(char board[3][3])
{
	// horizontal wins
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
	{
		return true;
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
	{
		return true;
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
	{
		return true;
	}
	// vertical wins
	else if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
	{
		return true;
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
	{
		return true;
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		return true;
	}
	// diagonal wins
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return true;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return true;
	}
	
	else
	{
		return fullBoard();
	}
}


bool fullBoard()
{
	int spotsTaken = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'O')
			{
				spotsTaken++;
			}
		}
	}
	if (spotsTaken == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}