#pragma once
#ifndef GRID_H
#define GRID_H
#include "Zeichnen.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
using namespace std;

class Kachel {
private:
	Gosu::Color farbe = Schwarz;
	int kachelgr��e;
	int x, y;
public:
	Kachel();
	Kachel(int, int, int, Gosu::Color);
	void set_farbe(Gosu::Color);

	void zeichnen(void);
};
//Fensterbreite, Fensterh�he, Kachelgr��e und Abstand
vector<vector<Kachel>> gridZeichnen(int fensterbreite, int fensterh�he, int kachelgr��e, int abstand);
void ArrayZeichnen(vector<vector<Kachel>>);
#endif // !GRID_H


