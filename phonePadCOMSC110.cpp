//Celik Berk Altingok
//1610932

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void phonePad(const string & mystr)
{
	string s;
	int a;
	char b;
	a = mystr.size();

	for (int i = 0; i < a; i++)
	{
		b = toupper(mystr.at(i));

		if (isalpha(b))
		{
			cout << (((b - 'A') - (b >= 'S')) / 3 + 2);
		}
		else {
			cout << b;
		}

	}
	
}

int main()
{

	string mystr;

	cout << "Enter" << endl;
	getline(cin, mystr);
	
	phonePad(mystr);
	
	return 0;
}