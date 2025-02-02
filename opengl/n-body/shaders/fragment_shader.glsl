#version 440 core

layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

uniform float u_worldSize;

in vec4 particleVelocity;
in float particleSize;

vec4 getParticleColor() {
  float maxVelocity = u_worldSize * 0.1;
  float velocityMagnitude = length(particleVelocity);
  float normalizedVelocity = clamp(velocityMagnitude / maxVelocity, 0.0, 1.0);

  // Define three colors for the gradient (e.g. red, orange, yellow)
  vec3 colorLow = vec3(0.0, 0.0, 1.0); // blue (slowest)
  vec3 colorMid = vec3(1.0, 0.5, 0.0); // orange (middle)
  vec3 colorHigh = vec3(1.0, 0.0, 0.0); // red (fastest)

  // Interpolate between the three colors based on the normalized velocity value
  float smoothNormalizedVelocity1 = smoothstep(0.0, 0.5, normalizedVelocity);
  float smoothNormalizedVelocity2 = smoothstep(0.5, 1.0, normalizedVelocity);

  vec3 color = mix(colorLow, colorMid, smoothNormalizedVelocity1);
  color = mix(color, colorHigh, smoothNormalizedVelocity2);

  return vec4(color, 1); // pass the velocity to the fragment shader
}


vec4 getParticleBrightColor() {
  return vec4(FragColor.rgb, 1.0);
}

void main() {
  // Set the color of the particle
  FragColor = getParticleColor();
  // Render in the second framebuffer the bright particles
  BrightColor = getParticleBrightColor();
}
