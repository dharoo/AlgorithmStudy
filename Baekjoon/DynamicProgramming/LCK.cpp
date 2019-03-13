#include "LCK.h"
#include <queue>
/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때,
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며,
최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

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

		printf("메인 단어 입력 :");
		fgets(oSent, 1000, stdin);
		char *ptr = strtok(oSent, "\0");
		for (int i = 0; i < strlen(ptr) - 1; ++i)
		{
			oMainQueue.push(ptr[i]);
		}

		printf("서브 단어 입력 :");
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

