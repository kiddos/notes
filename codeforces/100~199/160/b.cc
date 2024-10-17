#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> first, second;
  for (int i = 0; i < n; ++i) {
    first.push_back(s[i] - '0');
  }
  for (int i = n; i < 2 * n; ++i) {
    second.push_back(s[i] - '0');
  }
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  
  auto is_less = [&](vector<int>& a, vector<int>& b) -> bool {
    for (int i = 0; i < n; ++i) {
      if (a[i] >= b[i]) {
        return false;
      }
    }
    return true;
  };

  bool ans = is_less(first, second) || is_less(second, first);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
