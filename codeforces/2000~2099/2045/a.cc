#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int len = s.length();

  auto possible = [&](int k) -> bool {
    int c = 0, v = 0, y = 0;
    for (char ch : s) {
      if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        v++;
      } else if (ch == 'Y') {
        y++;
      } else {
        c++;
      }
    }
    int missing = max(0, k-v) + max(0, k*2 - c);
    return y >= missing;
  };

  int l = 0, r = len;
  int syllable = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      syllable = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }


  int c = 0, v = 0, y = 0, n = 0, g = 0;
  for (char ch : s) {
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      v++;
    } else if (ch == 'Y') {
      y++;
    } else if (ch == 'G') {
      g++;
    } else {
      if (ch == 'N') {
        n++;
      }
      c++;
    }
  }

  int require_c = syllable * 2;
  int require_v = syllable;

  // greedy use a,e,i,o,u
  int use = min(require_v, v);
  require_v -= use;
  v -= use;
  // greedy use y
  use = min(require_v, y);
  require_v -= use;
  y -= use;

  // greedy use other consonant
  use = min(require_c, c);
  require_c -= use;
  c -= use;
  // greedy use y
  use = min(require_c, y);
  require_c -= use;
  y -= use;
  // greedy use g
  use = min(require_c, g);
  require_c -= use;
  g -= use;

  int n_used = min(syllable * 2, n);
  int ng_pair = min(n_used, g);
  
  int ans = syllable * 3 + ng_pair;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
