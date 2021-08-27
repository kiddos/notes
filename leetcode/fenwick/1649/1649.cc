#include <bits/stdc++.h>

using namespace std;

// Create Sorted Array through Instructions
//
// first intuition might be using multiset
// however, to get the number of elements smaller/larger than some random element
// will take linear time for multiset
//
// need to use binary index tree

class Fenwick {
 public:
  Fenwick(int n) : data_(n + 1) {}

  void update(int i, int val) {
    int n = data_.size();
    while (i < n) {
      data_[i] += val;
      i += (i & -i);
    }
  }

  int get(int i) {
    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

 private:
  vector<int> data_;
};

class Solution {
 public:
  int createSortedArray(vector<int>& instructions) {
    int max_instruction = 0;
    for (int ins : instructions) max_instruction = max(max_instruction, ins);
    Fenwick tree(max_instruction);

    const int MOD = 1e9 + 7;
    int n = instructions.size();
    long ans = 0;
    for (int i = 0; i < n; ++i) {
      int ins = instructions[i];
      ans += min(tree.get(ins - 1), i - tree.get(ins));
      ans %= MOD;
      tree.update(ins, 1);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> instructions;
  int ans;

  instructions = {1, 5, 6, 2};
  ans = Solution().createSortedArray(instructions);
  assert(ans == 1);

  instructions = {1, 2, 3, 6, 5, 4};
  ans = Solution().createSortedArray(instructions);
  assert(ans == 3);

  instructions = {1, 3, 3, 3, 2, 4, 2, 1, 2};
  ans = Solution().createSortedArray(instructions);
  assert(ans == 4);
  return 0;
}
