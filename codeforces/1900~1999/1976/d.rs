use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;

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
    let s: Vec<char> = s.chars().collect();
    
    let n = s.len();
    let mut b = 0;
    let mut level_count = BTreeMap::new();
    level_count.insert(0, 1);
    let mut ans: i64 = 0;
    for i in 0..n {
        if s[i] == '(' {
            b += 1;
        } else if s[i] == ')' {
            b -= 1;
        }
        if let Some(c) = level_count.get(&b) {
            ans += c;
        }
        level_count.entry(b).and_modify(|c| *c += 1).or_insert(1);

        while !level_count.is_empty() {
            if let Some(&x) = level_count.keys().next() {
                if x < b - x {
                    level_count.remove(&x);
                } else {
                    break;
                }
            }
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
