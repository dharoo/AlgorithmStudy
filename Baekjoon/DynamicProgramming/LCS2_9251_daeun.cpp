/*
LCS 9251
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제
시간제한 1초
메모리제한 256MB
*/
#define MAX_STR_LEN 1000

#include <cstdio>
#include <algorithm>
#include <cstring>

// main내에서 선언하면 터진다. 스택영역, 데이터영역 크기가 다르기때문?
int lcs[MAX_STR_LEN][MAX_STR_LEN];

int main()
{
	char strA[MAX_STR_LEN] = "";
	char strB[MAX_STR_LEN] = "";

	fgets(strA, sizeof(strA), stdin);
	fgets(strB, sizeof(strB), stdin);

	strA[strlen(strA) - 1] = '\0';
	strB[strlen(strB) - 1] = '\0';

	memset(lcs, 0, sizeof(lcs));

	for (int i = 0; i < strlen(strA); ++i)
	{
		for (int j = 0; j < strlen(strB); ++j)
		{
			if (strA[i] == strB[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
			else
			{
				lcs[i + 1][j + 1] = std::max(lcs[i + 1][j], lcs[i][j + 1]);
			}
		}
	}

	printf("%d", lcs[strlen(strA)][strlen(strB)]);

	return 0;
}
