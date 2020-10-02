#version 120

uniform vec2 iResolution;
uniform vec2 cameraPosition;
uniform float zoom;
uniform vec2 juliaParameters;
uniform vec3 colorShift;
uniform float maxStep;

#define THRESHOLD 0.000001
#define ANTI_ALIASING 2

vec2 f(vec2 z) {
    float magnitude = dot(z, z);
    return (2.0 * z + vec2(z.x * z.x - z.y * z.y, -2.0 * z.x * z.y) / (magnitude * magnitude)) / 3.0;
}

vec2 roots[] = vec2[](
    vec2(1.0, 0.0),
    vec2(-0.5, 0.5 * sqrt(3.0)),
    vec2(-0.5, -0.5 * sqrt(3.0))
);

vec3 palette[] = vec3[](
    vec3(1.0, colorShift.y, colorShift.z),
    vec3(colorShift.x, 1.0, colorShift.z),
    vec3(colorShift.x, colorShift.y, 1.0)
);

vec3 drawFractal(vec2 z) {
    for (int iterations = 0; iterations < maxStep; ++iterations) {
    	z = f(z);
        for (int root = 0; root < roots.length(); ++root) {
            vec2 difference = z - roots[root];
            float distance = dot(difference, difference);
            if (distance < THRESHOLD) {
    			return palette[root] * (0.75 + 0.25 * cos(0.25 * (float(iterations) - log2(log(distance) / log(THRESHOLD)))));
            }
        }
    }
}

void main(void) {
    vec3 color = vec3(0);

    for (int x = 0; x < ANTI_ALIASING; ++x) {
        for (int y = 0; y < ANTI_ALIASING; ++y) {
			vec2 uv = (2.0 * (gl_FragCoord.xy + vec2(x, y) / float(ANTI_ALIASING)) - iResolution.xy) / iResolution.y;
			uv /= zoom;
			uv = uv + 2.0 * cameraPosition;
            color += drawFractal(uv);
        }
    }

    gl_FragColor = vec4(color / float(ANTI_ALIASING * ANTI_ALIASING), 1.0);
}