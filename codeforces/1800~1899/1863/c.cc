#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  k %= (n+1);

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  deque<int> d;
  set<int> mex;
  for (int i = 0; i <= n; ++i) mex.insert(i);
  for (int i = 0; i < n; ++i) {
    d.push_back(a[i]);
    mex.erase(a[i]);
  }

  for (int i = 0; i < k; ++i) {
    int x = *mex.begin();
    mex.erase(mex.begin());
    d.push_front(x);
    int last = d.back();
    mex.insert(last);
    d.pop_back();
  }

  for (int x : d) {
    cout << x << " ";
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
