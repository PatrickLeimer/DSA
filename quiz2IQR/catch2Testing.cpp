#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

class Node {
public:
    int value;
    Node* next = nullptr;
};

extern Node* insertEnd(Node* head, int key);
extern float interQuartile(Node* head);

TEST_CASE("IQR - 4 elements") {
    Node* head = nullptr;
    for (int i = 1; i < 5; i++) {
        head = insertEnd(head, i);
    }

    float result = interQuartile(head);
    // For 4 elements: Q1 = (1+2)/2 = 1.5, Q3 = (3+4)/2 = 3.5 => difference = 2.0
    REQUIRE(result == Catch::Approx(2.0f));
}

TEST_CASE("IQR - 5 elements") {
    Node* head = nullptr;
    for (int i = 1; i < 6; i++) {
        head = insertEnd(head, i);
    }

    float result = interQuartile(head);
    // For 5 elements: Q1 = (1+2)/2 = 1.5, Q3 = (4+5)/2 = 4.5 => difference = 3.0
    REQUIRE(result == Catch::Approx(3.0f));
}

TEST_CASE("IQR - 6 elements") {
    Node* head = nullptr;
    for (int i = 1; i < 7; i++) {
        head = insertEnd(head, i);
    }

    float result = interQuartile(head);
    // For 6 elements: Q1 = 2, Q3 = 5 => difference = 3.0
    REQUIRE(result == Catch::Approx(3.0f));
}

TEST_CASE("IQR - 7 elements") {
    Node* head = nullptr;
    for (int i = 1; i < 8; i++) {
        head = insertEnd(head, i);
    }

    float result = interQuartile(head);
    // For 7 elements: Q1 = 2, Q3 = 6 => difference = 4.0
    REQUIRE(result == Catch::Approx(4.0f));
}
TEST_CASE("IQR - 7 different elements") {
    //2 4 4 5 6 7 8
    Node* head = nullptr;
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    head = insertEnd(head, 8);

    float result = interQuartile(head);
    // For 7 elements: Q1 = 4, Q3 = 7 => difference = 3.0
    REQUIRE(result == Catch::Approx(3.0f)); //Compares to the real result
}