//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H
#define FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H

using namespace std;

class Eraser : public Drawer {
public:
    int bg_r_val;
    int bg_g_val;
    int bg_b_val;
    int bg_a_val;

public:

    void set_bg_r_val(int r_value);
    void set_bg_g_val(int g_value);
    void set_bg_b_val(int b_value);
    void set_bg_a_val(int a_value);
};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_ERASER_H
