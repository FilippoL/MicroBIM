#pragma once
#include <string>

#include <iostream>
#include <iomanip>

#include <map>

#include <utility>

#include <vector>

class UserInterfaceRenderer {
public:
	void draw_text(const std::string& text) const;
	void draw_vector(const std::vector < std::string >& options) const;
	void draw_map(const std::map < char, double >& items) const;
	void clear_screen() const;

	void set_validity(bool valid) {
		m_inputValidity = valid;
	}

private:
	bool m_inputValidity = true;
};