#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int lucky(ll x) {
  int min_d = 10, max_d = 0;
  while (x > 0) {
    int d = x % 10;
    x /= 10;
    min_d = min(min_d, d);
    max_d = max(max_d, d);
  }
  return max_d - min_d;
}

void solve() {
  ll l = 0, r = 0;
  cin >> l >> r;

  string left = to_string(l);
  string right = to_string(r);
  if (left.length() < right.length()) {
    for (int k = 0; k < left.length(); ++k) cout << "9";
    cout << endl;
    return;
  }
  left = string(right.length()- left.length(), '0') + left;

  int n = right.length();
  int best_diff = 10;
  ll ans = l;
  bool visited[20][2][2][11][11];
  memset(visited, 0, sizeof(visited));
  function<void(int,bool,bool,int,int,ll)> dp = [&](int i, bool greater, bool smaller, int min_d, int max_d, ll current) {
    if (i == n) {
      int diff = max_d - min_d;
      if (diff < best_diff) {
        best_diff = diff;
        ans = current;
      }
      return;
    }
    if (visited[i][greater][smaller][min_d][max_d]) {
      return;
    }
    visited[i][greater][smaller][min_d][max_d] = true;

    int start = greater ? 0 : left[i]-'0';
    int end = smaller ? 9 : right[i]-'0';
    // if (start != end) cout << "index=" << i << " " << start << " <-> " << end << endl;
    for (int d = start; d <= end; ++d) {
      bool g = greater || d > (left[i]-'0');
      bool s = smaller || d < (right[i]-'0');
      // cout << i <<"," << d << "  | ";
      dp(i+1, g, s, min(min_d, d), max(max_d, d), current * 10 + d);
    }
    // cout << endl;
  };

  dp(0, 0, 0, 9, 0, 0);
  // cout << best_diff << endl;

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
