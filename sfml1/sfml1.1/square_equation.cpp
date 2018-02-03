#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
    std::puts("please enter a and b for `ax^2 + bx + c = 0`:");
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);
    const float D = (b * b) - (4 * a * c);
    const float sqrtD = std::sqrt(D);
    const float root1 = (-b + sqrtD) / (2 * a);
    const float root2 = (-b - sqrtD) / (2 * a);
    if (D < 0)
    {
        std::printf("no roots\n");
    }
    if (D == 0)
    {
        std::printf("%f\n", root1);
    }
    if (D > 0)
    {
        std::printf("%f %f\n", root1, root2);
    }
}