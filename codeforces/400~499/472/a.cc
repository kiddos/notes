#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<bool> is_prime(n+1, true);
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i + i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  set<int> composite;
  for (int i = 4; i <= n; ++i) {
    if (!is_prime[i]) {
      composite.insert(i);
    }
  }

  for (int c : composite) {
    int c2 = n - c;
    if (composite.count(c2)) {
      cout << c << " " << c2 << endl;
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
