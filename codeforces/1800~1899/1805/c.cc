#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<ll> lines(n);
  for (int i = 0; i < n; ++i) cin >> lines[i];

  vector<array<ll, 3>> parabolas;
  for (int i = 0; i < m; ++i) {
    ll a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    parabolas.push_back({a, b, c});
  }

  sort(lines.begin(), lines.end());

  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    auto [a, b, c] = parabolas[i];
    int larger_index = lower_bound(lines.begin(), lines.end(), b) - lines.begin();
    int l = larger_index, r = n-1;
    int index = -1;
    while (l <= r) {
      int m = l + (r-l) / 2;
      int k = lines[m];
      if ((b - k) * (b - k) >= 4 * a * c) {
        r = m-1;
      } else {
        index = m;
        break;
      }
    }

    l = 0, r = larger_index-1;
    while (l <= r) {
      int m = l + (r-l) / 2;
      int k = lines[m];
      if ((b - k) * (b - k) >= 4 * a * c) {
        l = m+1;
      } else {
        index = m;
        break;
      }
    }

    ans.push_back(index);
  }

  for (int i = 0; i < m; ++i) {
    if (ans[i] < 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << lines[ans[i]] << endl;
    }
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
