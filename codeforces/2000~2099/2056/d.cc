#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  auto count_bad = [&](int x) -> i64 {
    vector<int> px(n+1);
    for (int i = 1; i <= n; ++i) {
      if (a[i] == x) {
        px[i]++;
      }
      px[i] += px[i-1];
    }

    map<int,int> prefix;
    vector<int> b(n+1);
    i64 bad = 0;
    for (int i = 1, j = 0, balance = 0; i <= n; ++i) {
      while (j < n && px[i] - px[j] > 0) {
        prefix[b[j++]]++;
      }

      if (a[i] <= x) {
        balance--;
      } else{
        balance++;
      }
      b[i] = balance;

      if (prefix.count(balance)) {
        bad += prefix[b[i]];
      }
    }
    return bad;
  };

  i64 total_bad = 0;
  for (int x = 1; x <= 10; ++x) {
    total_bad += count_bad(x);
    // cout << "x=" << x << ", bad=" << total_bad << endl;
  }

  i64 total_subarray = (i64)n * (n+1) / 2;
  i64 ans = total_subarray - total_bad;
  cout << ans << endl;
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
