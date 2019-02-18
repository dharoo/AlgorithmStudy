#include "stdio.h"
#include <vector>
#include <string.h>

// �ϳ���ž
// 20���ϱ����� ������ �Բ� ���

// 20�ʰ��� ����Ƚ���� ���, unsigned long long���� result���� ����� overflow�߻�
// ���� string���� ���� ǥ��, PlusNumber(char** curNum, const char* offset) �Լ� ����

using namespace std;

vector<pair<int, int>> MovePair;

int result = 0;

// n���� disk�� from���� to�� �Űܶ�
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
// curNum >= offset�� �����Ҷ� ����
void PlusNumber(char** curNum, const char* offset)
{
	int len = strlen(*curNum);
	char *newNum = new char[len + 2];
	newNum[len + 1] = '\0';
	strcpy(newNum + 1, *curNum);

	int offsetLen = strlen(offset);
	// ���� �ڸ��� �ö󰡴� ��
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

	// ���ο� �ڸ����� �ʿ��� ���
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
		
		// �Ʒ� �Լ� �����, �ð��ʰ�
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