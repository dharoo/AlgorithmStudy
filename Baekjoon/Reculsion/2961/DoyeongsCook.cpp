#include <math.h>
#include <iostream>
#include <vector>

int m_nMax = 1000000000;
int anChecks[10] = { false };

struct STTaste {
	int nS;
	int nB;

	STTaste(int a_nS, int a_nB)
		:
		nS(a_nS),
		nB(a_nB)
	{}
};

std::vector<STTaste*> m_oTasteList;


void Cooking(int a_nSize, int a_nDepth)
{
	int nS = 1;
	int nB = 0;
	int nT = 1000000000;

	if (a_nSize == a_nDepth) {
		for (int i = 0; i < a_nSize; i++) {
			if (anChecks[i]) {
				nB += m_oTasteList[i]->nB;
				nS *= m_oTasteList[i]->nS;
				nT = nB - nS;

				if (nT < 0) nT *= -1;
			}
		}

		if (m_nMax > nT) m_nMax = nT;

		return;
	}

	anChecks[a_nDepth] = false;
	Cooking(a_nSize, a_nDepth + 1);

	anChecks[a_nDepth] = true;
	Cooking(a_nSize, a_nDepth + 1);
}

int main(void)
{
	int nSize = 0;

	scanf("%d", &nSize);

	for (int i = 0; i < nSize; ++i) {
		int nS = 0;
		int nB = 0;
		scanf("%d %d", &nS, &nB);

		STTaste* newMat = new STTaste(nS, nB);
		m_oTasteList.push_back(newMat);
	}

	Cooking(nSize, 0);

	printf("%d\n", m_nMax);
	return 0;
}