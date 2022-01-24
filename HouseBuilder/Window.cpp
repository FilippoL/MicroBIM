#include "Window.h"

Window::Window() {
	m_currentLabel = "window";
}

bool Window::initialise_size()
{
	if (m_answered && m_isRound) {
		return m_roundSizeInitialiser.initialise_size(m_currentLabel, m_roundWindow);
	}
	else if (m_answered && !m_isRound) {
		return m_squaredSizeInitialiser.initialise_size(m_currentLabel, m_squaredWindow);
	}

	m_inputRenderer.draw_text("Do you want a (R)ound or (S)quare shaped " + m_currentLabel + "? ");
	m_userAnswer = m_inputHandler.get_parsed_input();

	if (m_userAnswer == "r" || m_userAnswer == "round") {
		m_isRound = true;
		m_answered = true;
	}
	else if (m_userAnswer == "s" || m_userAnswer == "square") {
		m_isRound = false;
		m_answered = true;
	}
	else {
		m_inputRenderer.set_validity(false);
	}

	return false;
}