//
// Created by Asha on 4/24/2018.
//

#ifndef FINAL_PROJECT_ASHAAGRAWAL07_TOOL_H
#define FINAL_PROJECT_ASHAAGRAWAL07_TOOL_H

using namespace std;

class Tool {
public:
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
    //constructor
    Tool::Tool(int r, int g, int b, int a, int w) : r_val(r), g_val(g), b_val(b), a_val(a), width(w) {}

    /**
     * changes the red value of the tool
     * @param r_value the new red value
     */
    void Tool::set_r_val(int r_value);
    /**
     * changes the green value of the tool
     * @param g_value the new green value
     */
    void Tool::set_g_val(int g_value);
    /**
     * changes the blue value of the tool
     * @param b_value the new blue value
     */
    void Tool::set_b_val(int b_value);
    /**
     * changes the alpha value of the tool
     * @param a_value the new alpha value
     */
    void Tool::set_a_val(int a_value);
    /**
     * changes the width/thickness of the tool
     * @param new_width the new width value
     */
    void Tool::set_width(int new_width);

};
#endif //FINAL_PROJECT_ASHAAGRAWAL07_TOOL_H
