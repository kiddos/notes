#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_VAL = 100;
vector<bool> is_prime(MAX_VAL, true);
vector<string> composite;

void precompute() {
  for (int i = 2; i < MAX_VAL; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j < MAX_VAL; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 10; i < MAX_VAL; ++i) {
    if (!is_prime[i]) {
      composite.push_back(to_string(i));
    }
  }
}

void solve() {
  int k = 0;
  cin >> k;
  string s;
  cin >> s;

  for (int i = 0; i < k; ++i) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
      cout << "1" << endl;
      cout << s[i] << endl;
      return;
    }
  }

  auto is_subseq = [&](const string& s, const string& p) -> bool {
    for (int i = 0, j = 0; i < (int)s.length(); ++i) {
      if (p[j] == s[i]) {
        j++;
      }
      if (j == (int)p.length()) {
        return true;
      }
    }
    return false;
  };

  for (string& c : composite) {
    if (is_subseq(s, c)) {
      cout << "2" << endl;
      cout << c << endl;
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
