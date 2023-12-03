#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_sorted(vector<int>& a, int start) {
  int n = a.size();
  for (int i = start+1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  multiset<int> s(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    s.erase(s.find(a[i]));

    if (s.empty()) {
      break;
    } else if (*s.begin() < a[i]) {
      ans++;
    } else {
      if (is_sorted(a, i+1)) {
        break;
      } else {
        cout << "-1" << endl;
        return;
      }
    }
  }
  cout << ans << endl;
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
