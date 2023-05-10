#include<iostream>
#include<string>
#include"Menu.h"
#include "Game.h"
#include "Challenger.h"
#include "Player.h"

using namespace std;

enum ACTIONTYPE {
	PLAY_GAME,
	EXIT_GAME,
	HINT_SETTING,
	FAIL_SETTING,
	WORD_SETTING,
	ADD_WORD,
	RESET_WORD
};

int main() {


	Menu* mainMenu = new Menu("Main menu", "The game main menu");
	Menu* settingMenu = new Menu("Setting menu", "The game setting menu");
	Menu* wordBankMenu = new Menu("Word bank menu", "The game word bank menu");
	Menu* playMenu = new Menu("play menu", "Start playing the game", PLAY_GAME);
	Menu* exitMenu = new Menu("exit menu", "Quit playing the game", EXIT_GAME);
	mainMenu->addSubMenu(settingMenu);
	mainMenu->addSubMenu(wordBankMenu);
	mainMenu->addSubMenu(playMenu);
	mainMenu->addSubMenu(exitMenu);


	Menu* setHint = new Menu("Hint setting", "set maximum hints allowed", HINT_SETTING);
	Menu* setFail = new Menu("Fail setting", "set maximum failure allowed", FAIL_SETTING);
	Menu* setWord = new Menu("Word setting", "set maximum words in game", WORD_SETTING);
	settingMenu->addSubMenu(setHint);
	settingMenu->addSubMenu(setFail);
	settingMenu->addSubMenu(setWord);


	Menu* addWord = new Menu("Add new word", "add a word to the word bank", ADD_WORD);
	Menu* resetWordBank = new Menu("Reset", "reset word bank", RESET_WORD);
	wordBankMenu->addSubMenu(addWord);
	wordBankMenu->addSubMenu(resetWordBank);


	Game* currentGame = new Game();

	Challenger* c1 = new Challenger(currentGame);

	Player* p1 = new Player(currentGame);


	Menu* currentMenu = mainMenu;


	while (true) {

		currentMenu->displayMenu();
		//if (currentMenu->getSubMenu(1) == nullptr && currentMenu->getSubMenu(0)->getAction() == HINT_SETTING) {
		//	cout << "DMMM" << endl;
		//	//currentGame->menuSetHint();
		//	cout << "Update number of hints allowed" << endl;
		//}
		//cout << "HHHHHHHHHHHHHHHHHHHH" << endl;
		int opt = currentMenu->pickOption();
		currentMenu = currentMenu->getSubMenu(opt - 1);
		switch (currentMenu->getAction()) {
		case -1:

			break;
		case PLAY_GAME:
			p1->playGame();
			cout << "Start playing the game" << endl;
			break;

		case EXIT_GAME:
			exit(0);
		case HINT_SETTING:
			c1->setHintLimit();
			cout << "Update number of hints allowed" << endl;
			break;
		case FAIL_SETTING:
			c1->setFailLimit();
			break;

		case WORD_SETTING:
			c1->setWordLimit();
			break;
		case ADD_WORD:
			c1->addNewWord();
			break;
		case RESET_WORD:
			c1->resetWorkBank();
			break;
		}
	}
	return 0;
}