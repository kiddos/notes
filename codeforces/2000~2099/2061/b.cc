#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int,int> sticks;
  for (int i = 0; i < n; ++i) {
    sticks[a[i]]++;
  }
  int p1 = 0;
  for (auto& [len, count] : sticks) {
    if (count >= 2) {
      p1 = len;
    }
  }
  if (p1 == 0) {
    cout << "-1" << endl;
    return;
  }

  sticks[p1] -= 2;
  if (sticks[p1] == 0) {
    sticks.erase(p1);
  }

  vector<pair<int,int>> s(sticks.begin(), sticks.end());
  for (int i = 0; i < (int)s.size(); ++i) {
    int s1 = s[i].first;
    if (s[i].second > 1) {
      cout << s1 << " " << s1 << " " << p1 << " " << p1 << endl;
      return;
    }
    if (i+1 < (int)s.size()) {
      int s2 = s[i+1].first;
      if (s1 + p1 * 2 > s2) {
        cout << s1 << " " << s2 << " " << p1 << " " << p1 << endl;
        return;
      }
    }
  }

  cout << "-1" << endl;
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
