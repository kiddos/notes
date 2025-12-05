#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int g = 0, c = 0, l = 0;
  cin >> g >> c >> l;
  vector<int> scores = {g, c, l};
  sort(scores.begin(), scores.end());
  if (scores[2] - scores[0] >= 10) {
    cout << "check again" << endl;
  } else {
    cout << "final " << scores[1] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
