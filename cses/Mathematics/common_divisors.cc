#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> divs;
  for (int d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      divs.push_back(d);
      divs.push_back(x / d);
    }
  }
  sort(divs.begin(), divs.end());
  divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
  return divs;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int max_val = *max_element(x.begin(), x.end());
  vector<int> x_count(max_val+1);
  for (int i = 0; i < n; ++i) {
    x_count[x[i]]++;
  }

  vector<int> factor_count(max_val+1);
  factor_count[1] = n;
  for (int i = 2; i <= max_val; ++i) {
    for (int j = i; j <= max_val; j += i) {
      factor_count[i] += x_count[j];
    }
  }

  int ans = 0;
  for (int f = max_val; f >= 1; --f) {
    if (factor_count[f] >= 2) {
      ans = f;
      break;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
