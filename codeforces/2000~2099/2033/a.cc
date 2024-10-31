#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> x;

void precompute() {
  int p = 0;
  x.push_back(0);
  for (int i = 1; i <= 100; ++i) {
    if (i % 2 == 1) {
      p -= i * 2 - 1;
    } else {
      p += i * 2 - 1;
    }
    x.push_back(p);
  }
}

void solve() {
  int n = 0;
  cin >> n;

  int l = 0, r = x.size()-1;
  int idx = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (abs(x[mid]) <= n) {
      idx = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  if (x[idx] < 0) {
    cout << "Kosuke" << endl;
  } else {
    cout << "Sakurako" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
