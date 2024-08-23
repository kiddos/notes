#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int x = 0;
  cin >> x;
  return x;
}

void answer(vector<pair<int,int>>& ans) {
  cout << "! ";
  for (auto& [a, b] : ans) {
    cout << a << " " << b << " ";
  }
  cout << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  vector<bool> known(n+1);
  known[1] = true;

  vector<pair<int,int>> ans;
  for (int i = 2; i <= n; ++i) {
    if (known[i]) {
      continue;
    }

    while (!known[i]) {
      int a = 1, b = i;
      while (true) {
        int x = query(a, b);
        if (x == a) {
          // b should be attach to a
          ans.push_back({a, b});
          known[b] = true;
          break;
        } else {
          // x is some node in middle of a - b
          if (known[x]) {
            a = x;
          } else {
            b = x;
          }
        }
      }
    }
  }

  answer(ans);
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
