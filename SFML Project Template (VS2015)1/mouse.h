#ifndef MOUSE_H
#define MOUSE_H
#include <SFML/Graphics.hpp>

class mouse
{
    public:

        sf::Vector2f mouseXy;
        sf::Vector2f mouseXyBuffer;
        sf::FloatRect mouseHitBox;
        sf::Vector2i pixelPos;
        sf::Vector2f worldPos;
        sf::Rect<float> mouseRect;

        mouse();

        void mousePosition(sf::RenderWindow& rw);
        bool mouseIntersect();
        bool rightClick();
        bool leftClick();

        virtual ~mouse();
    protected:
    private:
};

#endif // MOUSE_H
