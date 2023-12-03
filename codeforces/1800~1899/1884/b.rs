use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeSet;

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
    let n = read_int::<usize>();
    let s = read_str();
    let b = s.as_bytes();
    let mut zeros = BTreeSet::new();
    for i in 0..s.len() {
        if b[i] == b'0' {
            zeros.insert(i);
        }
    }

    let mut ans = vec![-1 as i64; n];
    let mut result = 0 as i64;
    let mut j = 0;
    for i in (0..n).rev() {
        if zeros.is_empty() {
            break;
        }
        let largest = *zeros.last().unwrap();
        result += i as i64;
        result -= largest as i64;
        ans[j] = result;
        j += 1;
        zeros.remove(&largest);
    }

    for i in 0..n {
        write!(writer, "{} ", ans[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
