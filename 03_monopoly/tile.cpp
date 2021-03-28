#include "tile.h"

#include <stdio.h>

String Tile::get_name() {
	return _name;
}

void Tile::set_name(const String &name) {
	_name = name;
}

void Tile::on_player_arrived(Player *p) {
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
}

void TaxTile::on_player_arrived(Player *p) {
}
String TaxTile::get_class_name() {
	return "TaxTile";
}

TaxTile::TaxTile() :
		Tile() {
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
}
String OwnableTile::get_class_name() {
    return "OwnableTile";
}

OwnableTile::OwnableTile() :
		Tile() {
}

int GainTile::get_gain() const {
    return _gain;
}
void GainTile::set_gain(const int val) {
    _gain = val;
}

void GainTile::on_player_arrived(Player *p) {
}
String GainTile::get_class_name() {
    return "GainTile";
}

GainTile::GainTile() :
		Tile() {
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
}
String LuckTile::get_class_name() {
    return "LuckTile";
}

LuckTile::LuckTile() :
		Tile() {
}

int JailTile::get_jail_time() const {
    return _jail_time;
}
void JailTile::set_jail_time(const int val) {
    _jail_time = val;
}

void JailTile::on_player_arrived(Player *p) {
}
String JailTile::get_class_name() {
    return "JailTile";
}

JailTile::JailTile() :
		Tile() {
}
