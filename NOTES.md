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

  ```
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

  ```
  Option Explicit
  On Error Resume Next

  MsgBox "hello!!"
  ```

  - copy files using object fso

  ```
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
