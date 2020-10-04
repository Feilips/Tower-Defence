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
	int x, y;
	bool Check_if_changed;
	bool istWeg = false;
	bool istWeg = false;
public:
	//Konstruktoren
	
	//Standartkonstruktor
	Kachel();
	//Konstruktor mit x und y Position der oberen linken Ecke, die Kantenl�nge und die Farbe
	Kachel(int, int, int, Gosu::Color);
	Kachel(int, int, int, Gosu::Color,bool);
	
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
	bool get_istWeg(void)const;
	void set_istWeg(const bool);
	
	//Zeichnet eine Kachel
	void zeichnen(void);
};
//Fensterbreite, Fensterh�he, Kachelgr��e und Abstand
vector<vector<Kachel>> gridZeichnen(int fensterbreite, int fensterh�he, int kachelgr��e, int abstand);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt die getroffene Kachel als Vektor zur�ck
Vektoren MausZuKachel(int, int, vector<vector<Kachel>>);
//nimmt die Mauskoordinaten (x|y) und die Kachelmatrix und gibt zur�ck, ob �berhaupt eine Kachel getroffen wurde
bool hatKachelgetroffen(int, int, vector<vector<Kachel>>);
//Zeichnet die Kachelmatrix
void ArrayZeichnen(vector<vector<Kachel>>);
#endif // !GRID_H


