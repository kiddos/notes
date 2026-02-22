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
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], i);
  }
  sort(p.begin(), p.end());

  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    if (p[i].first != a[i]) {
      if (l < 0) {
        l = i;
      }
      r = i;
    }
  }


  if (l < 0 && r < 0) {
    cout << "yes" << endl;
    cout << "1 1" << endl;
  } else {
    for (int i = l, j = r; i <= r; ++i, --j) {
      if (p[i].second != j) {
        cout << "no" << endl;
        return;
      }
    }
    cout << "yes" << endl;
    cout << l+1 << " " << r+1 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
