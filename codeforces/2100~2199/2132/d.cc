#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_POWER = 16;
vector<i64> number_count = {0};
vector<i64> number_count_prefix = {0};
vector<i64> digit_total = {0};
vector<i64> digit_total_prefix = {0};

void precompute() {

  i64 power = 1;
  for (int p = 1; p <= MAX_POWER; ++p, power *= 10) {
    i64 first = power;
    i64 last = (power * 10) - 1;
    i64 c = last - first + 1;
    c *= p;
    number_count.push_back(c);
    number_count_prefix.push_back(number_count_prefix.back() + c);
  }

  vector<vector<i64>> dp1(MAX_POWER+1, vector<i64>(10));
  vector<vector<i64>> dp2(MAX_POWER+1, vector<i64>(10));
  for (int d = 1; d <= 9; ++d) {
    dp1[1][d] = 1;
    dp2[1][d] = 1;
  }

  power = 10;
  for (int p = 2; p <= MAX_POWER; ++p, power *= 10) {
    for (int d = 1; d <= 9; ++d) {
      dp1[p][d] = 9 * dp2[p-1][d] + power;
      dp2[p][d] = dp2[p-1][d] + dp1[p][d];
    }
  }
  for (int p = 1; p <= MAX_POWER; ++p) {
    i64 total = 0;
    for (int d = 1; d <= 9; ++d) {
      i64 total_count = dp2[p][d];
      total += total_count * d;
    }
    digit_total_prefix.push_back(total);
    digit_total.push_back(total - digit_total.back());
  }

  // for (i64 c : number_count_prefix) {
  //   cout<< c << endl;
  // }
  // for (i64 c : digit_total) {
  //   cout<< c << endl;
  // }
  // for (i64 c : digit_total_prefix) {
  //   cout<< c << endl;
  // }

  // i64 total = 0, len = 0;
  // for (int i = 1; i <= 99999; ++i) {
  //   string s = to_string(i);
  //   len += s.length();
  //   for (char ch : s) {
  //     total += ch - '0';
  //   }
  // }
  // cout << total << "," <<len << endl;
}

void solve() {
  i64 n = 0;
  cin >> n;

  auto it = upper_bound(number_count_prefix.begin(), number_count_prefix.end(), n);
  --it;
  int prefix_idx = it - number_count_prefix.begin();
  i64 ans = digit_total_prefix[prefix_idx];

  i64 missing_count = n - number_count_prefix[prefix_idx];
  // cout << "missing_count=" << missing_count << endl;
  i64 power = 1;
  for (int i = 0; i < prefix_idx; ++i) {
    power *= 10;
  }
  // cout << "power=" << power << endl;
  i64 digit_length = prefix_idx + 1;
  i64 last_num = power + missing_count / digit_length;
  // cout << "last_number=" << last_num << endl;
  // cout << power << "~" << last_num << endl;

  if (last_num > power) {
    // count power ~ last_digit-1
    i64 middle = 0;
    string last = to_string(last_num-1);
    // cout << "last=" << last << endl;
    i64 p = 1, suffix = 0;
    for (int i = last.length()-1, d = 0; i >= 0; --i, ++d, p *= 10) {
      i64 c = last[i] - '0';
      if (i == 0) {
        middle += max(last[i] - '1', 0) * digit_total_prefix[d];
      } else {
        middle += (last[i] - '0') * digit_total_prefix[d];
      }
      middle += (c - 1) * c / 2 * p;
      middle += c * (suffix + 1);
      suffix += c * p;
      // cout << "middle=" << middle << ", suffix=" << suffix << endl;
    }
    // cout << "middle=" << middle << endl;
    ans += middle;
  }

  i64 last_num_count = missing_count - missing_count / digit_length * digit_length;
  i64 last_count = 0;
  string last = to_string(last_num);
  for (int i = 0; i < last_num_count; ++i) {
    last_count += last[i] - '0';
  }
  // cout << "last_count=" << last_count << endl;
  ans += last_count;
  cout << ans << endl;

  // i64 ans2 = 0;
  // string s2;
  // int k = 1;
  // while ((int)s2.length() < n) {
  //   s2 += to_string(k);
  //   k++;
  // }
  // cout << s2 << endl;
  // for (int i = 0; i < n; ++i) {
  //   ans2 += s2[i]- '0';
  // }
  // cout << "ans2=" << ans2 << endl;
  // cout <<"ans=" << ans << endl;

  // i64 ans3 = 0;
  // for (int i = number_count_prefix[prefix_idx]; i < n; ++i) {
  //   ans3 += s2[i]- '0';
  // }
  // cout << "ans3=" << ans3 << endl;
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
