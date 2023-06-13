#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> index;
  vector<int> colors(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      if (!index.empty() && s[index.back()] == ')') {
        colors[index.back()] = 2;
        colors[i] = 2;
        index.pop_back();
      } else {
        index.push_back(i);
      }
    } else if (s[i] == ')') {
      if (!index.empty() && s[index.back()] == '(') {
        colors[index.back()] = 1;
        colors[i] = 1;
        index.pop_back();
      } else {
        index.push_back(i);
      }
    }
  }

  if (!index.empty()) {
    cout << "-1" << endl;
    return;
  }

  unordered_set<int> color_set(colors.begin(), colors.end());

  if (color_set.size() == 1) {
    for (int i = 0; i < n; ++i) colors[i] = 1;
  }

  cout << color_set.size() << endl;
  for (int i = 0; i < n; ++i) {
    cout << colors[i] << " ";
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
