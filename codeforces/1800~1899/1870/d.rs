use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{min, max};

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

    let n = read_int::<usize>();
    let mut c = read_vec::<i32>();
    let k = read_int::<i32>();

    for i in (0..n-1).rev() {
        c[i] = min(c[i], c[i+1]);
    }

    let mut a = vec![0; n];
    a[0] = k / c[0];
    let mut x = k - k / c[0] * c[0];
    for i in 1..n {
        if c[i] == c[i-1] {
            a[i] = a[i-1];
        } else {
            let add = c[i] - c[i-1];
            a[i] = min(a[i-1], x / add);
            x = max(0, x - add * a[i]);
        }
    }

    for i in 0..n {
        write!(writer, "{} ", a[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
