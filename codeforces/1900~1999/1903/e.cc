#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool other_play_move(vector<set<int>>& p) {
  int index = 0;
  cin >> index;
  if (index < 0) {
    return false;
  }

  if (p[0].count(index)) {
    p[0].erase(index);
  } else if (p[1].count(index)) {
    p[1].erase(index);
  }
  return p[0].size() > 0 || p[1].size() > 0;
}

void move(set<int>& s) {
  int x = *s.begin();
  cout << x << endl;
  s.erase(x);
}

void play_first(vector<set<int>>& p, int idx) {
  cout << "First" << endl;
  while (p[0].size() > 0 || p[1].size() > 0) {
    if (!p[idx].empty()) {
      move(p[idx]);
    } else {
      move(p[1-idx]);
    }
    if (p[0].empty() && p[1].empty()) {
      break;
    }
    if (!other_play_move(p)) {
      break;
    }
  }
}

void play_second(vector<set<int>>& p, int idx) {
  cout << "Second" << endl;
  while (p[0].size() > 0 || p[1].size() > 0) {
    if (!other_play_move(p)) {
      break;
    }

    if (!p[idx].empty()) {
      move(p[idx]);
    } else {
      move(p[1-idx]);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> points;
  for (int i = 0; i <= n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    points.emplace_back(x, y);
  }

  vector<set<int>> p(2);
  for (int i = 1; i <= n; ++i) {
    int k = (points[i].first % 2) ^ (points[i].second % 2);
    p[k].insert(i);
  }

  int k0 = (points[0].first % 2) ^ (points[0].second % 2);
  if (p[0].size() == p[1].size()) {
    if (k0 == 0) {
      play_first(p, 1);
    } else {
      play_first(p, 0);
    }
  } else if (p[0].size() > p[1].size()) {
    if (k0 == 0) {
      play_first(p, 1);
    } else {
      play_second(p, 1);
    }
  } else {
    if (k0 == 0) {
      play_second(p, 0);
    } else {
      play_first(p, 0);
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
