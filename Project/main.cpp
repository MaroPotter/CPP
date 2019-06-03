#include <iostream>
#include <SFML/Window.hpp>
int main() {

    sf::Window window(sf::VideoMode(640, 480), "Hello world!");

    sf::sleep(sf::seconds(3));

    return 0;
}