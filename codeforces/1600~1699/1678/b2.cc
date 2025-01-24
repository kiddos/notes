#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int,int>> segments;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j+1 < n && s[j+1] == s[i]) {
      j++;
    }
    int len = j-i+1;
    i = j+1;
    segments.emplace_back(s[i]-'0', len);
  }

  int size = segments.size();
  bool flag = false;
  int ops = 0;
  int ans1 = 0;
  for (int i = 0; i < size; ++i) {
    if (segments[i].second % 2 == 1) {
      if (flag) {
        flag = false;
        ans1 += ops;
        ops = 0;
      } else {
        flag = true;
        ops = 1;
      }
    } else {
      if (flag) {
        ops++;
      }
    }
  }

  int ans2 = 0;
  char last = ' ';
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i+1] && s[i] != last) {
      ans2++;
      last = s[i];
    }
  }

  cout << ans1 << " " << max(ans2, 1) << endl;
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
