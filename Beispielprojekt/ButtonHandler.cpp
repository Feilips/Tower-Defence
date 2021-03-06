#include "stdafx.h"
#include "ButtonHandler.h"
#include "Vektoren.h"
#include <vector>
#include "Grid.h"
#include <iostream>
using namespace std;
vector<vector<Kachel>> Maustaste_Losgelassen(vector<vector<Kachel>> arrayKachel, int x_maus, int y_maus)
{

	int iterator_ze = 1;
	int iterator_sp = 1;

	for (iterator_ze = 1; iterator_ze < arrayKachel.size(); iterator_ze++)
	{
		for (iterator_sp = 1; iterator_sp < arrayKachel.at(0).size(); iterator_sp++)
		{
			arrayKachel[iterator_ze - 1][iterator_sp - 1].set_change(false);
		}
	}
	return arrayKachel;
}

vector<vector<Kachel>> Maustaste_Gedr�ckt(vector<vector<Kachel>> arrayKachel, int x_maus, int y_maus)
{
	if (hatKachelgetroffen(x_maus, y_maus, arrayKachel))//Wenn man eine Kachel geklickt hat
	{
		//Dann soll eine Funktion ausgef�hrt werden, die die Kachelposition als Vektor zur�ckgibt
		Vektoren a = MausZuKachel(x_maus, y_maus, arrayKachel);

		//a.print();
		Kachel z = arrayKachel[a.get_x()][a.get_y()];

		if (z.get_farbe() == Schwarz && z.get_change() == false)
		{
			z.set_change(true);
			//cout << "Schwarz wurde erkannt" << endl;
			z.set_farbe(Rot);
		}
		else if (z.get_farbe() == Rot && z.get_change() == false)
		{
			z.set_change(true);
			z.set_farbe(Schwarz);
			//cout << "Rot wurde erkannt" << endl;
		}

		arrayKachel[a.get_x()][a.get_y()] = z;

	}
	return arrayKachel;
}
