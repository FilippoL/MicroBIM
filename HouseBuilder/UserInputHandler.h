#pragma once
#include <iostream>

#include <string>

#include <locale>

#include <regex>

#include <array>

#include <iostream>

#include "DataStructures.h"

class UserInputHandler {
public:
	std::string get_parsed_input();

	void split_on_identifier(std::string const& str, Dimension& out, std::string const& identifier) const;

	bool is_true() const;
	bool is_valid() const;
	bool sentence_contains(const std::string& sentence, const std::string& word) const;

	bool is_true_or_false(const std::string& str);
	bool is_number(const std::string& str) const;

	void clean_string(std::string& out) const;
	void wait_for_user_input() const;

private:
	bool m_valid = false;
	bool m_isTrue = true;

	std::string m_input;
};