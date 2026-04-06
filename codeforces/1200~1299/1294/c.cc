#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> f;
  int x = n;
  for (int d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      f.push_back(d);
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  sort(f.begin(), f.end());
  vector<int> ans;
  int current = 1;
  for (int fi : f) {
    current *= fi;
    if (ans.empty() || ans.back() != current) {
      ans.push_back(current);
      current = 1;
    }
  }
  if (current > 1) {
    ans.push_back(current);
  }

  if (ans.size() < 3) {
    cout << "NO" << endl;
    return;
  }

  while (ans.size() > 3) {
    int ai = ans.back();
    ans.pop_back();
    ans.back() *= ai;
  }

  set<int> s(ans.begin(), ans.end());
  if (s.size() != 3) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int ai : ans) {
    cout << ai << " ";
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
