#pragma once
#include "ConsoleCanvas.h"

class Entity
{
public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void set_position(Point position) { m_position = position; }
	void move_by(Point offset) { m_position = m_position + offset; };

	inline Point get_position() const { return m_position; }

	virtual void draw(ConsoleCanvas& canvas) = 0;

protected:
	Point m_position{ 0,0 };
};

class Shape : public Entity
{
public:
	Shape() = default;
	~Shape() override = default;

	inline void set_glyph(const char& glyph) { m_glyph = glyph; }
	inline char get_glyph() const { return m_glyph; }
	virtual double get_area() = 0;

private:
	char m_glyph{ '#' };
};
