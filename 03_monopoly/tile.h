#ifndef TILE_H
#define TILE_H

#include "player.h"

class Tile {
public:
	String get_name();
	void set_name(const String &name);

	virtual void on_player_arrived(Player *p);

	virtual void reset();

	virtual void print();
	virtual String get_class_name();

	Tile();
	virtual ~Tile();

private:
	String _name;
};

class TaxTile : public Tile {
public:
	int get_tax() const;
	void set_tax(const int tax);

	void on_player_arrived(Player *p);
	void print();
	String get_class_name();

	TaxTile();

private:
	int _tax;
};

class OwnableTile : public Tile {
public:
	int get_price() const;
	void set_price(const int val);

	int get_enter_price() const;
	void set_enter_price(const int val);

	Player *get_owner() const;
	void set_owner(Player *val);

	void on_player_arrived(Player *p);
	void print();
	void reset();

	String get_class_name();

	OwnableTile();

private:
	int _price;
	int _enter_price;
	Player *_owner;
};

class GainTile : public Tile {
public:
	int get_gain() const;
	void set_gain(const int val);

	void on_player_arrived(Player *p);
	void print();
	String get_class_name();

	GainTile();

private:
	int _gain;
};

class LuckTile : public Tile {
public:
	int get_chance() const;
	void set_chance(const int val);

	int get_gain_min() const;
	void set_gain_min(const int val);

	int get_gain_max() const;
	void set_gain_max(const int val);

	void on_player_arrived(Player *p);
	void print();
	String get_class_name();

	LuckTile();

private:
	int _chance;
	int _gain_min;
	int _gain_max;
};

class JailTile : public Tile {
public:
	int get_jail_time() const;
	void set_jail_time(const int val);

	void on_player_arrived(Player *p);
	void print();
	String get_class_name();

	JailTile();

private:
	int _jail_time;
};

#endif
