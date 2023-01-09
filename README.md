## [Screenshots]
Sobel-X Filter
![sobelXanimal](https://user-images.githubusercontent.com/98858820/210124941-e6de3e32-281d-4264-89a9-70f984ee1c07.jpg)
Sepia Tone Filter
![sepiabuilding](https://user-images.githubusercontent.com/98858820/210125116-3f84bf61-8f95-4c1b-a49d-6bd21ab65aa3.jpg)
Blue Filter
![bluepeople](https://user-images.githubusercontent.com/98858820/210125119-19240441-ea73-4db7-9f38-46bac24359cf.jpg)
## [Description]
I designed an image processor that incorporated the functional of saving the filtered image. The filters I included in this program are the following:
- Red Filter: displays an image with only red pixels
- Green Filter: displays an image with only green pixels
- Blue Filter: displays an image with only blue pixels
- Vertical Flip: displays an image that is vertically flipped
- Horizontal Flip: displays an image that is horionztally flipped
- Grayscale Filter: displays an image that is gray
- Threshold Filter: displays an image that is black and white, with the threshold of 100
- Blur Filter: displays an image that is blurred
- Sharpen Filter: displays an image with accentuated edge
- Sepia Tone Filter: displays an image with reddish brown tone
- Intensity Grayscale Filter: dispalys an image with intensity grayscale
- Edge Filter: displays an image with only the edges
- Sobel-X Filter: displays an image with only vertical edges
- Sobel-Y Filter: displays an image with only horizontal edges
- Brightness: displays an image that is brighten by a factor of 100
## [Compile and Run]
Download SFML 2.5.1: https://www.sfml-dev.org/download/sfml/2.5.1/

Compile with: g++ -std=c++17 -g ./src/*.cpp -I./include -o prog -lsfml-graphics -lsfml-window -lsfml-system

Run with: ./prog
## [Future Updates]
- Allow the user to upload an image file 
- Allow the user to apply multiple filters
- Allow the user to resize the window
- Support more challenging image filters (salt and pepper noise, tone mapping, etc)
- Use abstraction (inheritance or composition) to reduce code repetition
