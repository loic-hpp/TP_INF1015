//	Description: Implementation de la classe Room.
//	Fichier: Room.cpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

#include "Room.hpp"

Room::Room(std::string name, std::string description):
	name_(name), description_(description)
{
}

void Room::display(std::ostream& o)
{
	o << "\n-- " << name_ << " --" << std::endl
		<< description_ << std::endl;
	
	// TODO: afficher items dans cette room (Reste a connecter quels items dans quels Rooms)
	o << "Tu remarques:" << std::endl;
	// item_.displayItemsFoundInRoom();

	for (auto it = neighbour_.begin(); it != neighbour_.end(); ++it) {
		const auto& [key, value] = *it;
		if (value != nullptr)
			o << "\n" << value->name_ << " se trouve � la position: " << key;
	}
	
	o << "\n" << "Tu as:" << std::endl;
	std::vector<std::shared_ptr<Item>> inventory = item_.getInventoryList();
	for (int i = 0; i <= inventory.size(); i++)
	{
		if (inventory.empty())
		{
			o << "\t" << "Tu as rien dans ton inventaire" << std::endl;
		}
		else
		{
			o << "\t" << inventory[i]->getName() << std::endl;
		}
	}
}

Room* Room::getNorthNeighbour()
{
	return neighbour_["Nord (N)"];
}

Room* Room::getSouthNeighbour() 
{
	return neighbour_["Sud (S)"];
}

Room* Room::getEastNeighbour() 
{
	return neighbour_["Est (E)"];
}

Room* Room::getWestNeighbour() 
{
	return neighbour_["Ouest (O)"];
}

void Room::setNeighbour(Room* northNeighbour, Room* southNeighbour, Room* eastNeighbour, Room* westNeighbour)
{
	neighbour_["Nord (N)"] = northNeighbour;
	neighbour_["Sud (S)"] = southNeighbour;
	neighbour_["Est (E)"] = eastNeighbour;
	neighbour_["Ouest (O)"] = westNeighbour;
}

std::string Room::getName(Room room)
{
	return room.name_;
}

std::string Room::getDescription(void)
{
	return description_;
}