//
// Created by Asha on 4/24/2018.
//

#include "eraser.h"

//overriding everything from Drawer

void set_r_val(int r_value) {
//not allowed to reset r_val
}

void set_g_val(int g_value) {
//not allowed to reset g_val
}

void set_b_val(int b_value) {
//not allowed to reset b_val
}

void Eraser::set_a_val(int a_value) {
    if(a_value <= bg_a_val) {
		Tool::a_val = a_value;
    } else {
		Tool::a_val = bg_a_val;
    }
}

void set_width(int width) {
	Tool::set_width(width);
}
