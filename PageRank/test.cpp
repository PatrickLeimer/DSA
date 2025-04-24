#include <catch2/catch_test_macros.hpp>
#include <iostream>

// Patrick Leimer 3/31/2025 88717127
#include "AdjacencyList.h"
#include "catch2/catch_approx.hpp"
#include <sstream>

using namespace std;


string runPageRank(const string &inputStr) {
  // Use an istringstream to simulate input.
  istringstream iss(inputStr);
  int no_of_lines, power_iterations;
  iss >> no_of_lines >> power_iterations;

  map<string, vector<string>> graph;
  string from, to;
  for (int i = 0; i < no_of_lines; i++) {
    iss >> from >> to;
    graph[from].push_back(to);
  }

  AdjacencyList testingG(graph);
  return testingG.PageRank(power_iterations);
}

TEST_CASE("Numeric sanity check", "[simple]") {
  // instantiate any class members that you need to test here
  int one = 1;
  // anything that evaluates to false in a REQUIRE block will result in a
  // failing test
  REQUIRE(one == 1);
  // all REQUIRE blocks must evaluate to true for the whole test to pass
  REQUIRE_FALSE(one == 0);
}

TEST_CASE("Addition checks with sections", "[sections]") {
  // you can also use "sections" to share setup code between tests, for example:
  int one = 1;

  SECTION("num is 2") {
    int num = one + 1;
    REQUIRE(num == 2);
  };

  SECTION("num is 3") {
    int num = one + 2;
    REQUIRE(num == 3);
  };
  // each section runs the setup code independently to ensure that they don't
  // affect each other
}


TEST_CASE("Adjacency list parsing (small example)", "[graph]") {
  // the following is a "raw string" - you can write the exact input (without
  //   any indentation!) and it should work as expected
  string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

  string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

  string actualOutput = runPageRank(input);
  REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Test 4", "[idk]") {
  string input = R"(3
P T
T K
P K
)";
  REQUIRE(true);
}

TEST_CASE("Test 5", "[edge-case]") {
  string input = R"(1
google.com
)";

  double googleRank = 1.0;  // pretend from your function
  REQUIRE(googleRank == Catch::Approx(1.0).epsilon(0.0001));
}



