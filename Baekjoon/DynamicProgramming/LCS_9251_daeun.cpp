/*
LCS 9251
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, 
����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� ����

�ð����� 1��
�޸����� 256MB
*/

#define MAX_STR_LEN 1000

#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

char strA[MAX_STR_LEN] = "";
char strB[MAX_STR_LEN] = "";

// strA + idxA, strB + idxB �� LCS
vector<int> cache;

int GetIndex(int idxA, int idxB)
{
	return idxA * strlen(strB) + idxB;
}

// ���
int FindLCS(int idxA, int idxB)
{
	if (strA[idxA] == '\0' || strB[idxB] == '\0') return 0;

	int idx = GetIndex(idxA, idxB);
	if (cache[idx] != -1) return cache[idx];

	int LCSLen = 0;

	if (strA[idxA] == strB[idxB])
	{
		LCSLen = FindLCS(idxA + 1, idxB + 1) + 1;
	}
	else
	{
		int lenA = FindLCS(idxA, idxB + 1);
		int lenB = FindLCS(idxA + 1, idxB);
		LCSLen = std::max(lenA, lenB);
	}

	return cache[idx] = LCSLen;
}

// �ð��ʰ�
int FindLCS(char* strA, char* strB, int curLen)
{
	if (strA[0] == '\0' || strB[0] == '\0') return curLen;

	if (strA[0] == strB[0])
	{
		return FindLCS(strA + 1, strB + 1, curLen + 1);
	}
	else
	{
		int lenA = FindLCS(strA, strB + 1, curLen);
		int lenB = FindLCS(strA + 1, strB, curLen);
		return std::max(lenA, lenB);
	}
}

int main()
{
	fgets(strA, sizeof(strA), stdin);
	fgets(strB, sizeof(strB), stdin);

	strA[strlen(strA)-1] = '\0';
	strB[strlen(strB)-1] = '\0';

	cache.assign(strlen(strA)*strlen(strB), -1);

	int len = FindLCS(0, 0);
	printf("%d", len);

	return 0;
}