#ifndef PLAYER_H
#define PLAYER_H

#include "string.h"

class Player {
public:
	String get_name();
	void set_name(const String &name);

	int get_tile_index() const;
	void set_tile_index(const int val);

	int get_money() const;
	void set_money(const int val);

	int get_jail_time() const;
	void set_jail_time(const int val);

	bool get_lost() const;
	void set_lost(const bool val);

	virtual bool want_buy(const String &tile_name, int price);
	virtual void pay_entry_fee(const int val, Player *to);
	virtual void throw_dice();
	virtual void on_lose();

	virtual void print();

	virtual String get_class_name();

	Player();
	virtual ~Player();

protected:
	String _name;
	int _tile_index;
	int _money;
	int _jail_time;
	bool _lost;
};

class AgressivePlayer : public Player {
public:
	bool want_buy(const String &tile_name, int price);
	void on_lose();

	String get_class_name();

	AgressivePlayer();
};

class ConservativePlayer : public Player {
public:
	bool want_buy(const String &tile_name, int price);
	void on_lose();

	String get_class_name();

	ConservativePlayer();
};

class TrickyPlayer : public Player {
public:
	bool want_buy(const String &tile_name, int price);
	void on_lose();

	String get_class_name();

	TrickyPlayer();
};

class HumanPlayer : public Player {
public:
	bool want_buy(const String &tile_name, int price);
	void on_lose();

	String get_class_name();

	HumanPlayer();
};

class CheatingPlayer : public Player {
public:
	bool want_buy(const String &tile_name, int price);
	void throw_dice();
	void on_lose();

	String get_class_name();

	CheatingPlayer();
};

#endif
