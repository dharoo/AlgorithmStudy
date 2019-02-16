#include <math.h>
#include <iostream>
#include <vector>

int m_nMaximum = 1000000000;

struct STTaste{
	int nS;
	int nB;

	STTaste(int a_nS, int a_nB)
		:
		nS(a_nS),
		nB(a_nB)
	{}
};

std::vector<STTaste*> m_oMaterialVector;

int set[10] = { 1,2,3,4,5,6,7,8,9,10 };
int flag[10] = { false };

void Cooking(int a_nSize, int a_nDepth)
{
	int nS = 1;
	int nB = 0;
	int nTaste = 1000000000;

	if (a_nSize == a_nDepth){
		for (int i = 0; i < a_nSize; i++){
			if (flag[i]){
				nB += m_oMaterialVector[i]->nB;
				nS *= m_oMaterialVector[i]->nS;
				nTaste = nB - nS;

				if (nTaste < 0) nTaste *= -1;
			}
		}

		if (m_nMaximum > nTaste) m_nMaximum = nTaste;

		return;
	}

	flag[a_nDepth] = false;
	Cooking(a_nSize, a_nDepth + 1);

	flag[a_nDepth] = true;
	Cooking(a_nSize, a_nDepth + 1);
}

int main(void)
{
	int nSize = 0;

	scanf("%d", &nSize);

	for (int i = 0; i < nSize; ++i){
		int nS = 0;
		int nB = 0;
		scanf("%d %d", &nS, &nB);

		STTaste* newMat = new STTaste(nS, nB);
		m_oMaterialVector.push_back(newMat);
	}

	Cooking(nSize, 0);

	printf("%d\n", m_nMaximum);
	return 0;
}