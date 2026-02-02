#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  multiset<int> alice(a.begin(), a.end());
  multiset<int> bob(b.begin(), b.end());
  int flag = 0;
  while (!alice.empty() && !bob.empty()) {
    int ai = *alice.rbegin();
    int bi = *bob.rbegin();
    if (flag == 0) {
      bob.erase(prev(bob.end()));
      if (bi > ai) {
        bob.insert(bi - ai);
      }
    } else {
      alice.erase(prev(alice.end()));
      if (ai > bi) {
        alice.insert(ai - bi);
      }
    }
    flag ^= 1;
  }

  if (!alice.empty()) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
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
