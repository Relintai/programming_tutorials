#include "board.h"

#include <cstdio>

#include "player_loader.h"
#include "tile_loader.h"

Player *Board::get_current_player() {
	return _active_players[_current_player_index];
}
Player *Board::get_previous_player() {
	return _previous_player;
}

int Board::get_turn() const {
	return _turn;
}
void Board::set_turn(const int turn) {
	_turn = turn;
}

Vector<Tile *> Board::get_tiles() const {
	return _tiles;
}
void Board::set_tiles(const Vector<Tile *> &tiles) {
	_tiles = tiles;
}

Vector<Player *> Board::get_active_players() const {
	return _active_players;
}
void Board::set_active_players(const Vector<Player *> &players) {
	_active_players = players;
}

Vector<Player *> Board::get_lost_players() const {
	return _lost_players;
}
void Board::set_lost_players(const Vector<Player *> &players) {
	_lost_players = players;
}

void Board::load(const String &tile_file, const String &player_file) {
	clear();

	_tiles = TileLoader::load_tile_file(tile_file);
	_active_players = PlayerLoader::load_player_file(player_file);
}

void Board::load_players(const String &file) {
	clear_players();

	_active_players = PlayerLoader::load_player_file(file);
}
void Board::load_tiles(const String &file) {
	for (int i = 0; i < _tiles.size(); ++i) {
		delete _tiles[i];
	}

	_tiles = TileLoader::load_tile_file(file);
}

void Board::step() {
	Player *cp = _active_players[_current_player_index];

	printf("Player - %s's turn.\n", cp->get_name().c_str());

	int jail_time = cp->get_jail_time();

	if (jail_time > 0) {
		--jail_time;

		printf("Player - is in jail for %d more turns.\n", jail_time);

		cp->set_jail_time(jail_time);

		return;
	}

	int t = cp->throw_dice();

	int ti = cp->get_tile_index();

	ti += t;

	if (ti >= _tiles.size()) {
		ti = t % _tiles.size();
	}

	cp->set_tile_index(ti);

	Tile *tile = _tiles[ti];

	tile->on_player_arrived(cp);

	_previous_player = cp;

	if (cp->get_lost()) {
		_active_players.remove_keep_order(_current_player_index);

		_lost_players.push_back(cp);

		if (_current_player_index >= _active_players.size()) {
			_current_player_index = 0;
		}

		return;
	}

	++_current_player_index;

	if (_current_player_index >= _active_players.size()) {
		_current_player_index = 0;
	}
}
void Board::run() {
	while (_active_players.size() > 1 && _turn < 200) {
		step();

		++_turn;
	}

	on_game_finished();
}

void Board::on_game_finished() {
	if (_active_players.size() != 1) {
		printf("The game has been finished! No winner!\n");
	} else {
		printf("The game has been finished! %s the winner!\n", _active_players[0]->get_name().c_str());
	}

	printf("The game took %d turns!\n", _turn);
}

void Board::clear() {
	for (int i = 0; i < _tiles.size(); ++i) {
		delete _tiles[i];
	}

	for (int i = 0; i < _active_players.size(); ++i) {
		delete _active_players[i];
	}

	for (int i = 0; i < _lost_players.size(); ++i) {
		delete _lost_players[i];
	}

	_tiles.clear();
	_active_players.clear();
	_lost_players.clear();
}

void Board::clear_players() {
	for (int i = 0; i < _active_players.size(); ++i) {
		delete _active_players[i];
	}

	for (int i = 0; i < _lost_players.size(); ++i) {
		delete _lost_players[i];
	}

	_active_players.clear();
	_lost_players.clear();
}

void Board::reset() {
	_previous_player = nullptr;
	_current_player_index = 0;
	_turn = 0;

	for (int i = 0; i < _tiles.size(); ++i) {
		_tiles[i]->reset();
	}

	clear_players();
}

void Board::print() {
	printf("Board:\n");

	printf("Tiles:\n");
	for (int i = 0; i < _tiles.size(); ++i) {
		_tiles[i]->print();
	}

	printf("Active players (%d):\n", _active_players.size());
	for (int i = 0; i < _active_players.size(); ++i) {
		_active_players[i]->print();
	}

	printf("Lost players (%d):\n", _lost_players.size());
	for (int i = 0; i < _lost_players.size(); ++i) {
		_lost_players[i]->print();
	}
}

Board::Board() {
	reset();
}
Board::Board(const String &tile_file, const String &player_file) {
	reset();

	load(tile_file, player_file);
}

Board::~Board() {
	clear();
}
