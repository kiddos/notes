#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> factors;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      factors.push_back(i);
      if (i * i != x) {
        factors.push_back(x / i);
      }
    }
  }
  sort(factors.begin(), factors.end());
  factors.resize(unique(factors.begin(), factors.end()) - factors.begin());
  return factors;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int sum = accumulate(a.begin(), a.end(), 0);
  vector<int> factors = get_factors(sum);
  reverse(factors.begin(), factors.end());
  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }
  for (int size : factors) {
    if (size > n) {
      continue;
    }
    int val = sum / size;
    int target = val;
    auto start = p.begin();
    bool valid = true;
    for (int k = 0; k < size; ++k) {
      auto it = lower_bound(start, p.end(), target);
      if (it == p.end() || *it != target) {
        valid = false;
        break;
      }

      start = it+1;
      target += val;
    }
    if (valid) {
      int op = n - size;
      cout << op << endl;
      return;
    }
  }

  cout << "-1" << endl;
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
