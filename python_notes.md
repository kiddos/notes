Tensorflow `get_variable`
=========================

* use get variable instead of low level `tf.Variable`

  ```python
  var = tf.get_variable(name='weight%d' % 0, shape=[100, 100], dtype=tf.float32)
  ```

  2017-1-3

Tensorflow Sample Softmax
=========================

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

  2017-1-3

Flask Framework
===============

* install flask

  ```shell
  sudo pip install -U flask
  ```

* flask basic usage

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

* deploy flask app

  ```shell
  export FLASK_APP=app.py
  export FLASK_DEBUG=1
  flask run
  ```

  2017-1-5

Web socket
==========

* install SimpleWebSocketServer for python

  ```shell
  sudo pip install git+https://github.com/dpallot/simple-websocket-server.git
  ```
* Server usage

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

* Web client

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

  2017-1-6

Tensorflow seq2seq library
==========================

* embedding attention

  ```python
  tf.nn.seq2seq.embedding_attention_seq2seq(
      encoder_inputs, decoder_inputs, cell,
      num_encoder_symbols=vocab_size,
      num_decoder_symbols=vocab_size,
      embedding_size=hidden_size, output_projection=output_softmax,
      feed_previous=false, dtype=tf.float32)
  ```

* bucketing

  ```python
  self.outputs, self.losses = tf.nn.seq2seq.model_with_buckets(
      encoder_inputs, decoder_inputs, target,
      target_weights, buckets,
      lambda x, y: seq2seq_forward(x, y),
      softmax_loss_function=sample_loss)
  ```

  2017-1-7

OpenAI gym
==========

* install

  ```shell
  git clone https://github.com/openai/gym.git
  sudo pip install -e .
  sudo pip install -e '.[atari]'
  sudo pip install -e '.[board_game]'
  ```

* play

  ```python
  import gym
  env = gym.make('SpaceInvaders-v0')
  env.reset()

  for i in range(1000):
      env.render()
  ```

* deploy

  for some reasone, I need sudo for running the code to install docker images.

  ```shell
  sudo python test_universe.py
  ```

  2017-1-9

OpenAI universe
===============

* install

  ```shell
  git clone https://github.com/openai/universe.git
  cd universe
  pip install -e .
  ```

* play

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

  2017-1-10

FTP API
=======

* import

  ```python
  from ftplib import FTP
  ```

* download file

  ```python
  ftp = FTP('address')
  ftp.login(user=username, passwd=password)
  ftp.cwd(dir)

  filenames = ftp.nlst('./')
  for filename in filenames:
      with open(file, 'w') as f:
          ftp.retrbinary('RETR ' + filename, f.write)
  ```

  2017-1-13

NumPy Normal Sampling
=====================

* generate normal distribution data

  ```python
  sample = sigma * np.random.randn(dim1, dim2) + mu
  ```

  2017-1-14

Sqlite API
==========

  ```python
  db = sqlite3.connect(DB_NAME)
  cur = db.cursor()
  entries = cur.execute("""SELECT * FROM %s""" % (TABLE_NAME))
  data = entries.fetchall()
  ```

  2017-1-15

Flask https context
===================

  ```python
  from flask import Flask
  from flask_sslify import SSLify

  app = Flask(__name__)
  ssl = SSLify(app)

  app.run(host='0.0.0.0', port=5000, ssl_context=('app.crt', 'app.key'))
  ```

  2017-1-17

Flask socketio
==============

* server

  ```python
  from flask import Flask
  from flask_socketio import SocketIO

  app = Flask(__name__)
  socketio = SocketIO(app)

  socketio.run(app, host='0.0.0.0', port=5000, debug=True)
  ```

* javascript client

  ```javascript
  // cdn
  <script type="text/javascript"
    src="//cdnjs.cloudflare.com/ajax/libs/socket.io/1.3.6/socket.io.min.js">
  </script>
  ```

  2017-1-17

JSON parsing
============

* parsing

  ```python
  import json

  json.dumps(['foo', {'bar': ('baz', None, 1.0, 2)}])
  json.loads('["foo", {"bar":["baz", null, 1.0, 2]}]')
  ```

  2017-1-23

Flask Streaming
===============

* streaming

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

  2017-1-24

Deprecate optparse module in python 3.4
=======================================

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

  2017-1-25

Setuptools
==========

* basic usage

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

  2017-1-28

Flask Socket SSL
================

* start the app with ssl

  ```python
  socketio.run(app, host='0.0.0.0', debug=True,
      certfile='app.crt', keyfile='app.key')
  ```

  2017-1-31

Tensorflow Training out of memory
=================================

* some gpu might not have enough memory for training large model, might consider changing to cpu

  ```python
  with tf.device('/cpu:0'):
    model = Model()
  ```

  2017-1-31

Extract TAR
===========

  ```python
  with tarfile.open(file, 'r:gz') as tf:
    file_list = tf.getmembers()
    if not os.path.isfile(os.path.join(output_dir, file_list[0].name)):
      tf.extractall(output_dir)
  ```

  2017-2-1

SASS module
===========

* installation

  ```shell
  pip install sass
  ```

* sample

  ```python
  import sass
  sass.compile_string("div { a { color: black}}")
  ```

  2017-2-2

Stylus Module
=============

* installation

  ```shell
  pip install stylus
  ```

* sample

  ```
  from stylus import Stylus
  compiler = Stylus()

  compiler.compile(file_content)
  ```

  2017-2-2

Scrapy
======

* web crawling

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

  2017-2-17

PiCamera
========

* import

  ```python
  from picamera.array import PiRGBArray
  from picamera import PiCamera
  ```

* to capture numpy image

  ```python
  camera = PiCamera()
  raw_capture = PiRGBArray(camera, size=size)
  camera.capture(raw_capture, format='bgr')
  image = raw_capture.array
  ```

  2017-3-2

Flask Streaming
===============

* http 206 response

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

  2017-3-5

Django project
==============

* create project

  ```shell
  django-admin startproject django-site
  ```

* run development server

  ```shell
  ./managed.py runserver 8080
  ```

* create app

  ```shell
  ./managed.py startapp appname
  ```

  2017-3-7

Socket blocking, timeout, no delay
==================================

* to block until data

  ```python
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.bind(('0.0.0.0', 8787))
  sock.setblocking(1)
  ```

* timeout

  ```
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.settimeout(3)
  ```

* no delay

  ```
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
  ```

  2017-3-11

TkInter Frame extension
==================

* wrapper class

  ```python
  class Frame(tk.Frame):
    def __init__(self, master):
      tk.Frame.__init__(self, master)
      self.master = master
      self.pack()
  ```

  2017-3-12

Tkinter Display Numpy Image
===========================

* imports

  ```python
  from PIL import Image, ImageTk
  ```

* display

  ```python
  image = Image.fromarray(images)
  imagetk = ImageTk.PhotoImage(image)

  image_canvas = tk.Canvas(master, width=320, height=240)
  image_canvas.create_image(160, 120), image=imagetk)
  image_canvas.pack(side=tk.TOP, expand=True, fill=tk.BOTH)
  ```

  2017-3-12

Build in Unit Test Framework
============================

* import

  ```python
  import unittest
  ```

* template class

  ```python
  class TestBasic(unittest.TestCase):
    def test_case1(self):
      pass

    def test_case2(self):
      pass
  ```

  2017-3-13

Django MVC
==========

* model

  ```shell
  from __future__ import unicode_literals

  import datetime
  from django.db import models
  from django.utils import timezone
  from django.utils.encoding import python_2_unicode_compatible

  @python_2_unicode_compatible
  class Question(models.Model):
    question_text = models.CharField(max_length=200)
    pub_date = models.DateField('date published')

    def __str__(self):
      return self.question_text

    def was_published_recently(self):
      now = timezone.now()
      return now - datetime.timedelta(days=1) <= self.pub_date <= now

  @python_2_unicode_compatible
  class Choise(models.Model):
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    choice_text = models.CharField(max_length=200)
    votes = models.IntegerField(default=0)

    def __str__(self):
      return self.choice_text
  ```

* view

  2 ways to send views

    - using function
    - generic class

  ```python
  from django.shortcuts import render, get_object_or_404
  from django.http import HttpResponse, Http404, HttpResponseRedirect
  from django.template import loader
  from django.views import generic
  from django.urls import reverse
  from models import Question

  class IndexView(generic.ListView):
    template_name = 'polls/index.html'
    context_object_name = 'latest_question_list'

    def get_queryset(self):
      return Question.objects.filter(
          pub_date__lte=timezone.now()).order_by('-pub_date')[:5]

  class DetailView(generic.DetailView):
    model = Question
    template_name = 'polls/detail.html'

  class ResultView(generic.DetailView):
    model = Question
    template_name = 'polls/results.html'

  def vote(request, question_id):
    question = get_object_or_404(Question, pk=question_id)
    try:
      selected_choice = question.choise_set.get(pk=request.POST['choice'])
    except Exception as e:
      print(e)
      return render(request, 'polls/detail.html', {
        'question': question,
        'error_message': 'You didn\'t select a choice'
      })
    else:
      selected_choice.votes += 1
      selected_choice.save()
      return HttpResponseRedirect(reverse('polls:result', args=(question.id,)))
  ```

* controller

  routing

  ```
  from django.conf.urls import url

  import views

  app_name = 'polls'
  urlpatterns = [
    url(r'^$', views.IndexView.as_view(), name='index'),
    url(r'^(?P<pk>[0-9]+)/$', views.DetailView.as_view(), name='detail'),
    url(r'^(?P<pk>[0-9]+)/results/$', views.ResultView.as_view(), name='result'),
    url(r'^(?P<question_id>[0-9]+)/vote/$', views.vote, name='vote'),
  ]
  ```

* unit test

  ```python
  from django.test import TestCase
  from django.utils import timezone
  import datetime

  from models import Question

  class QuestionMethodTest(TestCase):
    def test_was_published_recently_with_future_question(self):
      time = timezone.now() + datetime.timedelta(days=30)
      future_question = Question(pub_date=time)
      self.assertIs(future_question.was_published_recently(), False)

    def test_was_published_recently_with_old_question(self):
      time = timezone.now() - datetime.timedelta(days=30)
      old_question = Question(pub_date=time)
      self.assertIs(old_question.was_published_recently(), False)

    def test_was_publiched_recently_with_recent_question(self):
      time = timezone.now() - datetime.timedelta(hours=1)
      recent_question = Question(pub_date=time)
      self.assertIs(recent_question.was_published_recently(), True)
  ```

  2017-3-14

TFLearn
=======

* write higher level code, with foundation of tensorflow

  ```python
  tflearn.init_graph(num_cores=4, gpu_memory_fraction=0.5)

  net = tflearn.input_data(shape=[None, 784])
  net = tflearn.fully_connected(net, 64, activation='relu')
  net = tflearn.fully_connected(net, 10, activation='softmax')
  net = tflearn.regression(net, optimizer='adam',
      loss='categorical_crossentropy')
  model = tflearn.DNN(net)
  model.fit(data, label)
  prediction = model.predict(data)
  ```

  2017-3-15

Theano Framework
================

* import

  ```python
  import theano.tensor as T
  from theano import function, shared
  ```

* inputs

  ```python
  x = T.fvector('x')
  y = T.dmaxtrix('y')
  ```

* variables

  ```python
  w = shared(np.random.randn(1), name='w')
  b = shared(0.0, name='b')
  ```

* outputs

  ```python
  prediction = x * w + b
  cost = (prediction - y) ** 2
  ```

* feed

  ```python
  w_grad, b_grad = T.grad(cost, [w, b])
  update = function(inputs=[x, y], outputs=[cost, prediction],
      updates=[(w, w - 0.01 * w_grad), (b, b - 0.01, b_grad)])

  c, p = update(data, label)
  ```

  2017-3-16

Keras Framework
===============

* easier to create model

  ```python
  model = Sequential()
  model.add(Dense(256, input_dim=784,
    kernel_initializer=keras.initializers.RandomNormal(stddev=0.02)))
  model.add(Activation('relu'))
  model.add(Dense(10))
  model.add(Activation('softmax'))

  model.compile(loss='categorical_crossentropy',
      optimizer=keras.optimizers.SGD(lr=1e-4, momentum=0.9),
      metrics=['accuracy'])
  model.fit(data, label, epochs=100, batch_size=256)
  ```

  2017-3-17

Loggings
========

* import

  ```python
  import logging
  import coloredlogs
  ```

* color

  ```python
  mod_logger = logging.getLogger('module')
  coloredlogs.install(level='DEBUG')
  ```

* use

  ```python
  mod_logger.debug('hello world')
  mod_logger.info('hello world')
  mod_logger.warn('hello world')
  mod_logger.error('hello world')
  mod_logger.critical('hello world')
  ```

  2017-3-21

MQTT python API
===============

* import

  ```python
  import paho.mqtt.client as mq
  import time
  ```

* usage:

  ```python
  TOPIC = 'my/topic'

  def on_connect(client, userdata, flags, rc):
    print('connect with result code: %s' % (str(rc)))
    client.subscribe(TOPIC)

  def on_message(client, userdata, msg):
    print('topic: %s, msg: %s, quality: %s' %
        (msg.topic, msg.payload, msg.qos))

  client = mq.Client()
  client.on_connect = on_connect
  client.on_message = on_message

  client.connect('broker ip', 1883, 60)

  index = 0

  while True:
    try:
      client.publish(TOPIC, 'I am such a nerd' + str(index), qos=2)
      index += 1
      client.loop()
      time.sleep(1.0)
    except:
      break
  ```

  2017-3-22

ROS Subscribe
=============

* create a subscribe node:

  ```python
  #!/usr/bin/env python
  # -*- coding: utf-8 -*-

  import rospy
  from std_msgs.msg import String

  def listen_callback(data):
    rospy.loginfo(rospy.get_caller_id() + ' I heard %s' % (data.data))

  def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('chatter', String, listen_callback)
    rospy.spin()

  if __name__ == '__main__':
    listener()
  ```

  2017-3-27

ROS Publish
===========

* create a publish node:

  ```python
  #!/usr/bin/env python
  # -*- coding: utf-8 -*-

  import rospy
  from std_msgs.msg import String

  def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
      hello_str = 'hello world!!, %s' % rospy.get_time()
      rospy.loginfo(hello_str)
      pub.publish(hello_str)
      rate.sleep()

  if __name__ == '__main__':
    try:
      talker()
    except rospy.ROSInterruptException:
      pass
  ```

  2017-3-28

ROS server
==========

* create a server node:

  ```python
  #!/usr/bin/env python
  # -*- coding: utf-8 -*-

  from beginner_tutorial.srv import *
  import rospy

  def add_two_ints(req):
    print('returning [%s + %s = %s]' % (req.a, req.b, req.a + req.b))
    return AddTwoIntsResponse(req.a + req.b)

  def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    server = rospy.Service('add_two_ints', AddTwoInts, add_two_ints)
    print('Ready to add two ints...')
    rospy.spin()

  if __name__ == '__main__':
    add_two_ints_server()
  ```

  2017-3-29

ROS client
==========

* create a client node:

  ```python
  #!/usr/bin/env python
  # -*- coding: utf-8 -*-

  import sys
  import rospy
  from beginner_tutorial.srv import *

  def add_two_ints_client(x, y):
    rospy.wait_for_service('add_two_ints')
    try:
      add_two_ints = rospy.ServiceProxy('add_two_ints', AddTwoInts)
      res = add_two_ints(x, y)
      return res.sum
    except rospy.ServiceException as e:
      print('Service Call Failed: %s' % (e))

  def main():
    if len(sys.argv) == 3:
      a = int(sys.argv[1])
      b = int(sys.argv[2])
      print('request: a=%d, b=%d' % (a, b))
      print('%d + %d = %d' % (a, b, add_two_ints_client(a, b)))
    else:
      print('usage: %s <a> <b>' % (sys.argv[0]))

  if __name__ == '__main__':
    main()
  ```

  2017-3-30

Python Logger
=============

* for logging usages

  - import

    ```python
    import logging
    ```

  - usage

    ```python
      logging.basicConfig()
      logger = logging.getLogger(model_name)
      logger.setLevel(logging.INFO)
      logger.info('setting up...')
    ```

  2017-4-9

NamedTuple
==========

* create a named tuple

  - import

    ```python
    from collections import namedtuple
    ```

  - usages

    ```
    l = []
    tup = namedtuple('t', ['state', 'action', 'reward',
        'next_state', 'done'])
    l.append(tup(state, action, reward, next_state, done))
    ```

  2017-4-10


Gym Montor
==========

* gym monitor for recording episodes

  ```python
  env = gym.make('CartPole-v1')
  if not os.path.isdir('method'):
    env = wrappers.Monitor(env, 'method')
  ```

  2017-4-11

Tensorflow Histogram and Image
==============================

* summary for image

  ```
  tf.summary.image(name='image_name',
      tensor=image, max_outputs=3)
  ```

* summary for histogram

  ```
  tf.summary.histogram(name='histogram_name', values=hist)
  ```

  2017-4-12

Tensorflow global step
======================

* get global step

  ```python
  global_step = tf.Variable(0, name="global_step", trainable=False)
  tf.contrib.framework.get_global_step()
  ```

  2017-4-13

Tensorflow Reset Graph
======================

* reset tensorflow graph

  ```python
  tf.reset_default_graph()
  ```

  2017-4-14

Tensorflow Trainable Variable
=============================

* list all trainable variable

  ```python
  var_index = len(tf.trainable_variables())
  vars = tf.trainable_variables()[var_index:]
  ```

  2017-4-14

Numpy Stack
===========

* stack is different from concat, where it create a new axis

  ```python
  arrays = [np.random.randn(3, 4) for _ in range(10)]
  np.stack(arrays, axis=0).shape
  ```

  2017-4-15

NumPy Random
============

* random sampling according to probablitiy

  ```python
  a = np.random.choice(np.arange(n), p=prob)
  ```

  2017-4-16

Gym Custom Environment
======================

* to create an custom gym environment

  ```python
  class CustomEnvironment(Env):
    metadata = {'render.modes': ['ansi', 'rgb_array', 'human']}

    def __init__(self, path):
      self.current_dir = os.path.dirname(os.path.realpath(__file__))
      self._reset()
      self.spec = None
      self.view = None
      self.action_space = spaces.Discrete(2)
      self.observation_space = spaces.Box(low=0, high=1, shape=(1, 1))

    def get_state(self):
      return np.zeros(shape=[1, 1])

    def _seed(self, seed=None):
      random.seed(seed)

    def _step(self, action):
      info = {}
      reward = 0
      done = False
      return self.get_state(), reward, done, info

    def _reset(self):
      return self.get_state()

    def _render(self, mode='human', close=False):
      if not close:
      if mode == 'rgb_array':
          return self.get_state()
      elif mode is 'human':
        pass
      else:
        self.logger.info(str(self.get_state()))

    def _close(self):
      pass
  ```

  2017-4-17
