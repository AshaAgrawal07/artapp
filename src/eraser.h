//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H
#define FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H

#include "tool.h"
using namespace std;

class Eraser : public Tool {
public:
    /**
     * this is the alpha value of the background color, which will serve as the upperbound for the alpha values of the eraser
     */
    int bg_a_val;

public:
    //constructor
    //inputs will be the rbga straight from the background color
    Eraser(int r, int g, int b, int a, int w) : Tool(r, g, b, a, w), bg_a_val(a) {}
	void set_r_val(int r_value);
	void set_g_val(int g_value);
	void set_b_val(int b_value);
	void set_a_val(int a_value);

};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H
