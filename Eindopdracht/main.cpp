#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Huwwo UwU x3 xoxo");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    float posX = 200.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed 
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            // Move right
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                posX += 10;
            }

            // Move left
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                posX -= 10;
            }
        }

        window.clear();
        window.draw(shape);
        shape.setPosition(posX, 50);
        window.display();

        if (posX > 640) 
        {
            posX = -200.f;
        }
        if (posX < 100) 
        {
            posX = 640.f;
        }
    }

    return 0;
}