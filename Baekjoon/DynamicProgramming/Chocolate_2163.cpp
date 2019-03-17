#include <cstdio>
#include <algorithm>

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	int result = std::min(n, m)*std::max(n - 1, m - 1) + std::min(n - 1, m - 1);
	printf("%d", std::max(result, 1));

	return 0;
}