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

    let n = read_int::<i32>();
    let mut s1 = BTreeMap::new();
    let mut s2 = BTreeMap::new();
    for _ in 0..n {
        let inputs = read_str().split(" ").map(|x| x.trim().to_string()).collect::<Vec<String>>();
        let l: i32 = inputs[1].trim().parse().unwrap();
        let r: i32 = inputs[2].trim().parse().unwrap();
        if inputs[0] == "+" {
            if s1.contains_key(&l) {
                *s1.get_mut(&l).unwrap() += 1;
            } else {
                s1.insert(l, 1);
            }
            if s2.contains_key(&r) {
                *s2.get_mut(&r).unwrap() += 1;
            } else {
                s2.insert(r, 1);
            }
        } else if inputs[0] == "-" {
            s1.entry(l).and_modify(|c| *c -= 1);
            if *s1.get(&l).unwrap() == 0 {
                s1.remove(&l);
            }
            s2.entry(r).and_modify(|c| *c -= 1);
            if *s2.get(&r).unwrap() == 0 {
                s2.remove(&r);
            }
        }

        if s1.is_empty() {
            writeln!(writer, "NO").ok();
        } else {
            let end = *s1.keys().max().unwrap();
            let start = *s2.keys().min().unwrap();
            if start < end {
                writeln!(writer, "YES").ok();
            } else {
                writeln!(writer, "NO").ok();
            }
        }
    }
}

fn main() {
    solve();
}
