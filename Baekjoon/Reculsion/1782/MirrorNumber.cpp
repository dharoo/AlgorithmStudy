#include "MirrorNumber.h"
#include <iostream>
#include <math.h>
#include <string.h>

namespace MirrorNumber
{
	int m_nStart = 0;
	int m_nEnd = 0;
	int m_nResult = 0;

	void monkeyMagic(int* a_nValue)
	{
		int nLength = (int)log10(*a_nValue) + 1;
		if (*a_nValue == 0)  nLength = 1;

		char *pszStr = (char*)malloc(sizeof(char*) * (nLength + 1));

		bool clear = true;
		if (*a_nValue == m_nEnd + 1) return;

		sprintf(pszStr, "%d", *a_nValue);

		for (int i = 0; i < nLength; ++i) {

			char start = pszStr[i];
			char end = pszStr[(nLength - 1) - i];

			int nStart = atoi(&start);
			int nEnd = atoi(&end);

			if (nStart == 3 || nStart == 4 || nStart == 6 || nStart == 7 || nStart == 9 ||
				nEnd == 3 || nEnd == 4 || nEnd == 6 || nEnd == 7 || nEnd == 9) {
				clear = false;
				break;
			}

			if ((nStart != nEnd)) {
				if ((nStart == 2 && nEnd == 5) || (nStart == 5 && nEnd == 2)) continue;
				else clear = false;
			}

			if (nStart == nEnd){
				if (nStart == 0 || nStart == 1 || nStart == 8) continue;
				else clear = false;
			}
		}

		if (clear) m_nResult++;
		
		free(pszStr);

		*a_nValue += 1;
		if (*a_nValue < m_nEnd) monkeyMagic(a_nValue);
	}

	int main(void)
	{
		scanf("%d %d", &m_nStart, &m_nEnd);

		monkeyMagic(&m_nStart);

		printf("%d", m_nResult);

		system("pause");
		return 0;
	}
}