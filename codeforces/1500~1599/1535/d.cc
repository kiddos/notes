#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;
  string s0;
  cin >> s0;
  int len = s0.length();

  vector<int> index(len+1);
  string s = " ";
  for (int i = len-1, p = 1, k = 1; i >= 0; p <<= 1, i -= p) {
    s += s0.substr(i, p);
    for (int j = i; j < i+p; ++j) {
      index[j+1] = k++;
    }
  }

  vector<int> win_count(len+1);
  function<int(int)> construct = [&](int i) -> int {
    if (i > len) {
      return 1;
    }
    int left = construct(i*2);
    int right = construct(i*2+1);
    if (s[i] == '0') {
      win_count[i] = left;
    } else if (s[i] == '1') {
      win_count[i] = right;
    } else if (s[i] == '?') {
      win_count[i] = left + right;
    }
    return win_count[i];
  };

  construct(1);
  // for (int i = 1; i <= len; ++i) {
  //   cout << win_count[i] << " ";
  // }
  // cout << endl;

  function<void(int)> update = [&](int idx) {
    if (idx < 1) return;

    int left = idx*2 > len ? 1 : win_count[idx*2];
    int right = idx*2+1 > len ? 1 : win_count[idx*2+1];
    if (s[idx] == '0') {
      win_count[idx] = left;
    } else if (s[idx] == '1') {
      win_count[idx] = right;
    } else if (s[idx] == '?') {
      win_count[idx] = left + right;
    }
    update(idx / 2);
  };

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int p = 0;
    char c = '\0';
    cin >> p >> c;

    p = index[p];
    s[p] = c;
    update(p);

    // cout << s << endl;
    // for (int i = 1; i <= len; ++i) {
    //   cout << win_count[i] << " ";
    // }
    // cout << endl;

    int ans = win_count[1];
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
