//need to use tockenizer to store in a char []!!!
//just ust the tockenizer and comehow store it all in a char array 
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include<vector>
#include<cstring>
#include"login.h"
#include<boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int main(int argc, char * argv[])
{
	/*currently set at 1 for 1 itteration to avoid infinite loop*/
	int exit_check = 0;

	/*entire itteration of rshell until exit is called*/
do{
		//initializes parsing
		
	vector<string> holdCommands;
	string str;
	command_prompt();
	getline(cin,str);
	typedef tokenizer<char_separator<char> > tokenizer;
	char_separator<char> sep(";");
	tokenizer tokens(str, sep);
	for(tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); tok_iter++)
	{
		holdCommands.push_back(*tok_iter);
		string test;
		test = *tok_iter;
	}	

	char *  y[1024]; //int temp;
	memset(y,'\0',sizeof(y));
	for(unsigned i = 0; i < holdCommands.size(); i++)
	{	
		y[i] = const_cast<char*>( holdCommands.at(i).c_str());
		//temp = i;
		//strcat(y[i], "\0");
		cout << y[i] << endl;
	}

		//testin execvp and fork
		pid_t childPID = fork();
		if(childPID <  0){
			//forking error
			perror("Forking Failed\n");
			exit(-1);
		}
		else if(childPID != 0){
			//parent process lies here
			wait(NULL); //waits for child to finish
		}
		else{
			//child process lies here
			//exit is not working still
			//if(strcmp(y , "exit") == 0){
			//	exit_check = 1;
			//	exit(0);
		//	}
			//else{
				int run_shell = execvp(y[0],y );
				if(run_shell < 0){
					perror("Exec Failed");
					exit(-1);
				}
			//}
		}
	
	}while(exit_check == 0);

	/*Tokenizer str;
	string token;
	string line;

	getline(cin, line);
	str.set(line, ";"); //extra parameter changes delimiter to all characters in second string

	while((token = str.next()) != "")
	{
		cout << token << endl;
	}
	cout << endl;*/
	
	/*getline(cin, line);
	string delimiter = "; ";
	
	size_t pos = 0;
	while((pos = line.find(delimiter)) != string::npos)
	{
		token = line.substr(0, pos);
		cout << token << endl;
		line.erase(0, pos + delimiter.length());
	}
	cout << line << endl;*/

	//}
	return 0;
}
