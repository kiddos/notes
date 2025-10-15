#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> p;
  int i = 0;
  while (i < n) {
    if (s[i] == '1') {
      p.push_back(i+1);
      i++;
    } else {
      int j = i;
      vector<int> r = {i+1};
      while (j+1 < n && s[j+1] == '0') {
        j++;
        r.push_back(j+1);
      }
      if (r.size() == 1) {
        cout << "NO" << endl;
        return;
      }
      i = j+1;
      reverse(r.begin(), r.end());
      for (int x : r) {
        p.push_back(x);
      }
    }
  }

  cout << "YES" << endl;
  for (int x : p) {
    cout << x << " ";
  }
  cout << endl;
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
