#include "stdio.h"
#include <math.h>
#include <vector>

// 문제 1782 거울숫자
// N이 주어질 때, N 이하의 자연수 중에 거울에 비춰봤을 때 대칭이 되는 숫자를 찾아라 
// 0, 1, 8
// 2 & 5

// 시간제한 1초, 메모리제한 64MB

// 실행결과 - 메모리 초과
// long long 크기 8byte -> 64*1000 / 8 = 8000개
// 0 10000000000000000 실행결과 624999로 메모리 overflow



// n-bit 숫자 중 거울 숫자를 찾고, 거울숫자가 되는 숫자를 앞, 뒤로 붙여서 (n+2)-bit 숫자 중 거울 숫자를 만들어낸다.
// 그 후, a~b까지 중 거울숫자를 찾을때, (b까지 거울숫자) - ((a-1)까지 거울숫자)를 구한다
using namespace std;

// MirrorNumbers[len]은 길이가 len인 거울숫자들 - 편의를 위해 MirrorNumbers[1]부터 시작, MirrorNumbers[0]에는 0을 추가하였다.
vector<vector<long long>> MirrorNumbers;

// Self Mirror number인 (1, 1), (8, 8)과 (2, 5), (5, 2)
vector<pair<int, int>> MirrorPairs;


// 주어진 숫자의 길이(?)를 반환한다
int GetLengthOfNum(long long n)
{
	int len = 1;

	while (n >= 10)
	{
		n /= 10;
		len++;
	}

	return len;
}

// 0 ~ n까지 숫자 중 거울숫자의 갯수를 반환한다
int GetNumOfMirrorNumbers(long long n)
{
	if (n < 0) return 0;

	int len = GetLengthOfNum(n);
	int num = 0;
	
	for (int i = 1; i <= len - 1; ++i)
	{
		num += MirrorNumbers[i].size();
	}

	auto mirrorNumbrs = MirrorNumbers[len];

	for (int i = 0; i < mirrorNumbrs.size(); ++i)
	{
		if (n >= mirrorNumbrs[i])
		{
			num += 1;
		}
	}

	return num;
}

// 길이가 len인 숫자 중 거울숫자를 찾아 MirrorNumbers[len]에 담는다.
void FindMirrorNumbers(int len)
{
	if (len == 1)
	{
		MirrorNumbers[len].push_back(0);
		MirrorNumbers[len].push_back(1);
		MirrorNumbers[len].push_back(8);
	}
	else if (len == 2)
	{
		MirrorNumbers[len].push_back(11);
		MirrorNumbers[len].push_back(25);
		MirrorNumbers[len].push_back(52);
		MirrorNumbers[len].push_back(88);
	}
	else
	{
		for (int i = 0; i < MirrorNumbers[len - 2].size(); ++i)
		{
			for (int j = 0; j < MirrorPairs.size(); ++j)
			{
				long long num = MirrorNumbers[len - 2][i];
				num += MirrorPairs[j].first * powl(10, len - 2);
				num *= 10;
				num += MirrorPairs[j].second;

				MirrorNumbers[len].push_back(num);
			}
		}

		// a-th MSB, a-th LSB 숫자가 0인경우
		if (len >= 4)
		{
			// MSB, LSB, 2nd MSB, 2nd LSB를 제외한 길이부터 시작
			int curLen = len - 4;
			int idxMsb = len - 3;
			int idxLsb = 2;

			while (curLen >= 0)
			{
				for (int i = 0; i < MirrorNumbers[curLen].size(); ++i)
				{
					for (int j = 0; j < MirrorPairs.size(); ++j)
					{
						long long num = MirrorNumbers[curLen][i];
						num += MirrorPairs[j].first * powl(10, idxMsb);
						num *= powl(10, idxLsb);
						num += MirrorPairs[j].second;

						MirrorNumbers[len].push_back(num);
					}
				}
				curLen -= 2;
				idxMsb -= 1;
				idxLsb += 1;
			}
		}
	}
}

int main()
{
	long long from = 0, to = 0;
	scanf("%lli %lli", &from, &to);

	// MirrorNumbers[i]에는 i자릿수를 가지는 숫자들중 MirrorNumber의 vector를 저장한다.
	MirrorNumbers.assign(GetLengthOfNum(to) + 1, vector<long long>());
	MirrorNumbers[0].push_back(0);

	MirrorPairs.push_back(make_pair(1, 1));
	MirrorPairs.push_back(make_pair(2, 5));
	MirrorPairs.push_back(make_pair(5, 2));
	MirrorPairs.push_back(make_pair(8, 8));

	for (int i = 1; i <= GetLengthOfNum(to); ++i)
	{
		FindMirrorNumbers(i);
	}

	int result = GetNumOfMirrorNumbers(to) - GetNumOfMirrorNumbers(from-1);

	printf("%d", result);

	return 0;
	
}