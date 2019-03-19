#include <iostream>
//����
/*
����
2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

2 -> 2
9 -> 55
*/

/*
	2 x N ���簢������
	N : 1 -> 1
	N : 2 -> 2
	N : 3 -> 3
	N : 4 -> 5
	N : 5 -> 8
	.
	.
	.
	-> �Ǻ���ġ
*/
int main(void)
{
	int N = 0;
	scanf("%d", &N);
	int* anResult = 0;
	anResult = (int*)malloc(sizeof(int*) * N);
	anResult[0] = 1;
	anResult[1] = 1;

	for (int i = 1; i < N; ++i)
	{
		anResult[i+1] = (anResult[i] + anResult[i - 1]) % 10007;
	}

	printf("%d", anResult[N]);

	return 0;
}