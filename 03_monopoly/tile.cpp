#include "tile.h"

#include <stdio.h>

#include "math.h"

String Tile::get_name() {
	return _name;
}

void Tile::set_name(const String &name) {
	_name = name;
}

void Tile::on_player_arrived(Player *p) {
    printf("Player %s just stepped on %s.\n", p->get_name().c_str(), _name.c_str());
}

void Tile::reset() {

}

void Tile::print() {
	printf("Tile - %s - Name: %s\n", get_class_name().c_str(), _name.c_str());
}

String Tile::get_class_name() {
	return "Tile";
}

Tile::Tile() {
}

Tile::~Tile() {
}

int TaxTile::get_tax() const {
	return _tax;
}
void TaxTile::set_tax(const int tax) {
    _tax = tax;
}

void TaxTile::on_player_arrived(Player *p) {
    Tile::on_player_arrived(p);

    p->set_money(p->get_money() - _tax);
}
void TaxTile::print() {
    printf("Tile - %s - Name: %s, tax: %d\n", get_class_name().c_str(), get_name().c_str(), _tax);
}
String TaxTile::get_class_name() {
	return "TaxTile";
}

TaxTile::TaxTile() :
		Tile() {

    _tax = 0;
}

int OwnableTile::get_price() const {
    return _price;
}
void OwnableTile::set_price(const int val) {
    _price = val;
}

int OwnableTile::get_enter_price() const {
    return _enter_price;
}
void OwnableTile::set_enter_price(const int val) {
    _enter_price = val;
}

Player *OwnableTile::get_owner() const {
    return _owner;
}
void OwnableTile::set_owner(Player *val) {
    _owner = val;
}

void OwnableTile::on_player_arrived(Player *p) {
    Tile::on_player_arrived(p);

    if (!_owner) {
        printf("Tile - %s is for sale! It costs %d.\n", get_name().c_str(), _price);

        int m = p->get_money();

        if (m < _price) {
            printf("Player - %s, can't buy tile, not enough money!\n", p->get_name().c_str());
            return;
        }

        printf("Player - %s, do you want to buy?\n", p->get_name().c_str());

        if (p->want_buy(get_name(), _price)) {
            printf("Player - %s now owns %s.\n", p->get_name().c_str(), get_name().c_str());

            _owner = p;
        }
    } else {
        if (p == _owner) {
            printf("Tile - %s is now owned by you. Welcome!\n", get_name().c_str());
            return;
        }

        printf("Tile - %s is owned by %s. You need to pay an entry fee of %d!\n", get_name().c_str(), p->get_name().c_str(), _enter_price);

        int m = p->get_money();

        if (m <= _enter_price) {
            _owner->set_money(_owner->get_money() + m);
            p->set_money(0);
        } else {
            _owner->set_money(_owner->get_money() + _enter_price);
            p->set_money(m - _enter_price);
        }
    }
}
void OwnableTile::print() {
    printf("Tile - %s - Name: %s, price: %d, enter_price: %d, owner: %s.\n", get_class_name().c_str(), get_name().c_str(), _price, _enter_price, _owner ? _owner->get_name().c_str() : "None");
}
void OwnableTile::reset() {
    _owner = nullptr;
}
String OwnableTile::get_class_name() {
    return "OwnableTile";
}

OwnableTile::OwnableTile() :
		Tile() {

    _price = 0;
	_enter_price = 0;
	_owner = nullptr;
}

int GainTile::get_gain() const {
    return _gain;
}
void GainTile::set_gain(const int val) {
    _gain = val;
}

void GainTile::on_player_arrived(Player *p) {
    Tile::on_player_arrived(p);

    p->set_money(p->get_money() - _gain);
}
void GainTile::print() {
    printf("Tile - %s - Name: %s, gain: %d.\n", get_class_name().c_str(), get_name().c_str(), _gain);
}
String GainTile::get_class_name() {
    return "GainTile";
}

GainTile::GainTile() :
		Tile() {

    _gain = 0;
}

int LuckTile::get_chance() const {
    return _chance;
}
void LuckTile::set_chance(const int val) {
    _chance = val;
}

int LuckTile::get_gain_min() const {
    return _gain_min;
}
void LuckTile::set_gain_min(const int val) {
    _gain_min = val;
}

int LuckTile::get_gain_max() const {
    return _gain_max;
}
void LuckTile::set_gain_max(const int val) {
    _gain_max = val;
}

void LuckTile::on_player_arrived(Player *p) {
    Tile::on_player_arrived(p);

    int c = Math::rand(0, 100);

    if (c < _chance) {
        int v = Math::rand(_gain_min, _gain_max);

        p->set_money(p->get_money() + v);
    }
}
void LuckTile::print() {
    printf("Tile - %s - Name: %s, chance: %d, gain_min: %d, gain_max: %d.\n", get_class_name().c_str(), get_name().c_str(), _chance, _gain_min, _gain_max);
}
String LuckTile::get_class_name() {
    return "LuckTile";
}

LuckTile::LuckTile() :
		Tile() {

    _chance = 0;
	_gain_min = 0;
	_gain_max = 0;
}

int JailTile::get_jail_time() const {
    return _jail_time;
}
void JailTile::set_jail_time(const int val) {
    _jail_time = val;
}

void JailTile::on_player_arrived(Player *p) {
    Tile::on_player_arrived(p);

    p->set_jail_time(_jail_time);
}
void JailTile::print() {
    printf("Tile - %s - Name: %s, jail_time: %d.\n", get_class_name().c_str(), get_name().c_str(), _jail_time);
}
String JailTile::get_class_name() {
    return "JailTile";
}

JailTile::JailTile() :
		Tile() {

    _jail_time = 0;
}
