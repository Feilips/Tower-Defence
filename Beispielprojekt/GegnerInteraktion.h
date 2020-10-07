#pragma once
#ifndef GEGNERINTERAKTION_H
#define GEGNERINTERAKTION_H
#include"Gegner.h"
#include"Figuren.h"
//jeder Turm checkt jeden Gegner und interagiert mit ihm (schiesst ihn ab)
void schiessen(vector<Gegner>*, vector<Figuren>*);
void zeichnen(vector<Gegner>*);
void bewegen(vector<Gegner>*);
void bewegen(Gegner*);
void wegpunkt(vector<Gegner>*, vector<Kachel>);
#endif // !GEGNERINTERAKTION_H
