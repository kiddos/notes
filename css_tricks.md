Background Stripe
=================

  ```css
  background: repeating-linear-gradient(
    60deg,
    #D9D9D9,
    #D9D9D9 10px,
    #D6D6D6 10px,
    #D6D6D6 20px
  );
  ```

  2017-1-15

* element with ratio

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

  2017-1-29

Flex box for center element
===========================

* center element

  ```css
  .ele {
    display: flex;
    justify-content: center;
    align-items: center;
  }
  ```

  2017-2-3

No Select
=========

* disable user selection

  ```css
  .ele {
    user-select: none;
  }
  ```

  2017-2-3
