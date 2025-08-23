#version 460 core

#include <flutter/runtime_effect.glsl>

uniform vec4 uColor;
uniform vec2 uSize;

out vec4 FragColor;

void main() {
  vec2 pixel = FlutterFragCoord() / uSize;
  vec4 white = vec4(1.0);
  vec4 c = vec4(uColor.rgb * uColor.a, uColor.a);
  FragColor = mix(c, white, pixel.x);
}
