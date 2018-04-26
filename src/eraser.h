//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H
#define FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H

#include "drawer.h"
using namespace std;

class Eraser : public Drawer {
public:
    /**
     * this is the alpha value of the background color, which will serve as the upperbound for the alpha values of the eraser
     */
    double bg_a_val;

public:
    //constructor
    //inputs will be the rbga straight from the background color
    Eraser(int r, int g, int b, int a, int w) : Drawer(), bg_a_val(a) {}

};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H
