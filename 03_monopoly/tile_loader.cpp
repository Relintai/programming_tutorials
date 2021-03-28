#include "tile_loader.h"

#include <fstream>
#include <string>
#include "tile.h"

Vector<Tile *> TileLoader::load_tile_file(const String &file_name) {
	Vector<Tile *> tiles;

	std::fstream f;
	f.open(file_name.c_str());

	if (!f.fail()) {

		while (!f.eof()) {
			std::string class_name;

			f >> class_name;

			Tile *t =  nullptr;

			if (class_name == "Tile") {
				t = new Tile();
			} else if (class_name == "TaxTile") {
				t = new TaxTile();
			} else if (class_name == "OwnableTile") {
				t = new OwnableTile();
			} else if (class_name == "GainTile") {
				t = new GainTile();
			} else if (class_name == "LuckTile") {
				t = new LuckTile();
			} else if (class_name == "JailTile") {
				t = new JailTile();
			}

			if (t) {
				std::string name;

				f >> name;

				String n(name.c_str());

				t->set_name(n);

				tiles.push_back(t);
			}
		}

		f.close();
	}

	return tiles;
}
