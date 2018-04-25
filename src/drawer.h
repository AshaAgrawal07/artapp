//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_DRAWER_H
#define FINAL_PROJECT_ASHAAGRAWAL07_DRAWER_H

using namespace std;

class drawer {

    /**
     * red value of the tool
     */
    int r_val;
    /**
     * green value of the tool
     */
    int g_val;
    /**
     * blue value of the tool
     */
    int b_val;
    /**
     * alpha value of the tool
     */
    int a_val;
    /**
     * width/thickness of the tool
     */
    int width;

public:


    /**
     * changes the alpha value of the tool
     * @param a_value the new alpha value
     */
    void set_a_val(int a_value);
    /**
     * changes the width/thickness of the tool
     * @param new_width the new width value
     */
    void set_width(int new_width);

};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_DRAWER_H
