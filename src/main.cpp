#include<iostream>
#include"login.h"
using namespace std;

int main(){
	/*currently set at 1 for 1 itteration to avoid infinite loop*/
	bool exit_check = 1;

	/*entire itteration of rshell until exit is called*/
	/*need to make exit function*/
	do{
		/*prints command prompt every itteration*/
		command_prompt();	

	}while(!exit_check);

	return 0;
}
