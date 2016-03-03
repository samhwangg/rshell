#ifndef __test_h__
#define __test_h__

#include <iostream>
#include <vector>
#include <cstring>

//function that executes test command
void test_execution(char * command[1024], bool & e_check)
{
	struct stat buf;
	string flag;
	string t_rue = "(True)\n";
	string f_alse = "(False)\n";
	//test to see if 2nd parameter is a correct flag
	//test to see if no flag is passed
	if(command[1] != "-e" || command[1] != "-d" ||command[1] != "-f" ||)
	{
		if(command[2] == NULL)
		{
			flag = "-e";				
		}
		else
		{
			cout << "Error invalid flag: Use \"-e\", \"-d\", \"-f\" or no flag to use test.\n";
			e_check = false;
			return;
		}
	}

	//implementation of test command
	
	//checks if the file/directory exists and is a file
	if(command[1] == "-f")
	{
		if(stat(command , & buf) == -1)
		{
			perror("Stat failure");
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFREG: cout << t_rue;
			default: cout << f_alse;
		}
	}
	//checks if the file/directory exists and is a directory
	else if(command[1] == "-d")
	{
		if(stat(command , & buf) == -1)
		{
			perror("Stat failure");
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFDIR: cout << t_rue;
			default: cout << f_alse;
		}

	}
	//checks if the file/directory exists 
	else
	{
		if(stat(command , & buf) == -1)
		{
			perror("Stat failure");
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IfDIR: cout << t_rue;
			case S_IFREG: cout << t_rue;
			default: cout << f_alse;
		}
	}
	return;
}
#endif
