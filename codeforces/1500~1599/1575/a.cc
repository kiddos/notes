#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool asc_desc(const string& s1, const string& s2) {
  int m = s1.length();
  for (int i = 0; i < m; ++i) {
    if (i % 2 == 0) {
      if (s1[i] < s2[i]) return true;
      if (s1[i] > s2[i]) return false;
    } else {
      if (s1[i] > s2[i]) return true;
      if (s1[i] < s2[i]) return false;
    }
  }
  return false;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<string, int>> p;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    p.push_back({s, i});
  }
  sort(p.begin(), p.end(), [&](auto& p1, auto& p2) {
    return asc_desc(p1.first, p2.first);
  });
  for (auto& [s, idx] : p) {
    cout << idx << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
