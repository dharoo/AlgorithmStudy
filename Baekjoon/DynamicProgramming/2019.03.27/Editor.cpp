#include "Editor.h"
#include <iostream>
#include <string>
#include <vector>

namespace Editor 
{
	std::string aa;
	int nSize = 0;
	char command[3];
	std::vector<char> list;
	std::vector<char>::iterator iter;

	void printCursor()
	{
		system("cls");
		printList();
		if (iter != list.end())
		{
			printf("\n커서 : %c\n", *iter);
		}
		else
		{
			printf("\n커서 : end\n");
		}
	}
	/*
	void commandL()
	{
		if (iter != list.begin())
		{
			iter--;
		}
		printCursor();
	}

	void commandD()
	{
		if (iter != list.end())
		{
			iter++;
		}
		printCursor();
	}

	void commandB()
	{
		if (iter != list.begin())
		{
			iter = list.erase(iter - 1);
		}
		printCursor();
	}

	void commandP(char value)
	{
		iter = list.insert(iter, value);
		iter++;	
		printCursor();
	}
	*/
	void printList()
	{
		printf("=====리스트 목록=====\n");
		for (auto aa : list)
		{
			printf("%c", aa);
		}
		printf("\n");
	}

	int main(void)
	{
		//입력
		std::cin >> aa;

		for (auto bb : aa)
		{
			list.push_back(bb);
		}

		//명령어 개수
		scanf("%d", &nSize);
		printf("\n입력 : %d\n", nSize);
		iter = list.end();

		while (nSize > 0)
		{
			//명령어 입력
			//fgets(command, sizeof(command), stdin);
			std::cin >> command;

			if (command[0] == 'L')
			{
				if (iter != list.begin()) iter--;
			}
			else if (command[0] == 'D')
			{
				if (iter != list.end()) iter++;
			}
			else if (command[0] == 'B')
			{
				if (iter != list.begin()) iter = list.erase(iter - 1);
			}
			else if (command[0] == 'P')
			{
				iter = list.insert(iter, command[2]);
				iter++;
			}
			else
			{
				printf("\n에러 : %c\n", command[0]);
			}

			nSize--;
			printf("\n남은 수 : %d\n", nSize);
		}
		
		printList();
		
		return 0;
	}
}
