#version 120

uniform vec2 iResolution;
uniform vec2 cameraPosition;
uniform float zoom;
uniform vec2 juliaParameters;
uniform vec3 colorShift;
uniform float maxStep;

vec2 cmul (vec2 c1, vec2 c2)
{
	float a = c1.x;
	float b = c1.y;
	float c = c2.x;
	float d = c2.y;

	return vec2 (a * c - b * d, b * c + a * d);
}

float cabs (in vec2 complex)
{
	float x = complex.x;
	float y = complex.y;

	return sqrt(x*x + y*y);
}

//Based on explanation http://www.hiddendimension.com/fractalmath/Divergent_Fractals_Main.html
void main(void)
{
    vec2 c = gl_FragCoord.xy / iResolution.xy;
    //scaling real axis to [-2.5, 1.5] and  imaginary axis to  [-1.5, 1.5]
    c = c * vec2(4,3) - vec2(2.5, 1.5);
    c /= zoom;
    c += cameraPosition;
    vec2 z = vec2(0);
    int i = 0;

    for (;i < 100;i++)
    {
        if (cabs(z) >= 4.) break;
       z *= vec2(1, -1);
       z = cmul(z, z);
       z -= vec2(z.x + abs(z.x), 0) + c;
    }
    float t = 1 - i / 10;
    float red = pow(1 - t, 6) / 2 + colorShift.x;
    float green = pow(t, 2) / 5 + colorShift.y;
    float blue = pow(t, 7) / 2 + colorShift.z;
    vec3 col = vec3(red, green, blue);
    if (t >= 0.9)
      vec3 col = vec3(0.0, 0.0, 0.0);
    gl_FragColor = vec4(col, 1.0);
}