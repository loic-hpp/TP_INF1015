//	Description: Implementation de la classe World.
//	Fichier: World.cpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	21 decembre 2022
//	Cr�� le 11 d�cembre 2022

#include "World.hpp"

World::World(std::string name, std::string header):
	name_(name), header_(header)
{
	createRooms();
}

void World::display(std::ostream& o)
{
	o << "\n>>>>>>>> " << header_ << " <<<<<<<<<<"
		<< "\n> > > > > " << name_ << " < < < < <";
}

void World::displayCurrentRoom(std::ostream& o)
{
	if (isRunning_) 
	{
		currentRoom_->display(o);
	}
	else
	{
		std::cout << "Fin de jeu, va t'en etre productif!" << std::endl;
	}
}

void World::moveNorth()
{
	if (currentRoom_->getNorthNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getNorthNeighbour();
}

void World::moveSouth()
{
	if (currentRoom_->getSouthNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getSouthNeighbour();
}

void World::moveEast()
{
	if (currentRoom_->getEastNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getEastNeighbour();
}

void World::moveWest()
{
	if (currentRoom_->getWestNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getWestNeighbour();
}

void World::look(std::string command)
{
	// TODO
}

// TODO : enlever items affiches dans la chambre pour seulement afficher dans inventaire (comme image example)
// TODO: unlock room with tobogan ou diamant cle
void World::use(std::string command)
{
	// TODO
}

void World::take(std::string command)
{
	// TODO
	/*if (inventoryInstance_.isItemInInvetory(command))
	{
		inventoryInstance_.addItemToInventoryList(totalItemsList_[inventoryInstance_.getCurrentItemIndex()]);
	}*/
}

void World::restart()
{
	currentRoom_ = beginRoom_;
}

void World::setPlaying(bool status)
{
	isRunning_ = status;
}

void World::createRooms()
{
	roomList_.push_back(std::make_shared<Room>("Balcon", "Petit coin ou profiter de l'air frais avec des chaises et tables", totalItemsList_[2]));
	roomList_.push_back(std::make_shared<Room>("Salle de billard", "Sallon de jeux avec comme activit� principale le billard", totalItemsList_[3]));
	roomList_.push_back(std::make_shared<Room>("Chambre a coucher", "Chambre avec lit Queen de qualite superieure", totalItemsList_[4]));
	roomList_.push_back(std::make_shared<Room>("Grand couloir", "Allee reliant plusieurs pieces dans l'hotel", totalItemsList_[5]));
	roomList_.push_back(std::make_shared<Room>("Vestiaire", "Entree de l'hotel pour laisser manteaux et bottes", totalItemsList_[1]));
	roomList_.push_back(std::make_shared<Room>("Salle de reception", "Salle pour check-in et recuperer ses cles", totalItemsList_[0]));
	roomList_.push_back(std::make_shared<Room>("Salle secrete", "Salle ou se trouve le secret le plus grande de Poly", totalItemsList_[6]));

	roomList_[1]->setNeighbour(nullptr, roomList_[3].get());
	roomList_[3]->setNeighbour(roomList_[1].get(), roomList_[4].get(),nullptr, roomList_[2].get());
	roomList_[4]->setNeighbour(roomList_[3].get(), nullptr, roomList_[5].get());
	roomList_[5]->setNeighbour(nullptr, nullptr, nullptr, roomList_[4].get());
	roomList_[2]->setNeighbour(nullptr, nullptr, roomList_[3].get());
	
	if (totalItemsList_[0]->getIsUsed())
	{
		//	Ouverture peut etre dans meme if parce que c'est deux places loins
		//  et c'est ouvert pendant un tour?
		roomList_[6]->setNeighbour(nullptr, nullptr, nullptr, roomList_[3].get());
		roomList_[0]->setNeighbour(nullptr, nullptr, nullptr, roomList_[3].get());
		totalItemsList_[0]->setIsUsed(false);
	}

	currentRoom_ = roomList_[4].get();
	beginRoom_ = roomList_[4].get();
}