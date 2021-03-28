#include "player.h"

#include <stdio.h>

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
	_money = val;
}

int Player::get_jail_time() const {
	return _jail_time;
}

void Player::set_jail_time(const int val) {
	_jail_time = val;
}

bool Player::get_lost() const {
	return _lost;
}

void Player::set_lost(const bool val) {
	_lost = val;
}

bool Player::want_buy(const String &tile_name, int price) {
	return false;
}

void Player::pay_entry_fee(const int val, Player *to) {
}

void Player::throw_dice() {
}

void Player::on_lose() {
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
	return false;
}
void AgressivePlayer::on_lose() {
}
String AgressivePlayer::get_class_name() {
	return "AgressivePlayer";
}
AgressivePlayer::AgressivePlayer() :
		Player() {
}

bool ConservativePlayer::want_buy(const String &tile_name, int price) {
	return false;
}
void ConservativePlayer::on_lose() {
}
String ConservativePlayer::get_class_name() {
	return "ConservativePlayer";
}
ConservativePlayer::ConservativePlayer() :
		Player() {
}

bool TrickyPlayer::want_buy(const String &tile_name, int price) {
	return false;
}
void TrickyPlayer::on_lose() {
}
String TrickyPlayer::get_class_name() {
	return "TrickyPlayer";
}
TrickyPlayer::TrickyPlayer() :
		Player() {
}

bool HumanPlayer::want_buy(const String &tile_name, int price) {
	return false;
}
void HumanPlayer::on_lose() {
}
String HumanPlayer::get_class_name() {
	return "HumanPlayer";
}
HumanPlayer::HumanPlayer() :
		Player() {
}

bool CheatingPlayer::want_buy(const String &tile_name, int price) {
	return false;
}
void CheatingPlayer::throw_dice() {
}
void CheatingPlayer::on_lose() {
}
String CheatingPlayer::get_class_name() {
	return "CheatingPlayer";
}
CheatingPlayer::CheatingPlayer() :
		Player() {
}
