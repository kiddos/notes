use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let s = read_str();
    let n = s.len();
    let bytes = s.as_bytes();

    if n == 1 {
        writeln!(writer, "Bob {}", bytes[0] - b'a' + 1).ok();
    } else if n % 2 == 0 {
        let mut ans: i32 = 0;
        for i in 0..n {
            ans += (bytes[i] - b'a' + 1) as i32;
        }
        writeln!(writer, "Alice {}", ans).ok();
    } else {
        let mut total: i32 = 0;
        for i in 0..n {
            total += (bytes[i] - b'a' + 1) as i32;
        }
        let prefix = total - (bytes[n-1] - b'a' + 1) as i32;
        let suffix = total - (bytes[0] - b'a' + 1) as i32;
        let alice = max(prefix, suffix);
        let bob = total - alice;
        writeln!(writer, "Alice {}", alice - bob).ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
