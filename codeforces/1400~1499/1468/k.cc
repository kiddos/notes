#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool can_return(const string& s, array<int,2>& obstacle) {
  array<int,2> p = {0, 0};
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    array<int,2> p2 = p;
    if (ch == 'U') {
      p2[1]++;
    } else if (ch == 'D') {
      p2[1]--;
    } else if (ch == 'R') {
      p2[0]++;
    } else if (ch == 'L') {
      p2[0]--;
    }
    if (p2 != obstacle) {
      p = std::move(p2);
    }
  }
  return p[0] == 0 && p[1] == 0;
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  array<int,2> p = {0, 0};
  array<int,2> max_travel = {0, 0};
  array<int,2> last_zero = {-1, -1};
  vector<array<int,2>> path;
  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    if (ch == 'U') {
      p[1]++;
    } else if (ch == 'D') {
      p[1]--;
    } else if (ch == 'R') {
      p[0]++;
    } else if (ch == 'L') {
      p[0]--;
    }

    for (int d = 0; d < 2; ++d) {
      max_travel[d] = max(max_travel[d], abs(p[d]));
      if (p[d] == 0) {
        last_zero[d] = i;
      }
    }
    path.push_back(p);
  }

  if (p[0] == 0 && p[1] == 0) {
    cout << max_travel[0]+1 << " " << max_travel[1]+1 << endl;
    return;
  }

  for (auto point : path) {
    if (can_return(s, point)) {
      cout << point[0] << " " << point[1] << endl;
      return;
    }
  }
  cout << "0 0" << endl;
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
