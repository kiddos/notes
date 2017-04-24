Template Specialization
=======================

* different template implementation

  ```cpp
  template <typename T>
  void func(T t);

  template<> void func<int>(int i) { return 10; }
  template<> void func<double>(double i) { return 3.0; }
  ```

  2017-1-1

Function `gmtime`
=================

* get time

  ```cpp
  time_t raw;
  time(&raw);

  struct* tm timeval = gmtime(raw);
  cout << "hour" << timeval->tm_hour;
  ```

  2017-1-1

Color Macro
===========

* color output in terminal

  ```cpp
  #define COLOR_STRING(color, s) "\033[" #color ";1m" #s "\033[0m"
  ```

  2017-1-1

CMake target
============

* check target exists

  ```cmake
  if (TARGET target)
  endif ()
  ```

  2017-1-1

SWIG interface
==============

* swig interface file

  ```swig
  %module module_name

  %{
  #include "module_header.h"
  %}

  %include "module_header.h"
  ```

* cmake file

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

  2017-1-2

libtbb
======

* another parallel programming library

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

  2017-1-4

Qt Image behavior
=================

* QImage doesn't recreate memory

  ```cpp
  QImage image = QImage(ptr, cols, rows, step, QImage::Format_RGB888);
  // need to make sure ptr still exist when using it
  ```

  2017-1-8

Template Programming Basic Building Block
=========================================

* values

  ```cpp
  struct ValueHolder {
    enum { value = 6 };
  }
  ```

* function

  ```cpp
  template <int A, int B>
  struct Adder {
    enum { result = A + B  };
  }
  ```

* branching

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

* recursion

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

  2017-2-6

Inherit from lambda
===================

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

  2017-2-7

Variadic Template
=================

* template with argument list

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

  2017-2-8

Variadic Template `sizeof...`
=============================

* sizeof... with variadic template

  ```cpp
  template<class... Types>
  struct count {
      static const std::size_t value = sizeof...(Types);
  };
  ```

* lambda capture

  ```
  template<class ...Args>
  void f(Args... args) {
      auto lm = [&, args...] { return g(args...); };
      lm();
  }
  ```

  2017-2-9

stl algorithm function
======================

* common ones

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

  2017-2-10


Raw String
==========

* Raw String

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

  2017-2-11

Variadic Function basic bulding block
=====================================

* basic building block

  ```cpp
  template <typename... Args>
  double sum(double d, Args... args) { return d + sum(args); }
  ```

  2017-2-12

Cheap way for `operator=`
=========================

* c++ cheap way for operator=

  ```cpp
  Object& operator=(const Object& src) {
    this->~Object();
    new(this) Object(src);
  }
  ```

  2017-2-13

Quick include
=============

* quick include algorithm, iostream, vector

  ```cpp
  #include <bits/stdc++.h>
  ```

  2017-2-14

Google Benchmark
================

* basic usage

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

  2017-2-16

Google Test with CMake
======================

* basic template

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

  2017-2-18

Swig Tricks
===========

* when c++ header use `std::string`, need to include this interface

  ```swig
  %include "std_string.i"
  ```

* rename operator

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

  2017-2-19

Swig Template
=============

* basic usage

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

  2017-2-20

NumPy.i
=======

* swig file

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

* cmake download numpy

  ```cmake
  if (NOT EXISTS ./numpy.i)
    message("Downloading numpy.i from github.com...")
    file(DOWNLOAD
      https://raw.githubusercontent.com/numpy/numpy/master/tools/swig/numpy.i
      ./numpy.i EXPECTED_MD5 7ace9cd48149759e03624dae78cf2216 SHOW_PROGRESS)
  endif ()
  ```

  2017-2-21

Stateful Lambda
===============

* mutable lambda: allows body to modify the parameters captured by copy, and to call their non-const member functions

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

  2017-2-22

Cast Operator
=============

* operator int()/float()/double() is more like a cast operator

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

  2017-2-23

Variant
=======

* for c++14, use boost::variant

  ```cpp
  #include <boost/variant.hpp>
  using var = boost::variant<int, float, double>;

  var v = 12, w = 6;
  try {
    std::cout << boost::get<int>(v) << std::endl;
    std::cout << boost::get<double>(w) << std::endl;
  } catch (boost::bad_get&) {}
  ```

  2017-2-24

c++17 if constexpr
==================

  - Unfortunately, my compiler still not support this

  ```cpp
  if constexpr (...)
  ```

  2017-2-25

Integral Constant
=================

* basic usage

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

  2017-2-25

Static if implementation
========================

* static if implemented by Vittorio Romeo

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

  2017-2-26

Emscripten: Compile native c++ code into javascript
===================================================

* still writing cpp code, but compile it differently

  ```cpp
  #include <iostream>

  int main(void) {
    std::cout << "hello world!\n";
    return 0;
  }
  ```

* run

  ```shell
  em++ hello.cc
  nodejs a.out.js
  ```

  2017-2-27

Emscripten: support sdl 1.2
===========================

* use SDL 1.2

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

* run

  ```shell
  em++ hello.cc -o hello.html
  google-chrome hello.html
  ```

  2017-2-28

Arduino PulseIn
===============

* wait for certain port to be at HIGH/LOW and return time

  ```cpp
  range_ = pulseIn(port_, HIGH, timeout);
  ```

  2017-2-28

Volitile
========

* prevent optimization for IoT development

  ```cpp
  volitile char mem[64];
  ```

  2017-2-28

GTest Assertion
===============

* basic usage

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

  2017-3-2

Fast Inverse Square Root
========================

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

  2017-3-3

Unicode
=======

* print special unicode

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

  2017-3-4

Guideline Support Library
=========================

* static check null pointer

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

* ownership of pointer

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

  2017-3-6

Pragma Macro
============

* create pragma macro

  ```cpp
  #define OPENMP() _Pragma("omp parallel for")
  ```

  2017-3-8

BLAS library
============

* use blas library for faster linear algebra performance

  ```cpp
  int m = 1024;
  int n = 1024;
  int k = 1024 * 4;
  float* a = new float[m * k]{0};
  float* b = new float[k * n]{0};
  float* c = new float[m * n]{0};
  cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0f, a, m, b,
              k, 1.0f, c, m);
  ```

  2017-3-9

Custom exception inherit from `std::exception`
==============================================

* inherit from `std::exception`

  ```cpp
  class CustomException : public std::exception {
  public:
    CustomException() : msg_("CustomException") {}
    explicit CustomException(const char* msg)
      : msg_(std::string("CustomException: ") + msg) {}
    explicit CustomException(const std::string& msg)
      : msg_(std::string("CustomException: ") + msg) {}
    virtual ~CustomException() {}
    virtual const char* what() const noexcept {
      return msg_.c_str();
    }

  protected:
    std::string msg_;
  };
  ```

  2017-3-10


Boost `ptr_container`
=====================

* vector

  ```cpp
  boost::ptr_vector<int> s;
  for (int i = 0 ; i < 10 ; ++i) {
    s.push_back(new int{i});
  }
  ```

* set

  ```cpp
  boost::ptr_set<int> s;
  for (int i = 0 ; i < 10 ; ++i) {
    s.insert(new int{i});
  }
  ```

  2017-3-23

Boost `BOOST_SCOPE_EXIT`
========================

* execute just before the scope ends, useful for cleaning up memory

  ```cpp
  BOOST_SCOPE_EXIT(&arr) {
    delete[] arr;
    arr = 0;
    std::cout << "clean up array\n";
  } BOOST_SCOPE_EXIT_END;
  ```

  2017-3-24

Boost Pool
==========

* With Boost.Pool you can, for example, accelerate memory management to provide memory to your program faster.

* Simple Segregated Storage: Every time you request memory from Boost.Pool, the library accesses the next free segment and assigns memory from that segment to you. The entire segment is then marked as used, no matter how many bytes you actually need from that segment.

* Low level interface:

  ```cpp
  boost::simple_segregated_storage<std::size_t> storage;
  vector<char> v(1024);

  storage.add_block(&v.front(), v.size(), 256);
  int* i = static_cast<int*>(storage.malloc());
  storage.free(i);
  ```

* Object Pool:

  ```cpp
  boost::object_pool<int> pool{32, 0};
  int* i = pool.malloc();
  *i = 1;

  int* j = pool.construct(2);
  pool.destroy(i);
  pool.destroy(j);
  ```

* Singleton Pool:

  ```cpp
  struct p {};
  int* i = static_cast<int*>(singleton_pool<p, sizeof(int)>::malloc());
  *i = 1;

  int* j =
      static_cast<int*>(singleton_pool<p, sizeof(int)>::ordered_malloc(10));
  j[9] = 2;

  singleton_pool<p, sizeof(int)>::release_memory();
  singleton_pool<p, sizeof(int)>::purge_memory();
  ```

* Pool Allocator:

  ```cpp
  std::vector<int, boost::pool_allocator<int>> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  v.clear();

  std::list<int, boost::fast_pool_allocator<int>> l;
  for (int i = 0; i < 10; ++i) {
    l.push_back(i);
  }
  l.clear();
  boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::purge_memory();
  ```

  2017-3-25

ROS Subscribe
=============

* create a subscriber node:

  ```cpp
  #include "ros/ros.h"
  #include "std_msgs/String.h"

  void ChatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I heard: [%s]", msg->data.c_str());
  }

  int main(int argc, char** argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe("chatter", 1000, ChatterCallback);
    ros::spin();
    return 0;
  }
  ```

  2017-3-27

ROS Publish
===========

* create a publisher node:

  ```cpp
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include <sstream>

  int main(int argc, char** argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle node;
    ros::Publisher chatter_pub =
        node.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()) {
      std_msgs::String msg;
      std::stringstream ss;
      ss << "Hello World!! [" << count++ << "]";
      msg.data = ss.str();

      ROS_INFO("%s", msg.data.c_str());
      chatter_pub.publish(msg);

      ros::spinOnce();
      loop_rate.sleep();
    }
    return 0;
  }
  ```

  2017-3-28

ROS server
==========

* create srv file

  ```ros
  int64 a
  int64 b
  ---
  int64 sum
  ```

* create server node:

  ```cpp
  #include "ros/ros.h"
  #include "beginner_tutorial/AddTwoInts.h"

  bool Add(beginner_tutorial::AddTwoInts::Request& req,
          beginner_tutorial::AddTwoInts::Response& res) {
    res.sum = req.a + req.b;
    ROS_INFO("request: a=%ld, b=%ld", req.a, req.b);
    ROS_INFO("response: sum=%ld", res.sum);
    return true;
  }

  int main(int argc, char** argv) {
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle node;

    ros::ServiceServer service = node.advertiseService("add_two_ints", Add);
    ROS_INFO("Ready to add two ints...");
    ros::spin();
    return 0;
  }
  ```

  2017-3-29

ROS client
==========

* using same srv file and create the client node:

  ```cpp
  #include <iostream>
  #include "beginner_tutorial/AddTwoInts.h"
  #include "ros/ros.h"

  int main(int argc, char** argv) {
    ros::init(argc, argv, "add_two_ints_client");
    if (argc != 3) {
      std::cout << "usage: add_two_ints_client <a> <b>\n";
      return 1;
    }

    ros::NodeHandle node;
    ros::ServiceClient client =
        node.serviceClient<beginner_tutorial::AddTwoInts>("add_two_ints");
    beginner_tutorial::AddTwoInts srv;
    srv.request.a = std::atoll(argv[1]);
    srv.request.b = std::atoll(argv[2]);
    if (client.call(srv)) {
      ROS_INFO("Sum: %ld", srv.response.sum);
    } else {
      ROS_ERROR("Fail to call service add_two_ints");
      return 1;
    }
    return 0;
  }
  ```

  2017-3-30

ROS Custrom message
===================

* create custom msg

  ```msg
  string simple_msg
  uint64 time
  ```

* subscriber node

  ```cpp
  #include "module_name/CustomMessage.h"
  #include "ros/ros.h"

  using module_name::CustomMessagePtr;

  void Callback(const CustomMessagePtr& tp) {
  }

  int main(int argc, char** argv) {
    ros::init(argc, argv, "receiver");
    ros::NodeHandle node;
    ros::Subscriber sub =
        node.subscribe("topic", 1000, Callback);
    ros::spin();
    return 0;
  }
  ```

* publisher node

  ```cpp
  #include <chrono>
  #include "module_name/CustomMessage.h"
  #include "ros/ros.h"

  using module_name::CustomMessage;

  int main(int argc, char** argv) {
    ros::init(argc, argv, "sender");
    ros::NodeHandle node;
    ros::Publisher publisher = node.advertise<CustomMessage>("topic", 1000);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
      CustomMessage msg;
      msg.simple_msg = "message";
      msg.time =
          std::chrono::duration_cast<std::chrono::microseconds>(
              std::chrono::high_resolution_clock::now().time_since_epoch())
              .count();
      publisher.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }
    return 0;
  }
  ```

  2017-3-31

ROS Arduino
===========

* include

  ```
  #include <ros.h>
  #include <rosserial_arduino/Adc.h>

  ```

* variable

  ```cpp
  ros::NodeHandle node;
  rosserial_arduino::Adc adc_msg;
  ros::Publisher publisher("adc", &adc_msg);
  ```

* usage
  ```cpp

  void setup() {
    node.initNode();
    node.advertise(publisher);
  }

  long AverageRead(int pin) {
    long value = 0;
    int read_count = 4;
    for (int i = 0 ; i < read_count ; ++i) {
      value += analogRead(pin);
    }
    return value / read_count;
  }

  void loop() {
    adc_msg.adc0 = AverageRead(0);
    adc_msg.adc1 = AverageRead(1);
    adc_msg.adc2 = AverageRead(2);
    adc_msg.adc3 = AverageRead(3);
    adc_msg.adc4 = AverageRead(4);
    adc_msg.adc5 = AverageRead(5);

    publisher.publish(&adc_msg);
    node.spinOnce();
  }
  ```

  2017-4-1

Boost TCP
=========

* simple usage

  ```cpp
  #include <boost/asio.hpp>

  using namespace boost::asio;
  using namespace boost::asio::ip;

  io_service service;
  tcp::resolver resolver{service};
  tcp::socket sock{service};
  array<char, 8192> bytes;

  void Read(const boost::system::error_code& ec, size_t byte_transferred) {
    if (!ec) {
      if (byte_transferred > 0) {
        cout << byte_transferred << '\n';
        cout.write(bytes.data(), byte_transferred);
        if (byte_transferred == 8192) {
          sock.async_read_some(buffer(bytes), Read);
        }
      }
    }
  }

  void Connect(const boost::system::error_code& ec) {
    string r = "GET / HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n";
    write(sock, buffer(r));
    sock.async_read_some(buffer(bytes), Read);
  }

  void Resolve(const boost::system::error_code& ec, tcp::resolver::iterator it) {
    if (!ec) {
      cout << "resolving...\n";
      sock.async_connect(*it, Connect);
    }
  }

  int main(void) {
    tcp::resolver::query q{"www.google.ca", "80"};
    resolver.async_resolve(q, Resolve);
    service.run();
    return 0;
  }
  ```

  2017-4-2

Boost Singal2
=============

  2017-4-3

Boost MPI Simple Execute
========================

* run it with `mpiexec -n 4 exec`

  ```cpp
  #include <boost/mpi.hpp>
  #include <iostream>

  int main(int argc, char* argv[]) {
    boost::mpi::environment env{argc, argv};
    boost::mpi::communicator world;
    std::cout << world.rank() << ',' << world.size() << '\n';
    return 0;
  }
  ```

  2017-4-4

Boost DateTime
==============

* date time module

  ```cpp
  #include <boost/date_time.hpp>
  #include <iostream>

  using boost::gregorian::date;

  int main(void) {
    date d{2017, 4, 23};
    std::cout << d.year() << "/" << d.month()
        << "/" << d.day() << '\n';
    return 0;
  }
  ```

  2017-4-5

Boost Chrono
============

* namespace add operator<< overload, which is easier to use

  ```cpp
  #include <boost/chrono.hpp>
  #include <iostream>

  using namespace boost::chrono;

  int main() {
    std::cout << system_clock::now() << '\n';
  #ifdef BOOST_CHRONO_HAS_CLOCK_STEADY
    std::cout << steady_clock::now() << '\n';
  #endif
    std::cout << high_resolution_clock::now() << '\n';

  #ifdef BOOST_CHRONO_HAS_PROCESS_CLOCKS
    std::cout << process_real_cpu_clock::now() << '\n';
    std::cout << process_user_cpu_clock::now() << '\n';
    std::cout << process_system_cpu_clock::now() << '\n';
    std::cout << process_cpu_clock::now() << '\n';
  #endif

  #ifdef BOOST_CHRONO_HAS_THREAD_CLOCK
    std::cout << thread_clock::now() << '\n';
  #endif
    return 0;
  }
  ```

  2017-4-6

Boost Timer
===========

* boost timer

  ```cpp
  #include <boost/timer/timer.hpp>
  #include <cmath>
  #include <iostream>

  using namespace boost::timer;

  int main() {
    cpu_timer timer;

    for (int i = 0; i < 1000000; ++i) std::pow(1.234, i);
    std::cout << timer.format() << '\n';
    return 0;
  }
  ```

  2017-4-7

OpenGL Simple Window
====================

* use glew glfw for quick window

* init glfw

  ```cpp
  if (!glfwInit()) {
    std::cerr << "fail to initialize glfw\n";
    return 1;
  }
  ```

* window setting

  ```cpp
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  ```

* create window

  ```cpp
  window_ = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
  if (!window_) {
    std::cerr
        << "Failed to open GLFW window. If you have an Intel GPU, they are "
           "not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window_);
  ```

* init glew

  ```cpp
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW\n";
    glfwTerminate();
    return false;
  }
  ```

* inputs

  ```cpp
  glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);
  ```

* render loop

  ```cpp
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  do {
    // Clear the screen
    // flickering, so it's there nonetheless.
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw

    // Swap buffers
    glfwSwapBuffers(window_);
    glfwPollEvents();
  } while (glfwGetKey(window_, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window_) == 0);
  ```

  2017-4-21

OpenGL Draw Triangle
====================

* for every opengl Object, we need a vertex array object

  ```cpp
  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);
  ```

* and a vertex buffer object

  ```cpp
  ```

  2017-4-22

Boost FileSystem
================

* namespace

  ```cpp
  using namespace boost::filesystem;
  ```

* check file exists

  ```cpp
  path p{"filepath_test.cc"};
  try {
    file_status s = status(p);
    std::cout << std::boolalpha << is_regular_file(s) << '\n';
  } catch (filesystem_error &e) {
    std::cerr << e.what() << '\n';
  }
  ```

  2017-4-23

Boost Program Options
=====================

* namespace

  ```cpp
  namespace popt = boost::program_options;
  ```

* usage

  ```cpp
  popt::options_description desc("Allowed options");
  desc.add_options()("help,h", "help messages");
  desc.add_options()("input,i",
                     popt::value<std::string>()->default_value("input"),
                     "input file");
  desc.add_options()("output,o",
                     popt::value<std::string>()->default_value("output"),
                     "output file");

  popt::variables_map vmap;
  popt::store(popt::parse_command_line(argc, argv, desc), vmap);
  popt::notify(vmap);

  if (vmap.count("help")) {
    std::cout << desc << "\n";
    return 0;
  }
  ```

  2017-4-24
