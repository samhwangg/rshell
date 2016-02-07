//i commented out your code for testing purposes
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include<cstring>
#include"login.h"
#include "Tokenizer.h"

using namespace std;

int main(int argc, char * argv[]){
	/*currently set at 1 for 1 itteration to avoid infinite loop*/
	bool exit_check = 0;

	/*entire itteration of rshell until exit is called*/
	/*need to make exit function*/
	/*do{
		//prints command prompt every itteration
		//use next 3 lines for parsing
		command_prompt();
		char cmd[128];
		char * cmd_ptr[16];
		getline(cin,cmd);
		*cmd_ptr = cmd;
		cmd_ptr[15] = '\0';
		//testin execvp anf fork
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
			cout << "In child" << endl;
			//child process lies here
			int run_shell = execvp(cmd_ptr[0], cmd_ptr);
			if(run_shell < 0){
				perror("Exec Failed");
				exit(-1);
			}

			//sample test for exit will make funcation 
			if(strcmp(argv[0], "exit") == 0){
				exit_check = 1;
			}

		}
	}while(!exit_check);

	cout << "made it" << endl;*/

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
