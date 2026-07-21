#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 c = 0;
  cin >> n >> c;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> smaller, larger;
  for (int i = 0; i < n; ++i) {
    if (a[i] < c) {
      smaller.push_back(a[i]);
    } else {
      larger.push_back(a[i]);
    }
  }
  sort(smaller.begin(), smaller.end());

  deque<i64> d(smaller.begin(), smaller.end());

  i64 ans = 0;
  while (!d.empty() && !larger.empty()) {
    ans += larger.back() - c;
    larger.pop_back();
    d.pop_front();
  }

  while (d.size() >= 2) {
    i64 x = d.back();
    d.pop_back();
    d.pop_front();
    ans += x - c;
  }

  if (!d.empty()) {
    ans += d.back() - c;
    d.pop_back();
  }

  while (!larger.empty()) {
    ans += larger.back() - c;
    larger.pop_back();
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
