// SkynetHK-Aerial.cpp : Defines the entry point for the console application.

#include "stdafx.h"
//lets me use rand()
#include <cstdlib>
#include "iostream"
//lets me check the time
#include <ctime>

using namespace std;
int highNumber = 64;
int lowNumber = 1;
int guess = 0;
int numGuess = 1;
int LnumGuess = 1;
int RnumGuess = 1;
int RandomGuess = 0;
int HumanGuess = 1;
int HnumGuess = 1;
char again;

int main()
{
	 
	do
	{
		//have to reset the numbers for the play again
		highNumber = 64;
		lowNumber = 1; 
		numGuess = 1;
		LnumGuess = 1;
		RnumGuess = 1;
		HnumGuess = 1;

		// seeds the random number based of the time
		srand(static_cast<unsigned int>(time(0)));
		// picks a random number 1-64
		int EnemyLocation = (rand() % 64) + 1;
		//cout << "\nThe Enemy location is " << EnemyLocation; //cheats :)

		//code for the binary search=====================================================================

		//make the guess the bianary search function
		int guess = (highNumber - ((highNumber - lowNumber) / 2) + lowNumber);
		//cout << "\nSkynet drone guesses grid square: " << guess;


		while (guess != EnemyLocation)
		{


			//sets the new high or low number based on if it was high or low
			if (guess > EnemyLocation)
			{
				highNumber = guess;
				guess = (((highNumber - lowNumber) / 2) + lowNumber);
				//cout << "\nSkynet drone guesses grid square: " << guess;
				//incriment so it counts how many guesses it takes
				++numGuess;

			}
			if (guess < EnemyLocation)
			{
				lowNumber = guess;
				guess = (((highNumber - lowNumber) / 2) + lowNumber);
				//cout << "\nSkynet drone guesses grid square: " << guess;
				//incriment so it counts how many guesses it takes
				++numGuess;
			}

			//the while loop didnt end when the guess hit the number so i added this
			if (guess == EnemyLocation)
			{
				break;
			}


		}

		// code for the linear search ==================================================================
		//set the loop to go through 64 times
		for (int i = 0;i < 64;i + 1)
		{
			// num of guess and the grid square its checking is the same so can just use the same variable
			if (LnumGuess = EnemyLocation)
			{
				// once it hits the enemy location it quits so we know how many tries it took
				break;
			}
			// incriments and keeps track of number of guesses
			++LnumGuess;
		}


		// code for the Random search ===================================================================

		while (RandomGuess != EnemyLocation)
		{


			RandomGuess = (rand() % 64) + 1;

			if (RandomGuess == EnemyLocation)
			{
				break;
			}
			// incriments and keeps track of number of guesses
			++RnumGuess;
		}   


		//code for the human player =====================================================================
		while (HumanGuess != EnemyLocation)
		{
			cout << "\nEnter a guess (1-64) for the enemy position: ";
			cin >> HumanGuess;
			if (HumanGuess == EnemyLocation)
			{
				cout << "\nYou found the base";
				break;
			}
			// tells you if you are too high or low
			else if (HumanGuess > EnemyLocation)
			{
				cout << "\nYour guess was too high ";
			}
			else if (HumanGuess < EnemyLocation)
			{
				cout << "\nYour guess was too low";
			}
			// incriments and keeps track of number of guesses
			++HnumGuess;
		}

		cout << "\nThe Enemy location was at " << EnemyLocation;
		cout << "\nThe Human Player took " << HnumGuess << " guesses to find to location of the enemy\n";
		cout << "\nThe AI using Linear Search took " << LnumGuess << " guesses to find to location of the enemy\n";
		cout << "\nThe AI using Ramdom Search took " << RnumGuess << " guesses to find to location of the enemy\n";
		cout << "\nThe AI using Bianary Search took " << numGuess << " guesses to find to location of the enemy\n";

		cout << "\n run again? (y/n): ";
		cin >> again;
		//lets you run the program again if the used put y
	} while (again == 'y');


	return 0;
}