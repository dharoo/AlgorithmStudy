#include <cstdio>
#include <algorithm>
#include <cstring>

int* cache;

int FindNumofOp(int n)
{
	if (n == 1) return 0;

	if (cache[n] != 0) return cache[n];

	int result = FindNumofOp(n - 1);

	if (n % 3 == 0)
	{
		result = std::min(result, FindNumofOp(n / 3));
	}

	if (n % 2 == 0)
	{
		result = std::min(result, FindNumofOp(n / 2));
	}

	return cache[n] = result + 1;
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	cache = new int[n + 1];
	memset(cache, 0, (n + 1) * sizeof(int));

	int result = FindNumofOp(n);
	printf("%d\n", result);

	return 0;
}