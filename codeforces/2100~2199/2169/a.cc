#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int points(vector<int>& v, int a, int b) {
  int ans = 0;
  for (int x : v) {
    int d1 = abs(a - x);
    int d2 = abs(b - x);
    if (d2 < d1) {
      ans++;
    }
  }
  return ans;
}

void solve() {
  int n = 0, a = 0;
  cin >> n >> a;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int total1 = points(v, a, a+1);
  int total2 = points(v, a, a-1);
  if (total1 >= total2) {
    cout << a+1 << endl;
  } else {
    cout << a-1 << endl;
  }
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
