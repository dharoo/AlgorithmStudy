#define BF_SIZE 301

#include <cstdio>
#include <algorithm>
#include <cstring>

int cache[BF_SIZE][BF_SIZE];

int CutChocolate(int n, int m)
{
	if (n == 1 || m == 1)
	{
		return n * m - 1;
	}

	if (cache[n][m] != 0) return cache[n][m];

	int result = 0;

	if (n > m)
	{
		result = CutChocolate(n, m - 1) + CutChocolate(n, 1);
	}
	else
	{
		result = CutChocolate(n - 1, m) + CutChocolate(1, m);
	}

	return cache[n][m] = result + 1;
}

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	memset(cache, 0, BF_SIZE *BF_SIZE * sizeof(int));

	int result = CutChocolate(n, m);

	printf("%d", std::max(result, 1));

	return 0;
}