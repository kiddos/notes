#include <bits/stdc++.h>

using namespace std;

// Flatten a Multilevel Doubly Linked List
//
// try to think recursively for this one

struct Node {
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
 public:
  Node* flatten(Node* head) {
    Node* it = head;
    while (it) {
      if (it->child) {
        Node* next = it->next;
        Node* new_child = flatten(it->child);
        it->child = nullptr;
        new_child->prev = it;
        it->next = new_child;

        Node* it2 = new_child;
        while (it2 && it2->next) it2 = it2->next;
        it2->next = next;
        if (next) next->prev = it2;
      }
      it = it->next;
    }
    return head;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
