#include "Game.h"

Game::Game()
{
	hintLimit = failLimit = wordLimit = hintCount = failCount = wordCount = 0;
	wordBank.clear();
}

Game::~Game()
{
}

int Game::getHintCount()
{
	return this->hintLimit;
}

void Game::setHintCount(int h)
{
	this->hintCount = h;
}

int Game::getFailCount()
{
	return this->failCount;
}

void Game::setFailCount(int f)
{
	this->failCount = f;
}

int Game::getWordCount()
{
	return this->wordCount;
}

void Game::setWordCount(int w)
{
	this->wordCount = w;
}



void Game::menuSetHintLimit()
{
	while (true) {
		cout << "Set number of hints allowed:  ";
		int h;
		cin >> h;
		try {
			if (cin.fail()) {
				throw"Invalid Input";
			}
			else {
				this->hintLimit = h;
				cout << "Thanh cong" << endl;
				return;
			}
		}
		catch (const char* err) {
			cin.clear();
			cin.ignore();
			cout << "Error: " << err << endl;
		}
	}
}

void Game::menuSetFailLimit()
{
	while (true) {
		cout << "Set the number of Fail allowed:   ";
		int f;
		cin >> f;
		try {
			if (cin.fail()) {
				throw "Invalid Input";
			}
			else {
				this->failLimit = f;
				cout << "Thanh cong" << endl;
				return;
			}
		}
		catch (const char* mess) {
			cin.clear();
			cin.ignore();
			cout << "Error: " << mess << endl;
		}
	}
}

void Game::menuSetWordLimit()
{
	while (true)
	{
		cout << "Set the number of Word allowed:    ";
		int w;
		cin >> w;
		try {
			if (cin.fail()) {
				throw "Invalid Input";
			}
			else {
				this->wordLimit = w;
				cout << "Thanh Cong" << endl;
				return;
			}
		}
		catch(const char* mess){
			cin.clear();
			cin.ignore();
			cout << "Error: " << mess << endl;
		}
	}
}

void Game::addWord()
{
	cout << "Ur Word Limit is: " << wordLimit << endl;
	if (wordCount < wordLimit) {
		cin.clear();
		cin.ignore();
		cout << "Enter the word u wanna add to Word Bank" << endl;
		string text;
		getline(cin, text);
		cout << "Enter the Hint for this Word" << endl;
		string hint;

		getline(cin, hint);

		Word tempWord(text, hint);

		this->wordBank.push_back(tempWord);

		wordCount++;
		cout << "Thanh cong" << endl;
	}
	else {
		cout << "U reach the limit!!!" << endl;
	}
		

}

void Game::shuffeWordBank()
{
	srand(time(0));

	for (int i = wordBank.size() - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(wordBank[i], wordBank[j]);
	}
	//return wordBank;
}






void Game::start()
{
	cout << "You have " << hintLimit << " hints" << endl;
	cout << "You have " << failLimit << " fail times" << endl;


	/*srand(time(0));


	for (int i = wordBank.size()-1; i > 0; i--) {
		int j = rand() % (i + 1); 
		swap(wordBank[i], wordBank[j]); 
	}*/

	shuffeWordBank();


	for (int i = 0; i < wordBank.size(); i++) {
		currentWord = wordBank[i];

		currentWord.displayWord();

		if (hintCount < hintLimit) {
			cout << "Do u wanna see the Hint of this word (Choose 0 or 1)" << endl;
			int opt;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> opt;

			if (opt == 1) {
				currentWord.displayHint();
				hintCount++;

			}
		}




		failCount = 0;
		while (true)
		{
			cout << "----------------------------------" << endl;
			currentWord.displayWord();
			cout << "Enter a char ur guess" << endl;
			char guessChar;

			cin >> guessChar;

			int check = 0;
			check = currentWord.checkGuess(guessChar);
			if (check == 0) {
				cout << "Nope" << endl;
				failCount++;
			}
			else {
				cout << "OK do" << endl;
			}


			if (failCount == failLimit || currentWord.getDisplayText() == currentWord.getText() ) {

				break;
			}
			cout << "----------------------------------" << endl;
		}

		cout << "********************************" << endl;
		cout << "The correct word is: " << currentWord.getText() << endl;
		cout << "********************************" << endl;


		if (failCount == failLimit) {
			cout << endl;
			cout << "LOSEEEEEEEEEEE" << endl;
			cout << endl;
			break;
		}
	}

	if (failCount != failLimit) {
		cout << endl;
		cout << "WINNNNNNNNNNNNNNNNN" << endl;
		cout << endl;
	}

	hintCount = 0;
	failCount = 0;
}



void Game::resetWordBank()
{
	wordBank.clear();

}




//void Game::makeAGuess()
//{
//
//	
//
//	cout << "Enter a char ur guess" << endl;
//	char guessChar;
//	cin >> guessChar;
//
//	int check = currentWord.checkGuess(guessChar);
//	if (check == 0) {
//		cout << "Nope" << endl;
//		failCount++;
//	}
//	
//}



