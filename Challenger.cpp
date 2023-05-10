#include "Challenger.h"

Challenger::Challenger(Game* newGame)
{
	theGame = newGame;
}

Challenger::~Challenger()
{
	delete theGame;
}

void Challenger::setHintLimit()
{
	theGame->menuSetHintLimit();
}

void Challenger::setFailLimit()
{
	theGame->menuSetFailLimit();
}

void Challenger::setWordLimit()
{
	theGame->menuSetWordLimit();
}

void Challenger::addNewWord()
{
	theGame->addWord();
}

void Challenger::resetWorkBank()
{
	theGame->resetWordBank();
}
