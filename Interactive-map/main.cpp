#include <iostream>
#include "MapLoader.h"
#include "MapSaver.h"
#include "Map.h"
using namespace std;
interactiveMap::Map zemelapis;
void executeAdminInterface();
void drawRoom(Room room);
Room findRoom(std::string room);
int main() {
	zemelapis = MapLoader::loadMapFromFile("SavedMap.txt");
	string userInput;
	cout << "Kokiame pastate esate?\n";
	cin >> userInput;
	string pastatoId = userInput;//asfas
	while (!userInput._Equal("exit")) {
		cout << "Iveskite kambario numeri kuriame dabar esate:\n";
		cin >> userInput;
		if (userInput._Equal("admin")) {
			userInput = "";
			executeAdminInterface();
		}
		else {
			Room room = findRoom(userInput);
			if (room.id == userInput) {
				drawRoom(room);
				cout << "Iveskite kambario numeri i kuri noretumete patekti:\n";
				cin >> userInput;
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
	cout << "Zemelapio keitimas - 1\n";
	cout << "Iseiti             - 0\n";
	cin >> userInput;
	if (userInput._Equal("1")) {
		cout << "Iveskite failo pavadinima su .txt failo tipu";
		cin >> userInput;
		zemelapis = MapLoader::loadMapFromFile(userInput);
	}
}
void drawRoom(Room room) {
	cout << "Kaimyniniai kambariai: ";
	for (auto connection : room.connections) {
		cout << connection.connectedWithId << ", ";
	}
	cout << "\n";
	cout << "Daigtai esantys cia: ";
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