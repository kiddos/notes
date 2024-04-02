use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;
use std::ops::Bound::*;

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

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let _empty = read_str();
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];

    let mut field = Vec::new();
    for _i in 0..n {
        let row = read_str();
        field.push(row.as_bytes().to_vec());
    }

    let mut ans = 0;
    for offset in 0..2 {
        let mut points = Vec::new();
        for r in 0..n {
            for c in ((r % 2)^offset..m).step_by(2) {
                if field[r][c] == b'1' {
                    points.push((r as i32 + c as i32, r as i32 - c as i32));
                }
            }
        }

        points.sort();

        let mut s: BTreeMap<i32,i32> = BTreeMap::new();
        for (_a, b) in points {
            let mut it = s.range_mut((Unbounded, Included(b)));
            if let Some((b2, count)) = it.next_back() {
                *count -= 1;
                if *count == 0 {
                    let to_remove = *b2;
                    s.remove(&to_remove);
                }
            }
            *s.entry(b).or_insert(0) += 1;
        }

        for (_k, v) in s.iter() {
            ans += *v;
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
