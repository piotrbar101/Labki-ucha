
#include <iostream>
#include <iomanip>
using namespace std;
#include "macierz.h"

macierz::macierz(int n) : n {n}
{
}

macierz::macierz(int n, double k) : macierz {n}
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j] = k;
}

void macierz::losowa(double low, double high)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j] = low + ((double)rand() / RAND_MAX) * (high-low);
}

macierz macierz::transpozycja()
{
	macierz tr(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tr.t[i][j] = t[j][i];

	return tr;
}

ostream& operator<<(ostream& out, const macierz& z)
{
	for (int i = 0; i < z.n; i++)
	{
		for (int j = 0; j < z.n; j++)
		{
			out << setw(7) <<setprecision(4) <<fixed << z.t[i][j] << ' ';
		}
		out << endl;
	}

	return out;
}
