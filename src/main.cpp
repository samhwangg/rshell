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
	bool exit_check = false;

	/*entire itteration of rshell until exit is called*/
	do{
		//outputs the command prompt with user login info and hostname
		string cmd_line;
		command_prompt();
		//getline(cin,cmd_line);

		
		//create strings to store user input in cstring format
		char str[1024];
		char str2[1024];

		//vector of cstrings to store commands
		vector<char* > commands;
		//vector of strings to store separators
		vector<string> separators;
		//added to test
		separators.clear();
		//stores vector of parenthesis index
		vector<int> paren;
		//user input up to a max of 1024 characters
		cin.getline(str2,1024);
		
		//searches for '#' and moves all non-comments from str2 to str 
		for(unsigned i = 0; str2[i] != '\0'; i++)
		{
			//if comments, search for '#' position and move from 0 to '#' position
			if(str2[i] == '#')
			{
				strncpy(str, str2, i);
				str[i] = '\0';
				break;
			}
			//if no comments, move all of str2 to str
			if(i == (strlen(str2) - 1));
			{
				strncpy(str, str2, (i + 1));
				str[i + 1] = '\0';
			}

		}

		//search for separators and stores it into string vector
		//also stores position of parenthesis in relation to separators
		int separatorCount = 0;
		int parenCount = 0;
		for(unsigned i = 0; str[i] != '\0'; i++)
		{
			if(str[i] == ';')
			{
				separators.push_back(";");
				separatorCount++;
			}
			
			if(str[i] == '&')
			{
				separators.push_back("&&");
				i++;
				separatorCount++;
			}
	
			if(str[i] == '|')
			{
				separators.push_back("||");
				i++;
				separatorCount++;
			}

			if(str[i] == '(')
			{
				paren.push_back(separatorCount + 1);
				paren.push_back(separatorCount +1);
				parenCount++;
			}

			if(str[i] == ')')
			{
				paren.at((parenCount * 2) - 1) = separatorCount;
				parenCount--;
			}
		}

		//splits user input into tokens and stores it in the commands vector
		char* point;
		point = strtok(str, ";|&");
		while(point != NULL)
		{
			commands.push_back(point);
			point = strtok(NULL, ";|&");
			
		}
		//if there is a whitespace at the beginning of the command, remove it
		for(unsigned i = 0; i < commands.size(); i++)
		{
			if(commands.at(i)[0] == ' ')
			{
				commands.at(i)++;
			}
		}

		//finds brackets [ ] and changes it so test precedes the command
		int cmdsize = 0;
		for(unsigned i = 0; i < commands.size(); i++)
		{
			for(unsigned j = 0; commands.at(i)[j] != '\0'; j++)
			{
				if(commands.at(i)[j] == '[')
				{
					for(unsigned k = j; commands.at(i)[k] != '\0'; k++)
					{
						commands.at(i)[k] = commands.at(i)[k + 1];
					}
				}
				if(commands.at(i)[j] == ']')
				{
					for(unsigned k = j; commands.at(i)[k] != '\0'; k++)
					{
						commands.at(i)[k] = commands.at(i)[k + 1];
					}
					for(unsigned x = 0; commands.at(i)[x] != '\0'; x++)
					{
						cmdsize++;
					}
					for(unsigned y = 0; y < 4; y++)
					{
						for(unsigned z = cmdsize + 2; z > 0 ; z--)
						{	
							commands.at(i)[z] = commands.at(i)[z - 1];
						}
					}
					commands.at(i)[cmdsize + 3] = '\0';
					commands.at(i)[0] = 't';
					commands.at(i)[1] = 'e';
					commands.at(i)[2] = 's';
					commands.at(i)[3] = 't';
				}
			}
		}


		//removes quotation marks from echo commands
		for(unsigned i = 0; i < commands.size(); i++)
		{
			for(unsigned j = 0; commands.at(i)[j] != '\0'; j++)
			{
				if(commands.at(i)[j] == '\"')
				{
					for(unsigned k = j; commands.at(i)[k] != '\0'; k++)
					{
						commands.at(i)[k] = commands.at(i)[k + 1];
					}
				}
			}
		}


		//creates a 2D vector to store the commands and the flag in a vector of cstrings
		vector<vector<char* > > commandList;
		//added to test something
		commandList.clear();
		//added to test something
		vector<char* >separateCommands;
		char* sample;
		for(unsigned i = 0; i < commands.size(); i++)
		{
			sample = strtok(commands.at(i), " \t\n");
			while(sample != NULL)
			{
				separateCommands.push_back(sample);
				sample = strtok(NULL, " \t\n");
			}
			//pushes back vector of cstrings into vector, making a 2D vector
			commandList.push_back(separateCommands);
			
			separateCommands.clear();
		}
		
		//parenthesis output test
		for(unsigned i = 0; i < paren.size(); i++)
		{
			cout << paren.at(i) << endl;
		}



		//c string output test
		for(unsigned i = 0; i < commandList.size(); i++)
		{
			for(unsigned j = 0; j < commandList.at(i).size(); j++)
			{
				cout << commandList.at(i).at(j) << " ";
			}
			cout << endl;
		}

		//calls execute command
		//if(commandList.size() == 0)
		//{
			execute(separators, commandList, exit_check, paren);
		//}

		//destroy the memory locations created by cstrings
		//clears all vectors
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
		
	}while(!exit_check);
	
	
	return 0;
}
		
