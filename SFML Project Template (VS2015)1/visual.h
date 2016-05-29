#ifndef VISUAL_H
#define VISUAL_H
#include <SFML/Graphics.hpp>


class visual
{
    public:
        visual();
        void loadVisual(sf::RenderWindow& rw);
        void drawVisual(sf::RenderWindow& rw);
        virtual ~visual();
    protected:
    private:

        sf::Image background;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f scale;
};

#endif // VISUAL_H
