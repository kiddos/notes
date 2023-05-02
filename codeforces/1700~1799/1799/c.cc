#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  map<char, int> count;
  for (char ch : s) count[ch]++;

  int n = s.length();

  string t(n, ' ');
  int l = 0, r = n-1;
  while (count.size() > 0) {
    while (count.begin()->second > 1) {
      count.begin()->second -= 2;
      t[l++] = t[r--] = count.begin()->first;
    }
    if (count.begin()->second == 0) {
      count.erase(count.begin());
    } else {
      char left = count.begin()->first;
      count.erase(count.begin());
      if (count.size() == 1) {
        while (count.begin()->second > 1) {
          t[l++] = t[r--] = count.begin()->first;
          count.begin()->second -= 2;
        }
        if (count.begin()->second > 0) {
          t[l++] = count.begin()->first;
        }
        t[r--] = left;
      } else {
        t[r--] = left;
        while (!count.empty()) {
          while (count.begin()->second > 0) {
            t[l++] = count.begin()->first;
            count.begin()->second--;
          }
          count.erase(count.begin());
        }
      }
      break;
    }
  }

  cout << t << endl;
}

// abbccdd
// bbccdda

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
