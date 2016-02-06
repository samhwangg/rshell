#ifndef __login_h__
#define __login_h__
#include <unistd.h>
#include <iostream>

using namespace std;

void command_prompt(){
	char * name = getlogin();
	if(name == NULL){
		cout << "Error: Cannot retreieve login info." << endl;
	}	
	char hostname[256] = {"\0"};
	hostname[255] = '\0';
	int hostcheck =  gethostname(hostname, 255);
	if(hostcheck == -1){
		cout << "Error: Cannot retrieve login info." << endl;
	}
	cout << name << "@" << hostname << "$ ";

}

#endif
