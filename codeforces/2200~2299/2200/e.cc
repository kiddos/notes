#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_non_decreasing(vector<int>& a) {
  int n = a.size();
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) {
      return false;
    }
  }
  return true;
}

vector<int> get_prime_factors(int x) {
  vector<int> f;
  for (int d = 2; d*d <= x; ++d) {
    while (x % d == 0) {
      f.push_back(d);
      x /= d;
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  sort(f.begin(), f.end());
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (is_non_decreasing(a)) {
    cout << "Bob" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    vector<int> f = get_prime_factors(a[i]);
    f.resize(unique(f.begin(), f.end()) - f.begin());
    if (f.size() > 1) {
      cout << "Alice" << endl;
      return;
    }
    if (!f.empty()) {
      a[i] = f[0];
    }
  }

  if (is_non_decreasing(a)) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
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
