#include "MakeOne.h"
#include <iostream>
/*
	���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
	
	X�� 3���� ������ ��������, 3���� ������.
	X�� 2�� ������ ��������, 2�� ������.
	1�� ����.

	���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�.
	������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
	
	�Է�
	ù° �ٿ� 1���� ũ�ų� ����, 10^6���� �۰ų� ���� ���� N�� �־�����.
	
	���
	ù° �ٿ� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.
*/
namespace MakeOne
{
	int m_nResult = INT_MAX;

	//������ �� ���� a_nLevel + 1
	void Making(int a_nValue, int a_nLevel)
	{
		//���� 1�� ��
		if (a_nValue == 1)
		{
			//������� ���� �������� ũ��
			if (m_nResult > a_nLevel)
			{
				//������� �ٲ�
				m_nResult = a_nLevel;
				return;
			}
		}
		else if (a_nValue < 1)
		{
			return;
		}

		//!3���� ������ ��������
		if (a_nValue % 3 == 0)
		{
			Making(a_nValue / 3, a_nLevel + 1);
		}

		//!2�� ������ ��������
		if (a_nValue % 2 == 0)
		{
			Making(a_nValue / 2, a_nLevel + 1);
		}

		//!�׳� 1 ����
		Making(a_nValue - 1, a_nLevel + 1);
	}

	int main(void)
	{
		int nValue = 0;
		printf("���� �Է� : ");
		scanf("%d", &nValue);

		Making(nValue, 0);

		printf("��� : %d\n", m_nResult);

		return 0;
	}
}
