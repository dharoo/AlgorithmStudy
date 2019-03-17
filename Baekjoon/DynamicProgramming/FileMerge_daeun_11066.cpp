#define BF_SIZE 501
#define INT_MAX 2147483647

#include <cstdio>
#include <algorithm>
#include <cstring>

short files[BF_SIZE];
int cache[BF_SIZE][BF_SIZE];

int GetMergeCost(int start, int end)
{
	// base cases
	if (start >= end) return 0;
	if (end - start == 1) return files[start] + files[end];

	if (cache[start][end] != 0) return cache[start][end];

	int minCost = INT_MAX;

	for (int i = start; i < end; ++i)	// a ~ b, b + 1 ~ c의 모든 경우를 생각해야한다!
	{
		int cost = 0;
		cost += GetMergeCost(start, i);
		cost += GetMergeCost(i + 1, end);

		minCost = std::min(cost, minCost);
	}

	for (int i = start; i <= end; ++i) minCost += files[i];

	return cache[start][end] = minCost;
}

int main()
{
	int t = 0;
	scanf("%d", &t);

	memset(files, 0, BF_SIZE * sizeof(int));

	while (t--)
	{
		int k = 0;
		scanf("%d", &k);
		
		memset(cache, 0, BF_SIZE*BF_SIZE * sizeof(int));	// memset은 각 테스트케이스마다 필요!

		for (int i = 0; i < k; ++i)
		{
			scanf("%hd", &files[i]);
		}

		int result = GetMergeCost(0, k - 1);
		printf("%d\n", result);
	}

	return 0;
}
