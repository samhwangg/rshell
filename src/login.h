#ifndef __login_h__
#define __login_h__
#include <unistd.h>
#include <iostream>
#include <cstdlib>

using namespace std;

/* prints command prompt*/
/*gets user name and hostname*/
void command_prompt(){
	char * name = getlogin();
	if(name == NULL){
		cout << "Error: Cannot retreieve login info." << endl;
		exit(EXIT_FAILURE);
	}	
	char hostname[256]; 
	int hostcheck =  gethostname(hostname, 255);
	if(hostcheck == -1){
		cout << "Error: Cannot retrieve login info." << endl;
		exit(EXIT_FAILURE);
	}
	cout << name << "@" << hostname << "$ ";

}

#endif
