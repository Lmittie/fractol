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
    for (step = 0.0; step <= maxStep; ++step)
    {
        // z = z*z + c
        z = vec2(z.x*z.x - z.y*z.y, 2.0*z.x*z.y) + juliaParameters;
        if (length(z) > 2.0) break;
    }
    return step / maxStep;
}

vec2 random(vec2 pos, vec2 range, vec2 start)
{
    float newX = sin(dot(pos, vec2(32.1232, 7.324)))*23432.4;
    float newY = cos(dot(pos, vec2(432.23, 21.4)))*32145.4;
    
    newX = start.x + mod(newX, range.x);
    newY = start.y + mod(newY, range.y);
    
    return vec2(newX, newY);
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
    float red = (20 * pow((1 - t), 2) * pow(t, 2)) + cos(colorShift.x * 5.0) / 2.0;
    float green = (9 * (1 - colorShift.y * 5.0) * pow(t, 3));
    float blue = (8.5 * pow((1 - t), 3) * tan(10.0 * t)) + cos(colorShift.z * 5.0) / 2.0;
    vec3 col = vec3(red, green ,blue);
    if (t >= 0.9)
        col = vec3(0.0, 0.0, 0.0);
    gl_FragColor = vec4(col, 1.0);
}