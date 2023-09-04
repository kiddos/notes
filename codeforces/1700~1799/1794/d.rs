use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

const MAX_VAL: usize = 1e6 as usize;

fn sieve() -> Vec<bool> {
    let mut is_prime: Vec<bool> = vec![true; MAX_VAL+1];
    is_prime[1] = false;
    for i in 2..=MAX_VAL {
        if is_prime[i] {
            for j in (i*2..=MAX_VAL).step_by(i) {
                is_prime[j] = false
            }
        }
    }

    is_prime
}

const MAX_N: usize = 5000 as usize;
const MOD: i64 = 998244353;

fn power(mut x: i64, mut n: i64) -> i64 {
    let mut ans = 1;
    while n > 0 {
        if n % 2 == 1 {
            ans *= x;
            ans %= MOD;
        }

        x = x * x;
        x %= MOD;
        n >>= 1;
    }
    ans
}

fn dp(x: i64, y: i64, primes: &Vec<(i32,i32)>, inv_f: &Vec<i64>, memo: &mut Vec<Vec<i64>>) -> i64 {
    let mut ans = memo[x as usize][y as usize];
    if ans >= 0 {
        return ans;
    }

    if (x as usize) == primes.len() {
        ans = (y == 0) as i64;
        memo[x as usize][y as usize] = ans;
        return ans;
    }

    let x_count = primes[x as usize].1 as usize;
    ans = inv_f[x_count] * dp(x+1, y, &primes, &inv_f, memo) % MOD;
    if y > 0 {
        ans = ans + inv_f[x_count - 1] * dp(x+1, y-1, &primes, &inv_f, memo) % MOD;
        ans %= MOD;
    }

    memo[x as usize][y as usize] = ans;
    ans
}

fn solve() {
    let n = read_int::<usize>();
    let a = read_vec::<i32>();

    let is_prime = sieve();

    // precompute factorial
    let mut f: Vec<i64> = vec![1; MAX_N+1];
    let mut inv_f: Vec<i64> = vec![1; MAX_N+1];
    for i in 2..=MAX_N {
        f[i] = f[i-1] * (i as i64);
        f[i] %= MOD;
    }
    inv_f[MAX_N] = power(f[MAX_N], MOD-2);
    for i in (1..MAX_N).rev() {
        inv_f[i] = inv_f[i+1] * ((i as i64)+1);
        inv_f[i] %= MOD;
    }

    let mut freq: BTreeMap<i32, i32> = BTreeMap::new(); 
    for x in &a {
        match freq.get(x) {
            Some(val) => freq.insert(*x, val+1),
            None => freq.insert(*x, 1),
        };
    }

    let mut primes: Vec<(i32,i32)> = Vec::new();
    for (key, val) in freq.iter() {
        if is_prime[*key as usize] {
            primes.push((*key, *val));
        }
    }

    let mut memo: Vec<Vec<i64>> = vec![vec![-1; n*2+1]; n*2+1];
    let mut ans = dp(0, n as i64, &primes, &inv_f, &mut memo);

    ans *= f[n];
    ans %= MOD;
    for (key, val) in freq.iter() {
        if !is_prime[*key as usize] {
            ans *= inv_f[*val as usize];
            ans %= MOD;
        }
    }


    println!("{}", ans);
}

fn main() {
    solve();
}
