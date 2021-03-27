#include "int_vector.h"

void IntVector::push_back(const int element) {
	ensure_capacity(_size + 1);

	_data[_size++] = element;
}

void IntVector::pop_back() {
	if (_size == 0) {
		return;
	}

	--_size;
}

void IntVector::remove(const int index) {
	_data[index] = _data[_size - 1];

	--_size;
}

void IntVector::erase(const int element) {
	int index = find(element);

	if (index != -1) {
		remove(index);
	}
}

void IntVector::clear() {
	_size = 0;
}

bool IntVector::empty() const {
	return _size == 0;
}

int IntVector::get(const int index) {
	return _data[index];
}

const int &IntVector::get(const int index) const {
	return _data[index];
}

void IntVector::set(const int index, const int value) {
	_data[index] = value;
}

int IntVector::size() const {
	return _size;
}

int IntVector::capacity() const {
	return _actual_size;
}

void IntVector::ensure_capacity(const int capacity) {
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

void IntVector::resize(const int s) {
	ensure_capacity(s);

	_size = s;
}

void IntVector::append_array(const IntVector &other) {
	ensure_capacity(_size + other._size);

	for (int i = 0; i < other._size; ++i) {
		_data[_size++] = other._data[i];
	}
}

int IntVector::find(const int val) const {
	for (int i = 0; i < _size; ++i) {
		if (_data[i] == val) {
			return i;
		}
	}

	return -1;
}

int *IntVector::dataw() {
	return _data;
}

const int *IntVector::data() const {
	return _data;
}

const int &IntVector::operator[](const int index) const {
	return _data[index];
}

int &IntVector::operator[](const int index) {
	return _data[index];
}

IntVector::IntVector() {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = 100;
}

IntVector::IntVector(int prealloc) {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = 100;

	ensure_capacity(prealloc);
}

IntVector::IntVector(int prealloc, int grow_by) {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = grow_by;

	ensure_capacity(prealloc);
}
