use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;
use std::collections::BTreeMap;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn solve() {
    let n = read_int::<usize>();
    let a = read_vec::<i32>();
    let mut nums: BTreeMap<i32, i32> = BTreeMap::new();
    for i in 0..n {
        match nums.get(&a[i]) {
            None => nums.insert(a[i], 1),
            Some(count) => nums.insert(a[i], count+1),
        };
    }

    let mut first = 0;
    let mut second = 0;
    for (_x, count) in nums.iter() {
        if count > &1 {
            first += 1;
            second += 1;
        } else {
            if first <= second {
                first += 1;
            } else {
                second += 1;
            }
        }
    }

    let ans = min(first, second+1);

    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
