#include <bits/stdc++.h>

using namespace std;

// Copy List with Random Pointer
//
// just some implementation practice

struct Node {
  int val;
  Node* next;
  Node* random;

  Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* it = head;
    while (it) {
      Node* next = it->next;
      Node* copy = new Node(it->val);
      it->next = copy;
      copy->next = next;
      it = next;
    }

    it = head;
    while (it) {
      Node* copy = it->next;
      if (it->random) {
        copy->random = it->random->next;
      }
      it = copy->next;
    }

    Node* ans = head->next;
    it = head;
    while (it) {
      Node* copy = it->next;
      Node* next = copy->next;
      if (next) copy->next = next->next;
      else copy->next = nullptr;
      it->next = next;
      it = next;
    }
    return ans;
  }
};


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);


  return 0;
}
