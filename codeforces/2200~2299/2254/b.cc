#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int idx = 0;
  vector<pair<char,int>> segments;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-idx+1;
    segments.push_back({s[idx], len});
    idx = j+1;
  }

  int size = segments.size();
  int ans = size;
  int remove = 0;
  for (int i = 1; i < size-1; ++i) {
    if (segments[i].second == 1) {
      if (segments[i+1].first == segments[i-1].first) {
        remove = max(remove, 2);
      } else {
        remove = max(remove, 1);
      }
    }
  }
  ans -= remove;
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
