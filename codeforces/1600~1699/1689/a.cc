#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int use_a = 0, use_b = 0;

  int i = 0, j = 0;
  string ans;
  while (i < n && j < m) {
    char c1 = i < n ? a[i] : ('z'+1);
    char c2 = j < m ? b[j] : ('z'+1);

    if (c1 < c2) {
      if (use_a < k) {
        use_a++;
        use_b = 0;
        ans.push_back(c1);
        i++;
      } else {
        use_b++;
        use_a = 0;
        ans.push_back(c2);
        j++;
      }
    } else if (c2 < c1) {
      if (use_b < k) {
        use_b++;
        use_a = 0;
        ans.push_back(c2);
        j++;
      } else {
        use_a++;
        use_b = 0;
        ans.push_back(c1);
        i++;
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
