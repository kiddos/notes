#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
void mod_add(i64& ans, i64 x) {
  ans += x;
  ans %= MOD;
}

vector<int> to_digit(int x) {
  vector<int> digits;
  while (x > 0) {
    digits.push_back(x % 10);
    x /= 10;
  }
  return digits;
}

vector<int> f(const vector<int>& s1, vector<int>& s2) {
  vector<int> result;
  int len1 = s1.size();
  int len2 = s2.size();
  int i = 0, j = 0;
  while (i < len1 && j < len2) {
    result.push_back(s2[j++]);
    result.push_back(s1[i++]);
  }
  while (i < len1) {
    result.push_back(s1[i++]);
  }
  while (j < len2) {
    result.push_back(s2[j++]);
  }
  return result;
}

std::string f2(const std::string& s1, const std::string& s2) {
  std::string result;
  int len1 = s1.length();
  int len2 = s2.length();
  int i = len1-1, j = len2-1;
  while (i >= 0 && j >= 0) {
    result.push_back(s2[j--]);
    result.push_back(s1[i--]);
  }
  while (i >= 0) {
    result.push_back(s1[i--]);
  }
  while (j >= 0) {
    result.push_back(s2[j--]);
  }
  reverse(result.begin(), result.end());
  return result;
}


void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  constexpr int MAX_POWER = 30;
  vector<i64> p10(MAX_POWER+1, 1);
  for (int i = 1; i <= MAX_POWER; ++i) {
    p10[i] = p10[i-1] * 10;
    p10[i] %= MOD;
  }

  vector<int> digit_sum(MAX_POWER+1);
  for (int i = 0; i < n; ++i) {
    vector<int> digits = to_digit(a[i]);
    int len = digits.size();
    for (int j = 0; j < len; ++j) {
      digit_sum[j] += digits[j];
    }
  }

  while (!digit_sum.empty() && digit_sum.back() == 0) {
    digit_sum.pop_back();
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> digits = to_digit(a[i]);
    fill(digits.begin(), digits.end(), 0);
    vector<int> j1 = f(digit_sum, digits);
    vector<int> j2 = f(digits, digit_sum);
    for (int j = 0; j < (int)j1.size(); ++j) {
      i64 power = (j1[j] * p10[j]) % MOD;
      mod_add(ans, power);
    }
    for (int j = 0; j < (int)j2.size(); ++j) {
      i64 power = (j2[j] * p10[j]) % MOD;
      mod_add(ans, power);
    }
  }
  cout << ans << endl;

  // i64 ans2 = 0;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     string s1 = to_string(a[i]);
  //     string s2 = to_string(a[j]);
  //     string s3 = f2(s1, s2);
  //     // cout << "f(" << s1 << "," << s2 << ")=" << s3 << endl;
  //     ans2 += stol(s3);
  //     ans2 %= MOD;
  //   }
  // }
  // cout << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
