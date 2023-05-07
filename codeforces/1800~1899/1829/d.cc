#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  unordered_set<int> s = {n};
  queue<int> q;
  if (n % 3 == 0) q.push(n);
  while (!q.empty()) {
    int pile = q.front();
    q.pop();
    int a = pile / 3;
    int b = a * 2;
    if (a % 3 == 0 && !s.count(a)) {
      q.push(a);
    }
    if (b % 3 == 0 && !s.count(b)) {
      q.push(b);
    }
    s.insert(a);
    s.insert(b);
  }

  if (s.count(m)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
