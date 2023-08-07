#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;

  vector<int> count1(3), count2(3);
  for (int i = 0; i < n; ++i) {
    count1[s[i]-'a']++;
    count2[t[i]-'a']++;
  }

  if (count1 != count2) {
    cout << "NO" << endl;
    return;
  }

  int b1 = 0, b2 = 0;
  int i = 0, j = 0;
  while (i < n && j < n) {
    while (i < n && s[i] == 'b') {
      b1++;
      i++;
    }
    while (j < n && t[j] == 'b') {
      b2++;
      j++;
    }

    if ((i < n && j >= n) || (i >= n && j < n)) {
      cout << "NO" << endl;
      return;
    }
    if (i >= n && j >= n) {
      break;
    }

    if (s[i] != t[j]) {
      cout << "NO" << endl;
      return;
    }

    if (s[i] == 'a') {
      if (b1 > b2)  {
        cout << "NO" << endl;
        return;
      }
    } else if (s[i] == 'c') {
      if (b1 < b2) {
        cout << "NO" << endl;
        return;
      }
    }

    i++;
    j++;
  }

  cout << "YES" << endl;
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
