#include <bits/stdc++.h>
using namespace std;


class bino{
    public:
    int n = 5, k = 2;
    int min(int a, int b);
    int binomialCoeff(int n, int k);
}bi;



int bino:: binomialCoeff(int n, int k)
{
	int C[n + 1][k + 1];
	int i, j;

	
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i, k); j++) {
			
			if (j == 0 || j == i)
				C[i][j] = 1;

			
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	return C[n][k];
}


int bino::min(int a, int b) { return (a < b) ? a : b; }


int main()
{
	
	cout << "Value of C[" << bi.n << "][" << bi.k << "] is "
		<< bi.binomialCoeff(bi.n, bi.k);
}
