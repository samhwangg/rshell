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
	int exit_check = 1;

	/*entire itteration of rshell until exit is called*/
	do{
		//outputs the command prompt with user login info and hostname
		string cmd_line;
		command_prompt();
		getline(cin,cmd_line);

		//INSERT PARSING HERE

	
	}while(exit_check == 0);


	return 0;
}

