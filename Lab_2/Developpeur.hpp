﻿#pragma once
#include <string>
#include "ListeJeux.hpp"
#include "Jeu.hpp"
#include "gsl/span"

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
	//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
	//TODO: Les méthodes à faire...
public:
	Developpeur(std::string nomDeveloppeur, ListeJeux listejeux = {});
	~Developpeur();
	int nombreDinstances();
	std::string nomDeveloppeur();
	int participationJeux(ListeJeux listejeux);
	
private:
	std::pair<std::string, ListeJeux> paireNomJeux_;
	int compteur = 0;
};
