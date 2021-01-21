#include <iostream>
#include <ctime>
#include <random>


static std::default_random_engine randomGenerator(time(NULL));
std::uniform_int_distribution<int> cardNum(1, 13); // set cardnums
std::uniform_int_distribution<int> cardType(1, 4); // set cardtypes
std::uniform_int_distribution<int> dealerAce(1, 2); // for dealer if they have ace

class Blackjack
{
private:
	int plrcard1Num = 0;
	int plrcard2Num = 0;
	int dealercard1Num = 0;
	int dealercard2Num = 0;
	bool firstcardrevealed = false;

public:
	// cardNum setter/getters
	void setCardNums(int randomNum1, int randomNum2, int randomNum3, int randomNum4)
	{
		plrcard1Num = randomNum1;
		plrcard2Num = randomNum2;

		dealercard1Num = randomNum3;
		dealercard2Num = randomNum4;
	}

	// get plr cards
	int getPlrCard1Num()
	{
		return plrcard1Num;
	}

	int getPlrCard2Num()
	{
		return plrcard2Num;
	}

	//get dealer cards
	int getDealerCard1Num()
	{
		return dealercard1Num;
	}

	int getDealerCard2Num()
	{
		return dealercard2Num;
	}


	// ask plr if they want to reroll their hidden card
	void reRollCard1()
	{
		char rerollChoice;
		printf("Would you like to change your first card? y/n : ");
		std::cin >> rerollChoice;

		if (rerollChoice == 'y')
		{
			setCardNums(cardNum(randomGenerator), plrcard2Num, dealercard1Num, dealercard2Num);
			printf("You have changed your first card. \n");
			return;
		}
		else
		{
			return;
		}
	}


	// print game board fancy!!! <is for player only>
	void printCards(int card1Num, int card2Num, bool plr)
	{
		static int round = 1;
		if (round == 3)
			system("CLS");

		if (plr)
			printf("\t\tPlayer Cards:\n");
		else
			printf("\t\tDealer Cards:\n");
		
		if (round < 3)
		{


			printf("\n\t ___________\t ___________\n");
			printf("\t|           |\t|           |\n");
			if (card2Num >= 10)
				printf("\t|           |\t| %d        |\n", card2Num);
			else
				printf("\t|           |\t| %d         |\n", card2Num);
			printf("\t|           |\t|           |\n");
			printf("\t|           |\t|           |\n");
			printf("\t|     ?     |\t|           |\n");
			printf("\t|           |\t|           |\n");
			printf("\t|           |\t|           |\n");
			if (card2Num >= 10)
				printf("\t|           |\t|        %d |\n", card2Num);
			else
				printf("\t|           |\t|         %d |\n", card2Num);
			printf("\t|___________|\t|___________|\n\n");
			
		}
		else
		{

			printf("\n\t ___________\t ___________\n");
			printf("\t|           |\t|           |\n");
			if (card1Num >= 10)
				printf("\t| %d        |", card1Num);
			else
				printf("\t| %d         |", card1Num);

			if (card2Num >= 10)
				printf("\t| %d        |\n", card2Num);
			else
				printf("\t| %d         |\n", card2Num);

			printf("\t|           |\t|           |\n");
			printf("\t|           |\t|           |\n");
			printf("\t|           |\t|           |\n");
			printf("\t|           |\t|           |\n");
			printf("\t|           |\t|           |\n");

			if (card1Num >= 10)
				printf("\t|        %d |", card1Num);
			else
				printf("\t|         %d |", card1Num);

			if (card2Num >= 10)
				printf("\t|        %d |\n", card2Num);
			else
				printf("\t|         %d |\n", card2Num);

			printf("\t|___________|\t|___________|\n\n");
		}
		round++;
	}


	// handles all conditionals for blackjack
	void gameLogic(int plrcard1Num, int plrcard2Num, int dealercard1Num, int dealercard2Num)
	{
		if (plrcard1Num == 1)
		{
			printf("1 or 11 for your a? ");
			std::cin >> plrcard1Num;
		} 
		if (plrcard2Num == 1)
		{
			printf("1 or 11 for your a? ");
			std::cin >> plrcard2Num;
		}
	
		int dealerChoice = dealerAce(randomGenerator);
		if (dealercard1Num == 1)
		{
			if (dealerChoice == 1)
			{
				plrcard1Num = 11;
			}
			else
			{
				plrcard1Num = 1;
			}
		}
		if (dealercard2Num == 1)
		{
			if (dealerChoice == 1)
			{
				plrcard1Num = 11;
			}
			else
			{
				plrcard1Num = 1;
			}
		}		
		
		bool plrBust = false;
		bool dealerBust = false;

		if (plrcard1Num + plrcard2Num > 21 && dealercard1Num + dealercard2Num > 21)
		{
			plrBust = true;
			dealerBust = true;
			printf("Both busted, its a tie.\n");
		}
		if (plrcard1Num + plrcard2Num > 21)
		{
			plrBust = true;
			printf("You lose, you bust!\n");
		}
		if (dealercard1Num + dealercard2Num > 21)
		{
			dealerBust = true;
			printf("You win! Dealer bust!\n");
		}

		if (!plrBust && !dealerBust)
		{
			int plrSum = plrcard1Num + plrcard2Num;
			int dealerSum = dealercard1Num + dealercard2Num;

			if (plrSum == dealerSum)
				printf("Its a tie.\n");
			else if (plrSum > dealerSum)
				printf("You win! You had higher numbers");
			else
				printf("You lose! Dealer had higher numbers");
		}
	}
};

int main()
{
	// call class
	Blackjack game;
	// random gen of the player and dealer cards
	game.setCardNums(cardNum(randomGenerator), cardNum(randomGenerator), cardNum(randomGenerator), cardNum(randomGenerator));

	// fancy card + asks if plr wants to reroll
	game.printCards(game.getPlrCard1Num(), game.getPlrCard2Num(), true); //plr
	game.printCards(game.getDealerCard1Num(), game.getDealerCard2Num(), false); //dealer print
	game.reRollCard1(); // ask plr if they want to reroll, dealer gets taken care of in gameLogic();
	game.printCards(game.getPlrCard1Num(), game.getPlrCard2Num(), true); // plr print x2
	game.printCards(game.getDealerCard1Num(), game.getDealerCard2Num(), false); // dealer print x2

	// handles all conditionals
	game.gameLogic(game.getPlrCard1Num(), game.getPlrCard2Num(), game.getDealerCard1Num(), game.getDealerCard2Num());
}
