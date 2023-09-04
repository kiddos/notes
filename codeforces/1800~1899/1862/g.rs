use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;
use std::ops::Bound::{Unbounded, Excluded};

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

fn get_answer(nums: &BTreeMap<i64, i32>, gaps: &BTreeMap<i64, i32>) -> i64 {
    let mut ans: i64 = *nums.last_key_value().unwrap().0;
    if !gaps.is_empty() {
        ans += *gaps.last_key_value().unwrap().0;
    }
    ans
}

fn dec(map: &mut BTreeMap<i64, i32>, key: i64) {
    map.entry(key).and_modify(|count| *count -= 1);
    if *map.get(&key).unwrap() == 0 {
        map.remove(&key);
    }
}

fn inc(map: &mut BTreeMap<i64, i32>, key: i64) {
    map.entry(key).and_modify(|count| *count += 1).or_insert(1);
}


fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let mut a = read_vec::<i64>();
    let mut nums: BTreeMap<i64, i32> = BTreeMap::new();

    for i in 0..n {
        nums.entry(a[i]).and_modify(|count| *count += 1).or_insert(1);
    }

    let mut gaps: BTreeMap<i64, i32> = BTreeMap::new();
    let unique: Vec<_> = nums.keys().cloned().collect();
    for i in 1..unique.len() {
        let diff = unique[i] - unique[i-1];
        gaps.entry(diff).and_modify(|count| *count += 1).or_insert(1);
    }

    let q = read_int::<i32>();
    for _i in 0..q {
        let inputs = read_vec::<i64>();
        let i = (inputs[0] - 1) as usize;
        let x = inputs[1];
        
        if a[i] == x {
            write!(writer, "{} ", get_answer(&nums, &gaps)).ok();
        } else {
            nums.entry(a[i]).and_modify(|count| *count -= 1);

            if *nums.get(&a[i]).unwrap() == 0 {
                let mut left = nums.range((Unbounded, Excluded(a[i])));
                let mut l = -1;
                if let Some(item) = left.next_back() {
                    l = *item.0;
                    let diff = a[i] - l;
                    dec(&mut gaps, diff);
                }

                let mut r = -1;
                let mut right = nums.range((Excluded(a[i]), Unbounded));
                if let Some(item) = right.next() {
                    r = *item.0;
                    let diff = r - a[i];
                    dec(&mut gaps, diff);
                }

                if r >= 0 && l >= 0 {
                    let diff = r - l;
                    inc(&mut gaps, diff);
                }

                nums.remove(&a[i]);
            }

            a[i] = x;
            nums.entry(a[i]).and_modify(|count| *count += 1).or_insert(1);

            if *nums.get(&a[i]).unwrap() == 1 {
                let mut left = nums.range((Unbounded, Excluded(a[i])));
                let mut l = -1;
                if let Some(item) = left.next_back() {
                    l = *item.0;
                    let diff = a[i] - l;
                    inc(&mut gaps, diff);
                }

                let mut r = -1;
                let mut right = nums.range((Excluded(a[i]), Unbounded));
                if let Some(item) = right.next() {
                    r = *item.0;
                    let diff = r - a[i];
                    inc(&mut gaps, diff);
                }

                if r >= 0 && l >= 0 {
                    let diff = r - l;
                    dec(&mut gaps, diff);
                }
            }

            write!(writer, "{} ", get_answer(&nums, &gaps)).ok();
        }

        // print!("a=");
        // for x in nums.keys() {
        //     print!("{} ", x);
        // }
        // println!();

        // print!("gaps=");
        // for (key, value) in gaps.iter() {
        //     print!("{}:{}   ", key, value);
        // }
        // println!();
    }
    writeln!(writer).ok();
}


fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
