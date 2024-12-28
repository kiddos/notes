#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 w = 0;
  cin >> n >> w;
  vector<int> p(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }

  vector<int> depth(n+1);
  for (int i = 2; i <= n; ++i) {
    depth[i] = depth[p[i]]+1;
  }

  vector<int> size(n+1);
  vector<int> tag1(n+1), tag2(n+1);
  for (int e = 1; e <= n; ++e) {
    int a = e, b = (e+1) > n ? 1 : e+1;
    while (a != b) {
      if (depth[b] > depth[a]) {
        swap(a, b);
      }

      if (tag1[a]) {
        tag2[a] = e;
      } else {
        tag1[a] = e;
      }

      a = p[a];
      size[e]++;
    }
  }

  i64 known_weights = 0;
  int unconstrained = n;
  for (int i = 1; i < n; ++i) {
    int x = 0;
    i64 y = 0;
    cin >> x >> y;
    if (--size[tag1[x]] == 0) unconstrained--;
    if (--size[tag2[x]] == 0) unconstrained--;
    known_weights += y;
    i64 ans = known_weights * 2 + unconstrained * (w - known_weights);
    cout << ans << " ";
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
