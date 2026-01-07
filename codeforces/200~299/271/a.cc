#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool distinct(int x) {
  string s = to_string(x);
  unordered_set<char> chars(s.begin(), s.end());
  return chars.size() == s.length();
}

void solve() {
  int n = 0;
  cin >> n;
  int x = n + 1;
  while (!distinct(x)) {
    x++;
  }
  cout << x << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
