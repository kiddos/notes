#version 320 es
precision mediump float;

// Vertex attributes (bound in your Mesh::setupMesh)
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

// Uniforms for transforms
uniform mat4 uModel;       // Model transform
uniform mat4 uView;        // Camera view transform
uniform mat4 uProjection;  // Projection matrix

// Outputs to the fragment shader
out vec3 vFragPos;
out vec3 vNormal;
out vec2 vTexCoord;

void main() {
    // World position of the vertex
    vec4 worldPos = uModel * vec4(aPos, 1.0);
    vFragPos = worldPos.xyz;

    // Transform normal into world space (ignoring non-uniform scaling here)
    vNormal = mat3(uModel) * aNormal;

    // Pass texture coordinate straight through
    vTexCoord = aTexCoord;

    // Final clip-space position
    gl_Position = uProjection * uView * worldPos;
}