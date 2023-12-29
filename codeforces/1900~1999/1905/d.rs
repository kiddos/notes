use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;
use std::collections::{VecDeque, BTreeSet};

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
    let p = read_vec::<i64>();

    let mut s : BTreeSet<i64> = BTreeSet::new();
    for i in 0..=n {
        s.insert(i as i64);
    }

    let mut d: VecDeque<(i64, i64)> = VecDeque::new();
    let mut total_mex = 0;
    for i in 0..n  {
        s.remove(&p[i]);
        let mex = *s.iter().min().unwrap();
        d.push_back((mex, 1));
        total_mex += mex;
    }

    let mut current = total_mex;
    let mut ans = total_mex;
    for i in 0..n {
        if let Some(m) = d.front_mut() {
            current -= m.0;
            (*m).1 -= 1;
            if (*m).1 == 0 {
                d.pop_front();
            }
        }
        let mut count = 0;
        while !d.is_empty() && d.back().unwrap().0 > p[i] {
            let mex = (*d.back().unwrap()).0;
            let c = (*d.back().unwrap()).1;
            count += c;
            current += p[i] * c;
            current -= mex * c;

            d.pop_back();
        }
        if count > 0 {
            d.push_back((p[i], count));
        }
        current += n as i64;
        d.push_back((n as i64, 1));

        ans = max(ans, current);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
