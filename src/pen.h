//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_PEN_H
#define FINAL_PROJECT_ASHAAGRAWAL07_PEN_H

#include "tool.h"
using namespace std;

class Pen : public Tool {
public:
    //constructor
    Pen (int r, int g, int b, int a, int w) : Tool(r, g, b, a, w) {}
};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_PEN_H
