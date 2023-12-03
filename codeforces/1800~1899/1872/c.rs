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
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn min_divisor(x: i64) -> i64 {
    let s = (x as f64).sqrt() as i64;
    for d in 2..=s {
        if x % d == 0 {
            return d;
        }
    }
    x
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i64>();
    let l = inputs[0];
    let r = inputs[1];
    for i in l..=r {
        let x = min_divisor(i);
        if x != i {
            writeln!(writer, "{} {}", x, i - x).ok();
            return;
        }
    }
    writeln!(writer, "-1").ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
