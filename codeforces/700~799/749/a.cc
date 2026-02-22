#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 2) {
    cout << "1" << endl;
    cout << "2" << endl;
  } else {
    int x = n;
    vector<int> ans;
    while (x > 3) {
      ans.push_back(2);
      x -= 2;
    }
    ans.push_back(x);
    cout << ans.size() << endl;
    for (int p : ans) {
      cout << p <<  " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
