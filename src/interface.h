#ifndef __interface_h__
#define __interface_h__
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

void execute(vector<string> connectors, vector<vector<char *> > commands)
{	
	//used to see if previod command was ran properly
	//both values are default
	bool prev_check = 1;
	string prev_command = ";";

	//make hard case for no connectors to just run one command
	////just like main

	for(unsigned it  = 0; it < connectors.size() + 1; ++it)
	{
		//makes char ** that is used in execvp and 
		//fills with NULL
		char * buffer[1024];
		memset(buffer, '\0', sizeof(buffer));
		if(it != 0)
		{
			prev_command = connectors.at(it - 1);
		//	cout << prev_command << " ";
		}
		//check if previous call failed or not
		//cout << prev_check << endl;
		if(prev_check)
		{
			if(prev_command == ";")
			{
				//will always run

				//for loop to make command into a cstring array
				for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
				{
					buffer[cs] = const_cast<char *>(commands.at(it).at(cs));

				}

				//run execvp
				pid_t childPID = fork();
				if(childPID < 0)
				{
					//forking error
					perror("Forking child Failed\n");
					exit(-1);
				}
				else if(childPID != 0)
				{
					//parent process
					wait(NULL);	
				}
				else
				{
					prev_check = true;
					//in child process
					int run_shell = execvp(buffer[0],buffer);
					if(run_shell < 0)
					{
						perror("Execvp failed");
						prev_check = false;
					}

				}


			}
			else if(prev_command == "&&")
			{
				//will run

				//for loop to make command into a cstring array
				for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
				{
					buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
				}

				//run execvp
				pid_t childPID = fork();
				if(childPID < 0)
				{
					//forking error
					perror("Forking child Failed\n");
					exit(-1);
				}
				else if(childPID != 0)
				{
					//parent process
					wait(NULL);	
				}
				else
				{
					prev_check = true;
					//in child process
					int run_shell = execvp(buffer[0],buffer);
					if(run_shell < 0)
					{
						perror("Execvp failed");
						prev_check = false;
					}

				}

			}
			else if(prev_command == "||")
			{
				//will not run
				prev_check = false;	
			}

		}
		else
		{

			if(prev_command == ";")
			{
				//will always run

				//for loop to make command into a cstring array
				for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
				{
					buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
				}

				//run execvp
				pid_t childPID = fork();
				if(childPID < 0)
				{
					//forking error
					perror("Forking child Failed\n");
					exit(-1);
				}
				else if(childPID != 0)
				{
					//parent process
					wait(NULL);	
				}
				else
				{
					prev_check = true;
					int run_shell = execvp(buffer[0],buffer);
					if(run_shell < 0)
					{
						perror("Execvp failed");
						prev_check = false;
					}

				}




			}
			else if(prev_command == "&&")
			{
				prev_check = false;

			}
			else if(prev_command == "||")
			{
				//will run
				
				//for loop to make command into a cstring array
				for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
				{
					buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
				}

				//run execvp
				pid_t childPID = fork();
				if(childPID < 0)
				{
					//forking error
					perror("Forking child Failed\n");
					exit(-1);
				}
				else if(childPID != 0)
				{
					//parent process
					wait(NULL);	
				}
				else
				{
					prev_check = true;
					int run_shell = execvp(buffer[0],buffer);
					if(run_shell < 0)
					{
						perror("Execvp failed");
						prev_check = false;
					}
				}

			}

		}
			
	}
}
#endif
