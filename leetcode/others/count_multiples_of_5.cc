#include <bits/stdc++.h>

using namespace std;

int construct_tree(vector<int>& tree, vector<int>& nums, int ss, int se, int i) {
  if (ss == se) {
    int ans = nums[ss] % 5 == 0;
    tree[i] = ans;
    return ans;
  }
  int mid = ss + (se - ss) / 2;
  int ans = construct_tree(tree, nums, ss, mid, i * 2 + 1) +
            construct_tree(tree, nums, mid + 1, se, i * 2 + 2);
  tree[i] = ans;
  return ans;
}

vector<int> segment_tree(vector<int>& nums) {
  int n = nums.size();
  int height = ceil(log2(n));
  int max_size = 2 * (int)pow(2, height) - 1;
  vector<int> tree(max_size);
  construct_tree(tree, nums, 0, n - 1, 0);
  return tree;
}

int get_count(vector<int>& tree, int ss, int se, int qs, int qe, int i) {
  if (qs <= ss && qe >= se) {
    return tree[i];
  }
  if (se < qs || ss > qe) return 0;

  int mid = ss + (se - ss) / 2;
  return get_count(tree, ss, mid, qs, qe, i * 2 + 1) +
         get_count(tree, mid+1, se, qs, qe, i * 2 + 2);
}

int get_count(vector<int>& tree, int n, int qs, int qe) {
  return get_count(tree, 0, n - 1, qs, qe, 0);
}

int main() {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, q = 0;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> tree = segment_tree(nums);

    // vector<pair<int, int>> queries(n);
    for (int i = 0; i < q; ++i) {
      int start = 0, end = 0;
      cin >> start >> end;
      // cout << start << ", " << end << endl;
      int count = get_count(tree, n, start-1, end-1);
      cout << count << " ";
      // queries.push_back({start, end});
    }
  }
  return 0;
}
