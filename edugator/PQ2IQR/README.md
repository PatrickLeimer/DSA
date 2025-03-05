# DSA Programming Quiz 2

Patrick Leimer
Partner: Ilani Seguinot
———————————————————————————————————————————

### Part A: Interquartile Range

```cpp
// Patrick Leimer -- Partner is -> Ilani Seguinot
#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* fast = head->next->next->next, *slow = head->next->next, *count = head;
    float q1, q3;

    while(fast && fast->next && fast->next->next && fast->next->next->next) {
        // cout << "startingOOO  " << "fast : " << fast->value << " | slow: " << slow->value << " | count: " << count << " | q1: " << q1 << endl;
        count = count->next;
        slow = slow->next->next->next;
        fast = fast->next->next->next->next;
    }
    // 1 2 3 4 5 6 7
    //   c       s
    if (fast == nullptr){
        q1 = float((count->value));
        q3 = float((slow->value));
    }
    // 1 2 3 4
    // c   s f
    else if (fast->next == nullptr){
        q1 = (((long)count->value + (long)count->next->value) / 2.0);
        q3 = (((long)slow->value + (long)slow->next->value) / 2.0);
    }
    // 1 2 3 4 5
    // c   s f
    else if (fast->next->next == nullptr){
        q1 = ((count->value + count->next->value) / 2.0);
        q3 = ((slow->next->value + slow->next->next->value) / 2.0);
    }
    // 1 2 3 4 5 6
    // c   s f
    else if (fast->next->next->next == nullptr){
        q1 = (count->next->value);
        q3 = (slow->next->next->value);
    }

        // cout << "Q3: " << q3 << " - Q1: " << q1 << endl;
        return (float) (q3 - q1);

}

```

### Part B: Catch2 testing

```cpp
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
```

Check SCREENSHOT ->

Changed one of the approximations to 4 to test if it catches the error:

```cpp
C:\Users\patri\CLionProjects\Testing\cmake-build-debug\Testing.exe
Randomness seeded to: 3353484608
Q3: 3.5 - Q1: 1.5
Q3: 4.5 - Q1: 1.5
Q3: 5 - Q1: 2
Q3: 6 - Q1: 2
Q3: 7 - Q1: 4

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Testing.exe is a Catch2 v3.8.0 host application.
Run with -? for options

-------------------------------------------------------------------------------
IQR - 7 different elements
-------------------------------------------------------------------------------
C:/Users/patri/CLionProjects/Testing/test.cpp:56
...............................................................................

C:/Users/patri/CLionProjects/Testing/test.cpp:69: FAILED:
  REQUIRE( result == Catch::Approx(4.0f) )
with expansion:
  3.0f == Approx( 4.0 )

===============================================================================
test cases: 5 | 4 passed | 1 failed
assertions: 5 | 4 passed | 1 failed

Process finished with exit code 42

```
