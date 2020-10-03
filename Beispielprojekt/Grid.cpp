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
			rechteck_2Ecken(x1, y1, x2, y2, Gosu::Color::BLACK, 5);


			Kachelarray[j][i] = Kachel(x1, y1, kachelgr��e, Schwarz);
			
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
