#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer");
    sf::RectangleShape rectangle(sf::Vector2f(200, 100)); // Size of the rectangle (width, height)
    rectangle.setFillColor(sf::Color::Blue); // Color of the rectangle
    rectangle.setPosition(400, 250); // Position of the rectangle (x, y)
    sf::Texture TXcrops;

    if (!TXcrops.loadFromFile("crops.png", sf::IntRect(100, 100, 320, 320))) {
        // Handle error
        return -1;
    }
    // run the program as long as the window is open
    sf::Sprite SPcrops(TXcrops);
    SPcrops.setPosition(100, 100);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color(360, 360, 360));
    
        // draw everything here...
        // window.draw(...);
        window.draw(rectangle);
        window.draw(SPcrops);
        // end the current frame
        window.display();
    }

    return 0;
}