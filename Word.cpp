#include "Word.h"

Word::Word()
{
	text = "";
	hint = "";
}

Word::Word(string t, string h)
{
	setText(t);
	//this->text = t;
	this->hint = h;
}

Word::~Word()
{
}

string Word::getText()
{
	return text;
}

void Word::setText(string t)
{
	this->text = t;
	this->displayText = t;
	for (int i = 0; i < t.size(); i++) {
		this->displayText[i] = '_';
	}

}

string Word::getHint()
{
	return hint;
}

void Word::setHint(string h)
{
	this->hint = h;
}

string Word::getDisplayText()
{
	return displayText;
}

void Word::displayWord()
{
	cout << "The word has " << text.size() << " characters" << endl;
	cout << displayText << endl;
}

int Word::checkGuess(char guessChar)
{
	int occurence = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == guessChar ) {
			occurence++;
			displayText[i] = guessChar;
		}
	}
	return occurence;
}

void Word::displayHint()
{
	cout << "Hint: " << this->hint << endl;
}

void Word::reset()
{
	for (int i = 0; i < text.size(); i++) {
		this->displayText[i] = '_';
	}
}
