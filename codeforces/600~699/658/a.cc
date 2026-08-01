#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  int limak = 0;
  for (int i = 0, x = 0; i < n; ++i) {
    x += t[i];
    limak += max(0, p[i] - c * x);
  }
  int radewoosh = 0;
  for (int i = n-1, x = 0; i >= 0; --i) {
    x += t[i];
    radewoosh += max(0, p[i] - c * x);
  }
  if (limak > radewoosh) {
    cout << "Limak" << endl;
  } else if (radewoosh > limak) {
    cout << "Radewoosh" << endl;
  } else {
    cout << "Tie" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
