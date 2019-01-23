#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>

using namespace std;

void computerChoice(string & cMove, int & moveNum)
{

	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(1, 3);
	int dice_roll = distribution(generator);

	switch (dice_roll)
	{
	case 1: cMove = "Rock";
		moveNum = 1;
		break;
	case 2: cMove = "Paper";
		moveNum = 2;
		break;
	case 3: cMove = "Scissor";
		moveNum = 3;
		break;
	}

}
int main()
{
	string cMove, ss, game, myMove;
	int num, moveNum;

	cout << "Choose an Action!!" << endl;
	cout << "\n1. Rock" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Scissor" << endl;



	do {
		computerChoice(cMove, moveNum);

		getline(cin, ss);
		stringstream(ss) >> num;

		if (num == moveNum) { cout << "Tie Game!!" << endl; }

		else {
			switch (num)
			{
			case 1:  if (moveNum == 3) { game = "You Won!"; }
					 else { game = "You Lost!!"; }
					 myMove = "Rock";
					 break;

			case 2:   if (moveNum == 1) { game = "You Won!!"; }
					  else { game = "You Lost!!"; }
					  myMove = "Paper";
					  break;

			case 3:    if (moveNum == 2) { game = "You Won!!"; }
					   else { game = "You Lost!!"; }
					   myMove = "Scissor";
					   break;

			default: cout << "No Action Found!!" << endl;

			}
		}
	} while (num == moveNum);

	
	cout << "COM : " << cMove << " VS " << myMove << " : YOU ==> " << game << endl;


	return 0;
}