#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll count_pairs(const string& a, const string& b, vector<bool>& ignore) {
  int n = a.length();
  ll ans = 0;
  string c = a;
  for(int i = 0; i < n; ++i) {
    if (c[i] != b[i] && ignore[a[i]-'a']) {
      c[i] = b[i];
    }
  }

  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && c[j] != b[j]) j++;
    int pair_count = max(i-j+1, 0);
    if (c[i] == b[i]) {
      ans += pair_count;
    } else {
      j = i+1;
    }
  }
  return ans;
}

void solve() {
  ll n = 0, k = 0;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;

  unordered_set<char> s;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      s.insert(a[i]);
    }
  }
  vector<char> to_replace(s.begin(), s.end());

  ll ans = 0;
  int m = 1<<to_replace.size();
  vector<bool> ignore(26);
  for (int mask = 0; mask < m; ++mask) {
    if (bitset<32>(mask).count() > k) continue;
    string c = a;
    fill(ignore.begin(), ignore.end(), false);
    for (int b = 0; b < to_replace.size(); ++b) if (mask & (1<<b)){
      ignore[to_replace[b]-'a'] = true;
    }
    ll pairs = count_pairs(c, b, ignore);
    ans = max(ans, pairs);
  }

  // cout << "a: " << a  << endl;
  // cout << "b: " << b << endl;

  cout << ans << endl;
}


// abc
// [a, b, c]
// [ab, bc]
// [abc]
// 3, 4, 3
//
// abcde
// [a,b,c,d,e]
// [ab,bc,cd,de]
// [abc,bcd,cde]
// [abcd,bcde]
// [abcde]
// 5, 8, 9, 8, 5

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
