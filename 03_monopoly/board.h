#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "string.h"
#include "tile.h"
#include "vector.h"

class Board {
public:
	Player *get_current_player();
	Player *get_previous_player();

	int get_turn() const;
	void set_turn(const int turn);

	Vector<Tile *> get_tiles() const;
	void set_tiles(const Vector<Tile *> &tiles);

	Vector<Player *> get_active_players() const;
	void set_active_players(const Vector<Player *> &players);

	Vector<Player *> get_lost_players() const;
	void set_lost_players(const Vector<Player *> &players);

	void load(const String &tile_file, const String &player_file);
	void load_players(const String &file);
	void load_tiles(const String &file);

	void step();
	void run();

	void on_game_finished();

	void clear();
	void clear_players();
	void reset();

	void print();

	Board();
	Board(const String &tile_file, const String &player_file);
	virtual ~Board();

private:
	Vector<Tile *> _tiles;
	Vector<Player *> _active_players;
	Vector<Player *> _lost_players;

	Player *_previous_player;
	int _current_player_index;
	int _turn;
};

#endif