#ifndef LEGACY_H
#define LEGACY_H

//lagacy component (Adaptee)

class LegacyRectangle
{
private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;

public:
    LegacyRectangle(int x1, int y1, int x2, int y2)
    {};
    void OldDraw(){};
};

#endif //LEGACY_H