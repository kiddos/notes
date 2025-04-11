#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<char> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  string s = "01032025";
  unordered_map<char,int> require;
  for (char ch : s) {
    require[ch]++;
  }

  for (int i = 0; i < n; ++i) {
    if (require.count(a[i])) {
      if (--require[a[i]] == 0) {
        require.erase(a[i]);
      }
    }

    if (require.size() == 0) {
      cout << i+1 << endl;
      return;
    }
  }
  cout << "0" << endl;
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
