#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool possible(const string& ordering, char s, char e, int step) {
  int idx = ordering.find(s);
  idx += step;
  idx %= ordering.size();
  return ordering[idx] == e;
}

void solve() {
  string start, end;
  i64 n = 0;
  cin >> start >> end;
  cin >> n;
  string clockwise = "^>v<";
  string counter_clockwise = "^<v>";

  bool is_clockwise = possible(clockwise, start[0], end[0], n);
  bool is_counter_clockwise = possible(counter_clockwise, start[0], end[0], n);

  if (is_clockwise && is_counter_clockwise) {
    cout << "undefined" << endl;
  } else if (is_clockwise) {
    cout << "cw" << endl;
  } else if (is_counter_clockwise) {
    cout << "ccw" << endl;
  } else {
    cout << "undefined" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
