// testing Tokenizer class
#include "Tokenizer.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
//using namespace boost;

int main(int argc, char* argv[])
{
    // instanciate Tokenizer class
	
    Tokenizer str;
    string token;
    vector<string> holdCommands;
    string test = "ls -a; echo hello; cd ..";
    // set source string with default delimiters (space, tab, and newline char)
    str.set(test, ";");

    // Tokenizer::next() returns a next available token from source string
    // If it reaches EOS, it returns zero-length string, "".
    while((token = str.next()) != "")
    {
        holdCommands.push_back(token);
    }
    /*for(int i = 0; i < holdCommands.size(); i++)
	{
		cout << holdCommands.at(i) << endl;
	}*/

	char  y[1024] =  "";
	for(int i = 0; i < holdCommands.size(); i++)
	{	
		strcat(y,"\0");
		strcat(y,holdCommands.at(i).c_str());

	}
	cout << y << endl;

   /* // set a different string and delimiters(~, _)
    // Notice that space is not delimiter any more.
    counter = 0;
    str.set("Now,~the_delimiters~~~are__changed~to_tild  and  underscore.~", "~_");
    while((token = str.next()) != "")
    {
        ++counter;
        cout << counter << ": " << token << endl;
    }
*/
    return 0;
}

