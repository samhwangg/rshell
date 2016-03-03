#ifndef __test_h__
#define __test_h__

#include <iostream>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


//function that executes test command
void test_execution(char *command[1024], bool & e_check)
{
	struct stat buf;
	string flag;
	string t_rue = "(True)\n";
	string f_alse = "(False)\n";
	flag = command[1];

	//test to see if 2nd parameter is a correct flag
	//test to see if no flag is passed
	if(flag != "-e" && flag != "-d" && flag != "-f" )
	{
		if(command[2] == '\0')
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
	if(flag == "-f")
	{
		if(stat(command[2] , & buf) == -1)
		{
			perror("Stat failure");
			e_check = false;
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFREG: cout << t_rue; break;
			default: cout << f_alse; break;
		}
		
	}
	//checks if the file/directory exists and is a directory
	else if(flag == "-d")
	{
		if(stat(command[2] , & buf) == -1)
		{
			perror("Stat failure");
			e_check = false;
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFDIR: cout << t_rue; break;
			default: cout << f_alse; break;
		}
		
	}
	//checks if the file/directory exists 
	else
	{
		//if default flag was set!!
		if(command[2] == '\0')
		{
			if(stat(command[1] , & buf) == -1)
			{
				perror("Stat failure");
				e_check = false;
				return;
			}
			switch (buf.st_mode & S_IFMT)
			{
				case S_IFDIR: cout << t_rue; break;
				case S_IFREG: cout << t_rue; break;
				default: cout << f_alse; break;
			}
			e_check = true;
			return;
		}
		if(stat(command[2] , & buf) == -1)
		{
			perror("Stat failure");
			e_check = false;
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFDIR: cout << t_rue; break;
			case S_IFREG: cout << t_rue; break;
			default: cout << f_alse; break;
		}
	}
	e_check = true;
	return;
}
#endif
