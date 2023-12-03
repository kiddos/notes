use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<i32>();
    let mut a = read_vec::<i64>();
    a.sort();

    let mut l = 0;
    let mut r = n-1;
    let mut x = 0;
    let mut ans = 0;
    while l < r {
        while l < r && x < a[r as usize] {
            let required = a[r as usize] - x;
            let op1 = min(required, a[l as usize]);
            x += op1;
            ans += op1;
            a[l as usize] -= op1;
            if a[l as usize] == 0 {
                l += 1;
            }
        }

        if x < a[r as usize] {
            break;
        }
        r -= 1;
        x = 0;
        ans += 1;
    }

    if l == r {
        let mut h = a[l as usize];
        if h == 1 {
            ans += 1;
        } else {
            let att = (h - x) / 2;
            ans += att;
            h -= x + att + att;
            ans += 1;
            ans += h;
        }
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
