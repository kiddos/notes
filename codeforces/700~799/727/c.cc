#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;
  int a12 = query(1, 2);
  int a13 = query(1, 3);
  int a23 = query(2, 3);
  int a1 = (a12 + a13 - a23) / 2;
  int a2 = a12 - a1;
  int a3 = a13 - a1;
  vector<int> ans = {a1, a2, a3};
  for (int i = 4; i <= n; ++i) {
    int a1i = query(1, i);
    int ai = a1i - a1;
    ans.push_back(ai);
  }
  cout << "! ";
  for (int ai : ans) {
    cout << ai << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
