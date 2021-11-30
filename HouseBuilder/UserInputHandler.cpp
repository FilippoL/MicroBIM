#include "UserInputHandler.h"

std::string UserInputHandler::get_parsed_input() {
	std::getline(std::cin, m_input);

	std::regex regx("[@_!$%^&()<>?/|}{~:Lèàùòs+]");

	clean_string(m_input);

	if (std::regex_search(m_input, regx) == 0) {
		m_valid = true;
		return m_input;
	}
	else {
		m_valid = false;
		return "";
	}
}

void UserInputHandler::split_on_identifier(std::string const& str, Dimension& out, std::string const& identifier) const
{
	size_t start{ 0 };
	size_t end{ 0 };

	end = str.find(identifier, start);

	if (end == str.length() - 1) {
		out.w = 0;
		out.h = 0;
		return;
	}

	out.w = is_number(str.substr(start, end - start)) ? stoi(str.substr(start, end - start)) : 0;
	out.h = is_number(str.substr((end - start) + 1, str.length())) ? stoi(str.substr((end - start) + 1, str.length())) : 0;
}

bool UserInputHandler::is_true() const
{
	return m_isTrue;
}

bool UserInputHandler::is_valid() const
{
	return m_valid;
}

void UserInputHandler::clean_string(std::string& out) const {
	std::transform(out.begin(), out.end(), out.begin(), ::tolower);
	out.erase(std::remove(out.begin(), out.end(), ' '), out.end());
}

bool UserInputHandler::sentence_contains(const std::string& sentence, const std::string& word) const {
	const auto& pattern{ word };

	auto rx = std::regex{
		pattern,
		std::regex_constants::icase
	};

	return std::regex_search(sentence, rx);
}

void UserInputHandler::wait_for_user_input() const
{
	std::cout << "\nPress ENTER to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}

bool UserInputHandler::is_true_or_false(const std::string& str) {
	if (str == "t" || str == "true" || str == "1" || str == "vero") {
		m_isTrue = true;
		return true;
	}
	else if (str == "f" || str == "false" || str == "0" || str == "falso") {
		m_isTrue = false;
		return true;
	}
	else {
		return false;
	}
}

bool UserInputHandler::is_number(const std::string& str) const {
	return 	std::all_of(str.begin(), str.end(), ::isdigit);
}