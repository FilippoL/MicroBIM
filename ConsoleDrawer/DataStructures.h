#pragma once

#include <vector>
#include <array>
#include <string>

struct Point
{
	int x;
	int y;

	Point operator+ (const Point rhs) const {
		return Point{ this->x + rhs.x, this->y + rhs.y };
	};

	Point operator- (const Point rhs) const {
		return Point{ this->x - rhs.x, this->y - rhs.y };
	};

	bool operator== (const Point rhs) const {
		return ((this->x == rhs.x) && (this->y == rhs.y));
	};

	bool operator!= (const Point rhs) const {
		return ((this->x != rhs.x) && (this->y != rhs.y));
	};

	double get_magnitude() const { return abs(sqrt(this->x ^ 2 + this->y ^ 2)); }
};

struct Material
{
	char material;
	float price;
};

struct Dimension
{
	int w;
	int h;

	Dimension operator= (const std::array<int, 2>& rhs) {
		return Dimension{ rhs[0], rhs[1] };
	};

	bool operator== (const Dimension rhs) const {
		return ((this->w == rhs.w) && (this->h == rhs.h));
	};

	bool operator!= (const Dimension rhs) const {
		return ((this->w != rhs.w) && (this->h != rhs.h));
	};
};
