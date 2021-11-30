#include "UserInterfaceRenderer.h"

void UserInterfaceRenderer::draw_text(const std::string& text) const {
	m_inputValidity ? std::cout << text << std::endl << std::endl << "> " : std::cout << text << std::endl << "Please enter a valid input.\n" << std::endl << "> ";
}

void UserInterfaceRenderer::clear_screen() const
{
#if defined _WIN32
	system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined(__APPLE__)
	system("clear");
#endif
}

void UserInterfaceRenderer::draw_vector(const std::vector < std::string >& options) const {
	int counter{ 0 };

	for (const auto& option : options) {
		counter++;
		std::cout << counter << ") " << option << std::endl;
	}

	std::cout << "\n\n";
}

void UserInterfaceRenderer::draw_map(const std::map < char, double >& items) const {
	int c{ 1 };
	std::cout << "\n";
	for (const auto& elem : items)
	{
		std::cout << c << " - Material: " << elem.first << " - Price: " << std::setprecision(2) << elem.second << "\n";
		c++;
	}
}