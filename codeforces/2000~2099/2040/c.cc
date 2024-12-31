#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int S(vector<int>& p) {
  int n = p.size();
  int total = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      int min_val = *min_element(p.begin() + l, p.begin() + r + 1);
      total += min_val;
    }
  }
  return total;
}

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;

  if (n < 64 && k > (1LL << (n-1))) {
    cout << "-1" << endl;
    return;
  }

  vector<int> p(n);
  k--;
  int l = 0, r = n-1;
  for (int i = 1; i <= n; ++i) {
    if (i == n) {
      p[l++] = i;
    } else {
      if (n-1-i < 64) {
        i64 mask = (1LL << (n-1-i));
        if (k & mask) {
          p[r--] = i;
        } else {
          p[l++] = i;
        }
      } else {
        p[l++] = i;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
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
