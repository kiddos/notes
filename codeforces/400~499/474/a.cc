#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s0 = "qwertyuiopasdfghjkl;zxcvbnm,./";
  string d;
  cin >> d;
  string s;
  cin >> s;

  string ans;
  for (char ch : s) {
    auto idx = s0.find(ch);
    int idx2 = d == "R" ? idx-1 : idx+1;
    ans.push_back(s0[idx2]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
