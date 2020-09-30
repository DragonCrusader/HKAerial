/*
Jacob Schatzer
9/27/2020
A grid based search program
*/


#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));  //makes the Random Number Generator.

	int enemyLocation = rand() % 64 + 1; //random number between 1 and 64.
	int gridMax = 64;
	int gridMin = 1;
	int predictions = 0;
	int guessLocation = rand() % 64 + 1; //random number between 1 and 64.

	bool enemyFound = false;
	cout << "\n\t\t\t\t\t Welcome to Skynet, Captain.\n\n";
	cout << "Today, you will be witnessing our newest A.I UAV. The 'HK-Aerial'.\n\n";
	cout << "HK-Aerial Software Initalizing...\n\n";
	cout << "Captain, our Intelligence software stragetically places an enemy randomly within an 8x8 Grid.\nAllowing 1 of 64 random locations to be selected within the grid\n";
	cout << "HK-Aerial, automatically hunts down and tracks the enemy in the correct grid sector within a matter of seconds.\n\n";


	//Create the search loop (do) function.
	do
	{
		cout << "'HK-Aerial' Sending out Ping # " << predictions << "\n";


		if (guessLocation > enemyLocation)
		{
			cout << "\nThe target is not in Grid # " << guessLocation << " number too high.\n";
			gridMax = guessLocation;
			guessLocation = ((gridMax - gridMin) / 2) + gridMin;
			predictions++;
		}
		else if (guessLocation < enemyLocation)
		{
			cout << "\nThe target is not in Grid # " << guessLocation << " number too low.\n";
			gridMin = guessLocation;
			guessLocation = ((gridMax - gridMin) / 2) + gridMin;
			predictions++;
		}
		if (guessLocation == enemyLocation)
		{
			cout << "\nThe target was located in Grid #" << enemyLocation << "\n";
			cout << "\nTarget Spotted.  'HK-Aerial required " << predictions << " search attempts.\n";
			enemyFound = true;
		}

	} while (enemyLocation != guessLocation);

	system("pause");
	return(0);
}