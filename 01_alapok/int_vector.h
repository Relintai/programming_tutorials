#ifndef IntVector_H
#define IntVector_H

class IntVector {

public:
	void push_back(const int element);
	void pop_back();
	void remove(const int index);
	void erase(const int element);
	void clear();
	bool empty() const;
	int get(const int index);
	const int &get(const int index) const;
	void set(const int index, const int value);

	int size() const;
	int capacity() const;
	void ensure_capacity(const int capacity);
	void resize(const int s);
	void append_array(const IntVector &other);
	int find(const int val) const;

	int *dataw();
	const int *data() const;

	const int &operator[](const int index) const;
	int &operator[](const int index);

	IntVector();
	IntVector(int prealloc);
	IntVector(int prealloc, int grow_by);

private:
	int *_data;
	int _actual_size;
	int _size;
	int _grow_by;
};

#endif