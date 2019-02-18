#include "stdio.h"
#include <vector>
#include <string.h>

// 하노이탑
// 20이하까지는 과정도 함께 출력

// 20초과시 실행횟수만 출력, unsigned long long으로 result변수 저장시 overflow발생
// 따라서 string으로 숫자 표현, PlusNumber(char** curNum, const char* offset) 함수 구현

using namespace std;

vector<pair<int, int>> MovePair;

int result = 0;

// n개의 disk를 from에서 to로 옮겨라
void Hanoi(int n, int from, int to, int mid)
{
	if (n == 1)
	{
		MovePair.push_back(make_pair(from, to));
	}
	else
	{
		Hanoi(n - 1, from, mid, to);
		MovePair.push_back(make_pair(from, to));
		Hanoi(n - 1, mid, to, from);
	}
}

// curNum + offset
// curNum >= offset이 성립할때 동작
void PlusNumber(char** curNum, const char* offset)
{
	int len = strlen(*curNum);
	char *newNum = new char[len + 2];
	newNum[len + 1] = '\0';
	strcpy(newNum + 1, *curNum);

	int offsetLen = strlen(offset);
	// 다음 자릿수 올라가는 수
	int carry = 0;
	
	int num = newNum[len] - '0' + offset[offsetLen - 1] - '0' + carry;
	
	while (offsetLen > 0 || (len > 0 && offsetLen > 0 && num > 9))
	{
		if (num > 9)
		{
			newNum[len] = (num - 10) + '0';
			carry = 1;
		}
		else
		{
			newNum[len] = num + '0';
			carry = 0;
		}
		len--;
		offsetLen--;
		num = newNum[len] - '0' + offset[offsetLen - 1] - '0' + carry;
	}

	// 새로운 자릿수가 필요한 경우
	if (len <= 0 && carry == 1)
	{
		newNum[0] = '1';
		*curNum = new char[strlen(newNum) + 1];
		strcpy(*curNum, newNum);
	}
	else
	{
		newNum = newNum + 1;
		strcpy(*curNum, newNum);
		newNum -= 1;
	}
	
	delete[] newNum;
}

void HanoiBig(int n, int from, int to, int mid, char** curNum)
{
	if (n == 1)
	{
		PlusNumber(curNum, "1");
	}
	else
	{
		HanoiBig(n - 1, from, mid, to, curNum);
		PlusNumber(curNum, *curNum);
		PlusNumber(curNum, "1");
		
		// 아래 함수 수행시, 시간초과
		//HanoiBig(n - 1, mid, to, from, curNum);
	}
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	if (num <= 20)
	{
		Hanoi(num, 1, 3, 2);

		printf("%d\n", MovePair.size());

		for (auto iter = MovePair.begin(); iter != MovePair.end(); ++iter)
		{
			printf("%d %d\n", iter->first, iter->second);
		}
	}
	else
	{
		char* str = new char[2];
		str[0] = '0';
		str[1] = '\0';
		HanoiBig(num, 1, 3, 2, &str);

		printf("%s", str);
	}

	return 0;
}