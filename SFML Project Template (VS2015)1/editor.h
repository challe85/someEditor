#ifndef EDITOR_H
#define EDITOR_H
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "Game.h"
#include "mouse.h"
#include "gui.h"
#include <vector>
#include "randomFun.h"
#include "gameLogic.h"

class randomFun;


class editor
{
    public:
        editor();
        int tmpId;
        int tmpVectorId;
        int tmpTmpId;
        bool moveActive;

        entity setEntity;

        void loadEditor();

		void update();

        void startEditor();

        void editObject(mouse & editMouse);

        void getObject(entity & getEntity, std::vector<entity>& entityVector);
        void checkObject(mouse & editMouse, entity & setEntity, std::vector<entity>& entityVector);

        void addObject(std::vector<entity>& editVector, mouse& editMouse, randomFun& editRandomFun, gameLogic& editGameLogic);
        void resizeObject(entity & setEntity, mouse & getMouse, sf::Vector2f& setSize);
        void deleteObject(entity& setTmpEntity, std::vector<entity>& setTmpEntityVector);

        void regretCreationOfLastObject();

        void runEditor(mouse& editMouse, sf::RenderWindow& rw);



        virtual ~editor();
    protected:
    private:

    sf::Vector2i xy;
    sf::Vector2i xyBuffer;

    sf::Color color;
    sf::Vector2f entitySize;

    bool doResizeObject;
    bool doMoveObject;

    std::vector<entity> setEntityVector;

    entity setTmpEntity;


};

#endif // EDITOR_H
