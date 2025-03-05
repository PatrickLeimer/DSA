// Patrick Leimer -- Partner is -> Ilani Seguinot
#include <iostream>
#include <iomanip>

using namespace std;

class Node {
public:
    int value;
    Node* next = nullptr;
};

// Insert element at the end of the linked list
Node* insertEnd(Node* head, int key) {
    Node* temp = new Node();
    temp->value = key;
    if (!head) return temp;

    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
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


    cout << "Q3: " << q3 << " - Q1: " << q1 << endl;
    return (float) (q3 - q1);

}

int main() {
    Node* head = nullptr;

    // Sample input
    int values[] = {1, 2, 3, 4, 5, 6, 7}; // Sorted List
    for (int val : values) head = insertEnd(head, val);

    cout << fixed << setprecision(2) << interQuartile(head) << endl; // Expected Output: 8.00

    return 0;
}
