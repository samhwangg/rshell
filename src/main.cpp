//need to use tockenizer to store in a char []!!!
//just ust the tockenizer and comehow store it all in a char array 
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include <string>
#include<vector>
#include<cstring>
#include"login.h"

using namespace std;

int main(int argc, char * argv[])
{
	int exit_check = 1;

	/*entire itteration of rshell until exit is called*/
	do{
		//outputs the command prompt with user login info and hostname
		string cmd_line;
		command_prompt();
		//getline(cin,cmd_line);

		//INSERT PARSING HERE	
		char str[100];

		vector<char* > commands;
		vector<string> separators;

		cin.getline(str,100);

		char* point;

		for(int i = 0; i < 100; i++)
		{
			if(str[i] == ';')
				separators.push_back(";");
	
			if(str[i] == '&') {
				separators.push_back("&&");
				i++;
			}
	
			if(str[i] == '|') {
				separators.push_back("||");
				i++;
			}
		}
	
		point = strtok(str, ";|&");
		while(point != NULL)
		{
			commands.push_back(point);
			point = strtok(NULL, ";|&");
			
		}
	
		for(int i = 0; i < commands.size(); i++)
		{
			if(commands.at(i)[0] == ' ')
			{
				commands.at(i)++;
			}
		}

		vector<vector<char* > > commandList;
		vector<char* >separateCommands;
		char* sample;
		for(int i = 0; i < commands.size(); i++)
		{
			sample = strtok(commands.at(i), " ");
			while(sample != NULL)
			{	
				separateCommands.push_back(sample);
				sample = strtok(NULL, " ");
			}
	
			commandList.push_back(separateCommands);
	
			separateCommands.clear();
		}

		for(int i = 0; i < separators.size(); i++)
		{
			cout << separators.at(i) << endl;
		}

		for(int i = 0; i < commandList.size(); i++)
		{
			for(int j = 0; j < commandList.at(i).size(); j++)
			cout << commandList.at(i).at(j) << endl;
		}
	
		//does all the magic
		execute(seperators, separateCommands);
	
	}while(exit_check == 0);
	
	
	return 0;
}
		
