#include <iostream>
using namespace std;
#include <ctime>
#include "macierz.h"


//---------------------------------------------------
int main()
{
		srand(unsigned(time(NULL)));

		//-----------------------------------------------------------------
		// testy dla klasy macierz
		macierz AA(4),   // 4- wymiar, elementy tablicy wype�nione domy�ln� warto�ci� 0
			    BB(3),	 // 3- wymiar,  elementy tablicy wype�nione domy�ln� warto�ci� 0
				CC(4,3); // 4- wymiar,  elementy tablicy wype�nione  warto�ci� 3
		
		AA.losowa(-2,2); // losowa macierz o warto�ciach  rzeczywistych z podanego przedzia�u (wype�nia warto�ci bie��cego obiektu AA)
		cout << "macierz AA:" <<endl<< AA << endl;
		cout<<"Transpozycja AA:"<<AA.transpozycja()<<endl; // zwraca transponowan�  macierz, nie modyfikuje bie��cego obiektu
		//cout << "macierz AA powinna by� bez zmian:" <<endl<< AA << endl;

		//BB.losowa(0,3);
		//cout << "macierz BB:" << endl << BB << endl;

		//cout << "macierz CC:" <<endl<< CC << endl;
		//CC.jednostkowa();	//modyfikuje bie��cy obiekt tak, by zawiera� warto�ci macierzy jednostkowej
		//cout << "macierz CC:" <<endl<< CC << endl;
		//cout << "norma macierzy CC: " << CC.norma() << endl;	//zwraca norm� macierzy
		//cout << "Element CC(2,2): " << CC(2,2) << endl;			//element tablicy o indeksach 2,2
		//CC(1,2)=5;												//modyfikacja elementu o indeksach 1,2 (wiersz,kolumna)
		//cout << "macierz CC po zmianie CC(1,2)=5:" <<endl<< CC << endl;
		//
		//cout << "CC = AA+AA = " << (CC = AA+AA) << endl;
		//cout << "CC = CC-AA = " << (CC = CC-AA) << endl;
		//cout << "Czy AA==CC? " << (AA==CC? "TAK" : "NIE") << endl;	//macierze a i b s� r�wne, gdy dla wszystkich element�w |a(i,j)-b(i,j)|<EPS
		//cout << endl;
		//cout << "1.5*CC=" << (1.5*CC) << endl;
		//BB=CC;
		//cout << "BB = " << BB << endl;
		//cout << "AA*BB = " << (AA*BB) << endl;
		//cout<<"norma BB="<<BB.norma()<<endl;
		//cout<<"transpozycja BB="<<BB.transpozycja()<<endl;
		//
		////---------------------------------------------------------------
		//// zastosowanie klasy macierz  do wyznaczania maciaerzy psedoodwrotnej
		//
		//int w;

		//cout<<"Podaj wymiar macierzy kwadratowej: "<<endl;
		//cin>>w;

		//macierz A(w), A1(w),I(w);
		//		
		//double aa,bb;
		//cout<<"Okresl granice przedzialu losowania [a,b]:"<<endl;
		//do{
		//	cout<<"podaj a = ";
		//	cin>>aa;
		//	cout<<"podaj b = ";
		//	cin>>bb;
		//}while (aa>=bb);

		//A.losowa(aa,bb);
		//cout<<"A="<<A<<endl;

		//A1=A.pseudoodwrotna(); // zwraca pseudoodwrotno��  macierzy, nie modyfikuje bie��cego obiektu
	
		//I.jednostkowa();

		//cout<<"Macierz A1:"<<A1<<endl;
	
		//if (A*A1==I)
		//	cout<<"sprawdzenie OK"<<endl;
		//else
		//	cout<<"...hmmmmm...."<<endl;
		
}

