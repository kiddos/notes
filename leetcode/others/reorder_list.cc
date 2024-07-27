#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int v) : val(v), next(nullptr) {}
};

void cleanup(ListNode* head) {
  if (head) {
    cleanup(head->next);
    delete head;
  }
}

ListNode* insert(ListNode* head, int val) {
  if (!head) return new ListNode(val);
  ListNode* new_head = new ListNode(val);
  new_head->next = head;
  return new_head;
}

class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* mid = find_middle(head);
    ListNode* it1 = head;
    ListNode* it2 = reverse(mid);
    while (it2) {
      ListNode* next1 = it1->next;
      ListNode* next2 = it2->next;
      if (it1 == it2) break;
      it1->next = it2;
      it2->next = next1;
      it1 = next1;
      it2 = next2;
    }
    it1->next = nullptr;
  }

 private:
  ListNode* find_middle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
};

class Solution2 {
 public:
  void reorderList(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    stack<ListNode*> rest;
    while (slow) {
      rest.push(slow);
      slow = slow->next;
    }

    while (!rest.empty()) {
      ListNode* next = head->next;
      ListNode* top = rest.top();
      if (head == top) break;
      head->next = top;
      top->next = next;
      head = next;
      rest.pop();
    }

    head->next = nullptr;
  }
};

void print(ListNode* head) {
  ListNode* it = head;
  while (it) {
    cout << it->val << " ";
    it = it->next;
  }
  cout << endl;
}


int main(void) {
  constexpr int n = 100;
  ListNode* head = nullptr;
  for (int i = 0; i < n; ++i) {
    head = insert(head, i);
  }

  print(head);
  // Solution().reorderList(head);
  Solution2().reorderList(head);
  print(head);

  cleanup(head);
  return 0;
}
