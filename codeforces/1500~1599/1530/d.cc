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

  vector<bool> found(n+1);
  vector<int> ans(n+1);
  vector<int> last(n+1);
  for (int node = 1; node <= n; ++node) {
    if (!found[a[node]]) {
      ans[node] = a[node];
      last[a[node]] = node;
      found[a[node]] = true;
    }
  }

  vector<int> left;
  for (int node = 1; node <= n; ++node) {
    if (!found[node]) {
      left.push_back(node);
    }
  }

  for (int node = 1, i = 0; node <= n; ++node) {
    if (ans[node] == 0) {
      ans[node] = left[i++];
    }
  }

  for (int node = 1; node <= n; ++node) {
    if (ans[node] == node) {
      int prefer = a[node];
      int l = last[prefer];
      ans[node] = prefer;
      ans[l] = node;
      last[prefer] = node;
      last[node] = l;
    }
  }

  int total = 0;
  for (int node = 1; node <= n; ++node) {
    total += ans[node] == a[node];
  }

  cout << total << endl;
  for (int node = 1; node <= n; ++node) {
    cout << ans[node] << " ";
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
