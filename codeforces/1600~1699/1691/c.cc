#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;


  auto compute_cost = [](const string& S) -> int {
    int ans = 0;
    for (int i = 1; i < S.length(); ++i) {
      ans += (S[i-1]-'0') * 10 + S[i] - '0';
    }
    return ans;
  };

  int ans = compute_cost(s);
  auto first = s.find_first_of('1');
  auto last = s.find_last_of('1');

  if (first != string::npos && last != string::npos && first != 0 && last != n-1) {
    // can move both
    int op1_require = first;
    int op2_require = n - last - 1;
    if (op1_require + op2_require <= k) {
      string s2 = s;
      swap(s2[0], s2[first]);
      swap(s2[last], s2[n-1]);
      ans = min(ans, compute_cost(s2));
    }
    if (op1_require <= k) {
      string s2 = s;
      swap(s2[0], s2[first]);
      ans = min(ans, compute_cost(s2));
    }
    if (op2_require <= k) {
      string s2 = s;
      swap(s2[last], s2[n-1]);
      ans = min(ans, compute_cost(s2));
    }
  } else if (first != string::npos && first != 0) {
    // can only move first
    int ops_require = first;
    if (ops_require <= k) {
      swap(s[0], s[first]);
      ans = min(ans, compute_cost(s));
    }
  } else if (last != string::npos && last != n-1) {
    // can only move last
    int ops_require = n - last - 1;
    if (ops_require <= k) {
      swap(s[last], s[n-1]);
      ans = min(ans, compute_cost(s));
    }
  }

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
