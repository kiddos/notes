#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int half = n / 2;
  if (half % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  vector<int> first(half);
  vector<int> second(half);
  for (int i = 0, x = 2, y = 1; i < half; ++i, x += 2, y += 2) {
    first[i] = x;
    second[i] = y;
  }
  second.back() += half;

  cout << "YES" << endl;
  for (int i = 0; i < half; ++i) {
    cout << first[i] << " ";
  }
  for (int i = 0; i < half; ++i) {
    cout << second[i] << " ";
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
