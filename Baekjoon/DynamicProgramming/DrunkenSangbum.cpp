#include "DrunkenSangbum.h"
#include <iostream>
#include <vector>
/*
	n���� ���� �Ϸķ� �þ ������ �ִ�. 
	
	������ ù ��° ���忡�� ������ �� ���� ��� ����. 
	�� ���� ���忡���� 2, 4, 6, ... �� ���� �ٽ� ��װ�, 
	�� ��° ���忡���� 3, 6, 9, ... �� ���� ���������� ��װ�, ����ִٸ� ����. 
	k��° ���忡���� ��ȣ�� k�� ����� ���� ���� ������ ��װ�, ��� �ִٸ� ����.
	�̷��� n��° ������� ������ ���� ������ ����.
	
	�л����� ����̰� ���������ȴ� ���� ���ݰ� ��� ����ģ��.
	
	���� ������ �־����� ��, �� ���� �л����� ������ �� �ִ��� �˾ƺ���.
	
	�Է��� ù ��° �ٿ��� �׽�Ʈ�� Ƚ�� T�� �־�����. 
	�� �׽�Ʈ ���̽��� �� �ٿ� �� ���� ���� ���� n(5 �� n �� 100)�� �־�����.

	�� �ٿ� �� ���� �� �׽�Ʈ ���̽��� ��, �� �� ���� Ż���� �� �ִ����� ����Ѵ�.

	�Է� : 
	2
	5
	100

	��� :
	2
	10
*/

std::vector<int> m_vCases;
std::vector<int> m_vResult;

namespace DrunkenSangbum
{
	//a_nLevel : ���� ����
	//a_nRooms : ���ƾ� �� �� ���� ����
	//a_nArray : �� ������ Ȯ��(1 : ����, 0 : ����)
	void mainGame(int a_nLevel, int a_nRooms, std::vector<int> a_vResult)
	{
		//����� �� ���� ��ȣ
		int nCurrentValue = a_nLevel;

		//!�� ��ȣ�� �ִ񰪺��� ������
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
