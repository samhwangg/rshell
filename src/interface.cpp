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

//vector<string> connectors, vector<vector<char *>> commands
//use as parameters for execute
//void execute(){
int main()
{	
	//used to see if previod command was ran properly
	//both values are default
	bool prev_check = 1;
	string prev_command = ";";

	//all testing until parsing is finshied
	vector<string> connectors;
	connectors.push_back(";");
	connectors.push_back(";");
	vector<vector<string> > commands;
	//first command
	vector<string> test;
	test.push_back("echo"); 
	test.push_back("FISRT"); 
	commands.push_back(test);
	//second command
	vector<string> test2;
	test2.push_back("cal"); 
	commands.push_back(test2);
	vector<string> test3;
	test3.push_back("ls"); 
	test3.push_back("-l"); 
	commands.push_back(test3);
	
	

	//testing
	
//make hard case for no connectors to just run one command
////just like main

	for(int it = 0; it < connectors.size() + 1; ++it)
	{
		//makes char ** that is used in execvp and 
		//fills with NULL
		char * buffer[1024];
		memset(buffer, '\0', sizeof(buffer));
		//string curr_connect = connectors.at(it);
		//for(unsigned i = 0; i < commands.size(); ++i)
		//{
			//check if previous call failed or not
			if(prev_check)
			{
				if(prev_command == ";")
				{
					//will always run

					//for loop to make command into a cstring array
					for(int cs = 0; cs < commands.at(it).size() ; ++cs)
					{
						buffer[cs] = const_cast<char *>(commands.at(it).at(cs).c_str());
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

				}
				else if(prev_command == "||")
				{
					//will not run


				}
	
			}
			else
			{

				if(prev_command == ";")
				{
					//will always run

					//for loop to make command into a cstring array
					for(int cs = 0; cs < commands.at(it).size() ; ++cs)
					{
						buffer[cs] = const_cast<char *>(commands.at(it).at(cs).c_str());
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
					//will not run

				}
				else if(prev_command == "||")
				{
					//will run


				}

			}
			

		//}


	}

	return 0;
}


//}


/*void and_connect(bool prev_check){
//runs and logic
////if true run next
////if false dont


}




void or_connect(bool prev_check){
//runs or logic
//if false run next
//if true skip



}



void semi_connect(bool prev_check){
//always run command fail or not




}



void comment(){




}*/
