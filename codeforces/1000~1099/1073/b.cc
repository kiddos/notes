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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  reverse(a.begin(), a.end());
  vector<int> indices(n+1, -1);
  for (int i = 0; i < n; ++i) {
    indices[a[i]] = i;
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (indices[b[i]] < 0) {
      ans[i] = 0;
    } else {
      int idx = indices[b[i]];
      int move = 0;
      while ((int)a.size() > idx) {
        indices[a.back()] = -1;
        a.pop_back();
        move++;
      }
      ans[i] = move;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
