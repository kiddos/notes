#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int size = n * n;
  vector<int> a(size);
  for (int i = 0; i < size; ++i) {
    cin >> a[i];
  }
  multiset<int> s(a.begin(), a.end());
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int largest = *s.rbegin();
    s.erase(prev(s.end()));
    for (int x : ans) {
      int g = gcd(x, largest);
      auto it = s.find(g);
      if (it != s.end()) {
        s.erase(it);
      }
      it = s.find(g);
      if (it != s.end()) {
        s.erase(it);
      }
    }
    ans.push_back(largest);
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
