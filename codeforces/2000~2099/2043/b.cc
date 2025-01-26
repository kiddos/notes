#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> odd = {1, 3, 5, 7, 9};

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;

  vector<int> ans;
  for (int x : odd) {
    i64 y = d;
    int min_digit = 1;
    while (y % x != 0 && min_digit <= 18) {
      y = y * 10 + d;
      min_digit++;
    }

    if (y % x != 0) {
      continue;
    }

    // so n! % min_digit should be 0
    for (int f = 2; f <= n && min_digit > 1; ++f) {
      int g = gcd(f, min_digit);
      min_digit /= g;
    }
    if (min_digit == 1) {
      ans.push_back(x);
    }
  }
  for (int x : ans) {
    cout << x << " ";
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
