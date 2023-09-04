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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let mut a = read_vec::<i32>();

    a.insert(0, 0);

    if a[1] != (n as i32) {
        writeln!(writer, "NO").ok();
        return;
    }

    let mut b: Vec<i32> = Vec::new();
    for i in (1..=n).rev() {
        while (b.len() as i32) < a[i] {
            b.push(i as i32);
        }
    }
    b.insert(0, 0);
    for i in 1..=n {
        if a[i] != b[i] {
            writeln!(writer, "NO").ok();
            return;
        }
    }

    writeln!(writer, "YES").ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
