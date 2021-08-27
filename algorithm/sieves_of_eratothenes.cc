#include <bits/stdc++.h>

using namespace std;

vector<int> eratothenes(int n) {
  vector<bool> is_prime(n+1, true);
  for (long i = 2; i*i <= n; ++i) {
    if (is_prime[i]) {
      for (long j = 0; j <= n && i*i+j*i <= n; ++j)  {
        is_prime[i*i+j*i] = false;
      }
    }
  }
  vector<int> ans;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) ans.push_back(i);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int n = 5e5;
  vector<int> primes = eratothenes(n);
  for (int p : primes) {
    cout << p << " ";
  }
  cout << endl;
  cout << "number of primes: " << primes.size() << endl;
  return 0;
}
