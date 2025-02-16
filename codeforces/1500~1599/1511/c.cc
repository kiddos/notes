#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  deque<int> d(a.begin(), a.end());
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    int index = 1;
    auto it = d.begin();
    for (; it != d.end(); ++it, ++index) {
      if (*it == t) {
        break;
      }
    }
    d.erase(it);
    d.push_front(t);
    cout << index << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
