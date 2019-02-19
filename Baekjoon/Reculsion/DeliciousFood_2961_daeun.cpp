/*
	2961 도영이가 만든 맛있는 음식
	음식의 신맛은 사용한 재료의 신맛의 곱이고, 쓴맛은 합이다.

	입력: 재료의 개수 N(1 ≤ N ≤ 10), 신맛과 쓴맛이 공백으로 구분
		  신맛과 쓴맛은 모두 1,000,000,000보다 작은 양의 정수
	출력: 신맛과 쓴맛의 차이가 가장 작은 요리의 차이
*/

#define INT_MAX 2147483647

#include "stdio.h"
#include <stdlib.h>
#include <vector>

using namespace std;

vector<pair<int, int>> ingredients;
vector<pair<int, int>> flavors;

int GetDiffer(pair<int, int> flavor)
{
	return abs(flavor.first - flavor.second);
}

void FindFlavorsUntil(int idx)
{
	auto newFlavor = ingredients[idx];

	flavors.push_back(newFlavor);
	
	int size = flavors.size() - 1;

	for (int i = 0; i < size; ++i)
	{
		flavors.push_back(make_pair(flavors[i].first*newFlavor.first, flavors[i].second + newFlavor.second));
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	ingredients.assign(n, pair<int,int>());

	while (n--)
	{
		scanf("%d %d", &ingredients[n].first, &ingredients[n].second);
	}

	flavors.push_back(ingredients[0]);

	for (int i = 1; i < ingredients.size(); ++i) 
	{
		FindFlavorsUntil(i);
	}

	int result = INT_MAX;

	for (int i = 0; i < flavors.size(); ++i)
	{
		if (result > GetDiffer(flavors[i]))
		{
			result = GetDiffer(flavors[i]);
		}
	}
	
	printf("%d\n", result);

	return 0;
}