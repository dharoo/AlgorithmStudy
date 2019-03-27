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
			printf("\nĿ�� : %c\n", *iter);
		}
		else
		{
			printf("\nĿ�� : end\n");
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
		printf("=====����Ʈ ���=====\n");
		for (auto aa : list)
		{
			printf("%c", aa);
		}
		printf("\n");
	}

	int main(void)
	{
		//�Է�
		std::cin >> aa;

		for (auto bb : aa)
		{
			list.push_back(bb);
		}

		//��ɾ� ����
		scanf("%d", &nSize);
		printf("\n�Է� : %d\n", nSize);
		iter = list.end();

		while (nSize > 0)
		{
			//��ɾ� �Է�
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
				printf("\n���� : %c\n", command[0]);
			}

			nSize--;
			printf("\n���� �� : %d\n", nSize);
		}
		
		printList();
		
		return 0;
	}
}
