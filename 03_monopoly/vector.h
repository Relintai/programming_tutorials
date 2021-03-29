#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {

public:
	void push_back(const T &element);
	void pop_back();
	void remove(const int index);
	void remove_keep_order(const int index);
	void erase(const T &element);
	void clear();
	bool empty() const;
	T get(const int index);
	const T &get(const int index) const;
	void set(const int index, const T &value);

	int size() const;
	int capacity() const;
	void ensure_capacity(const int capacity);
	void resize(const int s);
	void append_array(const Vector<T> &other);
	int find(const T &val) const;

	int *dataw();
	const int *data() const;

	const T &operator[](const int index) const;
	T &operator[](const int index);

	Vector();
	Vector(int prealloc);
	Vector(int prealloc, int grow_by);

private:
	T *_data;
	int _actual_size;
	int _size;
	int _grow_by;
};

template <class T>
void Vector<T>::push_back(const T &element) {
	ensure_capacity(_size + 1);

	_data[_size++] = element;
}

template <class T>
void Vector<T>::pop_back() {
	if (_size == 0) {
		return;
	}

	--_size;
}

template <class T>
void Vector<T>::remove(const int index) {
	_data[index] = _data[_size - 1];

	--_size;
}

template <class T>
void Vector<T>::remove_keep_order(const int index) {
	--_size;

	for (int i = index; i < _size; ++i) {
		_data[i] = _data[i + 1];
	}
}

template <class T>
void Vector<T>::erase(const T &element) {
	int index = find(element);

	if (index != -1) {
		remove(index);
	}
}

template <class T>
void Vector<T>::clear() {
	_size = 0;
}

template <class T>
bool Vector<T>::empty() const {
	return _size == 0;
}

template <class T>
T Vector<T>::get(const int index) {
	return _data[index];
}

template <class T>
const T &Vector<T>::get(const int index) const {
	return _data[index];
}

template <class T>
void Vector<T>::set(const int index, const T &value) {
	_data[index] = value;
}

template <class T>
int Vector<T>::size() const {
	return _size;
}

template <class T>
int Vector<T>::capacity() const {
	return _actual_size;
}

template <class T>
void Vector<T>::ensure_capacity(const int capacity) {
	if (capacity <= _actual_size) {
		return;
	}

	int tsize = capacity + _grow_by;

	T *nd = new T[tsize];

	for (int i = 0; i < _size; ++i) {
		nd[i] = _data[i];
	}

	delete[] _data;

	_data = nd;
}

template <class T>
void Vector<T>::resize(const int s) {
	ensure_capacity(s);

	_size = s;
}

template <class T>
void Vector<T>::append_array(const Vector<T> &other) {
	ensure_capacity(_size + other._size);

	for (int i = 0; i < other._size; ++i) {
		_data[_size++] = other._data[i];
	}
}

template <class T>
int Vector<T>::find(const T &val) const {
	for (int i = 0; i < _size; ++i) {
		if (_data[i] == val) {
			return i;
		}
	}

	return -1;
}

template <class T>
int *Vector<T>::dataw() {
	return _data;
}

template <class T>
const int *Vector<T>::data() const {
	return _data;
}

template <class T>
const T &Vector<T>::operator[](const int index) const {
	return _data[index];
}

template <class T>
T &Vector<T>::operator[](const int index) {
	return _data[index];
}

template <class T>
Vector<T>::Vector() {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = 100;
}

template <class T>
Vector<T>::Vector(int prealloc) {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = 100;

	ensure_capacity(prealloc);
}

template <class T>
Vector<T>::Vector(int prealloc, int grow_by) {
	_data = nullptr;
	_actual_size = 0;
	_size = 0;
	_grow_by = grow_by;

	ensure_capacity(prealloc);
}

#endif