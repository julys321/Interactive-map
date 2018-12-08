#include <iostream>
#include "MapLoader.h"
#include "MapSaver.h"
#include "Map.h"
#include "ShortestPathTree.h"
using namespace std;
interactiveMap::Map zemelapis;
void executeAdminInterface();
void drawRoom(Room room);
Room findRoom(std::string room);
void PathTheUser(std::vector<std::string> path);
int main() {
	zemelapis = MapLoader::loadMapFromFile("SavedMap.txt");
	string userInput = "";
	cout << "____ Pastato " << zemelapis.name << " kelio radejas ____\n";
	while (!userInput._Equal("exit")) {
		std::string fromRoomId;
		std::string toRoomId;
		cout << "Iveskite kambario numeri kuriame dabar esate:\n";
		cin >> userInput;
		fromRoomId = userInput;
		if (userInput._Equal("admin")) {
			userInput = "";
			executeAdminInterface();
		}
		else {
			Room room = findRoom(userInput);
			if (room.id == userInput) {
				system("cls");
				drawRoom(room);
				cout << "\n-->Iveskite kambario numeri i kuri noretumete patekti:\n";
				cin >> userInput;
				toRoomId = userInput;
				std::vector<std::string> path = ShortestPathTree::getShortestPath(zemelapis, fromRoomId, toRoomId);
				PathTheUser(path);
				break;
			}
			else {
				cout << "Neteisingai ivestas kambario numeris\n";
			}

		}
	}
	MapSaver::writeMapToFile("SavedMap.txt", zemelapis);
	return 0;
}
void executeAdminInterface() {
	string userInput;
	cout << "Slaptazodis:\n";
	cin >> userInput;
	if (!userInput._Equal("0000")) {
		return;
	}
	system("cls");
	cout << "Zemelapio keitimas - 1\n";
	cout << "Iseiti             - 0\n";
	cin >> userInput;
	if (userInput._Equal("1")) {
		cout << "Iveskite failo pavadinima su .txt failo tipu:\n";
		cin >> userInput;
		zemelapis = MapLoader::loadMapFromFile(userInput);
	}
	system("cls");
}
void drawRoom(Room room) {
	cout << "#### Pastato "<<zemelapis.name<<" Kamabrys "<<room.id<<" ####\n";
	cout << "-Kaimyniniai kambariai: ";
	for (auto connection : room.connections) {
		cout << connection.connectedWithId << ", ";
	}
	cout << "\n";
	cout << "-Daigtai esantys cia: ";
	for (auto item : room.items) {
		cout << item.name << " nr" << item.id << ", ";
	}
	cout << "\n";
}
Room findRoom(std::string room) {
	for (Room i : zemelapis.rooms)
		if (i.id._Equal(room))
			return i;
	return NULL;
}
void PathTheUser(std::vector<std::string> path) {
	for (std::string nextStep : path) {
		cout << "\n-->Eikite i "<< nextStep<<"\n\n";
		system("pause");
		system("cls");
		drawRoom(findRoom(nextStep));
	}
	cout << "\n    !!! Atvykote !!!    \n\n";
	system("pause");
}