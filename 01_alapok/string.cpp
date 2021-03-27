#include "string.h"

void String::push_back(const int element) {
	ensure_capacity(_size + 1);

	_data[_size++] = element;
}

void String::pop_back() {
	if (_size == 0) {
		return;
	}

	--_size;
}

void String::remove(const int index) {
	_data[index] = _data[_size - 1];

	--_size;
}

void String::erase(const int element) {
	int index = find(element);

	if (index != -1) {
		remove(index);
	}
}

void String::clear() {
	_size = 0;
}

bool String::empty() const {
	return _size == 0;
}

int String::get(const int index) {
	return _data[index];
}

const int &String::get(const int index) const {
	return _data[index];
}

void String::set(const int index, const int value) {
	_data[index] = value;
}

int String::size() const {
	return _size;
}

int String::capacity() const {
	return _actual_size;
}

void String::ensure_capacity(const int capacity) {
	if (capacity <= _actual_size) {
		return;
	}

	int tsize = capacity + _grow_by;

	int *nd = new int[tsize];

	for (int i = 0; i < _size; ++i) {
		nd[i] = _data[i];
	}

	delete[] _data;

	_data = nd;
}

void String::resize(const int s) {
	ensure_capacity(s);

	_size = s;
}

void String::append_array(const String &other) {
	ensure_capacity(_size + other._size);

	for (int i = 0; i < other._size; ++i) {
		_data[_size++] = other._data[i];
	}
}

int String::find(const int val) const {
	for (int i = 0; i < _size; ++i) {
		if (_data[i] == val) {
			return i;
		}
	}

	return -1;
}

int *String::dataw() {
	return _data;
}

const int *String::data() const {
	return _data;
}

const int &String::operator[](const int index) const {
	return _data[index];
}

int &String::operator[](const int index) {
	return _data[index];
}

String::String() {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = 100;
}

String::String(int prealloc) {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = 100;

	ensure_capacity(prealloc);
}

String::String(int prealloc, int grow_by) {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = grow_by;

	ensure_capacity(prealloc);
}
