#include "DrunkenSangbum.h"
#include <iostream>
#include <vector>
/*
	n개의 방이 일렬로 늘어선 감옥이 있다. 
	
	게임의 첫 번째 라운드에서 감옥을 한 개씩 모두 연다. 
	그 다음 라운드에서는 2, 4, 6, ... 번 방을 다시 잠그고, 
	세 번째 라운드에서는 3, 6, 9, ... 번 방이 열려있으면 잠그고, 잠겨있다면 연다. 
	k번째 라운드에서는 번호가 k의 배수인 방이 열려 있으면 잠그고, 잠겨 있다면 연다.
	이렇게 n번째 라운드까지 진행한 이후 쓰러져 잠든다.
	
	학생들은 상범이가 쓰러져버렸단 것을 깨닫고 즉시 도망친다.
	
	방의 개수가 주어졌을 때, 몇 명의 학생들이 도주할 수 있는지 알아보자.
	
	입력의 첫 번째 줄에는 테스트의 횟수 T가 주어진다. 
	각 테스트 케이스는 한 줄에 한 개씩 방의 개수 n(5 ≤ n ≤ 100)이 주어진다.

	한 줄에 한 개씩 각 테스트 케이스의 답, 즉 몇 명이 탈출할 수 있는지를 출력한다.

	입력 : 
	2
	5
	100

	출력 :
	2
	10
*/

std::vector<int> m_vCases;
std::vector<int> m_vResult;

namespace DrunkenSangbum
{
	//a_nLevel : 현재 레벨
	//a_nRooms : 돌아야 할 총 방의 개수
	//a_nArray : 방 열린것 확인(1 : 열림, 0 : 닫힘)
	void mainGame(int a_nLevel, int a_nRooms, std::vector<int> a_vResult)
	{
		//열어야 할 방의 번호
		int nCurrentValue = a_nLevel;

		//!방 번호가 최댓값보다 작으면
		while (nCurrentValue < a_nRooms + 1)
		{
			int nValue = a_vResult[nCurrentValue];

			if (nValue == 0)
			{
				a_vResult[nCurrentValue] = 1;
			}
			else
			{
				a_vResult[nCurrentValue] = 0;
			}

			nCurrentValue += a_nLevel;
		}

		if (a_nLevel < a_nRooms)
		{
			mainGame(a_nLevel + 1, a_nRooms, a_vResult);
		}
		else
		{
			int nResult = 0;
			for (int i = 0; i < a_nRooms + 1; ++i)
			{
				int nValue = a_vResult[i];
				nResult += nValue;
			}

			printf("%d\n", nResult);
		}
		return;
	}


	void sangbumsGame(int a_nLevel)
	{
		for (int i = 0; i < a_nLevel; ++i)
		{
			int nSize = m_vCases[i];

			for (int i = 0; i < nSize+1; ++i)
			{
				m_vResult.push_back(0);
			}
			mainGame(1, nSize, m_vResult);
		}
	}


	int main(void)
	{
		int nTestCase = 0;
		scanf("%d", &nTestCase);

		for (int i = 0; i < nTestCase; ++i)
		{
			int nValue = 0;
			scanf("%d", &nValue);

			m_vCases.push_back(nValue);
		}

		sangbumsGame(nTestCase);

		return 0;
	}
}
