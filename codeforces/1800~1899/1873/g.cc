#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  vector<int> A;
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      a++;
    } else if (s[i] == 'B') {
      A.push_back(a);
      a = 0;
      b++;
    }
  }
  if (a) {
    A.push_back(a);
  }

  sort(A.rbegin(), A.rend());
  int ans = 0;
  for (int i = 0; i < min((int)A.size(), b); ++i) {
    ans += A[i];
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
