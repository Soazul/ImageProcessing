#include "filters.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

// constructor
Filter::Filter(unsigned int width, unsigned int height) {
	this->m_width = width;
	this->m_height = height;
}

void Filter::DisplayImage(sf::Image src, sf::RenderWindow& window){
	// create an image, texture, sprite
	sf::Vector2f resize(1200.0f, 675.0f); 
	sf::Texture texture;
	texture.loadFromImage(src);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(resize.x / sprite.getLocalBounds().width, resize.y / sprite.getLocalBounds().height);
	window.draw(sprite);
	window.display();
}

sf::Image Filter::RedFilter(sf::Image src){
	sf::Image subImage = src;
	sf::Texture texture;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			subImage.setPixel(x, y, sf::Color(color.r, 0, 0, color.a));
		}
	}
	return subImage;
}

sf::Image Filter::GreenFilter(sf::Image src){
	sf::Image subImage = src;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			subImage.setPixel(x, y, sf::Color(0, color.g, 0, color.a));
		}
	}
	return subImage;
}

sf::Image Filter::BlueFilter(sf::Image src){
	sf::Image subImage = src;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			subImage.setPixel(x, y, sf::Color(0, 0, color.b, color.a));
		}
	}
	return subImage;
}
sf::Image Filter::VerticalFlip(sf::Image src){
	sf::Image subImage = src;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x, y); 
			sf::Color color2 = src.getPixel(x, m_height-1-y);
			subImage.setPixel(x, y, color2);
			subImage.setPixel(x, m_height-1-y, color);
		}
	}
	return subImage;
}

sf::Image Filter::HorizontalFlip(sf::Image src){
	sf::Image subImage = src;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x, y); 
			sf::Color color2 = src.getPixel(m_width-x-1, y);
			subImage.setPixel(x, y, color2);
			subImage.setPixel(m_width-x-1, y, color);
		}
	}
	return subImage;
}

sf::Image Filter::GrayscaleFilter(sf::Image src){
	sf::Image subImage = src;
	
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			int avgColor = color.r * 0.29 + color.g*0.59 + color.b*0.11;
			subImage.setPixel(x, y, sf::Color(avgColor, avgColor, avgColor));
		}
	}
	return subImage;
}

sf::Image Filter::ThresholdFilter(sf::Image src, int threshold){
	sf::Image subImage = src;
	
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			int avgColor = color.r * 0.29 + color.g*0.59 + color.b*0.11;
			subImage.setPixel(x, y, sf::Color(avgColor, avgColor, avgColor));
			if (avgColor < threshold) {
				subImage.setPixel(x, y, sf::Color(0, 0, 0));
			}
			
		}
	}
	return subImage;
}

sf::Image Filter::Blur(sf::Image src){
	sf::Image subImage = src;
	for(int x = 1; x < m_width-1; x++){
		for(int y = 1; y < m_height-1; y++){
			sf::Color topLeft = src.getPixel(x-1,y-1);
			sf::Color topMiddle = src.getPixel(x,y-1);
			sf::Color topRight= src.getPixel(x+1, y-1);
			sf::Color midLeft = src.getPixel(x-1, y);
			sf::Color mid = src.getPixel(x,y);
			sf::Color midRight = src.getPixel(x+1,y);
			sf::Color botLeft = src.getPixel(x-1, y+1);
			sf::Color botMiddle = src.getPixel(x, y+1);
			sf::Color botRight = src.getPixel(x+1, y+1);
			float r = (1.0/16.0)*(topLeft.r + 2*topMiddle.r + topRight.r + 2*midLeft.r + 4*mid.r + 2*midRight.r + botLeft.r + 2*botMiddle.r + botRight.r);
			float g = (1.0/16.0)*(topLeft.g + 2*topMiddle.g + topRight.g + 2*midLeft.g + 4*mid.g + 2*midRight.g + botLeft.g + 2*botMiddle.g + botRight.g);
			float b = (1.0/16.0)*(topLeft.b + 2*topMiddle.b + topRight.b + 2*midLeft.b + 4*mid.b + 2*midRight.b + botLeft.b + 2*botMiddle.b + botRight.b);
			subImage.setPixel(x, y, sf::Color(r, g, b));
		}
	}
	return subImage;
}

sf::Image Filter::Sharpen(sf::Image src){
	sf::Image subImage = src;
	for(int x = 1; x < m_width-1; x++){
		for(int y = 1; y < m_height-1; y++){
			sf::Color topLeft = src.getPixel(x-1,y-1);
			sf::Color topMiddle = src.getPixel(x,y-1);
			sf::Color topRight= src.getPixel(x+1, y-1);
			sf::Color midLeft = src.getPixel(x-1, y);
			sf::Color mid = src.getPixel(x, y);
			sf::Color midRight = src.getPixel(x+1,y);
			sf::Color botLeft = src.getPixel(x-1, y+1);
			sf::Color botMiddle = src.getPixel(x, y+1);
			sf::Color botRight = src.getPixel(x+1, y+1);
			float r = -topLeft.r - topMiddle.r - topRight.r - midLeft.r + 9*mid.r - midRight.r - botLeft.r - botMiddle.r - botRight.r;
			float g = -topLeft.g - topMiddle.g - topRight.g - midLeft.g + 9*mid.g - midRight.g - botLeft.g - botMiddle.g - botRight.g;
			float b = -topLeft.b - topMiddle.b - topRight.b - midLeft.b + 9*mid.b - midRight.b - botLeft.b - botMiddle.b - botRight.b;
			if (r > 255 || g > 255 || b > 255){
				r = 255;
				g = 255;
				b = 255;
			}
			if (r < 0 || g < 0 || b < 0){
				r = 0;
				g = 0;
				b = 0;
			}
			subImage.setPixel(x, y, sf::Color(r, g, b));
		}
	}
	return subImage;
}

sf::Image Filter::SepiaTone(sf::Image src){
	sf::Image subImage = src;
	for(int x = 1; x < m_width-1; x++){
		for(int y = 1; y < m_height-1; y++){
			sf::Color topLeft = src.getPixel(x-1,y-1);
			sf::Color topMiddle = src.getPixel(x,y-1);
			sf::Color topRight= src.getPixel(x+1, y-1);
			sf::Color midLeft = src.getPixel(x-1, y);
			sf::Color mid = src.getPixel(x, y);
			sf::Color midRight = src.getPixel(x+1,y);
			sf::Color botLeft = src.getPixel(x-1, y+1);
			sf::Color botMiddle = src.getPixel(x, y+1);
			sf::Color botRight = src.getPixel(x+1, y+1);
			float r = topLeft.r*0.393 + topMiddle.g*0.769 + topRight.b*0.189;
			float g = midLeft.r*0.349 + mid.g*0.686 + midRight.b*0.168;
			float b = botLeft.r*0.272 + botMiddle.g*0.534 + botRight.b*0.131;
			if (r > 255 || g > 255 || b > 255){
				r = 255;
				g = 255;
				b = 255;
			}
			subImage.setPixel(x, y, sf::Color(r, g, b));

		}
	}
	return subImage;
}

sf::Image Filter::IntensityGrayscale(sf::Image src){
	sf::Image subImage = src;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			int avgColor = color.r + color.g + color.b;
			subImage.setPixel(x, y, sf::Color(avgColor, avgColor, avgColor));
		}
	}
	return subImage;
}

sf::Image Filter::EdgeFilter(sf::Image src){
	sf::Vector2u size = src.getSize();
	sf::Image subImage = src;
	sf::Image grayImage = GrayscaleFilter(subImage);
	sf::Image edgeImage;
	edgeImage.create(size.x, size.y);
	for(int x = 1; x < m_width-1; x++){
		for(int y = 1; y < m_height-1; y++){
			sf::Color topLeft = grayImage.getPixel(x-1,y-1);
			sf::Color topMiddle = grayImage.getPixel(x,y-1);
			sf::Color topRight= grayImage.getPixel(x+1, y-1);
			sf::Color midLeft = grayImage.getPixel(x-1, y);
			sf::Color mid = grayImage.getPixel(x, y);
			sf::Color midRight = grayImage.getPixel(x+1,y);
			sf::Color botLeft = grayImage.getPixel(x-1, y+1);
			sf::Color botMiddle = grayImage.getPixel(x, y+1);
			sf::Color botRight = grayImage.getPixel(x+1, y+1);
			float r = -topLeft.r - topMiddle.r - topRight.r - midLeft.r + 4*mid.r - midRight.r - botLeft.r - botMiddle.r - botRight.r;
			edgeImage.setPixel(x, y, sf::Color(r, r, r));
		}
	}
	return edgeImage;
}

sf::Image Filter::SobelX(sf::Image src){
	sf::Image subImage = src;
		for(int x = 1; x < m_width-1; x++){
		for(int y = 1; y < m_height-1; y++){
			sf::Color topLeft = src.getPixel(x-1,y-1);
			sf::Color topMiddle = src.getPixel(x,y-1);
			sf::Color topRight= src.getPixel(x+1, y-1);
			sf::Color midLeft = src.getPixel(x-1, y);
			sf::Color mid = src.getPixel(x, y);
			sf::Color midRight = src.getPixel(x+1,y);
			sf::Color botLeft = src.getPixel(x-1, y+1);
			sf::Color botMiddle = src.getPixel(x, y+1);
			sf::Color botRight = src.getPixel(x+1, y+1);
			float r = topLeft.r - topRight.r + 2*midLeft.r - 2*midRight.r + botLeft.r - botRight.r;
			subImage.setPixel(x, y, sf::Color(r, r, r));

		}
	}
	return subImage;
}

sf::Image Filter::SobelY(sf::Image src){
	sf::Image subImage = src;
		for(int x = 1; x < m_width-1; x++){
		for(int y = 1; y < m_height-1; y++){
			sf::Color topLeft = src.getPixel(x-1,y-1);
			sf::Color topMiddle = src.getPixel(x,y-1);
			sf::Color topRight= src.getPixel(x+1, y-1);
			sf::Color midLeft = src.getPixel(x-1, y);
			sf::Color mid = src.getPixel(x, y);
			sf::Color midRight = src.getPixel(x+1,y);
			sf::Color botLeft = src.getPixel(x-1, y+1);
			sf::Color botMiddle = src.getPixel(x, y+1);
			sf::Color botRight = src.getPixel(x+1, y+1);
			float r = -topLeft.r - 2*topMiddle.r - topRight.r + botLeft.r + 2*botMiddle.r + botRight.r;
			subImage.setPixel(x, y, sf::Color(r, r, r));

		}
	}
	return subImage;
}

sf::Image Filter::Brighten(sf::Image src, int brightenFactor){
	sf::Image subImage = src;
	for(int x = 0; x < m_width; x++){
		for(int y = 0; y < m_height; y++){
			sf::Color color = src.getPixel(x,y);
			float r = std::min(std::max(color.r + brightenFactor, 0), 255);
			float g = std::min(std::max(color.g + brightenFactor, 0), 255);
			float b = std::min(std::max(color.b + brightenFactor, 0), 255);
			subImage.setPixel(x, y, sf::Color(r, g, b));
		}
	}
	return subImage;
}
