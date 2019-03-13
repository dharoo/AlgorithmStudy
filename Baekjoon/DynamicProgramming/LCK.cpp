#include "LCK.h"
#include <queue>
/*
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��,
����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������,
�ִ� 1000���ڷ� �̷���� �ִ�.

���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.

ACAYKP
CAPCAK

ACAK -> 4

*/

namespace LCK
{
	void LCKMake(std::queue<char> a_oMain, std::queue<char> a_oSub)
	{
		int nResult = 0;
		char szMain = ' ';
		char szSub = ' ';

		while (true)
		{
			szMain = a_oMain.front();
			szSub = a_oSub.front();

			if (szMain != szSub)
			{
				if (a_oSub.size() != 1)
				{
					a_oSub.pop();
				}
				else 
				{
					a_oMain.pop();
				}
			}
			else
			{
				a_oMain.pop();
				a_oSub.pop();
				nResult++;
				//oResult.push_back(szMain);
			}

			if (a_oMain.size() < 1 || a_oSub.size() < 1)
			{
				//printf("\n%s, %d\n", oResult.c_str(), nResult);
				printf("%d", nResult);
				break;
			}
		}
	}

	int main(void)
	{
		char oSent[1000];
		std::queue<char> oMainQueue;
		std::queue<char> oSubQueue;

		printf("���� �ܾ� �Է� :");
		fgets(oSent, 1000, stdin);
		char *ptr = strtok(oSent, "\0");
		for (int i = 0; i < strlen(ptr) - 1; ++i)
		{
			oMainQueue.push(ptr[i]);
		}

		printf("���� �ܾ� �Է� :");
		fgets(oSent, 1000, stdin);
		ptr = strtok(oSent, "\0");
		for (int i = 0; i < strlen(ptr) - 1; ++i)
		{
			oSubQueue.push(ptr[i]);
		}

		LCKMake(oMainQueue, oSubQueue);

		return 0;
	}
}
