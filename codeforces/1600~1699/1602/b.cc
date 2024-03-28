#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> steps = {a};
  constexpr int MAX_STEPS = 2000;
  for (int t = 0; t < MAX_STEPS; ++t) {
    vector<int> c(n+1);
    for (int i = 1; i <= n; ++i) {
      c[a[i]]++;
    }

    vector<int> a2 = a;
    for (int i = 1; i <= n; ++i) {
      a2[i] = c[a2[i]];
    }

    if (a2 == a) {
      break;
    }
    a = std::move(a2);
    steps.push_back(a);
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x = 0, k = 0;
    cin >> x >> k;
    if (k >= (int)steps.size()) {
      vector<int>& a_t = steps.back();
      cout << a_t[x] << endl;
    } else {
      vector<int>& a_t = steps[k];
      cout << a_t[x] << endl;
    }
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
