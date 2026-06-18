#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x =0;
  cin >> n >> x;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  pair<int,int> seg = {0, 1000};
  for (int i = 0; i < n; ++i) {
    seg.first = max(seg.first, min(a[i], b[i]));
    seg.second = min(seg.second, max(a[i], b[i]));
  }

  if (seg.first > seg.second) {
    cout << "-1" << endl;
    return;
  }

  if (x >= seg.first && x <= seg.second) {
    cout << "0" << endl;
  } else if (x < seg.first) {
    cout << seg.first - x << endl;
  } else if (x > seg.second) {
    cout << x - seg.second << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
