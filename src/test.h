#ifndef __test_h__
#define __test_h__

#include <iostream>
#include <vector>
#include <cstring>

//function that executes test command
void test_execution(char * command[1024], bool & e_check)
{
	struct stat buf;
	//test to see if 2nd parameter is a correct flag
	//test to see if no flag is passed
	if(command[1] != "-e" || command[1] != "-d" ||command[1] != "-f" ||)
	{

	}

}
#endif
