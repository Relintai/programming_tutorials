
#include <iostream>

#include "string.h"
#include "vector.h"

#include "player.h"
#include "tile.h"

#include "tile_loader.h"
#include "player_loader.h"

#include "board.h"

#include "math.h"

int main() {
	Math::randomize();

	Board b;
	b.load("tiles.config", "players.config");

	b.run();

	b.print();

	return 0;
}
