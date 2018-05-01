//
// Created by Asha on 4/25/2018.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/tool.h"

TEST_CASE("tool constructor") {
    Tool tool = new Tool(50, 50, 50, 50, 50);
    REQUIRE(tool.r_val == 50);
    REQUIRE(tool.g_val == 50);
    REQUIRE(tool.b_val == 50);
    REQUIRE(tool.a_val == 50);
    REQUIRE(tool.width == 50);
}

TEST_CASE("set_r_val tests") {
    Tool tool = new Tool(50, 50, 50, 50, 50);
    tool.set_r_val(-10);
    REQUIRE(tool.r_val == 0);

    tool.set_r_val(300);
    REQUIRE(tool.r_val == 255);

    tool.set_r_val(200);
    REQUIRE(tool.r_val == 200);
}

TEST_CASE("set_g_val tests") {
    Tool tool = new Tool(50, 50, 50, 50, 50);
    tool.set_g_val(-10);
    REQUIRE(tool.g_val == 0);

    tool.set_g_val(300);
    REQUIRE(tool.g_val == 255);

    tool.set_g_val(200);
    REQUIRE(tool.g_val == 200);
}

TEST_CASE("set_b_val tests") {
    Tool tool = new Tool(50, 50, 50, 50, 50);
tool.set_b_val(-10);
REQUIRE(tool.b_val == 0);

tool.set_b_val(300);
REQUIRE(tool.b_val == 255);

tool.set_b_val(200);
REQUIRE(tool.b_val == 200);
}

TEST_CASE("set_a_val tests") {
    Tool tool = new Tool(50, 50, 50, 50, 50);
    tool.set_a_val(-10);
    REQUIRE(tool.a_val == 0);

    tool.set_a_val(500);
    REQUIRE(tool.a_val == 255);

    tool.set_a_val(7);
    REQUIRE(tool.a_val == 7);
}

TEST_CASE("set_width tests") {
    Tool tool = new Tool(50, 50, 50, 50, 50);
    tool.set_width(-10);
    REQUIRE(tool.width == 0);

    tool.set_width(2000);
    REQUIRE(tool.width == 200);

    tool.set_width(200);
    REQUIRE(tool.width == 200);
}

