#version 120

uniform vec2 iResolution;
uniform vec2 cameraPosition;
uniform float zoom;
uniform vec2 juliaParameters;
uniform vec3 colorShift;
uniform float maxStep;

float mandelbrot(vec2 uv)
{
    vec2 z = uv;
    float step = 0.0;
    for (step = 0.0; step < maxStep; ++step)
    {
        // z = z*z + c
        z = vec2(z.x*z.x - z.y*z.y, 2.0*z.x*z.y) + uv;
        if (length(z) > 2.0) break;
    }
    return step / maxStep;
}

void main(void)
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = gl_FragCoord.xy/iResolution;
    uv -= 0.5;
    //uv.x *= iResolution.x/iResolution.y;
    
    // zoom and translate
    uv /= zoom;
    uv += cameraPosition;

    // Output to screen
    float t = mandelbrot(uv);
    float red = (15 * pow((1 - t), 2) * pow(t, 2)) + colorShift.x;
    float green = (0.9 * (1 - t) * pow(t, 3)) + colorShift.y / 2.0;
    float blue = (8.5 * pow((1 - t), 3) * t) + colorShift.z / 2.0;
    vec3 col = vec3(red, green, blue) * 2.0;
    if (t >= 0.9)
        col = vec3(0.0, 0.0, 0.0);
    gl_FragColor = vec4(col, 1.0);
}