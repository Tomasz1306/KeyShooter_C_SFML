#include "System.h"
#include <bits/fs_fwd.h>
System::System() {
	this->level = 0;
	this->active = 0;
	if (!this->font.loadFromFile("rsc/SpecialElite-Regular.ttf")) {
		cout << "Cannot load Font ARIAL.TTF" << endl;
	}
	this->text.setFont(this->font);
	this->text.setCharacterSize(20);
	this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	this->text.setFillColor(Color::White);
	this->text.setStyle(Text::Bold);
	ifstream file("rsc/words1.txt");
	int n = 0;
	while (getline(file, this->wyrazy[n])) {
		cout << "Dlugosc: " << this->wyrazy[n].size() << endl;
		this->wyrazy[n].pop_back();
		n++;
		if(n == 99){
			break;
		}
	}
	srand(::time(0));
	this->clock_global.restart();
	this->clock_level.restart();
	this->static_coin.x = 700;
	this->static_coin.y = 20;
	this->static_coin.index = 0;
}

void System::generateWords(int level) {


	Random ran;
	float speed = 0;
	int posy = 0;
	int numberOfWords = 0;
	int spawnDelay = 0;
	int ilosc = ((this->level % 5) + 5);
	std::cout << "Ilosc; " << ilosc << std::endl;
	numberOfWords=ilosc;
	cout << "Number of wordR: " << numberOfWords << endl;
	for (int i = 0; i <= numberOfWords; i++) {
		int los = rand () % 99;
		string wyraz = this->wyrazy[los];
		speed = ran.random(1,3);
		if(speed == 0){
			speed = 1;
		}
		posy = rand() % 760 + 20;
		cout << wyraz.size() << endl;
		Word w(wyraz, 1550, posy, i);
		this->wordR.push_back(w);
		list<Word>::iterator it = this->wordR.end();
		it--;

		it->setSpawnDelay(spawnDelay);
		it->setSpeed(speed);
		it->setDelay(0);
	}

	list<Word>::iterator it = this->wordR.end();
	for(it = this->wordR.begin(); it != this->wordR.end(); it++){
		cout << it->getWord() << endl;
	}
	cout << "Wszystkie wyrazy zostaly dodane" << endl;
}
void System::drawWords(RenderWindow &window, float time) {
	list<Word>::iterator it = this->wordB.begin();
	list<Word>::iterator it2 = this->wordR.begin();
	list<Word>::iterator wb  = this->wordB.begin();
	list<Bullet>::iterator b = this->bullets.begin();
	list<Explosion>::iterator expl = this->g_explosion.begin();
	list<Explosion>::iterator expl_tmp = this->g_explosion.begin();
	list<Coin>::iterator c = this->g_coin.begin();

	sf::Sprite sprite;
	sf::Sprite sprite2;
	if(!this->wordB.empty()){
		for (; it != this->wordB.end(); it++) { this->text.setFillColor(Color::White);
			for (int i = 0; i < it->getSize(); i++) {
				this->text = it->getCharText(i);
				if (i == 0) {
					this->text.setPosition(it->getX(), it->getY());
				} else {
					this->text.setPosition(it->getX() + (i * 15), it->getY());
				}
				if (it->getActive()) {
					this->text.setFillColor(Color::Green);
				} else {
					this->text.setFillColor(Color::White);
				}
				this->text.setFont(this->font);
				window.draw(this->text);
				window.draw(it->getRect());
				window.draw(it->getHealtRect());
				this->text.setPosition(it->getX()+ (it->getSize() + 1) * 16, it->getY());
				this->text.setString(to_string(it->getHealth()));
				window.draw(this->text);
			}
		}

	}
	//draw ship
	window.draw(this->g_ship.getSprite());

	//cout << "Rysowanie kul" << endl;
	for(b = this->bullets.begin(); b != this->bullets.end(); b++){
		sprite2.setTexture(this->g_image.getBulletTexture(b->getIndex()));
		sprite2.setScale(2.0f, 2.0f);
		sprite2.setPosition(b->getX(), b->getY());
		sprite2.setOrigin(15,9);
		window.draw(sprite2);
	}
	//Rysowanie coinow
	if(this->static_coin.index == 23){
		this->static_coin.index = 0;
	}
	sprite.setTexture(this->g_image.getGoldCoin(this->static_coin.index));
	sprite.setPosition(this->static_coin.x, this->static_coin.y);
	sprite.setScale(5.0f,5.0f);
	window.draw(sprite);
	this->static_coin.index++;
	for(c = this->g_coin.begin(); c != this->g_coin.end(); c++){
		if(c->index == 23){
			c->index = 0;
		}
		sprite.setTexture(this->g_image.getGoldCoin(c->index));
		sprite.setPosition(c->x, c->y);
		sprite.setScale(3.5f,3.5f);
		window.draw(sprite);
		c->index++;
	}

	//Rysowanie Eksplozji
	for(;expl != this->g_explosion.end();expl++){
		sprite.setTexture(this->g_image.getExplosionTexture(expl->getIndex()));
		sprite.setPosition(expl->getX(), expl->getY());
		for(wb = this->wordB.begin(); wb != this->wordB.end(); wb++){
			if(wb->getId() == expl->getId()){
				sprite.setPosition(wb->getHealtX() + 8, wb->getHealtY() + 8);
			}
		}
		sprite.setOrigin(50,50);
		sprite.setScale(1.3f,1.3f);
		expl->setIndex(expl->getIndex() + 1);
		if(expl->getIndex() == 80){
			this->g_explosion.erase(expl);
			break;
		}
		window.draw(sprite);
	}

	//Rysowanie liczby wyrazow gotowych
	for(int i = 0; i < this->wordR.size(); i++){
		RectangleShape shape(Vector2f(10.0f,15.0f));
		shape.setPosition(500 + (i *11), 1);
		shape.setFillColor(Color::Red);
		window.draw(shape);
	}
	//Rysowanie liczby wyrazow na planszy
	for(int i = 0; i < this->wordB.size(); i++){
		RectangleShape shape(Vector2f(10.0f,15.0f));
		shape.setPosition(500 + (i *11), 18);
		shape.setFillColor(Color::Magenta);
		window.draw(shape);
	}
	for(int i = 0; i < this->g_coin.size(); i++){
		RectangleShape shape(Vector2f(10.0f,15.0f));
		shape.setPosition(500 + (i *11), 35);
		shape.setFillColor(Color::Yellow);
		window.draw(shape);
	}
	string str = to_string(this->elapsed_global.asSeconds());
	string newtime = "Game: <";
	for(int i = 0; i<6; i++){
		newtime.push_back(str[i]);

	}
	newtime.push_back('>');
	this->text.setString(newtime);
	this->text.setPosition(100,10);
	window.draw(this->text);
	time = this->elapsed_level.asSeconds();
	str = to_string(time);
	newtime = "Lvl:  <";
	for(int i = 0; i<6; i++){
		newtime.push_back(str[i]);
	}
	newtime.push_back('>');
	this->text.setString(newtime);
	this->text.setPosition(100,45);
	window.draw(this->text);
	this->text.setFillColor(Color::White);
	this->text.setPosition(50, 45);
	this->text.setString(to_string(this->level));
	window.draw(this->text);
	this->text.setString(std::to_string(this->money));
	this->text.setFillColor(Color::Yellow);
	this->text.setPosition(810, 20);
	window.draw(this->text);
}
void System::updatePosition(float deltaTime, float time) {
	
	this->elapsed_global = this->clock_global.getElapsedTime();
	this->elapsed_level = this->clock_level.getElapsedTime();
	this->newAddWordsToBoard();
	if(this->wordR.empty() && this->wordB.empty()){
		this->level += 1;
		this->generateWords(this->level + 5);	
		this->clock_level.restart();
	}


	list<Word>::iterator wb = this->wordB.begin();
	for (; wb != this->wordB.end(); wb++) {
		wb->setX(wb->getX() - ((deltaTime*50) * wb->getSpeed()));
		wb->setRectPos(wb->getX(), wb->getY());

	}
	for (wb = this->wordB.begin(); wb != this->wordB.end(); wb++) {
		if (wb->getX() <= 0) {
			wordB.erase(wb);
			this->active--;
			wb = this->wordB.begin();
		}
	}
	list<Coin>::iterator c = this->g_coin.begin();
	for(;c != this->g_coin.end(); c++){
		if(c->x > this->static_coin.x -3&& c->x < this->static_coin.x + 23
		&& c->y < this->static_coin.y + 5){
			this->g_coin.erase(c);
			c = this->g_coin.begin();
		}		
	}	
	for(c = this->g_coin.begin(); c != this->g_coin.end(); c++){
		float dx = this->static_coin.x - c->x;
		float dy = this->static_coin.y - c->y;
		float length = sqrt(dx * dx + dy * dy);
		float ndx = dx / length;
		float ndy = dy / length;
		c->x = c->x + (deltaTime * 400 * ndx);
		c->y = c->y + (deltaTime * 400 * ndy);
	}


	list<Explosion>::iterator expl = this->g_explosion.begin();
	list<Bullet>::iterator b = this->bullets.begin();
	for (; b != this->bullets.end(); b++) {
		for (wb = this->wordB.begin(); wb != this->wordB.end(); wb++) {
			if (b->getWordId() == wb->getId()) {
				float dx = wb->getHealtX() - b->getX();
				float dy = wb->getHealtY() - b->getY();
				float length = sqrt(dx * dx + dy * dy);
				float ndx = dx / length;
				float ndy = dy / length;
				b->setX(b->getX() + (deltaTime * 700 * ndx));
				b->setY(b->getY() + (deltaTime * 700 * ndy));
				if(b->getX() >= wb->getHealtX()){  
					wb->setHealth(wb->getHealth() - 10);	
					Explosion explosion;
					explosion.setX(wb->getHealtX());
					explosion.setY(wb->getHealtY());
					explosion.setId(wb->getId());
					this->g_explosion.push_back(explosion);
					this->bullets.erase(b);
					b = this->bullets.begin();
					if(wb->getHealth() <= 0){
						for(;expl != this->g_explosion.end();expl++){
							if(wb->getId() == expl->getId()){
								expl->setX(wb->getHealtX()+ 8);
								expl->setY(wb->getHealtY() + 8);
							}
						}
						for(int i = 0; i< wb->getSize(); i++){
							Coin coin;
							int ran_x = rand() % 100 - 50;
							int ran_y = rand() % 100 - 50;
							coin.x = wb->getHealtX() + ran_x;
							coin.y = wb->getHealtY() + ran_y;
							coin.index = 0;
							this->g_coin.push_back(coin);
							this->money += wb->getSize();
						}
						this->wordB.erase(wb);
						wb = this->wordB.begin();
						this->active--;
						for(wb = this->wordB.begin(); wb != this->wordB.end(); wb++){
						}
					}
				}
				break;
			}
		}
	}
}
void System::systemEvent(RenderWindow &window, Event event) {
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		}
		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::A) {
				this->shoot('A');
			}
			if (event.key.code == Keyboard::B) {
				this->shoot('B');
			}
			if (event.key.code == Keyboard::C) {
				this->shoot('C');
			}
			if (event.key.code == Keyboard::D) {
				this->shoot('D');
			}
			if (event.key.code == Keyboard::E) {
				this->shoot('E');
			}
			if (event.key.code == Keyboard::F) {
				this->shoot('F');
			}
			if (event.key.code == Keyboard::G) {
				this->shoot('G');
			}
			if (event.key.code == Keyboard::H) {
				this->shoot('H');
			}
			if (event.key.code == Keyboard::I) {
				this->shoot('I');
			}
			if (event.key.code == Keyboard::J) {
				this->shoot('J');
			}
			if (event.key.code == Keyboard::K) {
				this->shoot('K');
			}
			if (event.key.code == Keyboard::L) {
				this->shoot('L');
			}
			if (event.key.code == Keyboard::M) {
				this->shoot('M');
			}
			if (event.key.code == Keyboard::N) {
				this->shoot('N');
			}
			if (event.key.code == Keyboard::O) {
				this->shoot('O');
			}
			if (event.key.code == Keyboard::P) {
				this->shoot('P');
			}
			if (event.key.code == Keyboard::Q) {
				this->shoot('Q');
			}
			if (event.key.code == Keyboard::R) {
				this->shoot('R');
			}
			if (event.key.code == Keyboard::S) {
				this->shoot('S');
			}
			if (event.key.code == Keyboard::T) {
				this->shoot('T');
			}
			if (event.key.code == Keyboard::U) {
				this->shoot('U');
			}
			if (event.key.code == Keyboard::W) {
				this->shoot('W');
			}
			if (event.key.code == Keyboard::X) {
				this->shoot('X');
			}
			if (event.key.code == Keyboard::Y) {
				this->shoot('Y');
			}
			if (event.key.code == Keyboard::Z) {
				this->shoot('Z');
			}
			if (event.key.code == Keyboard::V) {
				this->shoot('V');
			}
		}
	}
}
void System::shoot(char key) {
	key += 32;
	list<Word>::iterator wb;
	sf::Vector2f kierunek;
	bool check = false;
	//Sprawdz czy istnieje jakies aktywne slowo(slowo ktore ktos zaczal pisac)
	for (wb = this->wordB.begin(); wb != this->wordB.end(); wb++) {
		if (wb->getActive()) {
			check = true;
			break;
		}
	}
	//Jezeli istnieje to wejdz do tego ifa a jezeli nie to do nastepnego
	if (check) {
		for (wb = this->wordB.begin(); wb != this->wordB.end(); wb++) {
			if (wb->getActive()) {
				char getChar = wb->getFirst();
				if(getChar == '+'){
					break;
				}
				if (key == getChar){
					if (!wb->destroyChar(key)) {
						wb->setActive(false);
						kierunek.x = wb->getHealtX() - this->g_ship.getX();
						kierunek.y = wb->getHealtY() - this->g_ship.getY();
						float katRad = atan2(kierunek.y, kierunek.x);
						float katDeg = katRad * 180 / M_PI;
						this->g_ship.rotate(katDeg + 90);
						sf::Transform trans = this->g_ship.getTransform();
						sf::Vector2f localRightCenter(15, 0); // Dla sprite'a o rozmiarze 50x50 przed skalowaniem

					    // Przekształcenie do koordynatów świata
    					sf::Vector2f worldRightCenter = trans.transformPoint(localRightCenter.x, localRightCenter.y);
									
						Bullet b(worldRightCenter.x, worldRightCenter.y,wb->getId());
						b.setIndex(0);
						this->bullets.push_back(b);
						//this->wordR.erase(it);
						//this->active--;
						break;
					}else{
						kierunek.x = wb->getHealtX() - this->g_ship.getX();
						kierunek.y = wb->getHealtY() - this->g_ship.getY();
						float katRad = atan2(kierunek.y, kierunek.x);
						float katDeg = katRad * 180 / M_PI;
						this->g_ship.rotate(katDeg + 90);
						sf::Transform trans = this->g_ship.getTransform();
						sf::Vector2f localRightCenter(15, 0); // Dla sprite'a o rozmiarze 50x50 przed skalowaniem

					    // Przekształcenie do koordynatów świata
    					sf::Vector2f worldRightCenter = trans.transformPoint(localRightCenter.x, localRightCenter.y);
									
						Bullet b(worldRightCenter.x, worldRightCenter.y,wb->getId());
						b.setIndex(0);
						this->bullets.push_back(b);
					}
				}
			}
		}
	} else {
		for (wb = this->wordB.begin(); wb != this->wordB.end(); wb++) {
			if (wb->getInBoard()) {
				if (key == wb->getFirst()) {
					kierunek.x = wb->getHealtX() - this->g_ship.getX();
					kierunek.y = wb->getHealtY() - this->g_ship.getY();
					float katRad = atan2(kierunek.y, kierunek.x);
					float katDeg = katRad * 180 / M_PI;
					this->g_ship.rotate(katDeg + 90);
						sf::Transform trans = this->g_ship.getTransform();
						sf::Vector2f localRightCenter(15, 0); // Dla sprite'a o rozmiarze 50x50 przed skalowaniem

					    // Przekształcenie do koordynatów świata
    					sf::Vector2f worldRightCenter = trans.transformPoint(localRightCenter.x, localRightCenter.y);
			
						Bullet b(worldRightCenter.x, worldRightCenter.y,wb->getId());
						b.setIndex(0);
						this->bullets.push_back(b);
					wb->setActive(true);
					wb->destroyChar(key);
					break;
				}
			}
		}
	}
}
void System::newAddWordsToBoard(){
	list<Word>::iterator wr;
	list<Word>::iterator wb;
	bool add_word = false;
	if(this->wordR.empty()){
		return;
	}
	if(this->wordB.empty() && !this->wordR.empty()){
	    wr = this->wordR.begin();
	    add_word = true;
	}
	if(this->wordB.size() < ((this->level /15) + 5)){
	    wr = this->wordR.begin();
	    add_word = true;
	    for(wb = this->wordB.begin(); wb != this->wordB.end(); wb++){
			add_word = true;
	        if(!wb->getActive()){
	            char r, b;
	            r = wr->getFirst();
	            b = wb->getFirst();
	            if(r == b){
					if(this->wordR.size() > 1){
	                	wr++;
	                	wb = this->wordB.begin();
						add_word = false;
					}else if(wr == this->wordR.end()){
						add_word = false;
						break;
					}else{
						add_word = false;
					}
	            }
	        }
	    }
	    for(wb = this->wordB.begin(); wb != this->wordB.end(); wb++){
	        if( (wr->getY() > (wb->getY() - 25)) &&
	            (wr->getY() < (wb->getY() + 25)) &&
	            (wr->getX() > 1000)	&&
	            (wr->getId() != wb->getId())){
	
	            wr->setY(rand() % 750 + 30);
	            wb = this->wordB.begin();
	            continue;
	        }
	    }
	}else{
	}
	if(add_word){
	    wr->setInBoard(true);
	    this->wordB.push_back(*wr);
	    this->wordR.erase(wr);
	    this->active++;
	}
}
void System::setActive(int x) {
	this->active = x;
}
int System::getActive() {
	return this->active;
}
