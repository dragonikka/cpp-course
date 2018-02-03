#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving Ball");
    sf::Clock clock;
    const sf::Vector2f position = {10, 350};

    constexpr float BALL_SIZE = 40;
    sf::CircleShape shape(BALL_SIZE);
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    constexpr float amplitudeY = 80.f;
    constexpr float periodY = 2; // in seconds.
    float speedX = 300.f;

    float xmax = 0;
    float wp = 0;

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
        float time = clock.getElapsedTime().asSeconds();
        float wavePhase = wp - time * float(2 * M_PI);
        const float x = xmax + speedX * time;
        const float y = amplitudeY * std::sin(wavePhase / periodY);
        sf::Vector2f offset = {x, y};

        if (x + 2 * BALL_SIZE >= WINDOW_WIDTH)
        {
            xmax = x;
            clock.restart();
            speedX = -speedX;
            wp = wavePhase;
        }
        if (x + 20 < 0)
        {
            xmax = x;
            clock.restart();
            speedX = -speedX;
            wp = wavePhase;
        }
        shape.setPosition(position + offset);
        window.clear();
        window.draw(shape);
        window.display();
    }
}