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
#include <wctype.h>
#include "test.h"

using namespace std;
//add overall object bool by reference
//add vector of paran pairs
void execute(vector<string> connectors, vector<vector<char *> > commands, bool & e_check, vector<int> & paren, int fi_check)
{	
	//used to see if previous command was ran properly
	//both values are default
	bool prev_check = true;
	string prev_command = ";";
	string e_cmp = "exit";
	string c_cmp = "clear";
	string t_cmp = "test";
	int c_pass = 0;

	//case for just exit being passed
	if(connectors.size() == 0)
	{
		if(commands.size() == 1)
		{
			if(commands.at(0).size() == 0){
				return;
			}
			if(strcmp(commands.at(0).at(0), e_cmp.c_str()) == 0)
			{
				e_check = true;
				exit(0);
			}
			else if(strcmp(commands.at(0).at(0), c_cmp.c_str()) == 0)
			{	
				//avoid random clear error
				c_pass = 1;
			}
		}
	}
	if(e_check == true){
		e_check = false;
		exit(0);
	}

	//case when only connectors are passed
	//and when connector end line
	int temp1 = commands.size();
	int temp2 = connectors.size();
	bool valid_case1 = true;
	if(temp1 == 0)
	{
		if(temp2 != 0)
		{
			cout << "Error: connector passed with no commands preceeding" << endl;
			valid_case1 = false;	
		}
		else
		{
			//empty input return nothing
			return;
		}
	}
	if(temp2 >= temp1)
	{
		//remove
		if(c_pass != 1)
		{
			cout << "Error: Syntax" << endl;
			return;
		}
	}
	int e_loop = 0;	
	//runs normaly if no syntax error detected
	if(valid_case1)
	{	
		//loop that runs all the commands passed in the command prompt
		//and accounts for the connectors
		for(unsigned it  = 0; it < connectors.size() + 1; ++it)
		{
			if(e_loop > 0){
				return;
			}
			//makes char ** that is used in execvp and 
			//fills with NULL loads one command at a time
			char * buffer[1024];
			memset(buffer, '\0', sizeof(buffer));
			//gets previous connector to check 
			//if the next command will run or not
			if(connectors.size() != 0)
			{
				if(it != 0)
				{
					prev_command = connectors.at(it - 1);
				}
			}
			//check if previous call failed or not
			if(prev_check)
			{
				if(prev_command == ";")
				{
					//will always run in the case of a true before ; 
					//for loop to make command into a cstring array
					for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
					{
						buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
					}

					//exit check
					if(strcmp(buffer[0], e_cmp.c_str()) == 0)
					{
						e_check = true;
						exit(0);
						return;

					}
					//test check
					if(strcmp(buffer[0],t_cmp.c_str()) == 0)
					{
						//call test here
						//ERROR FIX THIS CONVERSION
						test_execution(buffer, prev_check);
					}
					else
					{
						if(fi_check > 0){
							if(paren.size() != 0)
							{
								//working with beg and end paren
								int beg = paren.at(0);
								int end = paren.at(1);
								int p_size = paren.size();
								if(p_size == 2)
								{
									paren.pop_back(); paren.pop_back();
								}
								else
								{
									for( int i = 0; i + 2 <  p_size ; i++ ){
										paren.at(i) = paren.at(i + 2);
									}
									paren.pop_back(); paren.pop_back();
								}
			
								vector<string> conn2;
								//creates new connectors vectos
								for(int i = beg - 1 ; i < end ; ++i){
									conn2.push_back(connectors.at(i));
								}
											
								//create new commands vector
								vector<vector<char *> > recom;
								for(int i = beg - 1; i <= end ; ++i){
									recom.push_back(commands.at(i));
								}
								int go_check = 0;
								execute( conn2 , recom, e_check,  paren, go_check);
								if(e_check){
									exit(0);
								}
							}
						}
						//run execvp
						pid_t childPID = fork();
						pid_t PAR;
						if(childPID < 0)
						{
							//forking error
							perror("Forking child Failed\n");
							exit(-1);
						}
						else if(childPID != 0)
						{
							//parent process

							if((PAR = wait(NULL)) < 0)
							{
								perror("Waiting Error");
								exit(-1);
							}
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
								
								if(connectors.size() == 0){
								}
								else{	
									if(connectors.at(0) == "&&"){
										if(paren.size() != 0){
											if(paren.at(0) !=  1){
												if(prev_check == false){
													commands.clear();
													connectors.clear();
													e_loop++;
													return;
												}
											}
										}	
								
									}
								}
							}

						}

					}


				}
				else if(prev_command == "&&")
				{
					//will run if the previoud command returned true
					//for loop to make command into a cstring array
					for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
					{
						buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
					}

					//exit check
					if(strcmp(buffer[0], e_cmp.c_str()) == 0)
					{
						e_check = true;
						exit(0);
						return;

					}

					//test check
					if(strcmp(buffer[0],t_cmp.c_str()) == 0)
					{
						//call test here
						//ERROR FIX THIS CONVERSION
						test_execution(buffer, prev_check);
						return;
					}
					else
					{
						if(fi_check >  0){
							if(paren.size() != 0)
							{
								//working with beg and end paren
								int beg = paren.at(0);
								int end = paren.at(1);
								int p_size = paren.size();
								if(p_size == 2)
								{
									paren.pop_back(); paren.pop_back();
								}
								else
								{
									for( int i = 0; i + 2 <  p_size ; i++ ){
										paren.at(i) = paren.at(i + 2);
									}
									paren.pop_back(); paren.pop_back();
								}
			
								vector<string> conn2;
								//creates new connectors vectos
								for(int i = beg - 1 ; i < end ; ++i){
									conn2.push_back(connectors.at(i));
								}
											
								//create new commands vector
								vector<vector<char *> > recom;
								for(int i = beg - 1; i <= end ; ++i){
									recom.push_back(commands.at(i));
								}
								int go_check = 0;
								execute( conn2 , recom, e_check,  paren, go_check);
								if(e_check){
									exit(0);
								}
							}
						}
						//run execvp

						//run execvp
						pid_t childPID = fork();
						pid_t PAR;
						if(childPID < 0)
						{
							//forking error
							perror("Forking child Failed\n");
							exit(-1);
						}
						else if(childPID != 0)
						{
							//parent process

							if((PAR = wait(NULL)) < 0)
							{
								perror("Waiting Error");
								exit(-1);
							}
						}
						else
						{	
							prev_check = true;
							//in child process
							int run_shell = execvp(buffer[0],buffer);
							if(run_shell < 0)
							{
								perror("Execvp failed");
								if(paren.size() == 2){
									exit(0);
								}
								prev_check = false;
								if(connectors.at(0) == "&&"){
									if(paren.size() != 0){
										if(paren.at(0) >  1){
											if(prev_check == true){
												commands.clear();
												connectors.clear();
												e_loop++;
												return;
											}
										}
									}
								}
							}

						}

					}

				}
				else if(prev_command == "||")
				{
					//will not run in any case if previoud command was true
					prev_check = true;
					if(paren.size() == 2){
						return;
					}
				}

			}
			else
			{

				if(prev_command == ";")
				{
					//will always run in the case that previoud command was true
					//for loop to make command into a cstring array
					for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
					{
						buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
					}

					//exit check
					if(strcmp(buffer[0], e_cmp.c_str()) == 0)
					{
						e_check = true;
						exit(0);
						return;

					}

					//test check
					if(strcmp(buffer[0],t_cmp.c_str()) == 0)
					{
						//call test here
						//ERROR FIX THIS CONVERSION
						test_execution(buffer, prev_check);
						return;
					}
					else
					{
						

						if(fi_check > 0){
							if(paren.size() != 0)
							{
								//working with beg and end paren
								int beg = paren.at(0);
								int end = paren.at(1);
								int p_size = paren.size();
								if(p_size == 2)
								{
									paren.pop_back(); paren.pop_back();
								}
								else
								{
									for( int i = 0; i + 2 <  p_size ; i++ ){
										paren.at(i) = paren.at(i + 2);
									}
									paren.pop_back(); paren.pop_back();
								}
			
								vector<string> conn2;
								//creates new connectors vectos
								for(int i = beg - 1 ; i < end ; ++i){
									conn2.push_back(connectors.at(i));
								}
											
								//create new commands vector
								vector<vector<char *> > recom;
								for(int i = beg - 1; i <= end ; ++i){
									recom.push_back(commands.at(i));
								}
								int go_check = 0;
								execute( conn2 , recom, e_check,  paren, go_check);
								if(e_check){
									exit(0);
								}

							}
						}
						//run execvp
						pid_t childPID = fork();
						pid_t PAR;
						if(childPID < 0)
						{
							//forking error
							perror("Forking child Failed\n");
							exit(-1);
						}
						else if(childPID != 0)
						{
							//parent process

							if((PAR = wait(NULL)) < 0)
							{
								perror("Waiting Error");
								exit(-1);
							}
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
				}
				else if(prev_command == "&&")
				{
					//will not run if previoud command was false
					prev_check = false;
					if(paren.size() == 2){
						exit(0);
						return;
					}

				}
				else if(prev_command == "||")
				{
					int o_check = 0;
					//fixes multiple || error
					if(it > 1)
					{
						if(connectors.at(it - 2) == "||")
						{
							o_check = 1;
							prev_check = false;
						}

					}
					//runs command normally
					if(o_check == 0)
					{
						//will run if previos command was false	
						//for loop to make command into a cstring array
						for(unsigned cs = 0; cs < commands.at(it).size() ; ++cs)
						{
							buffer[cs] = const_cast<char *>(commands.at(it).at(cs));
						}
						//exit check
						if(strcmp(buffer[0], e_cmp.c_str()) == 0)
						{
							e_check = true;
							exit(0);
							return;
						}

						//test check
						if(strcmp(buffer[0],t_cmp.c_str()) == 0)
						{
							//call test here
							//ERROR FIX THIS CONVERSION
							test_execution(buffer, prev_check);
							return;
						}
						else
						{
							

							if(fi_check > 0){
								if(paren.size() != 0)
								{
									//working with beg and end paren
									int beg = paren.at(0);
									int end = paren.at(1);
									int p_size = paren.size();
									if(p_size == 2)
									{
										paren.pop_back(); paren.pop_back();
									}
									else
									{
										for( int i = 0; i + 2 <  p_size ; i++ ){
											paren.at(i) = paren.at(i + 2);
										}
										paren.pop_back(); paren.pop_back();
									}
				
									vector<string> conn2;
									//creates new connectors vectos
									for(int i = beg - 1 ; i < end ; ++i){
										conn2.push_back(connectors.at(i));
									}
											
									//create new commands vector
									vector<vector<char *> > recom;
									for(int i = beg - 1; i <= end ; ++i){
										recom.push_back(commands.at(i));
									}
									int go_check = 0;
									execute( conn2 , recom, e_check,  paren, go_check);
									if(e_check){
										exit(0);
									}
								}
							}
							//run execvp
							pid_t childPID = fork();
							pid_t PAR;
							if(childPID < 0)
							{
								//forking error
								perror("Forking child Failed\n");
								exit(-1);
							}
							else if(childPID != 0)
							{
								//parent process
	
								if((PAR = wait(NULL)) < 0)
								{
									perror("Waiting Error");
									exit(-1);
								}
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


					}

				}
				
			}

		}

	}
}
#endif
