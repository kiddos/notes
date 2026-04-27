#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> x1 >> y1 >> x2 >> y2;

  int min_x = min(x1, x2);
  int min_y = min(y1, y2);
  int size = max(abs(x1 - x2), abs(y1 - y2));

  vector<pair<int,int>> coords = {
    {min_x, min_y},
    {min_x + size, min_y},
    {min_x, min_y + size},
    {min_x + size, min_y + size},
  };
  vector<int> found(4);
  for (int i = 0; i < 4; ++i) {
    found[i] = (coords[i].first == x1 && coords[i].second == y1) ||
      (coords[i].first == x2 && coords[i].second == y2);
  }
  int total_count = accumulate(found.begin(), found.end(), 0);
  if (total_count != 2) {
    cout << "-1" << endl;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (!found[i]) {
      cout << coords[i].first << " " << coords[i].second << " ";
    }
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
