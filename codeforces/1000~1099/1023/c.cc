#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> open_index(n);
  vector<int> close;
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st.push_back(i);
    } else {
      open_index[i] = st.back();
      st.pop_back();
      close.push_back(i);
    }
  }
  vector<bool> ignore(n);
  int remove = n - k;
  while (remove > 0) {
    int i1 = close.back();
    close.pop_back();
    int i2 = open_index[i1];
    ignore[i1] = ignore[i2] = true;
    remove -= 2;
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    if (!ignore[i]) {
      ans.push_back(s[i]);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
