#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int idx = 0;
  vector<int> remove(2);
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-idx+1;
    if (len >= 2) {
      int bit = s[idx]-'0';
      remove[bit] += len-1;
    }
    idx = j+1;
  }

  if (abs(remove[0] - remove[1]) <= 1) {
    cout << remove[0] + remove[1] << endl;
    return;
  }

  if (remove[0] > remove[1]) {
    int ans = remove[0] + remove[1];
    int extra = remove[0] - remove[1] - 1;
    if (s[0] == '1' && extra > 0) {
      extra--;
      ans++;
    }
    if (s.back() == '1' && extra> 0) {
      extra--;
      ans++;
    }
    if (extra == 0) {
      cout << ans << endl;
    } else {
      cout << "-1" << endl;
    }
  } else {
    int ans = remove[0] + remove[1];
    int extra = remove[1] - remove[0] - 1;
    if (s[0] == '0' && extra > 0) {
      extra--;
      ans++;
    }
    if (s.back() == '0' && extra> 0) {
      extra--;
      ans++;
    }
    if (extra == 0) {
      cout << ans << endl;
    } else {
      cout << "-1" << endl;
    }
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
