#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr int POINT_COUNT = 360;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Ellipse",
        sf::Style::Default, settings);
    float x = 450;
    float y = 300;
    float mv = 0.00;

    sf::ConvexShape ellipse;
    ellipse.setPosition({x, y});
    ellipse.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    ellipse.setPointCount(POINT_COUNT);

    for (int pointNo = 0; pointNo < POINT_COUNT; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(POINT_COUNT);
        float radius = 200 * sin(6 * angle);
        sf::Vector2f point = {
            radius * std::cos(angle),
            radius * std::sin(angle)};
        ellipse.setPoint(pointNo, point);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        mv = mv + 0.01;
        x = x - radius * sin(mv);
        y = y - radius * cos(mv);
        ellipse.setPosition({x, y});
        window.clear();
        window.draw(ellipse);
        window.display();
    }
}