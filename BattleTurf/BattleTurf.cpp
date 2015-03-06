#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

void sleep(float seconds);

int main() {
    const int width = 800;
    const int height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "Prototype");
    sf::Vector2i pos;
    sf::RectangleShape* past;

    const int board_width = 15;
    const int board_height = 15;
    float box_width = width/board_width;
    float box_height = height/board_height;

    sf::RectangleShape boxes[board_width][board_height];

    for (int i = 0; i < board_height; i++) {
        for (int j = 0; j < board_width; j++) {
            boxes[i][j].setSize(sf::Vector2f(box_width, box_height));
            boxes[i][j].setPosition(j*(box_width), i*(box_height));
            boxes[i][j].setOutlineColor(sf::Color::Black);
            boxes[i][j].setOutlineThickness(2);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                if (past) past->setFillColor(sf::Color::White); //past starts out undefined, therefore false
                pos = sf::Mouse::getPosition(window);
                boxes[(int)(pos.y/box_height)][(int)(pos.x/box_width)].setFillColor(sf::Color::Cyan);
                past = &boxes[(int)(pos.y/box_height)][(int)(pos.x/box_width)]; //past declared, therefore true
                //std::cout << "x:" << pos.x << "y: " << pos.y << std::endl; //DEBUG
                //std::cout << "x:" << (int)(pos.x/box_width) << "y: " << (int)(pos.y/box_height) << std::endl; //DEBUG
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //text.setPosition(55 * (currentbox / 10), 55 * ( currentbox % 10));
            }
        }

        window.clear();
        for (int i = 0; i < board_height; i++) {
            for (int j = 0; j < board_width; j++) {
                window.draw(boxes[i][j]);
            }
        }

        window.display();
        sleep(1);
    }

    return 0;
}

void sleep(float seconds) {
    clock_t temp;
    temp = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < temp) {}
}
