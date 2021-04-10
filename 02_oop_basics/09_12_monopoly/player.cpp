#include "player.h"

#include <stdio.h>

#include "math.h"

#include <iostream>

String Player::get_name() {
	return _name;
}

void Player::set_name(const String &name) {
	_name = name;
}

int Player::get_tile_index() const {
	return _tile_index;
}

void Player::set_tile_index(const int val) {
	_tile_index = val;
}

int Player::get_money() const {
	return _money;
}

void Player::set_money(const int val) {
	int c = _money - val;

	if (c >= 0) {
		printf("Player - %s has gained %d dollars.\n", _name.c_str(), c);
	} else {
		printf("Player - %s has gained %d dollars.\n", _name.c_str(), -c);
	}

	_money = val;

	if (_money <= 0) {
		_money = 0;

		set_lost(true);
	}
}

int Player::get_jail_time() const {
	return _jail_time;
}

void Player::set_jail_time(const int val) {
	if (_jail_time == 0) {
		printf("Player - %s has been jailed for %d turns.\n", _name.c_str(), val);
	}

	_jail_time = val;
}

bool Player::get_lost() const {
	return _lost;
}

void Player::set_lost(const bool val) {
	_lost = val;

	if (val) {
		on_lose();
	}
}

bool Player::want_buy(const String &tile_name, int price) {
	return false;
}

int Player::throw_dice() {
	int t = Math::rand(1, 7);

	printf("Player - %s has thrown the dice, and rolled %d.\n", _name.c_str(), t);

	return t;
}

void Player::on_lose() {
	printf("Player - %s has lost the game. And he's sad.\n", _name.c_str());
}

void Player::print() {
	printf("Player - %s - Name: %s Tile Index: %d Money: %d Jail time: %d Lost: %d\n", get_class_name().c_str(), _name.c_str(), _tile_index, _money, _jail_time, _lost);
}

String Player::get_class_name() {
	return "Player";
}

Player::Player() {
	_tile_index = 0;
	_money = 0;
	_jail_time = 0;
	_lost = 0;
}

Player::~Player() {
}

bool AgressivePlayer::want_buy(const String &tile_name, int price) {
	return true;
}
void AgressivePlayer::on_lose() {
	printf("Player - %s has lost the game. And he's angry.\n", _name.c_str());
}
String AgressivePlayer::get_class_name() {
	return "AgressivePlayer";
}
AgressivePlayer::AgressivePlayer() :
		Player() {
}

bool ConservativePlayer::want_buy(const String &tile_name, int price) {
	if (price < _money / 2) {
		return true;
	}

	return false;
}
void ConservativePlayer::on_lose() {
	printf("Player - %s has lost the game.\n", _name.c_str());
}
String ConservativePlayer::get_class_name() {
	return "ConservativePlayer";
}
ConservativePlayer::ConservativePlayer() :
		Player() {
}

bool TrickyPlayer::want_buy(const String &tile_name, int price) {
	return Math::rand(2) == 0 ? true : false;;
}
void TrickyPlayer::on_lose() {
	printf("Player - %s has lost the game.\n", _name.c_str());
}
String TrickyPlayer::get_class_name() {
	return "TrickyPlayer";
}
TrickyPlayer::TrickyPlayer() :
		Player() {
}

bool HumanPlayer::want_buy(const String &tile_name, int price) {
	bool w = false;

	printf("Player - %s do you want to buy %s for %d? You have %d dollars.\n", _name.c_str(), tile_name.c_str(), price, _money);

	std::cin >> w;

	return w;
}
void HumanPlayer::on_lose() {
	printf("Player - %s has lost the game. And he's really sad.\n", _name.c_str());
}
String HumanPlayer::get_class_name() {
	return "HumanPlayer";
}
HumanPlayer::HumanPlayer() :
		Player() {
}

bool CheatingPlayer::want_buy(const String &tile_name, int price) {
	return true;
}
int CheatingPlayer::throw_dice() {
	int t = Math::rand(3, 7);

	printf("Player - %s has thrown the dice, and rolled %d.\n", _name.c_str(), t);

	return t;
}
void CheatingPlayer::on_lose() {
	printf("Player - %s has lost the game. And he's really angry.\n", _name.c_str());
}
String CheatingPlayer::get_class_name() {
	return "CheatingPlayer";
}
CheatingPlayer::CheatingPlayer() :
		Player() {
}
