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
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], i);
  }

  sort(p.rbegin(), p.rend());
  int l = 0, r = n-1, k = n;
  int pos = 0;
  vector<int> ans(n);
  while (l <= r) {
    int len = r-l+1;
    int front = p[l].first - pos;
    int back = p[r].first - pos;
    if (front == len && back == 0) {
      cout << "NO" << endl;
      return;
    }
    if (front == len) {
      ans[p[l].second] = k--;
      pos++;
      l++;
    } else if (back == 0) {
      ans[p[r].second] = -k;
      k--;
      r--;
    } else {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
