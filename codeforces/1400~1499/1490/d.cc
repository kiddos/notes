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

  vector<int> depths(n+1);
  function<void(int,int,int)> build_tree = [&](int l, int r, int d) {
    if (l > r) {
      return;
    }

    int max_index = l;
    for (int i = l+1; i <= r; ++i) {
      if (a[i] > a[max_index]) {
        max_index = i;
      }
    }
    depths[max_index] = d;
    build_tree(l, max_index-1, d+1);
    build_tree(max_index+1, r, d+1);
  };

  build_tree(1, n, 0);
  for (int i = 1; i <= n; ++i) {
    cout << depths[i] << " ";
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
