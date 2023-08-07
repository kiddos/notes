#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<int> right_one(n, n);
  vector<int> buffer;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      while (!buffer.empty()) {
        right_one[buffer.back()] = i;
        buffer.pop_back();
      }
      right_one[i] = i;
    } else if (s[i] == '0') {
      buffer.push_back(i);
    }
  }

  // cout << "right one: " << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << right_one[i] << " ";
  // }
  // cout << endl;

  vector<int> left_zero(n, -1);
  buffer.clear();
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '0') {
      while (!buffer.empty()) {
        left_zero[buffer.back()] = i;
        buffer.pop_back();
      }
      left_zero[i] = i;
    } else {
      buffer.push_back(i);
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << left_zero[i] << " ";
  // }
  // cout << endl;

  set<pair<int,int>> found;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;

    l--;
    r--;

    int r2 = left_zero[r], l2 = right_one[l];
    // cout << "l2=" << l2 << ", r2=" << r2 << endl;
    if (l2 > r2) {
      found.insert({-1, -1});
    } else {
      found.insert({l2, r2});
    }
  }

  int ans = found.size();
  cout << ans << endl;
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
