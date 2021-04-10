#ifndef TILE_LOADER_H
#define TILE_LOADER_H

#include "string.h"
#include "tile.h"
#include "vector.h"

class TileLoader {
public:
	static Vector<Tile *> load_tile_file(const String &file_name);
};

#endif
