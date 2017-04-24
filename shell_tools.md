SSL gen-key
===========

* method 1

  ```shell
  openssl req -x509 -sha256 -nodes -days 10000 -newkey rsa:2048 -keyout app.key -out face.crt
  ```

* method 2

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

  2017-1-17

FFMPEG record screen
====================

  ```shell
  ffmpeg -f x11grab -framerate 25 -r 25 -s 1920x1080 -i :0.0 output.mp4
  ```

  2017-1-18

Allow camera access without https
=================================

  ```shell
  mkdir -p /etc/opt/chrome/policies/managed
  touch /etc/opt/chrome/policies/managed/test_policy.json
  ```

* test_policy.json

  ```
  {
    "VideoCaptureAllowedUrls": ["http://www.example.com/", "http://[*.]example.edu/"]
  }
  ```

* or use cmd to start chrome

  ```
  google-chrome --use-fake-ui-for-media-stream
  ```

  2017-1-20


========

Nginx Web server and Flask
==========================

* installation

  ```shell
  sudo add-apt-repository ppa:nginx/stable
  sudo apt-get update
  sudo apt-get install nginx
  sudo /etc/init.d/nginx start
  ```

* configure

  edit the configuration file and restart

  ```shell
  sudo vim /etc/nginx/sites-enabled/default
  sudo /etc/init.d/nginx restart
  ```

  2017-2-4

gdb ui mode
===========

* command

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

  2017-3-1

Strace
======

* find system trace system call and signals

  ```shell
  strace ./executable
  ```

  2017-3-1

Valgrind
========

* command

  ```shell
  valgrind ./executable
  ```

  2017-3-1

LLDB
====

* neovim plugin

  `https://github.com/critiqjo/lldb.nvim`

  2017-3-1

ROS (Robot Operating System)
============================

* setup source:

  ```shell
  sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
  ```

* setup keys:

  ```shell
  sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
  ```

* install from repository:

  ```shell
  sudo apt-get install ros-kinetic-desktop-full
  ```

* install from source:

  - install bootstrap:

    ```shell
    sudo apt-get install python-rosdep python-rosinstall-generator python-wstool python-rosinstall build-essential
    ```

  - update bootstrap tools:

    ```shell
    sudo pip install -U rosdep rosinstall_generator wstool rosinstall
    ```

  - initialize rosdep

    ```shell
    sudo rosdep init
    rosdep update
    ```

  - create source workspace

    ```shell
    mkdir ros_source/src -p
    cd ros_source
    ```

  - pull repository

    ```shell
    rosinstall_generator desktop_full --rosdistro indigo --deps --wet-only --tar > indigo-desktop-full-wet.rosinstall
    wstool init -j8 src indigo-desktop-full-wet.rosinstall
    ```

  - update the repository

    ```shell
    wstool update -j 4 -t src
    ```

  - resolve dependencies

    ```shell
    rosdep install --from-paths src --ignore-src --rosdistro kinetic -y
    ```

  - build

    ```shell
    sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/indigo
    ```

  - add more packages

    ```shell
    rosinstall_generator turtlebot_navigation turtlebot_rviz_launchers --rosdistro indigo --deps --wet-only --tar > indigo-extra.rosinstall
    wstool merge -t src indigo-extra.rosinstall
    ```

  2017-3-26

Heroku
======

* install python3.6

  ```shell
  sudo add-apt-repository ppa:fkrull/deadsnakes
  sudo apt-get update
  sudo apt-get install python3.6
  ```

* install virtualenv

  ```shell
  sudo pip install virtualenv
  ```

* install heroku cli

  ```shell
  sudo add-apt-repository "deb https://cli-assets.heroku.com/branches/stable/apt ./"
  curl -L https://cli-assets.heroku.com/apt/release.key | sudo apt-key add -
  sudo apt-get update
  sudo apt-get install heroku
  ```

* check installation by typing credentials

  ```shell
  heroku login
  ```

* create an app

  ```
  heroku create app-name
  ```

* `Procfile`

  ```
  web: gunicorn gettingstarted.wsgi --log-file -
  web: python manage.py runserver 0.0.0.0:5000
  ```

* scale the app

  ```
  heroku ps:scale web=1
  ```

* app dependencies in `requirements.txt`

  ```
  Django==1.9.7
  gunicorn==19.6.0
  ```

* run app locally

  ```
  heroku local web
  ```

* push

  ```
  heroku git:remote -a app-name
  git push heroku master
  ```

  2017-4-8
