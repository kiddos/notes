use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

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
    let mut chars: Vec<char> = s.chars().map(|ch| ch).collect();
    chars.sort();
    chars.dedup();

    let b = s.as_bytes();
    for ch in chars {
        let mut count = vec![0; 26];
        for i in 0..n {
            if b[i] == ch as u8 {
                for k in 0..26 {
                    count[k] = 0;
                }
            } else {
                let c = (b[i] - b'a') as usize;
                count[c] += 1;
                if count[c] >= 2 {
                    writeln!(writer, "NO").ok();
                    return;
                }
            }
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
