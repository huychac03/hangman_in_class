#include "Player.h"

Player::Player(Game* newGame)
{
	theGame = newGame;
}

Player::~Player()
{
	delete theGame;
}

void Player::playGame()
{
	theGame->start();
}
