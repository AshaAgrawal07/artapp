//
// Created by Asha on 4/24/2018.
//

#include "eraser.h"

//overriding everything from drawer

void set_r_val(int r_value) {

}

void set_g_val(int g_value) {

}

void set_b_val(int b_value) {

}

void set_a_val(int a_value) {
    if(a_value <= bg_a_val) {
        a_val = a_value;
    } else {
        a_val = bg_a_val;
    }
}
