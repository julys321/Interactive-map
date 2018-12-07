#include <iostream>
#include "MapLoader.h"
#include "MapSaver.h"
#include "Map.h"
using namespace std;
interactiveMap::Map zemelapis;
void executeAdminInterface();
int main() {
	zemelapis = MapLoader::loadMapFromFile("SavedMap");
	string userInput;
	while (!userInput._Equal("exit")) {
		cout << "Kur noretumete nuvykti?\n";
		cin >> userInput;
		if (userInput._Equal("admin")) {
			userInput = "";
			executeAdminInterface();
		}
	}
	MapSaver::writeMapToFile("SavedMap", zemelapis);
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