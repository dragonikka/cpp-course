#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mousePosition = {float(event.x), float(event.y)};
}
void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, float dt)
{
    const float pointerSpeed = 15;
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    float angle = atan2(delta.y, delta.x);
    if (angle < 0)
    {
        angle = angle + 2 * M_PI;
    }

    const float pointerRotation = pointer.getRotation();
    const float mouseRotation = toDegrees(angle);
    const float maxRotation = pointerSpeed * dt;
    float nextRotation = std::min(std::abs(mouseRotation - maxRotation), maxRotation);
    if (mouseRotation < pointerRotation)
    {
        if ((mouseRotation + 180) < pointerRotation)
        {
            pointer.setRotation(pointerRotation + nextRotation);
        }
        else
        {
            pointer.setRotation(pointerRotation - nextRotation);
        }
    }
    else
    {
        if ((mouseRotation - 180) > pointerRotation)
        {
            pointer.setRotation(pointerRotation - nextRotation);
        }
        else
        {
            pointer.setRotation(pointerRotation + nextRotation);
        }
    }
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        const float dt = clock.restart().asSeconds();
        update(mousePosition, pointer, dt);
        redrawFrame(window, pointer);
    }
}