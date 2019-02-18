#include "stdio.h"
#include <math.h>

// 문제 1782 거울숫자
// N이 주어질 때, N 이하의 자연수 중에 거울에 비춰봤을 때 대칭이 되는 숫자를 찾아라 
// 0, 1, 8
// 2 & 5

// 실행결과 - 시간초과

bool IsSelfMirrorNum(int n)
{
	if(n == 0 || n == 1 || n == 8) return true;
	
	return false;
}

bool IsMirrorPair(int a, int b)
{
	if (a == b && IsSelfMirrorNum(a)) return true;

	return (a == 2 && b == 5) || (a == 5 && b == 2);
}

// 몇 번째 자리부터 MirrorNum이 안되는지 (길이가 5인 수인데 4를 리턴하면, 4번째 자리부터 (즉 일의자리부터 실패!))
int GetMirrorImPossibleLength(int n, int len)
{
	while (len-- > 0)
	{
		int MSB = n / powf(10, len);
		if (MSB == 3 || MSB == 4 || MSB == 6 || MSB == 7 || MSB == 9) return len;
		n %= (int) powf(10, len);
	}

	return 0;
}


// GetMirrorImPossibleLength함수로 대체, MirrorNum이 불가능하다면, 몇번째자리때문에 불가능한지
//bool IsMirrorPossible(int n, int len)
//{
//	while (len-- > 0)
//	{
//		int LSB = n % 10;
//		if (LSB == 3 || LSB == 4 || LSB == 6 || LSB == 7 || LSB == 9) return false;
//		n /= 10;
//	}
//
//	return true;
//}

// 주어진 숫자의 길이(?)를 반환한다
int GetLengthOfNum(int n)
{
	int len = 1;

	while (n >= 10)
	{
		n /= 10;
		len++;
	}

	return len;
}

bool IsMirrorNum(int n, int len)
{
	if (len == 1) return IsSelfMirrorNum(n);
	else if (len == 2) return IsMirrorPair(n / 10, n % 10);

	// 길이가 3이상일 때

	// 제일 앞자리 숫자와 뒷자리숫자가 대칭이면, Mirror number의 가능성이 있다
	if (IsMirrorPair(n / pow(10, len - 1), n % 10))
	{
		// 제일 앞자리 수와 뒷자리수를 제거한다
		n = n % (int)(pow(10, len - 1));
		n /= 10;
		//n = n >> 1; -> 이렇게 하는게 아닌지 원하는 결과를 못얻음
		return IsMirrorNum(n, len - 2);
	}

	// 제일 앞자리 숫자와 뒷자리 숫자가 다른경우 Mirror number가 불가능하다
	return false;
}

int main()
{
	int from, to = 0;
	int result = 0;
	
	scanf("%d %d", &from, &to);

	for (int i = from; i <= to; ++i)
	{
		int len = GetLengthOfNum(i);
		
		// 시간을 줄이기위한 노력 1 - MirrorNum이 불가능한 숫자가 포함될경우, IsMirrorNum함수를 실행하지 않는다
		// 0을 리턴하면, MirrorNum이 가능하다
		if (GetMirrorImPossibleLength(i, len) == 0 && IsMirrorNum(i, len))
		{
			result++;
		}
	}

	// 시간을 줄이기위한 노력 2 - MirrorNum이 불가능한 자릿수를 1올려준다
	// ex) 13412의 경우, 3때문에 MirrorNum이 불가하므로, 14000부터 탐색이 가능하도록 한다

	//for (int i = from; i < 10; ++i) 
	//{
	//	if (IsMirrorNum(i, 1)) result += 1;
	//}

	//int min = fmax(10, from);

	//for (int i = min; i <= to; )
	//{
	//	int len = GetLengthOfNum(i);
	//	int ImposLen = GetMirrorImPossibleLength(i, len);

	//	if (ImposLen != 0)
	//	{
	//		i += powf(10, ImposLen);
	//		i -= i % (int)powf(10, ImposLen);
	//	}
	//	else
	//	{
	
	// 시간을 줄이기위한 노력 3 - mirrornum이 발견되면 10의 자리 숫자까지 동일한데, 1의자리가 다른 MirrorNum이 존재하지 않으므로
	// 10의 자리숫자를 올려주고, 1의 자리숫자는 0부터 탐색한다
	//		if (/*IsMirrorPossible(i, len) && */IsMirrorNum(i, len))
	//		{
	//			result += 1;
	//			//++i;
	//			i += (10 - i % 10);
	//		}
	//		else ++i;
	//	}
	//}

	printf("%d", result);

	return 0;
}