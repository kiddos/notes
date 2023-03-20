#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int flip_count = 0;
  bool flip = false;
  int l = 0, r = n-1;
  while (l < r) {
    if (s[l] == s[r]) {
      if (flip) {
        flip = false;
      }
    } else {
      if (!flip) {
        flip_count++;
        flip = true;
      }
    }

    l++;
    r--;
  }
  if (flip_count <= 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
