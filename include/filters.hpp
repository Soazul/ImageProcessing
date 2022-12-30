#ifndef FILTER_HPP
#define FILTER_HPP

#include <SFML/Graphics.hpp>

class Filter{
private:
	unsigned int m_width, m_height;
public:
	Filter(unsigned int_width, unsigned int height);
	void DisplayImage(sf::Image src, sf::RenderWindow& window);
	sf::Image RedFilter(sf::Image src);
	sf::Image GreenFilter(sf::Image src);
	sf::Image BlueFilter(sf::Image src);
	sf::Image VerticalFlip(sf::Image src);
	sf::Image HorizontalFlip(sf::Image src);
	sf::Image GrayscaleFilter(sf::Image src);
	sf::Image ThresholdFilter(sf::Image src, int threshold);
	sf::Image Blur(sf::Image src);
	sf::Image Sharpen(sf::Image src);
	sf::Image SepiaTone(sf::Image src);
	sf::Image IntensityGrayscale(sf::Image src);
	sf::Image EdgeFilter(sf::Image src);
	sf::Image SobelX(sf::Image src);
	sf::Image SobelY(sf::Image src);
	sf::Image Brighten(sf::Image src, int brightenFactor);
};
#endif
