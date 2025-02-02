#version 440 core

layout(std430, binding=0) buffer positionsBuffer {
  vec4 positions[];
};

layout(std430, binding=1) buffer velocitiesBuffer {
  vec4 velocities[];
};

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;
uniform vec3 u_cameraPos;
uniform float u_worldSize;

out vec4 particleVelocity;
out float particleSize;

float getParticleSize() {
  float particleSize = 1.0f / length(u_cameraPos - positions[gl_VertexID].xyz);
  return particleSize * u_worldSize * 2.0;
}

void main() {
  gl_PointSize = getParticleSize();
  particleSize = gl_PointSize;

  gl_Position = u_projection * u_view * u_model * vec4(positions[gl_VertexID].xyz, 1.0f);
  particleVelocity = velocities[gl_VertexID];
}
