#pragma once
#include <iostream>
using std::ostream;


class macierz {
	    static const int N=10;	//wi�cej o polach static b�dzie na w4
		double	t[N][N] = { 0 };
		int		n;				//bie��cy wymiar macierzy

	public:
		// zdefiniuj tylko niezb�dne elementy dla klasy (wykorzystane w funkcji main)
		// metody, funkcje zaprzyja�nione, przeci��enia operator�w, itp

		macierz(int n);
		macierz(int n, double k);

		void losowa(double low, double high);

		macierz transpozycja();

		friend ostream& operator<<(ostream& out, const macierz& z);
};


