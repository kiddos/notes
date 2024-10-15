#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  unordered_map<string, string> to_use;
  for (int i = 0; i < m; ++i) {
    string lan1, lan2;
    cin >> lan1 >> lan2;
    if (lan2.length() < lan1.length()) {
      to_use[lan1] = lan2;
    } else {
      to_use[lan1] = lan1;
    }
  }

  vector<string> text(n);
  for (int i = 0; i < n; ++i) {
    cin >> text[i];
  }

  for (string& word : text) {
    cout << to_use[word] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
