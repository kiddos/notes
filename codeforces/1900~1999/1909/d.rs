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

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        return a;
    }
    return gcd(b, a % b);
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<i64>();
    let n = inputs[0] as usize;
    let k = inputs[1];
    let a = read_vec::<i64>();

    let mut b = vec![0; n];
    let mut pos = 0;
    let mut neg = 0;
    let mut sum = 0;
    for i in 0..n {
        b[i] = a[i] - k;
        if b[i] > 0 {
            pos += 1;
        } else if b[i] < 0 {
            neg += 1;
        }
        sum += b[i];
    }

    if pos == n {
        let mut g = b[0];
        for i in 1..n {
            g = gcd(g, b[i]);
        }
        let ans = sum / g - n as i64;
        writeln!(writer, "{}", ans).ok();
    } else if neg == n {
        let mut g = b[0].abs();
        for i in 1..n {
            g = gcd(g, b[i].abs());
        }
        let ans = (sum / g).abs() - n as i64;
        writeln!(writer, "{}", ans).ok();
    } else if neg == 0 && pos == 0 {
        writeln!(writer, "0").ok();
    } else {
        writeln!(writer, "-1").ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
