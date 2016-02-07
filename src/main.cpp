//i commented out your code for testing purposes
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include"login.h"
//#include "Tokenizer.h"

using namespace std;

int main(int argc, char * argv[]){
	/*currently set at 1 for 1 itteration to avoid infinite loop*/
	bool exit_check = 1;

	/*entire itteration of rshell until exit is called*/
	/*need to make exit function*/
	do{
		/*prints command prompt every itteration*/
		command_prompt();	
		string cmd;
		getline(cin,cmd);
		pid_t childPID = fork();
		if(childPID <  0){
			//child executes here
			perror("Child Procces Failed\n");
			exit(-1);
		}
		if(childPID != 0){
			cout << "Parent pid: " << getpid() << endl;
			cout << "Child pid: " << childPID << endl;
			wait(NULL); //waits for child to finish
		}
		else{
			cout << "Child pid: " << getpid() << endl;
			cout << "Parent pid: " << getppid() << endl;
			execl("/bin/mkdir","mkdir","testt", NULL);
			execl("/bin/ls","ls", NULL);
			execl("/bin/rm", "rm", "-rf", "testt", NULL);
		}
	}while(!exit_check);

	cout << "made it" << endl;

/*	Tokenizer str;
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
*/

	return 0;
}
