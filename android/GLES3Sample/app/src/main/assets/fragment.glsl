#version 320 es
precision mediump float;

in vec3 vFragPos;
in vec3 vNormal;
in vec2 vTexCoord;

out vec4 fragColor;

// Example uniforms
uniform vec3 uLightPos;
uniform vec3 uViewPos;
uniform sampler2D uTexture;

void main()
{
    // Simple diffuse lighting
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(uLightPos - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 baseColor = texture(uTexture, vTexCoord).rgb;
    vec3 lighting = diff * baseColor;

    fragColor = vec4(norm * 0.5 + 0.5, 1.0);
}
