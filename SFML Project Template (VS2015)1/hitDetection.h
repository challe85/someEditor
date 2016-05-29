#ifndef HITDETECTION_H
#define HITDETECTION_H
#include <SFML/Graphics.hpp>
#include "mouse.h"
#include "gui.h"
#include <vector>
#include "editor.h"
#include "entity.h"
#include "randomFun.h"


class hitDetection
{
    public:
        hitDetection();

        std::vector<entity>::iterator tmpItr;
        sf::Rect<float> renderWindowRect;

        void load();

        void update(gui& editGui,mouse& editMouse,sf::RenderWindow& rw, std::vector<entity>& editEntityVector, editor& editEditor, randomFun& editRandomFun);
        bool mouseHitDetection(entity& editEntity, mouse& editMouse);

        virtual ~hitDetection();
    protected:
    private:
};

#endif // HITDETECTION_H
