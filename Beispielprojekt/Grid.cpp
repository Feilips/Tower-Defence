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

Kachel::Kachel(int x, int y, int kachelgr��e, Gosu::Color farbe, bool Check_if_Changed) {
	this->x = x;
	this->y = y;
	this->kachelgr��e = kachelgr��e;
	this->farbe = farbe;
	this->Check_if_changed = false;
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
	vector<vector<Kachel>> Kachelarray(AnzahlKachelnSpalte, vector<Kachel>(AnzahlKachelnZeile));
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

			Kachel a(x1, y1, kachelgr��e, Gosu::Color::Color(255, 0, 0, 0),false);
			Kachelarray[i][j] = a;
			//Kachelarray[j][i].set_farbe(Gosu::Color::Color(255, 0, 0, 0));

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
	int Koordinate_Zeile;
	int Koordinate_Spalte;
	for (Koordinate_Zeile = 0; Koordinate_Zeile < Kachelarray.size(); Koordinate_Zeile++)
	{
		Kachel a = Kachelarray[Koordinate_Zeile][0];
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgr��e())) {
			break;
		}
	}
	for (Koordinate_Spalte = 0; Koordinate_Spalte < Kachelarray.at(0).size(); Koordinate_Spalte++)
	{
		Kachel a = Kachelarray[0][Koordinate_Spalte];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgr��e())) {
			break;
		}
	}
	return Vektoren(Koordinate_Zeile, Koordinate_Spalte);
}
bool hatKachelgetroffen(int x, int y, vector<vector<Kachel>> Kachelarray) {

	//[i][0] iterieren wir �ber die erste Spalte -> Hier muss die H�he gepr�ft werden
	//if Mauspos-H�he ein Wert der einer Kachel zugewiesen werden kann: 
	//[0][j] iterieren wir �ber die erste Zeile -> Hier muss die Breite gepr�ft werden
	
	bool g = false;
	bool h = false;
	for (int i = 0; i < Kachelarray.size(); i++)
	{
		Kachel a = Kachelarray[i][0];
		if (a.get_y() <= y && y <= (a.get_y() + a.get_kachelgr��e()) ){
			g = true;
			break;
		}
	}
	for (int j = 0; j < Kachelarray.at(0).size(); j++)
	{
		Kachel a = Kachelarray[0][j];
		if (a.get_x() <= x && x <= (a.get_x() + a.get_kachelgr��e())) {
			h = true;
			break;
		}
	}
	if (g && h)
	{
		return true;
	}
	else
	{
		return false;
	}
	
		
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
bool Kachel::get_change(void) const
{
	return this->Check_if_changed;
}
void Kachel::set_change(const bool changer)
{
	this->Check_if_changed = changer;
}
bool Kachel::get_istWeg(void)const {
	return this->istWeg;
}
void Kachel::set_istWeg(const bool b) {
	this->istWeg = b;
}
Vektoren Kachel::Mittelpunkt(void)  {
	Vektoren a;
	a.set_x(this->x + this->kachelgr��e / 2);
	a.set_y(this->y + this->kachelgr��e / 2);
	return a;
}
