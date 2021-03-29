#include "tile_loader.h"

#include "tile.h"
#include <fstream>
#include <string>

Vector<Tile *> TileLoader::load_tile_file(const String &file_name) {
	Vector<Tile *> tiles;

	std::fstream f;
	f.open(file_name.c_str());

	if (!f.fail()) {

		while (!f.eof()) {
			std::string class_name;
			std::string tile_name;

			f >> class_name >> tile_name;

			Tile *t = nullptr;

			if (class_name == "Tile") {
				t = new Tile();
			} else if (class_name == "TaxTile") {
				TaxTile *tt = new TaxTile();

				int tax;

				f >> tax;

				tt->set_tax(tax);
				t = tt;
			} else if (class_name == "OwnableTile") {
				OwnableTile *tt = new OwnableTile();

				int price;
				int enter_price;

				f >> price >> enter_price;

				tt->set_price(price);
				tt->set_enter_price(enter_price);

				t = tt;
			} else if (class_name == "GainTile") {
				GainTile *tt = new GainTile();

				int gain;

				f >> gain;

				tt->set_gain(gain);
				t = tt;
			} else if (class_name == "LuckTile") {
				LuckTile *tt = new LuckTile();

				int chance;
				int gain_min;
				int gain_max;

				f >> chance >> gain_min >> gain_max;

				tt->set_chance(chance);
				tt->set_gain_min(gain_min);
				tt->set_gain_max(gain_max);
				t = tt;
			} else if (class_name == "JailTile") {
				JailTile *tt = new JailTile();

				int jail_time;

				f >> jail_time;

				tt->set_jail_time(jail_time);
				t = tt;
			}

			if (t) {
				String n(tile_name.c_str());

				t->set_name(n);

				tiles.push_back(t);
			}
		}

		f.close();
	}

	return tiles;
}
