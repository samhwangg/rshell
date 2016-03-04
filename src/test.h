#ifndef __test_h__
#define __test_h__

#include <iostream>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

//function that executes test command
void test_execution(char *command[1024], bool & e_check)
{
	//case for just test passed
	if(command[1] == '\0')
	{
		e_check = false;
		return;
	}
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
			//check if a /is present in path input
			//removal of the /
			string path = command[1];
			if(path.at(0) == 47)
			{
				//loop to remove first element in string
				string new_path;
				for(unsigned i = 1; i < path.size();++i){
					new_path.push_back(path.at(i));
				}
				command[1] = (char *)new_path.c_str();
			}
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
		// first char slash check
		string path = command[2];
		if(path.at(0) == 47)
		{
			//loop to remove first element in string
			string new_path;
			for(unsigned i = 1; i < path.size();++i){
				new_path.push_back(path.at(i));
			}
			command[2] = (char *)new_path.c_str();
		}
		if(stat(command[2] , & buf) == -1)
		{
			perror("Stat failure");
			e_check = false;
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFREG: cout << t_rue; e_check = true; break;
			default: cout << f_alse; e_check = false;  break;
		}
		
	}
	//checks if the file/directory exists and is a directory
	else if(flag == "-d")
	{
		string path = command[2];
		if(path.at(0) == 47)
		{
			//loop to remove first element in string
			string new_path;
			for(unsigned i = 1; i < path.size();++i){
				new_path.push_back(path.at(i));
			}
			command[2] = (char *)new_path.c_str();
		}
		if(stat(command[2] , & buf) == -1)
		{
			perror("Stat failure");
			e_check = false;
			return;
		}
		switch (buf.st_mode & S_IFMT)
		{
			case S_IFDIR: cout << t_rue; e_check = true; break;
			default: cout << f_alse; e_check = false;  break;
		}
		
	}
	//checks if the file/directory exists 
	else
	{
		//if 3 arguements
		if(command[2] != '\0' )
		{
			string path = command[2];
			if(path.at(0) == 47)
			{
				//loop to remove first element in string
				string new_path;
				for(unsigned i = 1; i < path.size();++i){
					new_path.push_back(path.at(i));
				}
				command[2] = (char *)new_path.c_str();
			}
		}
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
				case S_IFDIR: cout << t_rue; e_check = true; break;
				case S_IFREG: cout << t_rue; e_check = true; break;
				default: cout << f_alse; e_check = false; break;
			}
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
	return;
}
#endif
