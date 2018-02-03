#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Rectangles and circle");

    window.clear();

    /*K*/
    sf::RectangleShape shape1;
    shape1.setSize({150, 30});
    shape1.setRotation(90);
    shape1.setPosition({200, 120});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({100, 30});
    shape2.setRotation(45);
    shape2.setPosition({200, 180});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({80, 30});
    shape3.setRotation(-45);
    shape3.setPosition({200, 180});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape3);

    /*M*/
    sf::RectangleShape shape4;
    shape4.setSize({150, 30});
    shape4.setRotation(90);
    shape4.setPosition({320, 120});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({100, 30});
    shape5.setRotation(45);
    shape5.setPosition({320, 120});
    shape5.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({100, 30});
    shape6.setRotation(-45);
    shape6.setPosition({350, 191});
    shape6.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({150, 30});
    shape7.setRotation(90);
    shape7.setPosition({450, 120});
    shape7.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape7);

    /*V*/
    sf::RectangleShape shape8;
    shape8.setSize({180, 30});
    shape8.setRotation(150);
    shape8.setPosition({540, 260});
    shape8.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    sf::RectangleShape shape9;
    shape9.setSize({180, 30});
    shape9.setRotation(-60);
    shape9.setPosition({540, 260});
    shape9.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape9);

    window.display();

    sf::sleep(sf::seconds(5));
}