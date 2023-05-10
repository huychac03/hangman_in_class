#pragma once
#include "Game.h"


class Player
{
public:
	Game* theGame = new Game();

	Player(Game*);

	~Player();

	void playGame();
};

