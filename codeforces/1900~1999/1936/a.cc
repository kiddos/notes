#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

char query(int a, int b, int c, int d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  char compare = '\0';
  cin >> compare;
  return compare;
}

void answer(int i, int j) {
  cout << "! " << i << " " << j << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  int largest = 0;
  for (int i = 1; i < n; ++i) {
    char result = query(i, i, largest, largest);
    if (result == '>') {
      largest = i;
    }
  }

  vector<int> js = {0};
  for (int i = 1; i < n; ++i) {
    char result = query(largest, i, largest, js.back());
    if (result == '>') {
      js = {i};
    } else if (result == '=') {
      js.push_back(i);
    }
  }

  int ans_j = js[0];
  for (int i = 1; i < (int)js.size(); ++i) {
    int j = js[i];
    char result = query(j, j, ans_j, ans_j);
    if (result == '<') {
      ans_j = j;
    }
  }

  answer(largest, ans_j);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}