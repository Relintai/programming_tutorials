#include "math.h"

float Math::inv_sqrt(const float x) {
	return (float)(1.0 / ::sqrtf(x));
}

float Math::fast_inv_sqrt(const float number) {
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));

	return y;
}

float Math::is_equal_approx(const float a, const float b) {
    if (a + EPSILON < b && a - EPSILON > b) {
		return true;
	}

	return false;
}

float Math::is_zero_approx(const float a) {
    if (a + EPSILON < 0 && a - EPSILON > 0) {
		return true;
	}

	return false;
}

void Math::seed(const unsigned int s) {
	srand(s);
}

void Math::randomize() {
	srand(time(NULL));
}

int Math::rand() {
	return ::rand();
}

float Math::randf() {
	return ::rand() / static_cast<float>(RANDOM_32BIT_MAX);
}

double Math::randd() {
	return ::rand() / static_cast<double>(RANDOM_32BIT_MAX);
}

int Math::rand(const int m) {
    return rand() % m;
}

int Math::rand(const int from, const int to) {
    return (rand() % (to - from)) + from;
}

float Math::rand(const float from, const float to) {
	return randf() * (to - from) + from;
}

float Math::rand(const double from, const double to) {
	return randd() * (to - from) + from;
}
