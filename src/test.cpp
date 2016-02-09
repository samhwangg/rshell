#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
using namespace boost;

int main()
{	
	vector<string> holdCommands;
	string str = "Hello|world|-foo;;bar";
	typedef tokenizer<char_separator<char> > tokenizer;
	char_separator<char> sep("-;|");
	tokenizer tokens(str, sep);
	for(tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); tok_iter++)
	{
		holdCommands.push_back(*tok_iter);
		string test;
		test = *tok_iter;
		cout << test << endl;
	}	

	char  y[1024] =  "";
	for(int i = 0; i < holdCommands.size(); i++)
	{	
		strcat(y,"\0");
		strcat(y,holdCommands.at(i).c_str());

	}
	cout << y << endl;


	
}
