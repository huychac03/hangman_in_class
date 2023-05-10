#pragma once
#include <iostream>
#include <vector>

#include "Word.h"
using namespace std;

class Game
{
protected:
	int hintLimit;
	int failLimit;
	int wordLimit;
	int hintCount;
	int failCount;
	int wordCount;
	vector<Word> wordBank;
	Word currentWord;


public:
	Game();
	~Game();

	int getHintCount();
	void setHintCount(int h);

	int getFailCount();
	void setFailCount(int f);

	int getWordCount();
	void setWordCount(int w);


	//////////////
	void menuSetHintLimit();
	void menuSetFailLimit();
	void menuSetWordLimit();

	void addWord(); // để ý wordLinmit


	void shuffeWordBank();


	virtual void start(); 

	void resetWordBank();
	//void makeAGuess();

};


