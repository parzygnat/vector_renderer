#ifndef LINE_H
#define LINE_H
#include "drawable.h"
#include "clickablelabel.h"
#include "utility_func.h"

class line: public drawable {
public:
    line(){}
    line(Color col);
    void addPoint(Point* p) override;
    Point* getPoint(int i) override;
    void draw(ClickableLabel* lab) override;
    void erase(ClickableLabel* lab) override;
    bool isFinished() override;

};


#endif // LINE_H
