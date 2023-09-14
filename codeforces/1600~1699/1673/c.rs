use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn is_palinedrome(x: i32) -> bool {
    let s = x.to_string();
    let s2 = x.to_string().chars().rev().collect::<String>();
    s == s2
}

const MAX_N: i32 = 40000;
const MOD: i64 = 1000000007;

fn main() {
    let t = read_int::<i32>();

    let mut palindromes: Vec<i32> = Vec::new();
    for i in 1..=MAX_N {
        if is_palinedrome(i) {
            palindromes.push(i);
        }
    }

    let m = palindromes.len();
    let mut dp: Vec<Vec<i64>> = vec![vec![0; m+1]; (MAX_N+1) as usize];
    dp[0][0] = 1;
    for n in 0..=(MAX_N as usize) {
        for i in 1..=m {
            dp[n][i] += dp[n][i-1];
            dp[n][i] %= MOD;
            let p = palindromes[i-1];
            if (n as i32) - p >= 0 {
                dp[n][i] += dp[((n as i32) - p) as usize][i];
                dp[n][i] %= MOD;
            }
        }
    }

    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    for _t in 0..t {
        let n = read_int::<usize>();
        writeln!(writer, "{}", dp[n][m]).ok();
    }
}
