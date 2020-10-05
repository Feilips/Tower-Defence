#pragma once
#ifndef GRID_H
#define GRID_H
#include "Zeichnen.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Vektoren.h"
using namespace std;
//Test
class Kachel {
private:
	Gosu::Color farbe = Schwarz;
	int kachelgr��e;
	Vektoren position;
	bool Check_if_changed;
	bool istWeg = false;
	
public:
	//Konstruktoren
	
	//Standartkonstruktor
	Kachel();
	//Konstruktor mit Position der oberen linken Ecke, die Kantenl�nge und die Farbe
	Kachel(Vektoren, int, Gosu::Color);
	Kachel(Vektoren, int, Gosu::Color, bool);
	
	//Methoden
	
	
	int get_x(void)const;
	void set_x(const int);
	int get_y(void)const;
	void set_y(const int);
	int get_kachelgr��e(void)const;
	void set_kachelgr��e(const int);
	Gosu::Color get_farbe(void)const;
	void set_farbe(const Gosu::Color);
	bool get_change(void)const;
	void set_change(const bool);
	bool get_istWeg(void)const;
	void set_istWeg(const bool);
	Vektoren Mittelpunkt(void);
	Vektoren get_position(void)const;
	void set_position(const Vektoren);
	
	
	//Zeichnet eine Kachel
	void zeichnen(void);
};
//Funktionen

//gibt die Kachelmatrix zur�ck. Nur die Kacheln, also ohne Weg. Fensterbreite, Fensterh�he, Kachelgr��e und Abstand. 
vector<vector<Kachel>> grid(int fensterbreite, int fensterh�he, int kachelgr��e, int abstand);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt die getroffene Kachel als Vektor zur�ck
Vektoren MausZuKachel(int, int, vector<vector<Kachel>>);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt zur�ck, ob �berhaupt eine Kachel getroffen wurde
bool hatKachelgetroffen(int, int, vector<vector<Kachel>>);
//Zeichnet die Kachelmatrix
void ArrayZeichnen(vector<vector<Kachel>>);
#endif // !GRID_H


