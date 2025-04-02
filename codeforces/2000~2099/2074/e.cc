#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(int i, int j, int k) {
  cout << "! " << i << " " << j << " " << k << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  mt19937 gen;
  uniform_int_distribution<int> dist(1, n);

  set<int> s;
  for (int i = 0; i < 3; ++i) {
    while (true) {
      int p = dist(gen);
      if (!s.count(p)) {
        s.insert(p);
        break;
      }
    }
  }
  vector<int> points(s.begin(), s.end());

  while (true) {
    int result = query(points[0], points[1], points[2]);
    if (result == 0) {
      answer(points[0], points[1], points[2]);
      return;
    }
    uniform_int_distribution<int> dist2(0, 2);
    swap(points[dist2(gen)%3], result);
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
