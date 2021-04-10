#ifndef MATH_H
#define MATH_H

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>

#define MATH_PI 3.1415926535897932384626433833
#define EPSILON 0.00001

class Math {
public:

    static const uint64_t RANDOM_32BIT_MAX = 0xFFFFFFFF;

    inline static float sin(const float x) { return ::sinf(x); }
    inline static double sin(const double x) { return ::sin(x); }

    inline static float cos(const float x) { return ::cosf(x); }
    inline static double cos(const double x) { return ::cos(x); }

    inline static float tan(const float x) { return ::tanf(x); }
    inline static double tan(const double x) { return ::tan(x); }

    inline static float asin(const float x) { return ::asinf(x); }
    inline static double asin(const double x) { return ::asin(x); }

    inline static float acos(const float x) { return ::acosf(x); }
    inline static double acos(const double x) { return ::acos(x); }

    inline static float atan(const float x) { return ::atanf(x); }
    inline static double atan(const double x) { return ::atan(x); }

    inline static float atan2(const float x, const float y) { return ::atan2f(x, y); }
    inline static double atan2(const double x, const float y) { return ::atan2(x, y); }

    inline static float sqrt(const float x) { return ::sqrtf(x); }
    inline static double sqrt(const double x) { return ::sqrt(x); }

    inline static float fmod(const float x, const float y) { return ::fmodf(x, y); }
    inline static double fmod(const double x, const float y) { return ::fmod(x, y); }

    inline static float floor(const float x) { return ::floorf(x); }
    inline static double floor(const double x) { return ::floor(x); }

    inline static float ceil(const float x) { return ::ceilf(x); }
    inline static double ceil(const double x) { return ::ceil(x); }

    inline static float pow(const float x, const float y) { return ::powf(x, y); }
    inline static double pow(const double x, const float y) { return ::pow(x, y); }

    inline static float log(const float x) { return ::logf(x); }
    inline static double log(const double x) { return ::log(x); }

    static float inv_sqrt(const float x);
    static float fast_inv_sqrt(const float x);

    inline static float abs(const float x) { return x > 0 ? x : -x; }
    inline static double abs(const double x) { return x > 0 ? x : -x; }
    inline static int abs(const int x) { return x > 0 ? x : -x; }

    inline static float deg2rad(const float x) { return x * MATH_PI / 180.0; }
    inline static double deg2rad(const double x) { return x * MATH_PI / 180.0; }
    inline static int deg2rad(const int x) { return x * MATH_PI / 180.0; }

    inline static float rad2deg(const float x) { return x * 180.0 / MATH_PI; }
    inline static double rad2deg(const double x) { return x * 180.0 / MATH_PI; }
    inline static int rad2deg(const int x) { return x * 180.0 / MATH_PI; }

    static float is_equal_approx(const float a, const float b);
    static float is_zero_approx(const float a);

    static void seed(const unsigned int s);
    static void randomize();

    static int rand();
    static float randf();
    static double randd();

    static int rand(const int m);

    static int rand(const int from, const int to);
    static float rand(const float from, const float to);
    static float rand(const double from, const double to);

};

#endif
