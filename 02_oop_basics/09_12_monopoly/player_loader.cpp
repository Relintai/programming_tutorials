#include "player_loader.h"

#include <fstream>
#include <string>
#include "player.h"

Vector<Player *> PlayerLoader::load_player_file(const String &file_name) {
	Vector<Player *> players;

	std::fstream f;
	f.open(file_name.c_str());

	if (!f.fail()) {

		while (!f.eof()) {
			std::string class_name;

			f >> class_name;

			Player *p =  nullptr;

			if (class_name == "Player") {
				p = new Player();
			} else if (class_name == "AgressivePlayer") {
				p = new AgressivePlayer();
			} else if (class_name == "ConservativePlayer") {
				p = new ConservativePlayer();
			} else if (class_name == "TrickyPlayer") {
				p = new TrickyPlayer();
			} else if (class_name == "HumanPlayer") {
				p = new HumanPlayer();
			} else if (class_name == "CheatingPlayer") {
				p = new CheatingPlayer();
			}

			if (p) {
				int money;
				std::string name;

				f >> money >> name;

				String n(name.c_str());
				p->set_name(n);

				p->set_money(money);

				players.push_back(p);
			}
		}

		f.close();
	}

	return players;
}
