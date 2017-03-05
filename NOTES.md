2017-1-1
========
* c++ template specialization syntax

  ```c++
  template <typename T>
  void func(T t);

  template<> void func<int>(int i) { return 10; }
  template<> void func<double>(double i) { return 3.0; }
  ```

* cmake target

  ```cmake
  if (TARGET target)
  endif ()
  ```

* gmtime function

  ```c++
  time_t raw;
  time(&raw);

  struct* tm timeval = gmtime(raw);
  cout << "hour" << timeval->tm_hour;
  ```

* color string macro

  ```c++
  #define COLOR_STRING(color, s) "\033[" #color ";1m" #s "\033[0m"
  ```


2017-1-2
========

* swig interface

  - swig interface file

  ```swig
  %module module_name

  %{
  #include "module_header.h"
  %}

  %include "module_header.h"
  ```

  - cmake file

  ```cmake
  find_package(SWIG REQUIRED)
  include(${SWIG_USE_FILE})

  find_package(PythonLibs 2.7 REQUIRED)
  include_directories(${PYTHON_INCLUDE_PATH})
  include_directories(${CMAKE_CURRNET_SOURCE_DIR})

  set(CMAKE_SWIG_FLAGS "")
  set_source_file_properties(module_name.i PROPERTIES CPLUSPLUS ON)
  swig_add_module(module_name python module_name.i ${SOURCE_FILES})
  swig_link_libraries(module_name ${PYTHON_LIBRARIES})
  ```


2017-1-3
========

* tensorflow get_variable

  ```python
  var = tf.get_variable(name='weight%d' % 0, shape=[100, 100], dtype=tf.float32)
  ```

* tensorflow dynamic placeholder

  ```python
  tf.placeholder(dtype=tf.float32, shape=[None])
  ```

* tensorflow sample softmax
  - if the output has high dimension, we could choose to use sample softmax

  ```python
  w = tf.get_variable(name='w', shape=[num_classes, dim], dtype=tf.float32)
  b = tf.get_variable(name='b', shape=[num_classes], dtype=tf.float32)
  inputs = tf.placeholder(dtype=tf.float32, shape=[batch_size, dim])
  labels = tf.reshape(labels, [-1, num_true]) # num_true is usually 1
  softmax_sampling = 512
  # if number of class is less than 512
  # doesn't really need sampling
  loss = tf.nn.sampled_softmax_loss(w, b, inputs,
      labels, softmax_sampling, num_classes)
  ```


2017-1-4
========

* tbb

  - another parallel programming library

  ```c++
  const int size = 1024;
  double* inputs = new double[size]{0};
  double* outputs = new double[size];

  tbb::parallel_for(0, size, 1, [=](int i) {
    outputs[i] = random_func(inputs[i]);
  });
  free(inputs);
  free(outputs);
  ```


2017-1-5
========

* flask framework

  - install flask

  ```
  sudo pip install -U flask
  ```

  - flask basic usage

  ```python
  from flask import Flask, render_template, send_from_directory

  app = Flask(__name__)

  @app.route('/')
  def socket_stream_index():
      return render_template('index.html')

  @app.route('/css/<path:path>')
  def serve_css(path):
      return send_from_directory('css', path)

  @app.route('/js/<path:path>')
  def serve_js(path):
      return send_from_directory('js', path)
  ```

  - deploy flask app

  ```
  export FLASK_APP=app.py
  export FLASK_DEBUG=1
  flask run
  ```


2017-1-6
========

* Web socket

  - install SimpleWebSocketServer for python

  ```shell
  sudo pip install git+https://github.com/dpallot/simple-websocket-server.git
  ```

  - Server usage

  ```python
  from SimpleWebSocketServer import SimpleWebSocketServer, WebSocket

  class SimpleEcho(WebSocket):

      def handleMessage(self):
          # echo message back to client
          self.sendMessage(self.data)

      def handleConnected(self):
          print self.address, 'connected'

      def handleClose(self):
          print self.address, 'closed'

  server = SimpleWebSocketServer('', 8000, SimpleEcho)
  server.serveforever()
  ```

  - Web client

  ```javascript
  var sock = new WebSocket('ws://localhost:9000');

  // on open
  sock.onopen = function(e) {
    console.log('socket opened.');
  };

  // on message
  sock.onmessage = function(e) {
    console.log(e.data);
    $('#messages').append('Server said: ' + e.data + '\n');
  };
  ```

  - jquery review

  ```jquery
  $(document).ready(function() {
    // setup
  });

  $('#element').keypress(function(e) {
    console.log(e.which);
  });
  ```


2017-1-7
========

* tensorflow seq2seq library

  - embedding attention

  ```python
  tf.nn.seq2seq.embedding_attention_seq2seq(
      encoder_inputs, decoder_inputs, cell,
      num_encoder_symbols=vocab_size,
      num_decoder_symbols=vocab_size,
      embedding_size=hidden_size, output_projection=output_softmax,
      feed_previous=false, dtype=tf.float32)
  ```

  - bucketing

  ```python
  self.outputs, self.losses = tf.nn.seq2seq.model_with_buckets(
      encoder_inputs, decoder_inputs, target,
      target_weights, buckets,
      lambda x, y: seq2seq_forward(x, y),
      softmax_loss_function=sample_loss)
  ```


2017-1-8
========

* Qt

  - QImage doesn't recreate memory

  ```cpp
  QImage image = QImage(ptr, cols, rows, step, QImage::Format_RGB888);
  // need to make sure ptr still exist when using it
  ```


2017-1-9
=========

* OpenAI gym

  - install

  ```
  git clone https://github.com/openai/gym.git
  sudo pip install -e .
  sudo pip install -e '.[atari]'
  sudo pip install -e '.[board_game]'
  ```

  - play

  ```python
  import gym
  env = gym.make('SpaceInvaders-v0')
  env.reset()

  for i in range(1000):
      env.render()
  ```

  - deploy

  for some reasone, I need sudo for running the code to install docker images.

  ```shell
  sudo python test_universe.py
  ```


2017-1-10
========

* OpenAI universe

  - install

  ```shell
  git clone https://github.com/openai/universe.git
  cd universe
  pip install -e .
  ```

  - play

  ```python
  import gym
  import universe  # register the universe environments

  env = gym.make('flashgames.DuskDrive-v0')
  env.configure(remotes=1)  # automatically creates a local docker container
  observation_n = env.reset()

  while True:
      action_n = [[('KeyEvent', 'ArrowUp', True)] for ob in observation_n]
      observation_n, reward_n, done_n, info = env.step(action_n)
      env.render()
  ```


2017-1-11
=========

* lua programming

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


2017-1-12
=========

* perl programming beginner

  - some starter code

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


2017-1-13
=========

* python ftp api

  ```python
  from ftplib import FTP

  ftp = FTP('address')
  ftp.login(user=username, passwd=password)
  ftp.cwd(dir)

  filenames = ftp.nlst('./')
  for filename in filenames:
      with open(file, 'w') as f:
          ftp.retrbinary('RETR ' + filename, f.write)
  ```

2017-1-14
=========

* numpy normal sampling

  ```python
  sample = sigma * np.random.randn(dim1, dim2) + mu
  ```


2017-1-15
=========

* python sqlite api

  ```python
  db = sqlite3.connect(DB_NAME)
  cur = db.cursor()
  entries = cur.execute("""SELECT * FROM %s""" % (TABLE_NAME))
  data = entries.fetchall()
  ```

* css background strip

  ```css
  background: repeating-linear-gradient(
    60deg,
    #D9D9D9,
    #D9D9D9 10px,
    #D6D6D6 10px,
    #D6D6D6 20px
  );
  ```

* javascript to json string

  ```javascript
  JSON.stringify({
    data: 'data',
    arr: [1, 2, 3]
  });
  ```


2017-1-16
=========

* ajax (Asynchronous Javascript and XML)

  - tradiational

  ```javascript
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      $('#box').text(this.responseText);
    }
  };
  xhttp.open('GET', '/txt/info.txt');
  xhttp.send();
  ```

  - jquery

  ```javascript
  // post
  $.ajax({
    url: '/hello',
    method: 'POST',
    data: {
      user: 'Joseph'
    },
    success: function(result) {
      $('#box').text(result);
    }
  });

  $.ajax({
    url: '/image/lena.png',
    success: function(result) {
      $('#image').src = result;
    }
  });

  $.ajax({
    url: '/time',
    success: function(result) {
      $('#time').text(result);
    },
  });
  ```


2017-1-17
=========

* ssl gen key

  - method 1

  ```shell
  openssl req -x509 -sha256 -nodes -days 10000 -newkey rsa:2048 -keyout app.key -out face.crt
  ```

  - method 2

  ```shell
  # generate key
  openssl genrsa -des3 -out app.key 1024
  openssl req -new -key app.key -out app.csr
  # remove pass
  mv app.key temp.key
  openssl rsa -in temp.key -out app.key
  # generate certificate
  opessl x509 -req -days 365 -in app.csr -signkey app.key -out app.crt
  ```


* flask https context

  ```python
  from flask import Flask
  from flask_sslify import SSLify

  app = Flask(__name__)
  ssl = SSLify(app)

  app.run(host='0.0.0.0', port=5000, ssl_context=('app.crt', 'app.key'))
  ```

* flask socketio

  - python server

  ```python
  from flask import Flask
  from flask_socketio import SocketIO

  app = Flask(__name__)
  socketio = SocketIO(app)

  socketio.run(app, host='0.0.0.0', port=5000, debug=True)
  ```

  - javascript client

  ```javascript
  // cdn
  <script type="text/javascript"
    src="//cdnjs.cloudflare.com/ajax/libs/socket.io/1.3.6/socket.io.min.js">
  </script>
  ```


2017-1-18
=========

* ffmpeg record screen

  ```shell
  ffmpeg -f x11grab -framerate 25 -r 25 -s 1920x1080 -i :0.0 output.mp4
  ```


2017-1-19
=========

* javascript draw rect on canvas

  ```
  context.strokeStyle = '#0F0';
  context.rect(x, y, w, h);
  context.stroke();
  ```


2017-1-20
=========

* allow camera access without https

  ```shell
  mkdir -p /etc/opt/chrome/policies/managed
  touch /etc/opt/chrome/policies/managed/test_policy.json
  ```

  - test_policy.json

  ```
  {
    "VideoCaptureAllowedUrls": ["http://www.example.com/", "http://[*.]example.edu/"]
  }
  ```

  - or use cmd to start chrome

  ```
  google-chrome --use-fake-ui-for-media-stream
  ```


2017-1-21
=========

* d3.js

  - drawing on svgs

  ```javascript
  var canvas = d3.select('#tag')
    .append('svg')
    .attr('width', 500).attr('height', 500);

  var circle = canvas
    .append('circle')
    .attr('cx', 250).attr('cy', 250)
    .attr('r', 50).attr('fill', 'red');
  ```


2017-1-22
=========

* javascript memory leak

  do not use

  ```
  setInterval(function() {
    // function code
  }, 1000);

  // or

  setTimeout(function() {
    // function code
  }, 1000);
  ```

  use

  ```javascript
  var f = function() {
    // function code
  };
  setInterval(f, 1000);

  // or

  setTimeout(f, 100);
  ```


2017-1-23
=========

* python json parsing

  ```python
  import json

  json.dumps(['foo', {'bar': ('baz', None, 1.0, 2)}])
  json.loads('["foo", {"bar":["baz", null, 1.0, 2]}]')
  ```


2017-1-24
=========

* flask streaming

  ```
  from flask import stream_with_context

  @app.route('/largefile.txt')
  def arge_file():
    def serve_large_file():
      with open('largefile.txt', 'rb') as f:
        while True:
          data = f.read(16777216)
          if not data: break
          yield data
  return Response(stream_with_context(serve_large_file()), direct_passthrough=True)
  ```


2017-1-25
=========

* python optparse module is deprecated since 3.2
  we should use argparse for python 3.4

  ```python
  import argparse

  parser = argparse.ArgumentParser(description='Process some integers.')
  parser.add_argument('integers', metavar='N', type=int, nargs='+',
                      help='an integer for the accumulator')
  parser.add_argument('--sum', dest='accumulate', action='store_const',
                      const=sum, default=max,
                      help='sum the integers (default: find the max)')
  args = parser.parse_args()
  print(args.accumulate(args.integers))
  ```


2017-1-26
=========

* markdown math formula

  ```
  $f(x) = x^2 + 2$

  $f'(x) = 2x$

  $x_{t+1} = x_t - \frac{f(x)}{f'(x)}$
  ```


2017-1-27
=========

* javascript

  - self calling function

  ```javascript
  (function(){
      // some private code that will be executed automatically
  })();
  ```

  - default values

  ```
  function doSomething(arg1){
    arg1 = arg1 || 10;
  }
  ```

  - querySelector

  ```
  var el = document.querySelector("div.user-panel.main input[name=login]");
  ```


2017-1-28
=========

* python setuptools

  ```python
  from setuptools import setup, find_packages

  setup(
      name='app-name',
      version='0.1.0',
      long_description='app description',
      packages=find_packages(),
      include_package_data=True,
      zip_safe=False,
      install_requres=['flask']
  )
  ```


2017-1-29
=========

* more accessable web application

  - when user using screen reader hover on the checkbox, they will only hear checkbox

  ```html
  <input type="checkbox" checked>Sign up
  ```

  - add a label around it making it more accessable

  ```html
  <input id="sign-up" type="checkbox" checked>
  <label for="sign-up">
    Sign up
  <label>

  <!-- or -->
  <label>
    <input id="sign-up" type="checkbox" checked> Sign up
  <label>
  ```

  - label button

  ```html
  <button class="menu" aria-label="menu"></button>

  <h2 id="sec1">Section</h2>
  <div role="button" tabindex="0" class="button"
    aria-labelledby="sec1 sec1-shop-now" id="sec1-shop-now">Shop Now</div>
  ```

  - element with ratio

  ```css
  div.container {
    position: relative;
    width: 100%;
    padding-top: 75%;  //  4:3
  }

  div.inner {
    position: absolute;
    top: 0;
    bottom: 0;
    left: 0;
    right: 0;
    width: 100%;
    height: 100%;
  }
  ```


2017-1-30
=========

* vbscript on windows

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


2017-1-31
=========

* flask socket ssl

  ```python
  socketio.run(app, host='0.0.0.0', debug=True,
      certfile='app.crt', keyfile='app.key')
  ```


* tensorflow training out of memory
  - some gpu might not have enough memory for training large model, might consider changing to cpu

  ```python
  with tf.device('/cpu:0'):
    model = Model()
  ```


2017-2-1
========

* python extract tar

  ```python
  with tarfile.open(file, 'r:gz') as tf:
    file_list = tf.getmembers()
    if not os.path.isfile(os.path.join(output_dir, file_list[0].name)):
      tf.extractall(output_dir)
  ```

* sqlite select group by

  ```sqlite
  SELECT col FROM table GROUP BY col
  ```


2017-2-2
========

* python sass

  - installation

  ```shell
  pip install sass
  ```

  - sample

  ```python
  import sass
  sass.compile_string("div { a { color: black}}")
  ```


* python stylus

  - installation

  ```shell
  pip install stylus
  ```

  - sample

  ```
  from stylus import Stylus
  compiler = Stylus()

  compiler.compile(file_content)
  ```


2017-2-3
========

* css flex box for center element

  ```css
  .ele {
    display: flex;
    justify-content: center;
    align-items: center;
  }
  ```

* css no select

  ```css
  .ele {
    user-select: none;
  }
  ```


2017-2-4
========

* nginx web server and flask

  - installation

  ```shell
  sudo add-apt-repository ppa:nginx/stable
  sudo apt-get update
  sudo apt-get install nginx
  sudo /etc/init.d/nginx start
  ```

  - configure

  edit the configuration file and restart

  ```shell
  sudo vim /etc/nginx/sites-enabled/default
  sudo /etc/init.d/nginx restart
  ```


2017-2-5
========

* typescript

  cleaner class for javascript

  ```typescript
  class Student {
    fullName: string;
    constructor(public firstName, public middleName, public lastName) {
      this.fullName = firstName + ' ' + middleName + ' ' + lastName;
    }
  }

  interface Person {
    firstName: string;
    lastName: string;
  }

  function greeter(person: Person) {
    return 'Hello, ' + person.firstName + ' ' + person.lastName;
  }

  var user = { firstName: 'John', lastName: 'Doe' };
  document.body.innerHTML = greeter(user)
  ```

  ```shell
  tsc student.ts
  ```


2017-2-6
========

* c++ template programming basic building block

  - values

  ```cpp
  struct ValueHolder {
    enum { value = 6 };
  }
  ```

  - function

  ```cpp
  template <int A, int B>
  struct Adder {
    enum { result = A + B  };
  }
  ```

  - branching

  ```cpp
  template <typename T1, typename T2>
  struct SameType {
    enum { result = 0 };
  }

  template <typename T>
  struct SameType<T, T> {
    enum { result = 1 };
  }
  ```

  - recursion

  ```cpp
  template <unsigned long N>
  struct Factorial {
    enum { value = N * Factorial<N-1>::value };
  }

  template <>
  struct Factorial<0> {
    enum { value = 1 };
  }
  ```


2017-2-7
========

* c++17 inherit from lambda

  ```cpp
  #include <utility>

  template <typename Op1, typename Op2>
  struct Merged : Op1, Op2 {
    Merged(Op1 op1, Op2 op2) : Op1(op1), Op2(op2) {}

    using Op1::operator();
    using Op2::operator();
  };

  int main(void) {
    auto l1 = []() { return 6; };
    auto l2 = [](int i) { return i * 6; };

    Merged<decltype(l1), decltype(l2)> merged(l1, l2);
    merged();
    merged(10);
    return 0;
  }
  ```


2017-2-8
========

* c++ variadic template

  ```cpp
  #include <utility>
  #include <iostream>

  using std::cout;

  struct A {
    void a() {}
  };

  struct B {
    void b() {}
  };

  template <typename... T>
  struct C : T... {
    void c() {}
  };

  int main(void) {
    C<A, B> c;
    c.a();
    c.b();
    c.c();
    return 0;
  }
  ```


2017-2-9
========

* c++ sizeof... with variadic template

  ```cpp
  template<class... Types>
  struct count {
      static const std::size_t value = sizeof...(Types);
  };
  ```

* c++ lambda capture

  ```
  template<class ...Args>
  void f(Args... args) {
      auto lm = [&, args...] { return g(args...); };
      lm();
  }
  ```


2017-2-10
=========

* c++ stl algorithm function

  ```cpp
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 0);
  std::vector<int> v2;
  std::copy(v.begin(), v.end(), std::back_inserter(v2));
  std::reverse(v2.begin(), v2.end());
  std::for_each(v2.begin(), v2.end(), [v2](int i) {
    return static_cast<int>(i * 1.1);
  });
  ```


2017-2-11
=========

* c++11 Raw String

  ```cpp
  #include <string>
  #include <iostream>

  int main(void) {
    std::string str = "Hello\tWorld\n";
    std::string r_str = R"(Hello\tWorld\n)";
    std::cout << str << r_str;
    return 0;
  }
  ```


2017-2-12
=========

* c++ variadic function basic building block

  ```cpp
  template <typename... Args>
  double sum(double d, Args... args) { return d + sum(args); }
  ```


2017-2-13
=========

* c++ cheap way for operator=

  ```cpp
  Object& operator=(const Object& src) {
    this->~Object();
    new(this) Object(src);
  }
  ```


2017-2-14
=========

* c++ quick include algorithm, iostream, vector

  ```cpp
  #include <bits/stdc++.h>
  ```


2017-2-15
=========

* python scrapy for web crawling

  ```python
  import scrapy

  class BlogSpider(scrapy.Spider):
    name = 'blogspider'
    start_urls = ['https://blog.scrapinghub.com']

    def parse(self, response):
      for title in response.css('h2.entry-title'):
        yield {'title': title.css('a ::text').extract_first()}

      next_page = response.css('div.prev-post > a ::attr(href)').extract_first()
      if next_page:
        yield scrapy.Request(response.urljoin(next_page), callback=self.parse)
  ```


2017-2-16
=========

* google benchmark

  ```cpp
  #include <benchmark/benchmark.h>

  static void BM_memcpy(benchmark::State& state) {
    float* src = new float[state.range(0)];
    float* dst = new float[state.range(0)];
    while (state.KeepRunning()) {
      memcpy(dst, src, sizeof(float) * state.range(0));
    }
    state.SetBytesProcessed(int64_t(state.iterations()) *
                            int64_t(state.range(0)));
    delete[] src;
    delete[] dst;
  }

  BENCHMARK(BM_memcpy)->RangeMultiplier(2)->Range(8, 8<<10);

  template <typename T>
  void BM_Sequential(benchmark::State& state) {
    std::vector<T> v;
    while (state.KeepRunning()) {
      for (int i = 0 ; i < state.range(0) ; ++i) {
        v.push_back(static_cast<T>(i));
      }
    }
    state.SetBytesProcessed(int64_t(state.iterations()) *
                            int64_t(state.range(0)));
  }

  BENCHMARK_TEMPLATE(BM_Sequential, int)->RangeMultiplier(2)->Range(1<<0, 8<<10);

  BENCHMARK_MAIN();
  ```


2017-2-17
=========

* tensorflow r1.0 change a lot of its API

  - cross_entropy need to specify param name

    ```python
    tf.nn.sigmoid_cross_entropy_with_logits(labels=label, logits=self.logits)
    tf.nn.softmax_cross_entropy_with_logits(labels=label, logits=self.logits)
    ```

  - concat is changed to

    ```
    tf.concat([v1, v2], axis)
    ```


2017-2-18
=========

* google test with cmake

  ```cpp
  enable_testing()
  find_package(GTest REQUIRED)
  include_directories(${GTEST_INCLUDE_DIRS})
  set(CMAKE_INCLUDE_CURRENT_DIR on)

  if (TARGET target)
    set(TEST_LIBS ${GTEST_BOTH_LIBRARIES} pthread target)
    add_executable(test_target test_src.cpp)
    target_link_libraries(test_target ${TEST_LIBS})
    add_test(Test1 test_target)
  endif ()
  ```


2017-2-19
=========

* swig tricks

  - when c++ header use `std::string`, need to include this interface

    ```swig
    %include "std_string.i"
    ```

  - rename operator

    ```cpp
    class Complex {
    public:
      Complex();
      Complex(float r, float i);
      Complex operator+(const Complex& complx);
      Complex operator-(const Complex& complx);
      Complex operator*(const Complex& complx);
      std::string out() {
        std::stringstream ss;
        ss << real_ << "+" << imaginary_ << "i";
        return ss.str();
      }

    private:
      float real_, imaginary_;
    };
    ```

    ```swig
    %rename(__add__) Complex::operator+;
    %rename(__sub__) Complex::operator-;
    %rename(__mul__) Complex::operator*;
    ```


2017-2-20
=========

* swig template

  ```
  template <typename DType>
  DType max(DType* a, int n) {
    assert(n > 0);
    DType max_val = a[0];
    for (int i = 1 ; i < n ; ++i) {
      if (a[i] > max_val) {
        max_val = a[i];
      }
    }
    return max_val;
  }

  %template(maxint) max<int>;
  %template(maxdouble) max<double>;
  ```


2017-2-21
=========

* swig numpy.i provide interface to numpy array

  - swig file

  ```swig
  %include "numpy.i"
  %init %{
  import_array()
  %}

  /* input */
  %apply (float* IN_ARRAY1, int DIM1) {(float* a, int n)};
  /* input mutable */
  %apply (float* INPLACE_ARRAY1, int DIM1) {(float* a, int n)};
  /* output */
  %apply (float* ARGOUT_ARRAY1, int DIM1) {(float* l, int n)};
  ```

  - cmake download numpy

  ```cmake
  if (NOT EXISTS ./numpy.i)
    message("Downloading numpy.i from github.com...")
    file(DOWNLOAD
      https://raw.githubusercontent.com/numpy/numpy/master/tools/swig/numpy.i
      ./numpy.i EXPECTED_MD5 7ace9cd48149759e03624dae78cf2216 SHOW_PROGRESS)
  endif ()
  ```


2017-2-22
=========

* c++ stateful lambda

  - mutable lambda: allows body to modify the parameters captured by copy, and to call their non-const member functions

  ```cpp
  #include <iostream>
  #include <utility>

  int main(void) {
    auto fib = [a = 0, b = 1]() mutable {
      a = std::exchange(b, b + a);
      return a;
    };

    for (int i = 0 ; i < 20 ; ++i) {
      std::cout << fib() << " ";
    }
    std::cout << "\n";
    return 0;
  }
  ```


2017-2-23
=========

* c++ cast operator

  - operator int()/float()/double() is more like a cast operator

  ```cpp
  class Rectangle {
   public:
    Rectangle() : width_(0), height_(0), id_(gen_id()) {}
    Rectangle(float w, float h) : width_(w), height_(h), id_(gen_id()) {}
    operator int() {
      return id_;
    }

   private:
    int gen_id() {
      static int id = 0;
      return id++;
    }
    float width_, height_;
    int id_;
  };
  ```


2017-2-24
=========

* c++ variant

  - for c++14, use boost::variant

  ```cpp
  #include <boost/variant.hpp>
  using var = boost::variant<int, float, double>;

  var v = 12, w = 6;
  try {
    std::cout << boost::get<int>(v) << std::endl;
    std::cout << boost::get<double>(w) << std::endl;
  } catch (boost::bad_get&) {}
  ```


2017-2-25
=========

* c++17 if constexpr

  ```cpp
  if constexpr (...)
  ```

  - Unfortunately, my compiler still not support this


* c++ integral constant

  ```cpp
  template <int I>
  using IntConstant_ = std::integral_constant<int, I>;
  template <int I>
  constexpr IntConstant_<I> IntConstant{};

  int main(void) {
    auto ten = IntConstant<10>;
    std::cout << ten << std::endl;

    return 0;
  }
  ```


2017-2-26
=========

* c++14 static if implemented by Vittorio Romeo

  ```cpp
  #ifndef STATIC_IF_H
  #define STATIC_IF_H

  #include <utility>

  #define FWD(...) std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

  template <bool Bool>
  using bool_ = std::integral_constant<bool, Bool>;

  template <bool Bool>
  constexpr bool_<Bool> bool_v {};

  template <typename Predicate>
  auto static_if(Predicate) noexcept;

  namespace sf {

  template <bool PredicateResult>
  struct static_if_impl;

  template <typename Function>
  struct static_if_result;

  template <typename Function>
  auto make_static_if_result(Function&& f) noexcept;

  template <>
  struct static_if_impl<true> {
    template <typename Function>
    auto& else_(Function&&) noexcept {
      return *this;
    }

    template <typename Predicate>
    auto& else_if(Predicate) noexcept {
      return *this;
    }

    template <typename Function>
    auto then(Function&& f) noexcept {
      return make_static_if_result(FWD(f));
    }
  };

  template <>
  struct static_if_impl<false> {
    template <typename Function>
    auto& then(Function&& f) noexcept {
      return *this;
    }

    template <typename Function>
    auto else_(Function&& f) noexcept {
      return make_static_if_result(FWD(f));
    }

    template <typename Predicate>
    auto else_if(Predicate) noexcept {
      return static_if(Predicate{});
    }

    template <typename ...T>
    auto operator()(T&&...) noexcept {}
  };

  template <typename Function>
  struct static_if_result : Function {
    template <typename F>
    static_if_result(F&& f) noexcept : Function(FWD(f)) {}

    template <typename F>
    auto& then(F&& f) noexcept {
      return *this;
    }

    template <typename Predicate>
    auto& else_if(Predicate p) noexcept {
      return *this;
    }

    template <typename F>
    auto& else_(F&&) noexcept {
      return *this;
    }
  };

  template <typename Function>
  auto make_static_if_result(Function&& f) noexcept {
    return static_if_result<Function>{FWD(f)};
  }

  } /* end of sf namespace */

  template <typename Predicate>
  auto static_if(Predicate) noexcept {
    return sf::static_if_impl<Predicate{}>{};
  }

  #endif /* end of include guard: STATIC_IF_H */
  ```


2017-2-27
=========

* emscripten: compile native c++ code into javascript

  - example

    - hello.cc

    ```cpp
    #include <iostream>

    int main(void) {
      std::cout << "hello world!\n";
      return 0;
    }
    ```

    run

    ```shell
    em++ hello.cc
    nodejs a.out.js
    ```


2017-2-28
=========

* emscripten: support sdl 1.2

  ```cpp
  #include <stdio.h>
  #include <SDL/SDL.h>

  #ifdef __EMSCRIPTEN__
  #include <emscripten.h>
  #endif

  extern "C" int main(int argc, char** argv) {
    printf("hello, world!\n");

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);

  #ifdef TEST_SDL_LOCK_OPTS
    EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
  #endif

    if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
    for (int i = 0; i < 256; i++) {
      for (int j = 0; j < 256; j++) {
  #ifdef TEST_SDL_LOCK_OPTS
        // Alpha behaves like in the browser, so write proper opaque pixels.
        int alpha = 255;
  #else
        // To emulate native behavior with blitting to screen, alpha component is ignored. Test that it is so by outputting
        // data (and testing that it does get discarded)
        int alpha = (i+j) % 255;
  #endif
        *((Uint32*)screen->pixels + i * 256 + j) = SDL_MapRGBA(screen->format, i, j, 255-i, alpha);
      }
    }
    if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
    SDL_Flip(screen);

    printf("you should see a smoothly-colored square - no sharp lines but the square borders!\n");
    printf("and here is some text that should be HTML-friendly: amp: |&| double-quote: |\"| quote: |'| less-than, greater-than, html-like tags: |<cheez></cheez>|\nanother line.\n");

    SDL_Quit();

    return 0;
  }
  ```

  run

  ```shell
  em++ hello.cc -o hello.html
  google-chrome hello.html
  ```


2017-3-1
========

* gdb ui mode

  ```shell
  gdb --tui
  ```

  or toggle using `Ctrl-X Ctrl-A`

* python script for gdb

  ```python
  import gdb

  while True:
    print('-' * 40)
    gdb.execute('run')
    e = gdb.parse_and_eval('$_exitcode')
    print('$_exitcode: %s' % e)
    if e != 0:
      break
  ```

* strace: find system trace system call and signals

  ```shell
  strace ./executable
  ```

* valgrind

  ```shell
  valgrind ./executable
  ```

* lldb and neovim plugin

  `https://github.com/critiqjo/lldb.nvim`


2017-3-2
========

* gtest assertion

  ```
  #include <gtest/gtest.h>

  testing::AssertionResult SimpleTest(int a) {
    if (a == 0) {
      return testing::AssertionFailure();
    } else {
      return testing::AssertionSuccess();
    }
  }

  TEST(SimpleTest, SimpleCase) {
    // EXPECT_TRUE(SimpleTest(0));
    EXPECT_FALSE(SimpleTest(0));
    EXPECT_TRUE(SimpleTest(1));
  }
  ```


2017-3-3
========

* Fast Inverse Square root

  ```cpp
  float InverseSqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*) &x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
  }
  ```


2017-3-4
========

* c++ print special unicode

  ```cpp
  #include <iostream>
  #include <string>
  #include <locale>
  #include <codecvt>

  using std::u16string;

  int main(void) {
    u16string s = u"\u2603";
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> cvt;
    std::cout << cvt.to_bytes(s) << "\xE2\x98\x83" << '\n';
    return 0;
  }
  ```


2017-3-5
========

* flask http 206 response

  ```
  range_header = request.headers.get('Range', None)
  if not range_header:
    return send_file(file_path)

  total_size = os.path.getsize(file_path)
  match = re.search('(\d+)-(\d*)', range_header)
  g = match.groups()
  byte1 = 0
  byte2 = None
  if g[0]: byte1 = int(g[0])
  if g[1]: byte2 = int(g[1])

  length = total_size - byte1
  if byte2 is not None:
    length = byte2 - byte1

  data = None
  with open(file_path, 'rb') as f:
    f.seek(byte1)
    data = f.read(length)
  res = Response(data, 206, mimetype='video/mp4', direct_passthrough=True)
  res.headers.add('Content-Range', 'bytes %d-%d/%d' %
      (byte1, byte1 + length - 1, total_size))
  return res
  ```

2017-3-6
========

* guideline support library GSL

  - static check null pointer

    ```cpp
    #include <iostream>
    #include <gsl/gsl>

    int main(void) {
      // gsl::not_null<int*> p = nullptr;  // does not compile
      gsl::not_null<int*> p = new int{3};
      std::cout << *p << '\n';
      return 0;
    }
    ```

  - ownership of pointer

    ```cpp
    #include <iostream>
    #include <gsl/gsl>

    using namespace gsl;

    void del(int* p) {
      delete p;
    }

    void create() {
      owner<int*> p = new int{10};
      int* p2 = new int{30};
      del(p);
      del(p2);
    }

    int main(void) {
      create();
      return 0;
    }
    ```


2017-3-7
========

