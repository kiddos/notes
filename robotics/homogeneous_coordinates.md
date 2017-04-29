Homogeneous Coordinates
=======================

## Motivation

* sensor does not provide distance measurement, but only the orientation (eg. camera)
* In Eucliean geometry, the math can be difficult
* Projective geometry is an alternative algebraic representation for objects and transformation, where math becomes simpler

## Projective Geometry

* does not change geometry relation
* computation is simpler

## Homogeneous Coordinates

* use in Projective Geometry
* simpler than Cartesian world
* can represent points of infinity
* single matrix representation
* Definition
  - The representation $x$ of geometry object is homogeneous if $x$ and $\lambda x$ represent the same object for $\lambda \neq 0$

  $$
  x = \left(
  \begin{array}{ccc}
  u\\
  v\\
  w\\
  \end{array}
  \right) = \left(
  \begin{array}{ccc}
  wx\\
  wy\\
  w\\
  \end{array}
  \right) = \frac{1}{w}\left(
  \begin{array}{ccc}
  x\\
  y\\
  1\\
  \end{array}
  \right)
  $$

  $$
  x = \left(
  \begin{array}{ccc}
  u\\
  v\\
  w\\
  \end{array}
  \right) = \frac{1}{w}\left(
  \begin{array}{ccc}
  x\\
  y\\
  1\\
  \end{array}
  \right) \rightarrow \left(
  \begin{array}{ccc}
  u/w\\
  v/w\\
  \end{array}
  \right) = \left(
  \begin{array}{ccc}
  x\\
  y\\
  \end{array}
  \right)
  $$

  - Origin

  $$
  \O_2 = \left(
  \begin{array}{ccc}
  0 \\
  0 \\
  1 \\
  \end{array}
  \right)
  $$

  $$
  \O_3 = \left(
  \begin{array}{ccc}
  0 \\
  0 \\
  0 \\
  1 \\
  \end{array}
  \right)
  $$

  - Infinity

  $$
  x_\infty = \left(
  \begin{array}{ccc}
  u \\
  v \\
  0 \\
  \end{array}
  \right)
  $$

  - Transformation

  ![table](https://www.ntu.edu.sg/home/ehchua/programming/opengl/images/Graphics3D_AffineTransforms.png)
