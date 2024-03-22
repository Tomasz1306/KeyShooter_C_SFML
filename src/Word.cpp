#include "Word.h"
Word::Word() {
	this->id = 0;
	this->x = 0;
	this->y = 0;
	this->health = 0;
	this->speed = 0;
	this->spawnDelay = 0;
	this->delay = 0;
	this->active = false;
	this->ready = false;
	this->ready = inBoard = false;
}


Word::Word(string str, float x, float y, int id) {
	this->id = id;
	this->x = x;
	this->y = y;
	this->speed = 0;
	this->spawnDelay = 0;
	this->delay = 0;
	this->active = false;
	this->ready = false;
	this->inBoard = false;
	int size = str.size();
	this->size = size;
	this->rect.setPosition(this->x, this->y);
	this->rect.setSize(Vector2f((size * 16), 35));
	this->rect.setFillColor(sf::Color::Transparent);
	this->rect.setOutlineThickness(2);
	this->rect2.setPosition(this->x +(size / 2), this->y - 20);
	this->rect2.setSize(Vector2f(20,20));
	this->rect2.setFillColor(sf::Color::Transparent);
	this->rect2.setOutlineThickness(2);
	this->health = size * 10;
	for (int i = 0; i < size; i++) {
		Text text;
		text.setString(str[i]);
		this->word.push_back(text);
	}
}
int Word::getSize() {
	return this->word.size();
}
string Word::getWord() {
	if(this->word.empty()){
		return "-";
	}
	list<Text>::iterator it = this->word.begin();
	string str2 = "";
	for (int i = 0; it != this->word.end(); it++, i++) {
		string n = (*it).getString();
		str2 += n;
	}
	return str2;
}
void Word::addWord(string word) {
	int size = word.size();
	for (int i = 0; i < size; i++) {
		Text text;
		text.setString(word[i]);
		this->word.push_back(text);
		string str = text.getString();
	}

}
bool Word::copy(Word &w) {
	list<Text>::iterator it;
	for (it = w.word.begin(); it != w.word.end(); it++) {
		this->word.push_back(*it);
	}
	return true;
}

char Word::getFirst() {
	if (this->word.empty()) {
		return '+'; // Zwróć znak '+' jako wartość domyślną, gdy lista jest pusta
	}
	list<Text>::iterator it = this->word.begin();
	sf::String znak;
	int i = 0;	
	while (it != this->word.end()) {
		znak = (*it).getString();
		if (znak == "0") {
			++it;
			continue;
		} else {
			break;
		}
	}

	if (it == this->word.end()) {
		return '+'; // Zwróć znak '+' jeśli nie znaleziono żadnego niezerowego znaku
	}
	std::locale locale;
	string k = znak.toAnsiString(locale);
	//sf::Uint32 unicode = znak.toUtf32()[0];
	//char tab = static_cast<char>(unicode);
	char tab = k[0];
	return tab;
}

/*
char Word::getFirst() {
	if (this->word.empty()) {
		return '+'; // Zwróć znak '+' jako wartość domyślną, gdy lista jest pusta
	}

	list<Text>::iterator it = this->word.begin();
	while (it != this->word.end()) {
		string znak = (*it).getString();
		if (znak == "0") {
			++it;
			continue;
		} else {
			break;
		}
	}

	if (it == this->word.end()) {
		return '+'; // Zwróć znak '+' jeśli nie znaleziono żadnego niezerowego znaku
	}

	string str = (*it).getString();
	if (str.empty()) {
		return '+'; // Zwróć znak '+' jeśli znaleziony niezerowy znak jest pusty
	}

	char tab = str[0];
	return tab;
}
*/
int Word::destroyChar(char x) {
	list<Text>::iterator it;
	// 0 = 48
	int numberOfZero = 0;
	for (it = this->word.begin(); it != this->word.end(); it++) {
		if ((*it).getString() == "0") {
			numberOfZero += 1;
		} else {
			break;
		}
	}
	if ((numberOfZero + 1) == this->word.size()) {
		//This is last char
		(*it).setString("0");
		return 0;
	} else {
		(*it).setString("0");
		return 1;
	}
}
Text Word::getCharText(int index) {
	list<Text>::iterator it = this->word.begin();
	for (int i = 0; i < index; i++) {
		it++;
	}
	string nowy = (*it).getString();
	return *it;
}
char Word::getChar(int index) {
	list<Text>::iterator it = this->word.begin();
	for (int i = 0; i < index; i++) {
		it++;
	}
	string nowy = (*it).getString();
	char nowy2 = nowy[0];
	return nowy2;
}
void Word::setRectPos(int x, int y){
	this->rect.setPosition(x,y);
	this->rect2.setPosition(x +(this->rect.getSize().x / 2.0f) - 10, y - 25);
}
void Word::setX(float x) {
	this->x = x;
}
void Word::setY(float y) {
	this->y = y;
}
void Word::setHealth(int h){
	this->health = h;
}
void Word::setId(int id) {
	this->id = id;
}
void Word::setSpeed(float speed) {
	this->speed = speed;
}
void Word::setSpawnDelay(int spawndelay) {
	this->spawnDelay = spawndelay;
}
void Word::setDelay(float delay) {
	this->delay = delay;
}
void Word::setInBoard(bool x) {
	this->inBoard = x;
}
void Word::setActive(bool active) {
	this->active = active;
}
void Word::setReady(bool ready) {
	this->ready = ready;
}
float Word::getX() {
	return this->x;
}
float Word::getY() {
	return this->y;
}
int Word::getId() {
	return this->id;
}
float Word::getSpeed() {
	return this->speed;
}
int Word::getSpawnDelay() {
	return this->spawnDelay;
}
float Word::getDelay() {
	return this->delay;
}
bool Word::getActive() {
	return this->active;
}
bool Word::getInBoard() {
	return this->inBoard;
}
bool Word::getReady() {
	return this->ready;
}
int Word::getHealth(){
	return this->health;
}
RectangleShape Word::getRect() {
	return this->rect;
}
RectangleShape Word::getHealtRect() {
	return this->rect2;
}
int Word::getHealtX(){
	return this->rect2.getPosition().x;
}
int Word::getHealtY(){
	return this->rect2.getPosition().y;
}
