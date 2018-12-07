#include "MapLoader.h"
#include "Map.h"
using namespace std;
int main() {
	interactiveMap::Map zemelapis = MapLoader::loadMapFromFile("MockMap.txt");

	return 0;
}