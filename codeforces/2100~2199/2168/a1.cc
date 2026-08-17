#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void first() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  string ans;
  for (int i = 0; i < n; ++i) {
    ans.push_back(a[i]-1 + 'a');
  }
  cout << ans << endl;
}

void second() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - 'a' + 1;
  }
  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void solve() {
  string s;
  cin >> s;
  if (s == "first") {
    first();
  } else if (s == "second") {
    second();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
