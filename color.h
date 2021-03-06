#ifndef COLOR_H
#define COLOR_H

struct Color{
    int r = 0;
    int g = 0;
    int b = 0;
    Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}
    bool operator!=(const Color& other) {
        return(r != other.r || g != other.g || b != other.b);
    }
};

#endif // COLOR_H
