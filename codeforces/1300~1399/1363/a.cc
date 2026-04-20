#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> p(2);
  for (int i = 0; i < n; ++i) {
    p[a[i]%2].push_back(a[i]);
  }

  if (p[1].empty()) {
    cout << "No" << endl;
    return;
  }
  p[1].pop_back();

  int even_size = x-1;
  while (even_size >= 2 && p[1].size() >= 2) {
    even_size -= 2;
    p[1].pop_back();
    p[1].pop_back();
  }

  if ((int)p[0].size() >= even_size) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
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
