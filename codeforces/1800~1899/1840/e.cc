#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  vector<string> s(2);
  cin >> s[0] >> s[1];

  int n = s[0].length();
  vector<bool> same(n);
  int diff = 0;
  for (int i = 0; i < n; ++i) {
    same[i] = s[0][i] == s[1][i];
    diff += !same[i];
  }

  ll t = 0, q = 0;
  cin >> t >> q;
  priority_queue<ll, vector<ll>, greater<>> pq;
  for (int i = 0; i < q; ++i) {
    while (!pq.empty() && pq.top() <= i) {
      pq.pop();
    }

    int type = 0;
    cin >> type;
    if (type == 1) {
      int pos = 0;
      cin >> pos;
      pos--;

      if (!same[pos]) {
        pq.push(i+t);
      }
    } else if (type == 2) {
      int i1 = 0, pos1 = 0, i2 = 0, pos2 = 0;
      cin >> i1 >> pos1 >> i2 >> pos2;
      i1--;
      i2--;
      pos1--;
      pos2--;
      swap(s[i1][pos1], s[i2][pos2]);

      bool b = s[0][pos1] == s[1][pos1];
      if (b != same[pos1]) {
        diff += b ? -1 : 1;
        same[pos1] = b;
      }

      b = s[0][pos2] == s[1][pos2];
      if (b != same[pos2]) {
        diff += b ? -1 : 1;
        same[pos2] = b;
      }

      // cout << s[0] << " " << s[1] << endl;
      // cout << diff << endl;
    } else if (type == 3) {
      bool ans = diff <= (int)pq.size();
      if (ans) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
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
