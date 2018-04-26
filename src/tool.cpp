//
// Created by Asha on 4/24/2018.
//

#include "tool.h"

void Tool::set_r_val(int r_value) {
    if (r_value < 0) {
        r_val = 0;
    } else if (r_value > 255) {
        r_val = 255;
    } else {
        r_val = r_value;
    }
}

void Tool::set_g_val(int g_value) {
    if (g_value < 0) {
        g_val = 0;
    } else if (g_value > 255) {
        g_val = 255;
    } else {
        g_val = g_value;
    }
}

void Tool::set_b_val(int b_value) {
    if (b_value < 0) {
        b_val = 0;
    } else if (b_value > 255) {
        b_val = 255;
    } else {
        b_val = b_value;
    }
}

void Tool::set_a_val(int a_value) {
    if (a_value < 0) {
        a_val = 0;
    } else if (a_value > 255) {
        a_val = 255;
    } else {
        a_val = a_value;
    }
}

void Tool::set_width(int new_width)
{
	if (new_width < 0) {
		width = 0;
	}
	else if (new_width > 255) {
		width = 1000;
	}
	else {
		width = new_width;
	}
}