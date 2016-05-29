#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <vector>
#include "entity.h"


class gameLogic
{
    public:
        gameLogic();

		std::vector<entity> onGroundVector; //Tmp might be stored elsewhere



        void loadGameLogic();
        void update(std::vector<entity>& editEntityVector);
		void gravity(std::vector<entity>& editEntityVector);
		void velocity();
		void pathing();

        virtual ~gameLogic();
    protected:
    private:
};

#endif // GAMELOGIC_H
