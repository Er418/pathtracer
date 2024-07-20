#ifndef BASIC_RAYTRACING_COLOR_H
#define BASIC_RAYTRACING_COLOR_H

#include <array>

class color {
public:
    color() : values{0.0, 0.0, 0.0} {};

    color(double r, double g, double b) : values{r, g, b} {};

    double r() const { return values[0]; };

    double g() const { return values[1]; };

    double b() const { return values[2]; };


    int r255() const { return std::max(0, std::min(255, int(255.999 * linear_to_gamma(r())))); };

    int g255() const { return std::max(0, std::min(255, int(255.999 * linear_to_gamma(g())))); };

    int b255() const { return std::max(0, std::min(255, int(255.999 * linear_to_gamma(b())))); };


    double operator[](int i) const { return values[i]; }

    double &operator[](int i) { return values[i]; }

    color operator+(const color &other) const {
        return {r() + other.r(), g() + other.g(), b() + other.b()};
    }

    color operator+=(const color &other) {
        values[0] += other.values[0];
        values[1] += other.values[1];
        values[2] += other.values[2];
        return *this;
    }

    color operator-(const color &other) const {
        return {r() - other.r(), g() - other.g(), b() - other.b()};
    }

    color operator-=(const color &other) {
        values[0] -= other.values[0];
        values[1] -= other.values[1];
        values[2] -= other.values[2];
        return *this;
    }

    color operator*(const color &other) const {
        return {r() * other.r(), g() * other.g(), b() * other.b()};
    }

    color operator*=(double k) {
        values[0] *= k;
        values[1] *= k;
        values[2] *= k;
        return *this;
    }

    color operator/=(double k) {
        return *this *= 1 / k;
    }

    static double linear_to_gamma(double linear_component) {
        if (linear_component > 0)
            return sqrt(linear_component);

        return 0;
    }


private:
    std::array<double, 3> values;
};

inline color operator*(double k, const color &c) {
    return {k * c.r(), k * c.g(), k * c.b()};
}

inline color operator*(const color &c, double k) {
    return k * c;
}

inline color operator/(const color &c, double k) {
    return (1 / k) * c;
}

class display_rgb {
public:
    display_rgb() : values{0, 0, 0} {};

    display_rgb(int r, int g, int b) : values{r, g, b} {};

    explicit display_rgb(const color &c) : values{c.r255(), c.g255(), c.b255()} {};

    int r() const { return values[0]; };

    int g() const { return values[1]; };

    int b() const { return values[2]; };

    int operator[](int i) const { return values[i]; }

    int &operator[](int i) { return values[i]; }

    void write(std::ostream &out) const {
        out << r() << ' ' << g() << ' ' << b() << '\n';
    }

private:
    std::array<int, 3> values;
};

#endif //BASIC_RAYTRACING_COLOR_H
