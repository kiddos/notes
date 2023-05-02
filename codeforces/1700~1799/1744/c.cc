#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  char current = '\0';
  cin >> n >> current;
  string s;
  cin >> s;

  string color = s + s;
  int len = color.length();
  vector<int> green(len+1, n);
  for (int i = len-1; i >= 0; --i) {
    if (color[i] == 'g') {
      green[i] = i;
    } else {
      green[i] = green[i+1];
    }
  }
  int r = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 'r') {
      r = max(r, green[i] - i);
    } else if (color[i] == 'y') {
      y = max(y, green[i] - i);
    }
  }

  if (current == 'g') {
    cout << "0" << endl;
  } else if (current == 'r') {
    cout << r << endl;
  } else if (current == 'y') {
    cout << y << endl;
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
