#include "stdafx.h"
#include "Grid.h"
#include "Zeichnen.h"
#include "list"
using namespace std;

Kachel::Kachel() {};
Kachel::Kachel(int x, int y, int kachelgr��e, Gosu::Color farbe) {
	this->x = x;
	this->y = y;
	this->kachelgr��e = kachelgr��e;
	this->farbe = farbe;
}




vector<vector<Kachel>> gridZeichnen(int fensterbreite, int fensterh�he, int kachelgr��e, int abstand) {
	int AnzahlKachelnZeile = fensterbreite / (kachelgr��e + abstand);
	int AnzahlKachelnSpalte = fensterh�he / (kachelgr��e + abstand);

	if ((fensterh�he - ((AnzahlKachelnSpalte + 1) * kachelgr��e + AnzahlKachelnSpalte * abstand)) >= 0)
	{
		AnzahlKachelnSpalte++;
	}
	if ((fensterbreite - ((AnzahlKachelnZeile + 1) * kachelgr��e + AnzahlKachelnZeile * abstand)) >= 0)
	{
		AnzahlKachelnZeile++;
	}
	vector<vector<Kachel>> Kachelarray(AnzahlKachelnZeile, vector<Kachel>(AnzahlKachelnSpalte));
	for (int i = 0; i < AnzahlKachelnSpalte; i++)
	{
		for (int j = 0; j < AnzahlKachelnZeile; j++)
		{
			int x1, x2, y1, y2;
			x1 = j * (kachelgr��e + abstand);
			y1 = i * (kachelgr��e + abstand);
			x2 = x1 + kachelgr��e;
			y2 = y1 + kachelgr��e;
			//rechteck_2Ecken(x1, y1, x2, y2, Gosu::Color::BLACK, 5);

			Kachel a(x1, y1, kachelgr��e, Schwarz);
			Kachelarray[j][i] = a;
			Kachelarray[j][i].set_farbe(Gosu::Color::Color(255, 0, 0, 0));

			//Kachelarray[j][i] = Kachel(x1, y1, kachelgr��e, Schwarz);
			
		}
	}
	return Kachelarray;
};
void Kachel::zeichnen(void) {
	rechteck_2Ecken(this->x, this->y, this->x + this->kachelgr��e, this->y + this->kachelgr��e, this->farbe, 5);
}
void Kachel::set_farbe(Gosu::Color f) {
	this->farbe = f;
}
void ArrayZeichnen(vector<vector<Kachel>> Kachelarray) {
	for each (auto x in Kachelarray)
	{
		for each (Kachel y in x)
		{
			y.zeichnen();
		}
	}
}
Vektoren MausZuKachel(int x, int y, vector<vector<Kachel>> Kachelarray)  {
	for (int i = 0; i < Kachelarray.size(); i++)
	{
		for (int j = 0; j < Kachelarray.at(i).size(); j++)
		{
			Kachel b = Kachelarray[j][i];
			if (b.get_x() <= x && x <= (b.get_x() + b.get_kachelgr��e()))
			{
				if (b.get_y() <= y && y <= (b.get_y() + b.get_kachelgr��e()))
				{
					return Vektoren(j, i);
				}
			}
		}
	}
}
bool hatKachelgetroffen(int x, int y, vector<vector<Kachel>> Kachelarray) {
	for each (auto a in Kachelarray)
	{
		for each (auto b in a)
		{
			if (b.get_x() <= x && x <= (b.get_x() + b.get_kachelgr��e()))
			{
				if (b.get_y() <= y && y <= (b.get_y() + b.get_kachelgr��e()))
				{
					return true;
				}
			}
		}
	}
	return false;
}
int Kachel::get_x(void) const {
	return this->x;
}
int Kachel::get_y(void) const {
	return this->y;
}
int Kachel::get_kachelgr��e(void) const {
	return this->kachelgr��e;
}
Gosu::Color Kachel::get_farbe(void) const {
	return this->farbe;
}
void Kachel::set_x(const int a) {
	this->x = a;
}
void Kachel::set_y(const int a) {
	this->y = a;
}
void Kachel::set_kachelgr��e(const int a) {
	this->kachelgr��e = a;
}
