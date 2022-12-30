#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Button{
private:
	sf::RectangleShape button;
	sf::Text message;
public:
	Button(std::string message);
	void SetFont(sf::Font &font);
	void SetPosition(sf::Vector2f position);
	void Render(sf::RenderWindow &window);
	bool IsMouseHovering(sf::RenderWindow &window);
};
#endif
