#include <iostream>
//문제
/*
문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

2 -> 2
9 -> 55
*/

/*
	2 x N 직사각형에서
	N : 1 -> 1
	N : 2 -> 2
	N : 3 -> 3
	N : 4 -> 5
	N : 5 -> 8
	.
	.
	.
	-> 피보나치
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