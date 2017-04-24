More Accessable Web Application
===============================

* when user using screen reader hover on the checkbox, they will only hear checkbox

  ```html
  <input type="checkbox" checked>Sign up
  ```

* add a label around it making it more accessable

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

* label button

  ```html
  <button class="menu" aria-label="menu"></button>

  <h2 id="sec1">Section</h2>
  <div role="button" tabindex="0" class="button"
    aria-labelledby="sec1 sec1-shop-now" id="sec1-shop-now">Shop Now</div>
  ```

  2017-1-29
