#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<bool> prefix(n, true);
  for (int i = k; i < n; ++i) {
    prefix[i] = s[i] != s[i-k] && prefix[i-k];
  }
  vector<bool> suffix(n, true);
  for (int i = n-k-1; i >= 0; --i) {
    suffix[i] = s[i] != s[i+k] && suffix[i+k];
  }

  vector<int> same_count(n, 1);
  for (int i = n-2; i >= 0; --i) {
    if (s[i] == s[i+1]) {
      same_count[i] = same_count[i+1] + 1;
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << prefix[i];
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << suffix[i];
  // }
  // cout << endl;

  bool valid = true;
  for (int i = 0; i < k; ++i) {
    valid = valid && prefix[n-i-1];
  }
  if (valid && same_count[0] == k) {
    cout << n << endl;
    return;
  }
  
  vector<int> offset(k);
  iota(offset.begin(), offset.end(), 1);

  auto check = [&](int idx) -> bool {
    // cout << "check = " << idx << endl;
    int j = idx % k;
    for (int i = idx; i < idx+k; ++i, j = (j+1) % k) {
      int si = i+k;
      int pi = idx - offset[j];
      int remaining = (n - i);
      int rest = (remaining + k - 1) / k;
      bool suffix_valid = si >= n || (suffix[si] && s[i] != s[si]);
      bool prefix_valid = pi < 0 || (prefix[pi] && ((rest % 2 == 1 && s[i] != s[pi]) || (rest % 2 == 0 && s[i] == s[pi])));
      bool valid = suffix_valid && prefix_valid;
      // cout << "idx=" << i << " result=" << suffix_valid << ", " << prefix_valid << ", pi=" << pi << endl;;
      if (!valid) {
        return false;
      }
    }
    return true;
  };

  for (int i = 0; i < n; ++i) {
    if (same_count[i] == k) {
      if (check(i)) {
        cout << i << endl;
        return;
      }
    }
  }
  cout << "-1" << endl;
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
