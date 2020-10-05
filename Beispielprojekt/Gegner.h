#pragma once
#ifndef GEGNER_H
#define GEGNER_H
#include "Vektoren.h"

class Gegner {
private:
	int leben;
	double geschwindigkeit;
	Vektoren position;
	Vektoren richtung;

public:
	//Konstruktoren
	
	//Standartkonstruktor
	Gegner(void);
	//Konstruktor f�r Leben und Geschwindigkeit
	Gegner(int, double);

	//Methoden:

	int get_leben(void)const;
	void set_leben(const int);
	double get_geschwindigkeit(void)const;
	void set_Geschwindigkeit(const double);
	int get_x(void)const;
	void set_x(const int);
	int get_y(void)const;
	void set_y(const int);
	Vektoren get_richtung(void)const;
	void set_richtung(const Vektoren);
	Vektoren get_position(void)const;
	void set_position(const Vektoren);



	void RichtungZuPunkt(const Vektoren);
	void Zeichnen(void)const;
};


#endif // !GEGNER_H
