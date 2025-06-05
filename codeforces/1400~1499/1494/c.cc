#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int solve(vector<int>& a, vector<int>& b) {
  int n = a.size();
  int m = b.size();
  if (n == 0 || m == 0) {
    return 0;
  }

  vector<int> same(n+1);
  for (int i = n-1, j = m-1; i >= 0; --i) {
    while (j >= 0 && b[j] > a[i]) {
      j--;
    }
    if (j >= 0 && a[i] == b[j]) {
      same[i]++;
      j--;
    }
  }
  for (int i = n-1; i >= 0; --i) {
    same[i] += same[i+1];
  }

  int ans = 0;
  for (int i = m-1; i >= 0; --i) {
    auto it = upper_bound(a.begin(), a.end(), b[i]);
    int greater_a = it - a.begin();
    int total = same[greater_a];

    int box = greater_a;
    if (box > 0) {
      int left = b[i] - box + 1;
      int b_idx = lower_bound(b.begin(), b.end(), left) - b.begin();
      int places = max(i-b_idx+1, 0);
      total += min(places, box);
    }
    ans = max(ans, total);
  }
  return ans;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<int> a1, b1, a2, b2;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      a1.push_back(-a[i]);
    } else if (a[i] > 0) {
      a2.push_back(a[i]);
    }
  }
  reverse(a1.begin(), a1.end());

  for (int i = 0; i < m; ++i) {
    if (b[i] < 0) {
      b1.push_back(-b[i]);
    } else if (b[i] > 0) {
      b2.push_back(b[i]);
    }
  }
  reverse(b1.begin(), b1.end());

  int ans = solve(a1, b1) + solve(a2, b2);
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
