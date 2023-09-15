#include <SFML/Graphics.hpp>
#include <iostream>


float displacement_x = 0.2f;
float displacement_y = 0.2f;
bool opaque_x = true;
bool opaque_y = true;


void set_transparency(sf::Color& color) {

    if (opaque_x == false || opaque_y == false) {
        color.a = 255;
        if (opaque_x == false) {
            opaque_x = true;
        }
        else {
            opaque_y = true;
        }
    }
    else {
        color.a = 50;
        if (opaque_x == true) {
            opaque_x = false;
        }
        else {
            opaque_y = false;
        }
    }
}

void set_transparency_sprite(sf::Sprite& sprite) {
    sf::Color color = sprite.getColor();
    set_transparency(color);
    sprite.setColor(color);
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "First Game!");

    sf::Texture texture;
   
    if (!texture.loadFromFile("C:/Users/farhan/Desktop/SFML_stuff/mosques.jpg", sf::IntRect(0, 0, 100, 150))) {
        return -1;
    }
    
    //auto size_texture = texture.getSize();

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
            set_transparency_sprite(sprite);
            displacement_x = -displacement_x;
        }
        if (y_pos >= 250 || y_pos < 0) {
            set_transparency_sprite(sprite);
            displacement_y = -displacement_y;
        }


        window.clear(sf::Color(5, 10, 50));
        sprite.move(sf::Vector2f(displacement_x, displacement_y));
        window.draw(sprite);
        window.display();

    }

    return 0;
}