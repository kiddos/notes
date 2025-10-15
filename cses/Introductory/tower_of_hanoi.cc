#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void move(vector<vector<int>>& st, int i1, int i2, int c, vector<pair<int,int>>& moves) {
  if (c == 1) {
    int top = st[i1].back();
    st[i1].pop_back();
    st[i2].push_back(top);
    moves.emplace_back(i1+1, i2+1);
    return;
  }
  int i3 = 3-i1-i2;
  move(st, i1, i3, c-1, moves);
  move(st, i1, i2, 1, moves);
  move(st, i3, i2, c-1, moves);
}

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<int>> st(3);
  for (int i = n; i >= 1; --i) {
    st[0].push_back(i);
  }

  vector<pair<int,int>> moves;
  move(st, 0, 2, n, moves);
  cout << moves.size() << endl;
  for (auto [from, to] : moves) {
    cout << from << " " << to << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
