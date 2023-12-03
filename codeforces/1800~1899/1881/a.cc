#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string repeat(const string& x, int time) {
  string ans = x;
  for (int i = 0; i < time; ++i) {
    ans += ans;
  }
  return ans;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string x, s;
  cin >> x >> s;

  if (x.find(s) != string::npos) {
    cout << "0" << endl;
    return;
  }

  int size = n;
  int max_r = 1;
  while (size < m) {
    size *= 2;
    max_r ++;
  }

  int l = 1, r = max_r+2;
  int ans = -1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    string x2 = repeat(x, mid);
    if (x2.find(s) != string::npos) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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
