//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_PEN_H
#define FINAL_PROJECT_ASHAAGRAWAL07_PEN_H

using namespace std;

class pen : public drawer {
public:
    /**
     * changes the red value of the tool
     * @param r_value the new red value
     */
    void set_r_val(int r_value);
    /**
     * changes the green value of the tool
     * @param g_value the new green value
     */
    void set_g_val(int g_value);
    /**
     * changes the blue value of the tool
     * @param b_value the new blue value
     */
    void set_b_val(int b_value);
};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_PEN_H
