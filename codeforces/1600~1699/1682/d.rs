use std::str::FromStr;
use std::fmt::Debug;
use std::io::{stdin, stdout, BufWriter, Write};

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
    let n = read_int::<usize>();
    let s = read_str();
    let raw = s.as_bytes();
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let mut one = 0;
    for i in 0..n {
        if raw[i] == b'1' {
            one += 1;
        }
    }

    if one > 0 && one % 2 == 0 {
        writeln!(writer, "YES").ok();
    } else {
        writeln!(writer, "NO").ok();
        return;
    }

    let mut edges: Vec<(usize,usize)> = Vec::new();
    let mut p = 0;
    for i in 0..n {
        if raw[i] == b'1' {
            p = i;
            break;
        }
    }
    p = (p+n-1) % n;
    for i in 1..n {
        let a = (p+i) % n;
        let b = (p+i+1) % n;
        if raw[b] == b'0' {
            edges.push((a+1, b+1));
        } else {
            edges.push((a+1, p+1));
        }
    }

    for edge in edges {
        writeln!(writer, "{} {}", edge.0, edge.1).ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
