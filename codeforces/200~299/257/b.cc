#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

array<int,2> simulate(int n, int m) {
  vector<int> count = {n-1, m};
  int last = 0, turn = 1;
  array<int,2> ans = {0, 0};
  while (count[0] > 0 || count[1] > 0) {
    if (turn == 0) {
      if (count[last] > 0) {
        count[last]--;
        ans[turn]++;
      } else {
        count[1-last]--;
        last = 1-last;
        ans[1-turn]++;
      }
    } else if (turn == 1) {
      if (count[1-last] > 0) {
        count[1-last]--;
        ans[turn]++;
        last = 1-last;
      } else {
        count[last]--;
        ans[1-turn]++;
      }
    }
    turn ^= 1;
  }
  // cout << ans[0] << " " << ans[1] << endl;
  return ans;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  array<int,2> ans1 = simulate(n, m);
  array<int,2> ans2 = simulate(m, n);
  array<int,2> ans = {0, 0};
  if (ans1[0] > ans2[0]) {
    ans = ans1;
  } else if (ans2[0] > ans1[0]) {
    ans = ans2;
  } else if (ans1[0] == ans2[0]) {
    if (ans1[1] < ans2[1]) {
      ans = ans1;
    } else {
      ans = ans2;
    }
  }

  cout << ans[0] << " " << ans[1] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
