#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<i64,int> nums;
  for (int i = 0; i < n; ++i) {
    nums[a[i]]++;
  }

  map<i64,int> gaps;
  for (auto it = next(nums.begin()); it != nums.end(); ++it) {
    i64 diff = it->first - prev(it)->first;
    gaps[diff]++;
  }

  auto get_answer = [&]() -> i64 {
    i64 ans = nums.rbegin()->first;
    if (!gaps.empty()) {
      ans += gaps.rbegin()->first;
    }
    return ans;
  };

  int q = 0;
  cin >> q;
  while (q-- > 0) {
    int i = 0;
    i64 x = 0;
    cin >> i >> x;
    i--;
    if (a[i] == x) {
      cout << get_answer() << " ";
    } else {
      // remove original a[i]
      nums[a[i]]--;

      if (nums[a[i]] == 0) {
        auto left = nums.upper_bound(a[i]-1);
        if (left != nums.begin()) {
          i64 diff = a[i] - prev(left)->first;
          if (--gaps[diff] == 0) gaps.erase(diff);
        }

        auto right = nums.lower_bound(a[i]+1);
        if (right != nums.end()) {
          i64 diff = right->first - a[i];
          if (--gaps[diff] == 0) gaps.erase(diff);
        }

        if (right != nums.end() && left != nums.begin()) {
          i64 diff = right->first - prev(left)->first;
          gaps[diff]++;
        }

        nums.erase(a[i]);
      }

      a[i] = x;
      nums[a[i]]++;

      if (nums[a[i]] == 1) {
        auto left = nums.upper_bound(a[i]-1);
        auto right = nums.lower_bound(a[i]+1);
        if (left != nums.begin() && right != nums.end()) {
          i64 diff = right->first - prev(left)->first;
          if (--gaps[diff] == 0) gaps.erase(diff);
        }

        if (left != nums.begin()) {
          i64 diff = a[i] - prev(left)->first;
          gaps[diff]++;
        }

        if (right != nums.end()) {
          i64 diff = right->first - a[i];
          gaps[diff]++;
        }
      }

      cout << get_answer() << " ";
    }

    // cout << endl;
    // cout << "sorted: ";
    // for (auto& [x, count] : nums) {
    //   cout << x << " ";
    // }
    // cout << endl;
    // cout << "gaps: ";
    // for (auto& [g, count]  : gaps) {
    //   cout << g << ":" << count << "   ";
    // }
    // cout << endl;
  }

  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
