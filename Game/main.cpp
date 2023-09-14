#include <SFML/Graphics.hpp>
#include <iostream>


float displacement_x = 0.2f;
float displacement_y = 0.2f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "First Game!");

    sf::Texture texture;
   
    if (!texture.loadFromFile("C:/Users/farhan/Desktop/SFML_stuff/mosques.jpg", sf::IntRect(0, 0, 100, 150))) {
        return -1;
    }
    
    auto size_texture = texture.getSize();

    sf::Sprite sprite(texture);
    
    

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        const float x_pos = sprite.getPosition().x;
        const float y_pos = sprite.getPosition().y;

        if (x_pos >= 300 || x_pos < 0) {
            displacement_x = -displacement_x;
        }
        if (y_pos >= 250 || y_pos < 0) {
            displacement_y = -displacement_y;
        }


        window.clear(sf::Color(5, 10, 50));
        sprite.move(sf::Vector2f(displacement_x, displacement_y));
        window.draw(sprite);
        window.display();

    }

    return 0;
}