#pragma once
#include "Game.h"


class Challenger
{
	
public:

	Game* theGame = new Game();

	Challenger(Game*);

	~Challenger();

	void setHintLimit();

	void setFailLimit();

	void setWordLimit();

	void addNewWord();

	void resetWorkBank();
};

