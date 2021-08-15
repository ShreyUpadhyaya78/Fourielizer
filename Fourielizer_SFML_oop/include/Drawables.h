#ifndef DRAWABLES_H
#define DRAWABLES_H


class Drawables
{
public:
    Drawables(){};
    virtual ~Drawables(){};

protected:
    //variables
    float rectHeight, rectWidth;

};

#endif // DRAWABLES_H

class Rectangles : public Drawables{
private:
    //game objects
    //sf::RectangleShape rect[4];

public:
    //initializers
    initshape();
};
