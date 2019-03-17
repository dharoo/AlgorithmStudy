#define BF_SIZE 1001

#include <cstdio>
#include <algorithm>
#include <cstring>

int cache[BF_SIZE];

long long GetNumOfTiling(int n)
{
	// base case - 없어도됨, 아래 캐시에서 체크
	if (n <= 2) return cache[n];

	// cache check
	if (cache[n] != 0) return cache[n];

	// |== 로 시작하는경우와 ||, == 로 시작하는경우
	long long result = GetNumOfTiling(n - 3) % 10007 + GetNumOfTiling(n - 2) % 10007 * cache[2];

	return cache[n] = result % 10007;
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	memset(cache, 0, BF_SIZE * sizeof(int));
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;

	int result = GetNumOfTiling(n);
	printf("%d", result);

	return 0;
}
