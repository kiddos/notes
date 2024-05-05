use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

const MAX_BIT: i32 = 31;

fn msb(x: i32) -> i32 {
    let mut msb = 0;
    for b in (0..=MAX_BIT).rev() {
        if (x & (1<< b)) > 0 {
            msb = b;
            break;
        }
    }
    msb
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let mut a = read_vec::<i32>();
    a.insert(0, 0);

    let mut dp1: Vec<Vec<Vec<i64>>> = vec![vec![vec![0; n+2]; MAX_BIT as usize + 1]; 2];
    let mut dp2: Vec<Vec<Vec<i64>>> = vec![vec![vec![0; n+2]; MAX_BIT as usize + 1]; 2];
    for b in 0..=(MAX_BIT as usize) {
        for i in 1..=n {
            if (a[i] & (1 << b)) > 0 {
                dp1[1][b][i] = dp1[0][b][i-1] + 1;
                dp1[0][b][i] = dp1[1][b][i-1];
            } else {
                dp1[0][b][i] = dp1[0][b][i-1] + 1;
                dp1[1][b][i] = dp1[1][b][i-1];
            }
        }
        for i in (1..=n).rev() {
            if (a[i] & (1 << b)) > 0 {
                dp2[1][b][i] = dp2[0][b][i+1] + 1;
                dp2[0][b][i] = dp2[1][b][i+1];
            } else {
                dp2[0][b][i] = dp2[0][b][i+1] + 1;
                dp2[1][b][i] = dp2[1][b][i+1];
            }
        }
    }

    let mut ans: i64 = 0;
    for i in 1..=n {
        let m = msb(a[i]) as usize;
        ans += dp1[1][m][i-1] * (1 + dp2[0][m][i+1]);
        ans += (1 + dp1[0][m][i-1]) * dp2[1][m][i+1];
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
