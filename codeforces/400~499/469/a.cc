#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int p = 0;
  cin >> p;
  vector<int> a(p);
  for (int i = 0; i < p; ++i) {
    cin >> a[i];
  }
  int q = 0;
  cin >> q;
  vector<int> b(q);
  for (int i = 0; i < q; ++i) {
    cin >> b[i];
  }

  vector<bool> passed(n+1);
  for (int i = 0; i < p; ++i) {
    passed[a[i]] = true;
  }
  for (int i = 0; i < q; ++i) {
    passed[b[i]] = true;
  }
  for (int i = 1; i <= n; ++i) {
    if (!passed[i]) {
      cout << "Oh, my keyboard!" << endl;
      return;
    }
  }
  cout << "I become the guy." << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
