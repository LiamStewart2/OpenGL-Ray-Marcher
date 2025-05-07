#version 450 core
out vec4 FragColor;

uniform float timePassed;

float minimumDistance = 0.01f;
float maximumDistance = 1000.0f;
float circleRadius = 1.0f;

const int sphereCount = 4;
vec3 spheres[sphereCount] = {vec3(-sin(timePassed / 3) * 4, 0, 4), vec3(sin(timePassed / 3) * 4, 0, 4), vec3(0, sin(timePassed / 3) * 4, 4), vec3(0, -sin(timePassed / 3) * 4, 4)};

const float viewportWidth = 1080;
const float viewportHeight = 720;

const vec4 skyColour = vec4(109.0 / 255.0, 176.0 / 255.0, 214.0 / 255.0, 1.0);
const vec4 floorColour = vec4(69.0 / 255.0, 69.0 / 255.0, 69.0 / 255.0, 1.0);

struct Ray{
    vec3 origin;
    vec3 direction;
};

float smoothMin(float dstA, float dstB, float k)
{
    float h = max(k-abs(dstA - dstB), 0) / k;
    return min(dstA, dstB) - h*h*h*k*1/6.0;
}

float lerp(float f1, float f2, float t)
{
    return f1 + (f2 - f1) * t;
}

vec4 lerp(vec4 v1, vec4 v2, float t)
{
    return vec4(lerp(v1.x, v2.x, t), lerp(v1.y, v2.y, t), lerp(v1.z, v2.z, t), lerp(v1.w, v2.w, t));
}

float Distance(vec3 v)
{
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

float signedDistanceToCircle(vec3 p, vec3 centre, float radius)
{
    return Distance(centre - p) - radius;
}

float signedDistanceToScene(vec3 p)
{
    float distanceToScene = maximumDistance;

    for(int i = 0; i < sphereCount; i++)
    {
        float distanceToCircle = signedDistanceToCircle(p, spheres[i], circleRadius);
        distanceToScene = smoothMin(distanceToCircle, distanceToScene, 2);
    }

    return distanceToScene;
}

void main()
{
    float aspectRatio = viewportWidth / viewportHeight;
    vec2 uv = (gl_FragCoord.xy / vec2(viewportWidth, viewportHeight)) * 2.0 - 1.0;
    uv.x *= aspectRatio;
    vec3 rayDirection = normalize(vec3(uv, 1.0)); // Assuming perspective projection
    Ray ray = {vec3(0, 0, 0), rayDirection};
    
    float totalDistance = 0.0f;
    float bounces = 0;
    while (totalDistance <= maximumDistance)
    {
        float dstToScene = signedDistanceToScene(ray.origin);
        if(dstToScene < minimumDistance)
            break;
        
        ray.origin += ray.direction * dstToScene;
        totalDistance += dstToScene;
        bounces += 1;
    }
    
    if(totalDistance < maximumDistance)
    {
        FragColor = vec4(0.2f, 0.7f, 0.2f, 1.0f);

        float brightness = 1 - totalDistance / bounces;
        FragColor = vec4(max(brightness, FragColor.x), max(brightness, FragColor.y), max(brightness, FragColor.z), 1 );
    }
    else
    {
        FragColor = vec4(uv.y / 2 + 0.5, 0, 0, 1);
        FragColor = lerp(floorColour, skyColour, uv.y / 2 + 0.7);
    }
} 