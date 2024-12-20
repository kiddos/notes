#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  auto create = [&](int stop) -> string {
    string ans(k, ' ');
    for (int i = 0, j = 0; i < k; ++i) {
      ans[i] = s[j];
      j = (j+1) % stop;
    }
    return ans;
  };

  int stop = n;
  for (int i = 1; i < n; ++i) {
    string prefix = s.substr(0, i);
    string suffix = s.substr(i);
    suffix = suffix.substr(0, min(suffix.length(), prefix.length()));
    if (prefix < suffix) {
      stop = i;
      break;
    }
  }

  string ans = create(stop);
  for  (int i = stop; i >= 1; --i) {
    ans = min(ans, create(i));
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
