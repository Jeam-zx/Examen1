#include <iostream>
#include "../headers/Vector3D.hpp"

int main(int argc, char **argv) {
    Vector3D v1(1, 2, 3);
    printf("VECTOR 1\n");
    printf("v1 = (%f, %f, %f)\n", v1.getX(), v1.getY(), v1.getZ());
    Vector3D v2(4, 5, 6);
    printf("VECTOR 2\n");
    printf("v2 = (%f, %f, %f)\n", v2.getX(), v2.getY(), v2.getZ());
    Vector3D v3 = v1 + v2;
    printf("SUMA VECTORIAL\n");
    printf("v3 = (%f, %f, %f)\n", v3.getX(), v3.getY(), v3.getZ());
    Vector3D v4 = v1 - v2;
    printf("RESTA VECTORIAL\n");
    printf("v4 = (%f, %f, %f)\n", v4.getX(), v4.getY(), v4.getZ());
    Vector3D v5 = v1 * v2;
    printf("PRODUCTO VECTORIAL\n");
    printf("v5 = (%f, %f, %f)\n", v5.getX(), v5.getY(), v5.getZ());
    Vector3D v6 = v1 + 3;
    printf("SUMA CON UN ESCALAR\n");
    printf("v6 = (%f, %f, %f)\n", v6.getX(), v6.getY(), v6.getZ());
    Vector3D v7 = v1 - 3;
    printf("RESTA CON UN ESCALAR\n");
    printf("v7 = (%f, %f, %f)\n", v7.getX(), v7.getY(), v7.getZ());
    Vector3D v8 = v1 * 3;
    printf("PRODUCTO CON UN ESCALAR\n");
    printf("v8 = (%f, %f, %f)\n", v8.getX(), v8.getY(), v8.getZ());
    double p = v1 % v2;
    printf("PRODUCTO PUNTO\n");
    printf("p = %f\n", p);
    double n = &v1;
    printf("NORMA\n");
    printf("n = %f\n", n);

    return 0;
}