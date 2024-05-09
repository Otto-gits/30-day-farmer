#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer");
    sf::RectangleShape rectangle(sf::Vector2f(200, 100)); // Size of the rectangle (width, height)
    rectangle.setFillColor(sf::Color::Blue); // Color of the rectangle
    rectangle.setPosition(400, 250); // Position of the rectangle (x, y)
    // run the program as long as the window is open
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
        window.clear(sf::Color(139, 69, 19));
    
        // draw everything here...
        // window.draw(...);
        window.draw(rectangle);
        // end the current frame
        window.display();
    }

    return 0;
}