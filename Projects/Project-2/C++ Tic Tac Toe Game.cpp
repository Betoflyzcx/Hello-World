/*
* File:   main.cpp
* Author: Alberto Garcia
* Created on July 14, 2016, 1:00 PM
* Purpose : Display A List Of Numbers TIC TAC TOE
*/

//System Libraries
#include "stdafx.h"
#include <iostream> //Input/Output Library
#include <string>
#include <vector>
#include <ctime>
using namespace std; //Namespace of the System Libraries
 //User Libraries



//Global Constants

 //Function Prototypes
void CheckTurn(int turn);
void DrawMap(char p_char, char Input, vector<char> &Map, int &MapSize);
void Gme_Stat(char L_input, char type);
void ResetMap(vector<char> &Map, int &MapSize);
bool CheckWin(char player, vector<string> &map);
string GetWinner(vector<string> &map);
bool Ai(char Opchar, vector<string> &map, char &Input);

//Execution Begins Here!
int main(int argc, char** argv) {
	char Board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	bool Used[9];
	char type;
	string Oppnnt;
	char Diffclty;
	char L_input;
	short turn = 1;
	bool Chk = false;
	int MapSize = 9;//Map y cordinate
	vector<char> Map(MapSize);//Map for drawing tic tac toe
	vector<string> map(9);// a temperarely stored map used for conversion of char to string
	ResetMap(Map, MapSize);

	cout << "Enter whether you wish to play against an AI or another PLAYER";
	cout << "Enter:\t 1 For Player \t Enter:\t For AI ";
	cin >> Oppnnt;
	while (Chk == false)
	{
		if (Oppnnt != "2")
		{
			if (Oppnnt != "1")
			{
				cout << "Try Again Enter:\t 1 For Player \t Enter:\t 2 For AI "; // Keeps looping until Valid is entered!
				cin >> Oppnnt;
			}
		}
		if (Oppnnt == "1" || Oppnnt == "2")
		{
			Chk = true;
		}
	}
	if (Oppnnt == "2")
	{
		bool Chk_D = false;
		cout << "Enter the Difficulty you wish to face: \t Enter 1 for easy \t Enter 2 for Intermediate \n \t";
		cout << "Enter 3 for impossible (Warning Impossible cannot be beaten)";
		cin >> Diffclty;
		while (Chk_D == false)
		{
			if (Diffclty != '3')
			{
				if (Diffclty != '2')
				{
					if (Diffclty != '1') // Keeps looping until Valid is entered!
						cin >> Oppnnt;
					cout << "Try Again Enter:\t 1 For easy \t Enter:\t 2 For intermediate \t Enter:\t 3 for impossible ";
				}
			}
			if (Diffclty == '1' || Diffclty == '2' || Diffclty == '3')
			{
				Chk_D = true;
			}
		}
	}
	while (true)
	{
		switch (turn)
		{
		case 1: // Player 1's Turn
			type = 'O';
			cout << "It's Player 1's Turn \n\n\n";
			cout << "Choose a location: \t 1 2 3 \n \t 4 5 6 \n \t 7 8 9 \n \t";
			cin >> L_input;
			while (isdigit(L_input) == false)
			{
				cout << "Enter a valid number 1-9";
				cin >> L_input;
			}


			while (Used[L_input] == true) // Checks if someone has already used the point
			{
				cout << "It appears someone has already chosen that spot..\t choose another spot\t";
				cout << "1 2 3 \n \t 4 5 6 \n \t 7 8 9 \n \t:";
				cin >> L_input;
			}
			if (Used[L_input] == false) // If the point isn't used.... marks it used
			{
				Used[L_input] = true;
			}
			DrawMap(type, L_input, Map, MapSize);

			map.clear();//empty map
			map.resize(9);//resize map to 0
			for (int i = 0; i < 9; i++)//loop the map length
			{
				map[i].push_back(Map[i]);//set the string map equal to the char map 
			}
			if (GetWinner(map) != "None")//There is a winner
			{
				cout << endl << GetWinner(map) << " Wins!" << endl;//Write the winner to screen
			}

		case 2: //  Player 2
			if (Oppnnt == "1") // checks if the user is facing another player or an AI
			{
				type = 'X';
				cout << "It's Player 2's Turn \n\n\n";
				cout << "Choose a location: \t 1 2 3 \n \t 4 5 6 \n \t 7 8 9 \n \t";
				cin >> L_input;
				while (isdigit(L_input) == false)
				{
					cout << "Enter a valid number 1-9";
					cin >> L_input;
				}


				while (Used[L_input] == true) // Checks if someone has already used the point
				{
					cout << "It appears someone has already chosen that spot..\t choose another spot\t";
					cout << "1 2 3 \n \t 4 5 6 \n \t 7 8 9 \n \t:";
					cin >> L_input;
				}
				if (Used[L_input] == false) // If the point isn't used.... marks it used
				{
					Used[L_input] = true;
				}
				DrawMap(type, L_input, Map, MapSize);

			}
			if (Oppnnt == "2")
			{
				short Dif = Diffclty - '0';
				srand(time(0));
				switch (Dif)
				{

				case 1:
					L_input = (rand() % 8 + 1);

					while (Used[L_input] == true) // Checks if someone has already used the point
					{
						L_input = (rand() % 8 + 1);
					}
					if (Used[L_input] == false) // If the point isn't used.... marks it used
					{
						Used[L_input] = true;
					}
					DrawMap(type, L_input, Map, MapSize);
					break;

				case 2:

					while (Used[L_input] == true)
					{
						if (L_input == '1' || L_input == '3' || L_input == '7' || L_input == '9')
						{
							L_input = '5';
						}
						else
						{
							L_input = (rand() % 8 + 1);
						}
					}
					if (Used[L_input] == false)
					{
						Used[L_input] = true;
					}
					DrawMap(type, L_input, Map, MapSize);
					break;

				case 3:
					while (Used[L_input])
					{
						int rnd = (rand() % 8 + 1); L_input = '0' + rnd;
					}
					Used[L_input] = true;
					if(Ai('O', map, L_input))
					{
						Ai('O', map, L_input);
					}
					cout << "rnd = " << L_input << endl;
					type = 'X';
					DrawMap(type, L_input, Map, MapSize);
				}
			}
		}
		map.clear();//empty map
		map.resize(9);//resize map to 0
		for (int i = 0; i < 9; i++)//loop the map length
		{
			map[i].push_back(Map[i]);//set the string map equal to the char map 
		}
		if (GetWinner(map) != "None")//There is a winner
		{
			cout << endl << GetWinner(map) << " Wins!" << endl;//Write the winner to screen
		}
	}

	//Exit Stage Right!
	return 0;
}
void DrawMap(char p_char, char Input, vector<char> &Map, int &MapSize)//Requires a return of player character and the position he wants to place it
{
	int uInput = Input - '0'; uInput -= 1;//Convert char to int

	for (int i = 0; i < MapSize; i++)
	{
		if (i % 3 == 0 && i != 0) { cout << endl; }//Add line skips when at 3

		Map[uInput] = p_char;//assign the player character(x or o) to the map
		cout << Map[i] << " ";//Draw the whole Map
	}
	cout << endl;

}
void CheckTurn(int turn)
{
	cout << "Player " << turn << "'s turn" << endl; //write the current players turn
}

void ResetMap(vector<char> &Map, int &MapSize)
{
	for (int i = 0; i < MapSize; i++)//Reset the map to empty spaces
	{
		Map[i] = '+';
	}
}
bool CheckWin(char player, vector<string> &map)//Checks for a winner
{
	string Win = "";//The winner is stored here
	Win.push_back(player); Win.push_back(player); Win.push_back(player);//Add 3 chars of itself so that it can compare to 3 places at once
	return ((map[0] + map[1] + map[2] == Win)	//Row 1
		|| (map[3] + map[4] + map[5] == Win)	//Row 2
		|| (map[6] + map[7] + map[8] == Win)	//Row 3
		|| (map[0] + map[3] + map[6] == Win)	//Column 1
		|| (map[1] + map[4] + map[7] == Win)	//Colomn 2
		|| (map[2] + map[5] + map[8] == Win)	//Column 3
		|| (map[0] + map[4] + map[8] == Win)	//Diagnol 1
		|| (map[2] + map[4] + map[6] == Win));	//Diagnol 2
}
string GetWinner(vector<string> &map)//Grab a winner and return string 
{
	if (CheckWin('O', map))	return "Player 1";//if a winner is O return player 1
	if (CheckWin('X', map)) return "Player 2";//if winner is X return player 2
	else return "None";//if there is no winner return non
}
bool Ai(char Opchar, vector<string> &map,char &Input)
{
	string Ochar = "";
	Ochar.push_back(Opchar); Ochar.push_back(Opchar);
		if (map[0] + map[1] == Ochar){Input = '3'; return true;} if (map[1] + map[2] == Ochar ){Input = '1'; return true;}	//Row 1
		if (map[3] + map[4] == Ochar){Input = '6'; return true;} if (map[4] + map[5] == Ochar ){Input = '4'; return true;}	//Row 2
		if (map[6] + map[7] == Ochar){Input = '9'; return true;} if (map[7] + map[8] == Ochar ){Input = '7'; return true;}	//Row 3
		if (map[0] + map[3] == Ochar){Input = '7'; return true;} if (map[3] + map[6] == Ochar ){Input = '1'; return true;}	//Column 1
		if (map[1] + map[4] == Ochar){Input = '8'; return true;} if (map[4] + map[7] == Ochar ){Input = '2'; return true;}	//Colomn 2
		if (map[2] + map[5] == Ochar){Input = '9'; return true;} if (map[5] + map[8] == Ochar ){Input = '3'; return true;}	//Column 3
		if (map[0] + map[4] == Ochar){Input = '9'; return true;} if (map[4] + map[8] == Ochar ){Input = '1'; return true;}	//Diagnol 1	
		if (map[2] + map[4] == Ochar){Input = '7'; return true;} if (map[4] + map[6] == Ochar ){Input = '3'; return true;}	//Diagnol 2
}