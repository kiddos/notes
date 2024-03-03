#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<i64,3>> segments;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0, c = 0;
    cin >> l >> r >> c;
    segments.push_back({l, r, c});
  }

  map<int,i64> left, right;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto& [l, r, c] = segments[i];

    if (i == 0) {
      left[l] = c;
      right[r] = c;
      ans = c;
    } else {
      if (l < left.begin()->first && r > right.rbegin()->first) {
        left[l] = c;
        right[r] = c;
        ans = c;
      } else if (l < left.begin()->first) {
        left[l] = c;
        if (r == right.rbegin()->first) {
          right[r] = min(right[r], c);
          ans = c;
        } else {
          ans = right.rbegin()->second + c;
        }
      } else if (r > right.rbegin()->first) {
        right[r] = c;
        if (l == left.begin()->first) {
          left[l] = min(left[l], c);
          ans = c;
        } else {
          ans = left.begin()->second + c;
        }
      } else if (l == left.begin()->first && r == right.rbegin()->first) {
        left[l] = min(left[l], c);
        right[r] = min(right[r], c);
        ans = min(ans, c);
      } else if (l == left.begin()->first) {
        left[l] = min(left[l], c);
        ans = min(ans, left.begin()->second + right.rbegin()->second);
      } else if (r == right.rbegin()->first) {
        right[r] = min(right[r], c);
        ans = min(ans, left.begin()->second + right.rbegin()->second);
      }
    }

    cout << ans << endl;
  }
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
