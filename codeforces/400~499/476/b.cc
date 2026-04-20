#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int C(int n, int k) {
  i64 ans = 1;
  for (int i = n; i > k; --i) {
    ans *= i;
  }
  for (int i = n-k; i > 1; --i) {
    ans /= i;
  }
  return ans;
}

void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> p1(2), p2(3);
  int n = s1.length();
  for (int i = 0; i < n; ++i) {
    if (s1[i] == '+') {
      p1[0]++;
    } else if (s1[i] == '-') {
      p1[1]++;
    }
    if (s2[i] == '+') {
      p2[0]++;
    } else if (s2[i] == '-') {
      p2[1]++;
    } else if (s2[i] == '?') {
      p2[2]++;
    }
  }
  double ans = 0;
  if (p2[0] > p1[0] || p2[1] > p1[1]) {
    cout << fixed << setprecision(6) << ans << endl;
    return;
  }
  ans = 1.0;
  if (p2[2] == 0) {
    cout << fixed << setprecision(6) << ans << endl;
    return;
  }
  ans = C(p2[2], p1[0] - p2[0]) * pow(0.5, p2[2]);
  cout << fixed << setprecision(9) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
