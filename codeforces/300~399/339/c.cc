#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int m = 0;
  cin >> m;
  vector<int> weights;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == '1') {
      weights.push_back(i+1);
    }
  }

  vector<int> ans;
  auto dfs = [&](const auto& self, int balance, int last, int t) -> bool {
    if (t == m) {
      return true;
    }
    if (balance < 0) {
      for (int w : weights) {
        ans.push_back(w);
        if (w != last && balance + w > 0 && self(self, balance + w, w, t + 1)) {
          return true;
        }
        ans.pop_back();
      }
    } else {
      for (int w : weights) {
        ans.push_back(w);
        if (w != last && balance - w < 0 && self(self, balance - w, w, t + 1)) {
          return true;
        }
        ans.pop_back();
      }
    }
    return false;
  };

  for (int w : weights) {
    ans.push_back(w);
    if (dfs(dfs, w, w, 1)) {
      break;
    }
    ans.pop_back();
  }

  if (ans.empty()) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int w : ans) {
    cout << w << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
