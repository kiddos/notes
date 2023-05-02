#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& p, vector<int>& a, int d) {
  int n = p.size();
  vector<int> pos(n+1);
  for (int i = 0; i < n; ++i) {
    pos[p[i]] = i+1;
  }

  vector<int> left(n+1), right(n+1);
  for (int i = n-1, r = 0; i >= 0; --i) {
    right[p[i]] = r++;
  }
  for (int i = 0, l = 0; i < n; ++i) {
    left[p[i]] = l++;
  }

  int m = a.size();
  int ans = n;
  for (int i = 1; i < m; ++i) {
    int px1 = pos[a[i-1]], px2 = pos[a[i]];
    if (px2 > px1 + d || px2 < px1) {
      cout << "0" << endl;
      return;
    }

    int moves = px2 - px1;
    int require = d - (px2 - px1) + 1;
    if (left[a[i-1]] + right[a[i]] >= require) {
      moves = min(moves, require);
    }

    ans = min(ans, moves);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0, d = 0;
    cin >> n >> m >> d;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    solve(p, a, d);
  }
  return 0;
}
