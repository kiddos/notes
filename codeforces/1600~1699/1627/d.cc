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

  int max_val = *max_element(a.begin(), a.end());
  vector<bool> found(max_val+1);
  for (int i = 0; i < n; ++i) {
    found[a[i]] = true;
  }

  for (int i = max_val; i >= 1; --i) {
    if (found[i]) {
      continue;
    }

    vector<int> multiples;
    for (int j = i+i; j <= max_val; j += i) {
      if (found[j]) {
        multiples.push_back(j);
      }
    }

    int size = multiples.size();
    for (int k = 1; k < size; ++k) {
      if (gcd(multiples[k], multiples[k-1]) == i) {
        found[i] = true;
        break;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= max_val; ++i) {
    ans += found[i];
  }
  cout << ans - n << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
