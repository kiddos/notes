#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int find_kmax(int n, int m) {
  int ans = 0;
  while (max(n, m) >= 2 && min(n, m) >= 1) {
    if (n > m) {
      n -= 2;
      m -= 1;
    } else {
      m -= 2;
      n -= 1;
    }
    ans++;
  }
  return ans;
}

vector<i64> greedy_select(vector<i64>& p) {
  int n = p.size();
  int l = 0, r = n-1;
  vector<i64> ans;
  while (l < r) {
    ans.push_back(p[r--] - p[l++]);
  }
  sort(ans.rbegin(), ans.rend());
  vector<i64> prefix = {0};
  for (int a : ans) {
    prefix.push_back(prefix.back() + a);
  }
  return prefix;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int kmax = find_kmax(n, m);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<i64> a_greedy = greedy_select(a), b_greedy = greedy_select(b);
  // for (i64 g : a_greedy) {
  //   cout << g << " ";
  // }
  // cout << endl;
  // for (i64 g : b_greedy) {
  //   cout << g << " ";
  // }

  auto f = [&](int k, int p) -> i64 {
    int p1 = p;
    int p2 = k-p1;
    return a_greedy[p1] + b_greedy[p2];
  };

  auto find_max = [&](int k, int l, int r) -> i64 {
    while (r-l+1 > 3) {
      int m1 = l + (r-l) / 3;
      int m2 = r - (r-l) / 3;
      i64 f1 = f(k, m1);
      i64 f2 = f(k, m2);
      if (f1 < f2) {
        l = m1;
      } else {
        r = m2;
      }
    }
    i64 ans = 0;
    for (int i = l; i <= r; ++i) {
      ans = max(ans, f(k, i));
    }
    return ans;
  };

  vector<i64> ans;
  for (int k = 1; k <= kmax; ++k) {
    int l = max(0, 2 * k - m), r = min(k, n - k);
    ans.push_back(find_max(k, l, r));
  }

  cout << kmax << endl;
  for (int k = 0; k < kmax; ++k) {
    cout << ans[k] << " ";
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
