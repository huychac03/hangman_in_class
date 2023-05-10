#include "Menu.h"

Menu::Menu() {
	name = "Default name";
	description = "Default description";
	action = -1;
	subMenu.clear();
}

Menu::Menu(string name, string description, int action)
{
	this->name = name;
	this->description = description;
	this->action = action;
	subMenu.clear();
}

Menu::~Menu()
{
	if (subMenu.size() > 0) {
		for (int i = 0; i < subMenu.size(); i++) {
			if (subMenu[i])
				delete subMenu[i];
		}
		subMenu.clear();
	}
}

string Menu::getName()
{
	return name;
}

void Menu::setName(string n)
{
	name = n;
}

string Menu::getDescription()
{
	return string();
}

void Menu::setDescription(string d)
{
	description = d;
}

int Menu::getAction()
{
	return action;
}

void Menu::setAction(int a)
{
	action = a;
}

void Menu::addSubMenu(Menu* m)
{
	this->subMenu.push_back(m);
	m->subMenu.push_back(this);
}

Menu* Menu::getSubMenu(int index)
{
	if (index >= 0 && index < subMenu.size())
		return subMenu[index];
	else
		return nullptr;
}

void Menu::displayMenu()
{
	//system("cls");
	cout << this->name << endl;
	cout << this->description << endl;
	for (int i = 0; i < subMenu.size(); i++) {
		cout << i + 1 << ". " << subMenu[i]->getName() << endl;
	}
}

int Menu::pickOption()
{
	while (true) {
		cout << "Pick an option: ";
		int opt;
		cin >> opt;
		try {
			if (cin.fail()) {
				throw "Invalid input";
			}
			else if (opt < 1 || opt > subMenu.size()) {
				throw "Out of range";
			}
			else
				return opt;
		}
		catch (const char* mess) {
			cin.clear();
			cin.ignore();
			cout << "Error " << mess << endl;
		}
	}
}