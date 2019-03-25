#include <cstdio>
#include <list>
#include <string>

using namespace std;

int main()
{
	list<int> numList;

	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
	{
		numList.push_back(i);
	}

	auto iter = numList.begin();
	
	printf("<"); 
	
	while (numList.size() > 1)
	{
		for (int i = 0; i < m - 1; ++i)
		{
			iter++;
			if (iter == numList.end()) iter = numList.begin();
		}

		printf("%d, ", *iter);
		
		iter = numList.erase(iter);
		if (iter == numList.end()) iter = numList.begin();
	}

	printf("%d>", *iter);
	
	return 0;
}