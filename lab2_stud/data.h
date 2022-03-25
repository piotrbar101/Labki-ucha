#pragma once


class Data
{
	int dzien;
	int miesiac;
	int rok;
	
	bool format;

	bool CzyPrzestepny() const;

public:
	Data(int d = 4, int m = 3, int r = 2022, bool format=false);
	Data(const char* napis, bool format=false);

	//uzupełnij TYLKO POTRZEBNE metody i funkcje zaprzyjaźnione


};

int LiczbaDni(const Data& d1, const Data& d2);

