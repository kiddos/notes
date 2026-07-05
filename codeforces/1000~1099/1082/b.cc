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
  int g_count = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-idx+1;
    segments.push_back({s[idx], len});
    if (s[idx] == 'G') {
      g_count++;
    }

    idx = j+1;
  }

  int size = segments.size();
  int ans = 0;
  for (int i = 0; i < size; ++i) {
    auto [ch, len] = segments[i];
    if (ch == 'G') {
      if (g_count > 1) {
        ans = max(ans, len+1);
      } else {
        ans = max(ans, len);
      }
    } else if (ch == 'S') {
      if (i > 0 && i+1 < size && len == 1) {
        int len1 = segments[i-1].second;
        int len2 = segments[i+1].second;
        if (g_count > 2) {
          ans = max(ans, len1+len2+1);
        } else {
          ans = max(ans, len1+len2);
        }
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
