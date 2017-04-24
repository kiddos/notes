lua programming
===============

* starter code

  ```lua
  print("hello")

  a = 100 + 300
  print(a)

  b = function(c) return c*c end

  print(b(100))

  collectgarbage()
  -- string concat
  a =  'hello ' .. 'world!'
  print(a)

  t = {}
  t.abc = 10

  print(t.abc)
  print(t.def)

  arr = {1, 2, 3, 4, 5, 6}
  print(arr)

  ```

  ```lua
  for k, v in ipairs(t) do
    print(k, v)
  end

  for k, v in ipairs(arr) do
    print(k, v)
  end

  function func(x)
    return function(y)
      return x + y
    end
  end

  add1 = func(1)
  add10 = func(10)

  print(add1(10))
  print(add10(10))

  local x = 1
  while x <= 10 do
    print(x)
    x = x + 1
  end

  for x = 1, 5, 0.5 do
    print(x)
  end

  if 5 == 5 then
    print('5')
  elseif 1 == 1 then
    print('1')
  end

  io.write('enter something: ')
  line = io.read()
  print(line)

  -- open file
  f = io.open('file', 'w')
  f.write('hello world')
  f.close()

  vec = dofile('vec.lua')
  print(vec.norm(1, 1))

  pcall(print, 'hello')

  print(math.sqrt(100))
  ```

  2017-1-11

perl programming beginner
=========================

* some starter code

  ```perl
  use strict;
  use warnings;
  use diagnostics;
  use feature 'say';
  use feature 'switch';

  print "hello world\n";

  my $name = 'Joseph';
  my ($age, $street) = (23, '123 main street');
  my $info = "$name lives on $street\n";
  $info = qq{$name lives on $street\n};
  print $info;

  my $random_stuff = <<"END";
  This is just some
  random stuff
  that does not make any sense
  END
  ```

  ```perl
  say $random_stuff;

  if ($age < 16) {
    say "you are young";
  } elsif ($age < 60) {
    say "you are ok";
  } else {
    say "you are old";
  }

  my $i = 0;
  while ($i < 10) {
    print "$i ";
    $i ++;
  }

  given ($age) {
    when ($age < 16) {
      say "cannot drive";
    }
    when ($age > 17) {
      say "can drive";
    }
  }

  my @stuff = ('Joseph', '123 main street', 23, 6.25);
  for my $s (@stuff) {
    say $s;
  }
  foreach my $s (@stuff) {
    say $s;
  }

  say @stuff[0, 1];
  say scalar @stuff;
  say join(", ", @stuff);

  my %new_stuff = (
    'Stuff1'=> 'weird',
    'Stuff2'=> 'cool',
    'Stuff3'=> 'non sense'
  );
  say %new_stuff;

  sub get_random_max {
    my ($max_num) = @_;
    $max_num ||= 11;
    return int(rand $max_num);
  }

  say get_random_max(100);

  sub sum {
    my ($n1, $n2) = @_;
    return $n1 + $n2;
  }

  say sum(10, 20);

  sub sum_many {
    my $sum = 0;
    foreach my $val (@_) {
      $sum += $val;
    }
    return $sum;
  }

  say sum_many(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  ```

  2017-1-12

Markdown Math Formula
=====================

* markdown math formula

  ```markdown
  $f(x) = x^2 + 2$

  $f'(x) = 2x$

  $x_{t+1} = x_t - \frac{f(x)}{f'(x)}$
  ```

  2017-1-26

VBScript on Windows
===================

* hello world program

  ```shell
  Option Explicit
  On Error Resume Next

  MsgBox "hello!!"
  ```

  - copy files using object fso

  ```shell
  Option Explicit
  ' On Error Resume Next

  Dim fso, folder, folderName, target

  Set fso = CreateObject("Scripting.FileSystemObject")
  Set target = fso.GetFolder("D:\workspace\exercise")
  folderName = "D:\workspace\copy"

  If (Not fso.FolderExists(folderName)) Then
    WScript.Echo "Creating folder" & folder & "..."
    fso.CreateFolder(folder)
  End If

  Dim file
  For Each file in target.Files
    file.Copy "D:\workspace\copy\"
  Next
  ```

  2017-1-30


Sqlite Select Group by
======================

  ```sqlite
  SELECT col FROM table GROUP BY col
  ```

  2017-2-1

