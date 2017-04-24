JSON String
===========

  ```javascript
  JSON.stringify({
    data: 'data',
    arr: [1, 2, 3]
  });
  ```
  2017-1-15

AJAX (Asynchronous Javascript and XML)
======================================

* tradiational

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

* jquery

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

  2017-1-16


Draw rect on canvas
===================

  ```
  context.strokeStyle = '#0F0';
  context.rect(x, y, w, h);
  context.stroke();
  ```

  2017-1-19

d3.js
=====

* drawing on svgs

  ```javascript
  var canvas = d3.select('#tag')
    .append('svg')
    .attr('width', 500).attr('height', 500);

  var circle = canvas
    .append('circle')
    .attr('cx', 250).attr('cy', 250)
    .attr('r', 50).attr('fill', 'red');
  ```

  2017-1-21

Memory Leak Problems
====================

* do not use

  ```
  setInterval(function() {
    // function code
  }, 1000);

  // or

  setTimeout(function() {
    // function code
  }, 1000);
  ```

* use

  ```javascript
  var f = function() {
    // function code
  };
  setInterval(f, 1000);

  // or

  setTimeout(f, 100);
  ```

  2017-1-22

Self Calling Function
=====================

  ```javascript
  (function(){
      // some private code that will be executed automatically
  })();
  ```

  2017-1-27

Default Values
==============

  ```javascript
  function doSomething(arg1){
    arg1 = arg1 || 10;
  }
  ```

  2017-1-27

`querySelector`
===============

  ```javascript
  var el = document.querySelector("div.user-panel.main input[name=login]");
  ```

  2017-1-27

Typescript Starter Code
=======================

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

  2017-2-5

ROS Webtool on ROSLIB
=====================

* connect using websocket

  ```javascript
  var ros = new ROSLIB.Ros({
    url: 'ws://192.168.16.157:9090'
  });
  ```

* event callback

  ```javascript
  ros.on('connection', function() {
    console.log('connect to websocket server!!');
  });
  ```

* topic object

  ```javascript
  var initPoseTopic = new ROSLIB.Topic({
    ros: ros,
    name: '/initialpose',
    messageType: 'geometry_msgs/PoseWithCovarianceStamped'
  });
  ```

* subscribe

  ```javascript
  initPoseTopic.subscribe(function(message) {
    console.log(JSON.stringify(message));
  });
  ```

* publish

  ```javascript
  initPoseTopic.publish(pose);
  ```


  2017-4-18

ROS Webtool on ROS2D
====================

* create viewer

  ```javascript
  var navViewer = new ROS2D.Viewer({
    divID: 'map-nav',
    width: $('#map-nav').width(),
    height: $('#map-nav').height()
  });
  ```

* create marker

  ```javascript
  var robotMarker = new ROS2D.NavigationArrow({
    size : 12,
    strokeSize : 1,
    fillColor : createjs.Graphics.getRGB(255, 128, 0, 0.66),
    pulse : true
  });
  navViewer.scene.addChild(robotMarker);
  ```

  2017-4-19

ROS Webtool on NAV2D
====================

* navigation

  ```javascript
  NAV2D.OccupancyGridClientNav({
    ros: ros,
    rootObject: navViewer.scene,
    viewer: navViewer,
    serverName: '/move_base',
    continuous: true,
    withOrientation: true,
    topic: '/map',
  });
  ```

  2017-4-20
