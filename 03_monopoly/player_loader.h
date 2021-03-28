#ifndef PLAYER_LOADER_H
#define PLAYER_LOADER_H

#include "player.h"
#include "string.h"
#include "vector.h"

class PlayerLoader {
public:
	static Vector<Player *> load_player_file(const String &file_name);
};

#endif
