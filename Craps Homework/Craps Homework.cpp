// Craps Homework.cpp : Defines the entry point for the console application.
//Craps
//Written 4 February 2013
//Written by Alex Kohler
#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
int die1; //Value of die 1
int die2; //value of die 2
int dicesum; //sum of die 1 and die 2
int gamecounter=0; //Counter to differentiate between "first game" rolls and subsequent rolls
int point; //Value player must roll to win after first roll
char repeat= 'y' ; //Confirmation value input from player to continue playing
	
cout << "Welcome to Craps!" << endl;
cout << "The game is about to begin" << endl; 



while (repeat == 'y' || repeat == 'Y') //loops until player decides to stop playing via any input other than Y or y
{
die1= 1 + rand() % 6; //generate the values of dice one and dice 2
die2= 1 + rand() %6;

dicesum= die1 + die2; //sum the values of the two dice

cout << "You rolled a " << die1 << " and a " << die2 << " for a total of " << dicesum << endl;

	if (dicesum==7 || dicesum==11) //first roll win
		{	
		cout << "You win!! Would you like to play again? (Y/N)" << endl;
		cin >> repeat;
		}
	else if  (dicesum==2 || dicesum==3 || dicesum==12) //first roll lose
		{
		cout << "Sorry, you lose. Would you like to play again? (Y/N)" << endl;
		cin >> repeat;
		}

	if (dicesum==1 || dicesum==4 ||dicesum==5||dicesum==6||dicesum==8||dicesum==9||dicesum==10)	//action to be taken if a winning/losing first roll is not rolled
		{
		point=dicesum; 
		cout << "Your point is " << dicesum << ". Continue? (Y/N)" << endl;
		gamecounter=gamecounter++; //increments game counter, moves game into subsequent phase where player can only win via rolling his or her point
		
			while (gamecounter > 0 && (repeat== 'y'||repeat=='Y')) //loop only initated after gamecounter increments--meaning the player did not win or lose on first roll
			{	

				die1= 1 + rand() % 6; //generate the values of dice one and dice 2
				die2= 1 + rand() %6;
				dicesum= die1 + die2; //sum the values of the two dice
				cout << "You rolled a " << die1 << " and a " << die2 << " for a total of " << dicesum << endl;


				if (dicesum==point)	//winning roll 
				{
				cout << "You win! Would you like to play again? (Y/N)" << endl;
				cin >> repeat;
				gamecounter=gamecounter--; //after winning, game counter increments back to 0 and goes back to inital phase of game 
				}
				
				else if (dicesum == 7) //losing roll
				{
				cout << "Sorry, you lose. Would you like to play again? (Y/N)" << endl;
				cin >> repeat;
				gamecounter=gamecounter--; //after losing, game counter increments back to 0 and goes back to inital phase of game
				}
			}





		}


	
}



	return 0;
}

