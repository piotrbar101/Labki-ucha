#pragma once
#include <iostream>
using std::ostream;


class macierz {
	    static const int N=10;	//wiêcej o polach static bêdzie na w4
		double	t[N][N] = { 0 };
		int		n;				//bie¿¹cy wymiar macierzy

	public:
		// zdefiniuj tylko niezbêdne elementy dla klasy (wykorzystane w funkcji main)
		// metody, funkcje zaprzyjaŸnione, przeci¹¿enia operatorów, itp

		macierz(int n);
		macierz(int n, double k);

		void losowa(double low, double high);

		macierz transpozycja();

		friend ostream& operator<<(ostream& out, const macierz& z);
};


