//
// Created by Asha on 4/25/2018.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/eraser.h"

TEST_CASE("eraser constructor") {
Eraser tool = new Eraser(50, 50, 50, .5, 50);
REQUIRE(tool.r_val == 50);
REQUIRE(tool.g_val == 50);
REQUIRE(tool.b_val == 50);
REQUIRE(tool.a_val == .5);
REQUIRE(tool.width == 50);
}

TEST_CASE("set_r_val tests") {
Eraser tool = new Eraser(50, 50, 50, .5, 50);
tool.set_r_val(-10);
REQUIRE(tool.r_val == 50);

tool.set_r_val(300);
REQUIRE(tool.r_val == 50);

tool.set_r_val(200);
REQUIRE(tool.r_val == 50);
}

TEST_CASE("set_g_val tests") {
Eraser tool = new Eraser(50, 50, 50, .5, 50);
tool.set_g_val(-10);
REQUIRE(tool.g_val == 50);

tool.set_g_val(300);
REQUIRE(tool.g_val == 50);

tool.set_g_val(200);
REQUIRE(tool.g_val == 50);
}

TEST_CASE("set_b_val tests") {
Eraser tool = new Eraser(50, 50, 50, .5, 50);
tool.set_b_val(-10);
REQUIRE(tool.b_val == 50);

tool.set_b_val(300);
REQUIRE(tool.b_val == 50);

tool.set_b_val(200);
REQUIRE(tool.b_val == 50);
}

TEST_CASE("set_a_val tests") {
Eraser tool = new Eraser(50, 50, 50, .5, 50);
tool.set_a_val(-.1);
REQUIRE(tool.a_val == 0);

tool.set_a_val(1.1);
REQUIRE(tool.a_val == 1);

tool.set_a_val(.7);
REQUIRE(tool.a_val == .7);
}

TEST_CASE("set_width tests") {
Eraser tool = new Eraser(50, 50, 50, .5, 50);
tool.set_width(-10);
REQUIRE(tool.width == 0);

tool.set_width(1300);
REQUIRE(tool.width == 1000);

tool.set_width(200);
REQUIRE(tool.width == 200);
}

