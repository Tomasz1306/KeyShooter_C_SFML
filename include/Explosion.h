#ifndef EXPLOSION_H
#define EXPLOSION_H

class Explosion{
private:

    int x;
    int y;
    int index;
    int id;

public:

    Explosion() : x(10), y(10), index(0){};
    void setX(int );
    void setY(int );
    void setIndex(int );
    void setId(int);
    int getX();
    int getY();
    int getIndex();
    int getId();

};


#endif /* EXPOLOSION*/