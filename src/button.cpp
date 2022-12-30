#include "button.hpp"
#include <SFML/Graphics.hpp>

//constructor
Button::Button(std::string txt){
	message.setString(txt);
	button.setSize({125, 25});
	button.setFillColor(sf::Color::White);
	button.setOutlineColor(sf::Color::Blue);
	button.setOutlineThickness(3.0f);
}

// design the message
void Button::SetFont(sf::Font &font){
	message.setFont(font);
	message.setCharacterSize(16);
	message.setFillColor(sf::Color::Black);
}

// center the message on the button
void Button::SetPosition(sf::Vector2f position){
	button.setPosition(position);
	float posX = (position.x + button.getLocalBounds().width/3) -
                  (message.getLocalBounds().width/3);
    float posY = (position.y + button.getLocalBounds().height/3) -
                  (message.getLocalBounds().height/2);
    message.setPosition({posX, posY});
}

// draw the button and message
void Button::Render(sf::RenderWindow &window){
	window.draw(button);
	window.draw(message);
}

// determine if the mouse is in the button
bool Button::IsMouseHovering(sf::RenderWindow &window){
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;
	float buttonX = button.getPosition().x;
	float buttonY = button.getPosition().y;
	//the end position for the button
	float buttonWidth = buttonX + button.getLocalBounds().width;
	float buttonHeight = buttonY + button.getLocalBounds().height;
	//if the mouse is within the button's boundaries
	if(mouseX < buttonWidth && mouseX > buttonX && mouseY < buttonHeight && mouseY > buttonY){
		return true;
	} else {
		return false;
	}
}
