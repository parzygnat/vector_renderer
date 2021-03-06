#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <vector>
#include <cmath>
#include "clickablelabel.h"
#include "point.h"
#include "color.h"
#include "utility_func.h"
#include "nlohmann/json.hpp"

using std::vector;
class drawable {
    public:
        drawable() {}
        ~drawable() {}
        enum shape {cir, pol, lin, ang, rec};
        shape getShape() {return sh;}
        virtual void addPoint(Point* p) = 0;
        virtual Point* getPoint(int i) = 0;
        virtual vector<Point *> getPoints() { return points; }
        virtual void draw(ClickableLabel* lab) = 0;
        virtual void erase(ClickableLabel* lab) = 0;
        virtual bool isFinished() = 0;
        void setThickness(int t) {thickness = t;}
        int getThickness() {return thickness;}
        Color getColor() {return col;}
        void setColor(Color col) {this->col = col;}
        virtual nlohmann::json Serialize() {
            nlohmann::json a;
            a["shape"] = this->getShape();
            for(auto point : this->getPoints()) {
                a["points"].push_back({point->x, point->y});
            }
            a["color"] = {this->getColor().r, this->getColor().g, this->getColor().b};
            a["thickness"] = this->getThickness();
            a["size"] = this->getPoints().size();
            return a;
        }
    protected:
        vector<Point*> points;
        Color col = {0, 0, 0};
        int value;
        int thickness = 1;
        shape sh;
};

#endif // DRAWABLE_H
