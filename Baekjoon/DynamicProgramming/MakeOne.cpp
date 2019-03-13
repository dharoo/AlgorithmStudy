#include "MakeOne.h"
#include <iostream>
/*
	정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
	
	X가 3으로 나누어 떨어지면, 3으로 나눈다.
	X가 2로 나누어 떨어지면, 2로 나눈다.
	1을 뺀다.

	정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
	연산을 사용하는 횟수의 최솟값을 출력하시오.
	
	입력
	첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.
	
	출력
	첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
*/
namespace MakeOne
{
	int m_nResult = INT_MAX;

	//연산할 때 마다 a_nLevel + 1
	void Making(int a_nValue, int a_nLevel)
	{
		//값이 1일 때
		if (a_nValue == 1)
		{
			//결과값이 현재 레벨보다 크면
			if (m_nResult > a_nLevel)
			{
				//결과값을 바꿈
				m_nResult = a_nLevel;
				return;
			}
		}
		else if (a_nValue < 1)
		{
			return;
		}

		//!3으로 나누어 떨어지면
		if (a_nValue % 3 == 0)
		{
			Making(a_nValue / 3, a_nLevel + 1);
		}

		//!2로 나누어 떨어지면
		if (a_nValue % 2 == 0)
		{
			Making(a_nValue / 2, a_nLevel + 1);
		}

		//!그냥 1 빼기
		Making(a_nValue - 1, a_nLevel + 1);
	}

	int main(void)
	{
		int nValue = 0;
		printf("숫자 입력 : ");
		scanf("%d", &nValue);

		Making(nValue, 0);

		printf("결과 : %d\n", m_nResult);

		return 0;
	}
}
