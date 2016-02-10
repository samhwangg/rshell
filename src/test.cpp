#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{	
	char str[100];

	vector<char* > commands;

	cin.getline(str,100);

	char* point;

	point = strtok(str, ";");

	while(point != NULL)
	{
		commands.push_back(point);
		point = strtok(NULL, ";");

	}

	for(int i = 0; i < commands.size(); i++)
	{
		if(commands.at(i)[0] == ' ')
		{
			commands.at(i)++;
		}
	}

	vector<vector<char* > > commandList;
	vector<char* >separateCommands;
	char* sample;
	for(int i = 0; i < commands.size(); i++)
	{
		sample = strtok(commands.at(i), " ");
		while(sample != NULL)
		{	
			separateCommands.push_back(sample);
			sample = strtok(NULL, " ");
		}

		commandList.push_back(separateCommands);

		separateCommands.clear();
	}

	//commandList.push_back(commands);	

	for(int i = 0; i < commandList.size(); i++)
	{
		for(int j = 0; j < commandList.at(i).size(); j++)
		cout << commandList.at(i).at(j) << endl;
	}
	



	return 0;
}
