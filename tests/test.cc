// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

#include <mylibrary/example.h>


TEST_CASE("Get Correct Score", "[player]") {
  const float random = cinder::randFloat();
  REQUIRE(random <= 1.);
}