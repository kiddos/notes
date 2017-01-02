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


