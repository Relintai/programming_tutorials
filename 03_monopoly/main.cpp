
#include <iostream>

#include "string.h"
#include "vector.h"

#include "player.h"
#include "tile.h"

#include "tile_loader.h"
#include "player_loader.h"

int main() {

	Vector<Tile *> tiles = TileLoader::load_tile_file("tiles.config");
	Vector<Player *> players = PlayerLoader::load_player_file("players.config");

	for (int i = 0; i < tiles.size(); ++i) {
		tiles[i]->print();
	}

	for (int i = 0; i < players.size(); ++i) {
		players[i]->print();
	}

	return 0;
}
