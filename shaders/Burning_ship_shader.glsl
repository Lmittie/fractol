#version 120

uniform vec2 iResolution;
uniform vec2 cameraPosition;
uniform float zoom;
uniform vec2 juliaParameters;
uniform vec3 colPal[4];
uniform float paletteShift;
uniform float maxStep;

float colormap_red(float x) {
    if (x < 0.7) {
        return 4.0 * x - 1.5;
    } else {
        return -4.0 * x + 4.5;
    }
}

float colormap_green(float x) {
    if (x < 0.5) {
        return 4.0 * x - 0.5;
    } else {
        return -4.0 * x + 3.5;
    }
}

float colormap_blue(float x) {
    if (x < 0.3) {
       return 4.0 * x + 0.5;
    } else {
       return -4.0 * x + 2.5;
    }
}

vec4 colormap(float x) {
    float r = clamp(colormap_red(x), 0.0, 1.0);
    float g = clamp(colormap_green(x), 0.0, 1.0);
    float b = clamp(colormap_blue(x), 0.0, 1.0);
    return vec4(r, g, b, 1.0);
}


//math
vec2 cmult(vec2 z1, vec2 z2) {
    return vec2(z1.x*z2.x - z1.y*z2.y, z1.x*z2.y + z1.y*z2.x);
}


float mandelbrot(vec2 c) {
    vec2 z = vec2(0.0, 0.0);
    vec2 zd = vec2(0.0, 0.0);
    for (int i = 0; i < maxStep; i++) {
        if (length(z) > 10.0) break;
        zd = 2.0*cmult(z, zd) + vec2(1.0, 0.0);
        vec2 za = vec2(abs(z.x), abs(z.y));
        z = cmult(za, za) + c;
    }
    
    float d = 0.5*length(z)*log(length(z))/length(zd);
    return d;
}

vec3 pal( float t, vec3 a, vec3 b, vec3 c, vec3 d ) {
    return a * t + b * cos(6.28318 * (c * t * 50.0 + d));
}

void main(void)
{
    vec2 offset = vec2(-1.75, -0.03);
	vec2 uv = -(2.0*gl_FragCoord.xy - iResolution.xy) / iResolution.y;

    uv /= zoom;
    uv = uv  - 2.0 * cameraPosition;
    float d = mandelbrot(uv);
    float color = clamp(8.0*d/zoom, 0.0, 1.0);
    color = pow(color, 0.2);
    
	gl_FragColor = colormap(color);
}