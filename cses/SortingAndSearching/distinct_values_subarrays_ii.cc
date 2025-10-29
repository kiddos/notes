#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  i64 ans = 0;
  map<int,int> count;
  for (int i = 0, j = 0; i < n; ++i) {
    count[x[i]]++;
    while ((int)count.size() > k && j < i) {
      if (--count[x[j]] == 0) {
        count.erase(x[j]);
      }
      j++;
    }
    int len = i - j + 1;
    ans += len;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
