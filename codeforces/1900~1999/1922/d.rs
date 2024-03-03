use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeSet;
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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut a = read_vec::<i64>();
    let mut d = read_vec::<i64>();
    a.insert(0, 0);
    a.push(0);
    d.insert(0, 0);
    d.push(0);

    let mut q: BTreeSet<usize> = BTreeSet::new();
    let mut alive: BTreeSet<usize> = BTreeSet::new();
    for i in 1..=n {
        q.insert(i);
        alive.insert(i);
    }

    let mut ans = vec![0; n];
    for round in 0..n {
        let mut to_remove = Vec::new();
        let mut q2 = BTreeSet::new();
        for &i in q.iter() {
            if !alive.contains(&i) {
                continue;
            }

            let mut sum = 0;
            if let Some(last_monster) = alive.range((Included(&1), Excluded(&i))).next_back() {
                sum += a[*last_monster];
            }
            if let Some(next_monster) = alive.range((Excluded(&i), Included(&n))).next() {
                sum += a[*next_monster];
            }
            if sum > d[i] {
                to_remove.push(i);
            }
        }

        ans[round] = to_remove.len();
        for i in to_remove.iter() {
            alive.remove(i);
            if let Some(last_monster) = alive.range((Included(&1), Excluded(i))).next_back() {
                q2.insert(*last_monster);
            }
            if let Some(next_monster) = alive.range((Excluded(i), Included(&n))).next() {
                q2.insert(*next_monster);
            }
        }
        q = q2;
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
