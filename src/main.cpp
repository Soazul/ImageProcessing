#include "filters.hpp"
#include "button.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(){
	std::string filename;
	sf::Image img;
	Filter f(1200, 675);	
	sf::RenderWindow renderWindow(sf::VideoMode(1375, 725),"Image Filters");
	renderWindow.setFramerateLimit(60);
	
	int animalCounter = 0;
	int animeCounter = 0;
	int buildingCounter = 0;
	int natureCounter = 0;
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) std::cout << "Font not found!\n";
		Button original("Original Image");
		original.SetFont(font);
		original.SetPosition({1225.0f, 3.0f});
		original.Render(renderWindow);
		Button red("Red Filter");
		red.SetFont(font);
		red.SetPosition({1225.0f, 38.0f});
		red.Render(renderWindow);
		Button green("Green Filter");
		green.SetFont(font);
		green.SetPosition({1225.0f, 73.0f});
		green.Render(renderWindow);
		Button blue("Blue Filter");
		blue.SetFont(font);
		blue.SetPosition({1225.0f, 108.0f});
		blue.Render(renderWindow);
		Button vertical("Vertical Flip");
		vertical.SetFont(font);
		vertical.SetPosition({1225.0f, 143.0f});
		vertical.Render(renderWindow);
		Button horizontal("Horizontal Flip");
		horizontal.SetFont(font);
		horizontal.SetPosition({1225.0f, 178.0f});
		horizontal.Render(renderWindow);
		Button grayscale("Grayscale Filter");
		grayscale.SetFont(font);
		grayscale.SetPosition({1225.0f, 213.0f});
		grayscale.Render(renderWindow);
		Button threshold("Threshold Filter");
		threshold.SetFont(font);
		threshold.SetPosition({1225.0f, 248.0f});
		threshold.Render(renderWindow);
		Button blur("Blur Filter");
		blur.SetFont(font);
		blur.SetPosition({1225.0f, 283.0f});
		blur.Render(renderWindow);
		Button sharpen("Sharpen Filter");
		sharpen.SetFont(font);
		sharpen.SetPosition({1225.0f, 318.0f});
		sharpen.Render(renderWindow);
		Button sepia("Sepia Tone Filter");
		sepia.SetFont(font);
		sepia.SetPosition({1225.0f, 353.0f});
		sepia.Render(renderWindow);
		Button intensity("Intensity Filter");
		intensity.SetFont(font);
		intensity.SetPosition({1225.0f, 388.0f});
		intensity.Render(renderWindow);
		Button edge("Edge Filter");
		edge.SetFont(font);
		edge.SetPosition({1225.0f, 423.0f});
		edge.Render(renderWindow);
		Button sobelX("Sobel-X Filter");
		sobelX.SetFont(font);
		sobelX.SetPosition({1225.0f, 458.0f});
		sobelX.Render(renderWindow);
		Button sobelY("Sobel-Y Filter");
		sobelY.SetFont(font);
		sobelY.SetPosition({1225.0f, 493.0f});
		sobelY.Render(renderWindow);
		Button brightness("Brightness");
		brightness.SetFont(font);
		brightness.SetPosition({1225.0f, 528.0f});
		brightness.Render(renderWindow);
		Button save("Save Image");
		save.SetFont(font);
		save.SetPosition({1225.0f, 647.0f});
		save.Render(renderWindow);
		Button animal("Animal Image");
		animal.SetFont(font);
		animal.SetPosition({50.0f, 687.0f});
		animal.Render(renderWindow);
		Button anime("Anime Image");
		anime.SetFont(font);
		anime.SetPosition({225.0f, 687.0f});
		anime.Render(renderWindow);
		Button building("Building Image");
		building.SetFont(font);
		building.SetPosition({400.0f, 687.0f});
		building.Render(renderWindow);
		Button nature("Nature Image");
		nature.SetFont(font);
		nature.SetPosition({575.0f, 687.0f});
		nature.Render(renderWindow);
		
		sf::RectangleShape introduction;
		sf::Text introMessage;
		introMessage.setString("Welcome to my image filter! \nThe right buttons are filter options." 
		"\nThe buttom buttons are image options. \nPress on any of the buttom buttons to get started.");
		introduction.setSize({460, 100});
		introduction.setFillColor(sf::Color::White);
		introduction.setOutlineColor(sf::Color::Blue);
		introduction.setOutlineThickness(3.0f);
		introduction.setPosition({375, 300});
		introMessage.setFont(font);
		introMessage.setCharacterSize(20);
		introMessage.setFillColor(sf::Color::Black);
		introMessage.setPosition({375, 300});
		renderWindow.draw(introduction);
		renderWindow.draw(introMessage);
		renderWindow.display();
			
		while(renderWindow.isOpen()){
			sf::Event event;
			while (renderWindow.pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:
				renderWindow.close();
			case sf::Event::MouseButtonPressed:
				if(original.IsMouseHovering(renderWindow)){
					f.DisplayImage(img, renderWindow);
				}
				if (red.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.RedFilter(img), renderWindow);
				}
				if (green.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.GreenFilter(img), renderWindow);
				}
				if(blue.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.BlueFilter(img), renderWindow);
				}
				if(vertical.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.VerticalFlip(img), renderWindow);
				}
				if(horizontal.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.HorizontalFlip(img), renderWindow);
				}
				if(grayscale.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.GrayscaleFilter(img), renderWindow);
				}
				if(threshold.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.ThresholdFilter(img, 100), renderWindow);
				}
				if(blur.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.Blur(img), renderWindow);
				}
				if(sharpen.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.Sharpen(img), renderWindow);
				}
				if(sepia.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.SepiaTone(img), renderWindow);
				}
				if(intensity.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.IntensityGrayscale(img), renderWindow);
				}
				if(edge.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.EdgeFilter(img), renderWindow);
				}
				if(sobelX.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.SobelX(img), renderWindow);
				}
				if(sobelY.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.SobelY(img), renderWindow);
				}
				if(brightness.IsMouseHovering(renderWindow)){
					f.DisplayImage(f.Brighten(img, 100), renderWindow);
				}
				if(animal.IsMouseHovering(renderWindow)){
					filename = "animal.jpg";
					img.loadFromFile(filename);
					f.DisplayImage(img, renderWindow);
				}
				if(anime.IsMouseHovering(renderWindow)){
					filename = "anime.jpg";
					img.loadFromFile(filename);
					f.DisplayImage(img, renderWindow);
				}
				if(building.IsMouseHovering(renderWindow)){
					filename = "building.jpg";
					img.loadFromFile(filename);
					f.DisplayImage(img, renderWindow);
				}
				if(nature.IsMouseHovering(renderWindow)){
					filename = "nature.jpg";
					img.loadFromFile(filename);
					f.DisplayImage(img, renderWindow);
				}
				if(save.IsMouseHovering(renderWindow)){
					sf::Texture texture;
					texture.create(1375, 725);
					texture.update(renderWindow);
					sf::Image screenshot;
					screenshot.create(1200, 675, sf::Color::Transparent);
					screenshot.copy(texture.copyToImage(), 0, 0);
					if(filename == "animal.jpg"){
						screenshot.saveToFile(std::to_string(animalCounter) + "-" + filename);
						animalCounter++;
					}else if(filename == "anime.jpg"){
						screenshot.saveToFile(std::to_string(animeCounter) + "-" + filename);
						animeCounter++;
					}else if(filename == "building.jpg"){
						screenshot.saveToFile(std::to_string(buildingCounter) + "-" + filename);
						buildingCounter++;
					}else {
						screenshot.saveToFile(std::to_string(natureCounter) + "-" + filename);
						natureCounter++;
					}
				}
			}
		}
	}
}
		
