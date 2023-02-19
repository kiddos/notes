#include <bits/stdc++.h>

using namespace std;

int most_significant(int n) {
  n--;
  int k = 0;
  for (int i = 0; i < 32; ++i) {
    if (n & (1 << i)) {
      k = i;
    }
  }
  return k;
}

vector<int> solve(int n) {
  int k = most_significant(n);
  vector<int> ans;
  int b = 1 << k;
  while (b) {
    ans.push_back(--b);
  }
  b = 1 << k;
  while (b < n) {
    ans.push_back(b++);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> ans = solve(n);
    for (int a : ans) cout << a << ' ';
    cout << '\n';
  }
  cout << flush << endl;
  return 0;
}
