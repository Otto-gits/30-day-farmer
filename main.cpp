#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer");
    sf::RectangleShape rectangle(sf::Vector2f(200, 100)); // Size of the rectangle (width, height)
    rectangle.setFillColor(sf::Color::Blue); // Color of the rectangle
    rectangle.setPosition(400, 250); // Position of the rectangle (x, y)
    sf::Texture TXcrops;

    if (!TXcrops.loadFromFile("crops.png", sf::IntRect(0, 0, 550, 75))) {
        std::cerr << "Failed to load crops.png" << std::endl;
        return -1;
    }
    // run the program as long as the window is open
    sf::Sprite SPcrops(TXcrops);
    SPcrops.setPosition(50, 10);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if ()
            }
        }

        // clear the window with black color
        window.clear(sf::Color(255, 255, 255));
    
        // draw everything here...
        // window.draw(...);
        window.draw(rectangle);
        window.draw(SPcrops);
        // end the current frame
        window.display();
    }

    return 0;
}