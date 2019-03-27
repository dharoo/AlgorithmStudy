#include "josepus.h"
#include <iostream>
#include <vector>

/*
�����۽� ������ ������ ����.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� M(�� N)�� �־�����. 
���� ������� M��° ����� �����Ѵ�. 
�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. 
�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. 
������ ������� ���ŵǴ� ������ (N, M)-�����۽� �����̶�� �Ѵ�.
���� ��� (7, 3)-�����۽� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� M�� �־����� (N,M)-�����۽� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� M�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� M �� N �� 5,000)

���
������ ���� �����۽� ������ ����Ѵ�.

���� �Է� 
7 3
���� ��� 
<3, 6, 2, 7, 5, 1, 4>
*/
namespace josepus
{
	//N : ��� ��
	//M : ���� ��ȣ
	std::vector<int> list;
	std::vector<int>::iterator iter;
	int N, M = 0;

	int main(void)
	{
		scanf("%d %d", &N, &M);
		
		for (int i = 1; i < N + 1; ++i)
		{
			list.push_back(i);
		}
		printf("<");
	
		iter = list.begin();
	
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M - 1; ++j)
			{
				++iter;
				if (iter == list.end())
				{
					iter = list.begin();
				}
			}
	
			printf("%d", *iter);
			iter = list.erase(iter);

			if (iter == list.end())
			{
				iter = list.begin();
			}

			if (i < N - 1)
			{
				printf(", ");
			}
		}
		
		printf(">");
	
		return 0;
	}
	
}
