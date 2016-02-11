#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<cstring>
#include"login.h"
#include"interface.h"

using namespace std;

int main(int argc, char * argv[])
{
	int exit_check = 0 ;

	/*entire itteration of rshell until exit is called*/
	do{
		//outputs the command prompt with user login info and hostname
		string cmd_line;
		command_prompt();
		//getline(cin,cmd_line);

		//INSERT PARSING HERE	

		char str[1024];
		char str2[1024];

		vector<char* > commands;
		vector<string> separators;

		cin.getline(str2,1024);

		for(unsigned i = 0; str2[i] != '\0'; i++)
		{
			if(str2[i] == '#')
			{
				strncpy(str, str2, i);
				str[i] = '\0';
				break;
			}
			if(i == (strlen(str2) - 1));
			{
				strncpy(str, str2, (i + 1));
				str[i + 1] = '\0';
			}

		}

		char* point;

		for(unsigned i = 0; i < 1024; i++)
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
	
		for(unsigned i = 0; i < commands.size(); i++)
		{
			if(commands.at(i)[0] == ' ')
			{
				commands.at(i)++;
			}
		}

		vector<vector<char* > > commandList;
		vector<char* >separateCommands;
		char* sample;
		for(unsigned i = 0; i < commands.size(); i++)
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

		for(unsigned i = 0; i < separators.size(); i++)
		{
			cout << separators.at(i) << endl;
		}

		for(unsigned i = 0; i < commandList.size(); i++)
		{
			for(unsigned j = 0; j < commandList.at(i).size(); j++)
			cout << commandList.at(i).at(j) << endl;
		}
	
		//does all the magic
		
		execute(separators, commandList);

		//insert destructor here
		for(int i = 0; i < 1024; i++)
		{
			str[i] = '\0';
			str2[i] = '\0';
		}
		point = '\0';
		commands.clear();
		separators.clear();
		commandList.clear();
		separateCommands.clear();
		
	}while(exit_check == 0);
	
	
	return 0;
}
		
