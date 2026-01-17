#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  unordered_map<string, int> found;
  for (int i = 0; i < n; ++i) {
    if (found.count(s[i])) {
      cout << s[i] << found[s[i]] << endl;
    } else {
      cout << "OK" << endl;
    }
    found[s[i]]++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
