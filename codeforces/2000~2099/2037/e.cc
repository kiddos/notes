#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(const string& s) {
  cout << "! " << s << endl;
}

// 01001
// 0110111
void solve() {
  int n = 0;
  cin >> n;

  int l = 1, r = 2;
  int result = 0;
  string ans = "1";
  while (r <= n) {
    result = query(l, r++);
    ans.push_back('1');
    if (result != 0) {
      break;
    } else {
    }
  }
  if (r > n && result == 0) {
    answer("IMPOSSIBLE");
    return;
  }
  for (int i = r-2, k = result; i >= 1 && k > 0; --i, --k) {
    ans[i-1] = '0';
  }

  while (r <= n) {
    int result2 = query(l, r++);
    if (result2 > result) {
      ans.push_back('1');
    } else {
      ans.push_back('0');
    }
    result = result2;
  }

  answer(ans);
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
