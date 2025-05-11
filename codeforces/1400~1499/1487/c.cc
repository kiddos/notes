#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> ans;
  vector<int> scores(n+1);

  auto update_score = [&](int i, int j, int state) {
    if (state == 1) {
      scores[i] += 3;
    } else if (state == -1) {
      scores[j] += 3;
    } else {
      scores[i]++;
      scores[j]++;
    }
  };

  if (n % 2 == 1) {
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1, state = 1; j <= n; ++j, state = -state) {
        ans.push_back(state);
        update_score(i, j, state);
      }
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 1) {
        ans.push_back(0);
        for (int j = i+2, state = 1; j <= n; ++j, state = -state) {
          ans.push_back(state);
          update_score(i, j, state);
        }
      } else {
        for (int j = i+1, state = -1; j <= n; ++j, state = -state) {
          ans.push_back(state);
          update_score(i, j, state);
        }
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << scores[i] << " ";
  // }
  // cout << endl;

  for (int state : ans) {
    cout << state << " ";
  }
  cout << endl;
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
