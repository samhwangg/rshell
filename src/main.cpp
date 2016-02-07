#include<iostream>
#include"login.h"
#include "Tokenizer.h"

using namespace std;

int main(int argc, char * argv[]){
	/*currently set at 1 for 1 itteration to avoid infinite loop*/
	bool exit_check = 1;

	/*entire itteration of rshell until exit is called*/
	/*need to make exit function*/
	do{
		/*prints command prompt every itteration*/
		command_prompt();	

	}while(!exit_check);

	Tokenizer str;
	string token;
	string line;

	cout << "Sample of parsing between spaces please enter command(s)" << endl;
	getline(cin, line);
	str.set(line); //default delimiter to separate string is " "

	while((token = str.next()) != "")
	{
		cout << token << endl;
	}
	cout << endl;

	cout << "Sample of parsing with different delimiters. Separate words with $" << endl;
	getline(cin, line);
	str.set(line, "$"); //extra parameter changes delimiter to all characters in second string

	while((token = str.next()) != "")
	{
		cout << token << endl;
	}
	cout << endl;

	cout << "So if I want to separate with the connectors according to the assignment the change should be easy. Type \"ls -a; echo hello; mkdir test\"" << endl;
	getline(cin, line);
	string delimiter = "; ";
	
	size_t pos = 0;
	while((pos = line.find(delimiter)) != string::npos)
	{
		token = line.substr(0, pos);
		cout << token << endl;
		line.erase(0, pos + delimiter.length());
	}
	cout << line << endl;
	//this works but
	//i think this is the wrong way to do it. Ill look up a way to use str.set 


	//this option looks at the indivudual characters instead of the whole line
	//str.set(line, delimiter);
	//

	//while((token = str.next()) != "")
	//{
	//	cout << token << endl;
	//}
	//cout << endl;


	return 0;
}
