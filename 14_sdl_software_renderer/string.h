#ifndef STRING_H
#define STRING_H

#include <inttypes.h>

class String {

public:
	void push_back(const char element);
	void pop_back();
	void remove(const int index);
	void erase(const char element);
	void clear();
	bool empty() const;
	char get(const int index);
	const char get(const int index) const;
	void set(const int index, const char value);

	int size() const;
	int capacity() const;
	void ensure_capacity(const int capacity);
	void resize(const int s);
	void append_array(const String &other);
	int find(const char val) const;

	float to_float();
	double to_double();
	int to_int();
	uint32_t to_uint();

	char *c_str();
	const char *c_str() const;

	char *dataw();
	const char *data() const;

	const char operator[](const int index) const;
	char operator[](const int index);

	String &operator+=(const String &b);
	String &operator+=(const char chr);
	String &operator+=(const char *p_c_str);

	friend String operator+(String lhs, const String &rhs);
	friend String operator+(String lhs, const char *rhs);
	friend String operator+(String lhs, const char rhs);

	friend bool operator==(const String &a, const String &b);
	friend bool operator!=(const String &a, const String &b);

	friend bool operator==(const String &a, const char *b);
	friend bool operator!=(const String &a, const char *b);

	friend bool operator==(const char *b, const String &a);
	friend bool operator!=(const char *b, const String &a);

	String();
	String(const String &other);
	String(const String &other, const int grow_by);
	String(const char* p_c_str);
	String(const char* p_c_str, const int grow_by);
	String(const int prealloc);
	String(const int prealloc, const int grow_by);

private:
	char *_data;
	int _actual_size;
	int _size;
	int _grow_by;
};

#endif