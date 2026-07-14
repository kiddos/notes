#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  for (auto it = count.rbegin(); it != count.rend(); ++it) {
    if (it->second % 2 == 1) {
      cout << "Conan" << endl;
      return;
    }
  }
  cout << "Agasa" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
