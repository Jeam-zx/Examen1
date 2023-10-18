#include "../headers/Vector3D.hpp"
#include "../ext/googletest/googletest/include/gtest/gtest.h"

// Prueba del constructor y los getters
TEST(Vector3DTest, ConstructorYGetters) {
Vector3D vec(1.0, 2.0, 3.0);
EXPECT_DOUBLE_EQ(vec.getX(), 1.0);
EXPECT_DOUBLE_EQ(vec.getY(), 2.0);
EXPECT_DOUBLE_EQ(vec.getZ(), 3.0);
}

// Prueba del operador de suma
TEST(Vector3DTest, OperadorSuma) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D b(4.0, 5.0, 6.0);
Vector3D resultado = a + b;
EXPECT_DOUBLE_EQ(resultado.getX(), 5.0);
EXPECT_DOUBLE_EQ(resultado.getY(), 7.0);
EXPECT_DOUBLE_EQ(resultado.getZ(), 9.0);
}

// Prueba del operador de suma con un escalar
TEST(Vector3DTest, OperadorSumaConEscalar) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D resultado = a + 3.0;
EXPECT_DOUBLE_EQ(resultado.getX(), 4.0);
EXPECT_DOUBLE_EQ(resultado.getY(), 5.0);
EXPECT_DOUBLE_EQ(resultado.getZ(), 6.0);
}

// Prueba del operador de resta
TEST(Vector3DTest, OperadorResta) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D b(4.0, 5.0, 6.0);
Vector3D resultado = a - b;
EXPECT_DOUBLE_EQ(resultado.getX(), -3.0);
EXPECT_DOUBLE_EQ(resultado.getY(), -3.0);
EXPECT_DOUBLE_EQ(resultado.getZ(), -3.0);
}

// Prueba del operador de resta con un escalar
TEST(Vector3DTest, OperadorRestaConEscalar) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D resultado = a - 2.0;
EXPECT_DOUBLE_EQ(resultado.getX(), -1.0);
EXPECT_DOUBLE_EQ(resultado.getY(), 0.0);
EXPECT_DOUBLE_EQ(resultado.getZ(), 1.0);
}

// Prueba del operador de producto vectorial
TEST(Vector3DTest, OperadorProductoVectorial) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D b(4.0, 5.0, 6.0);
Vector3D resultado = a * b;
EXPECT_DOUBLE_EQ(resultado.getX(), -3.0);
EXPECT_DOUBLE_EQ(resultado.getY(), 6.0);
EXPECT_DOUBLE_EQ(resultado.getZ(), -3.0);
}

// Prueba del operador de producto con un escalar
TEST(Vector3DTest, OperadorProductoConEscalar) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D resultado = a * 2.0;
EXPECT_DOUBLE_EQ(resultado.getX(), 2.0);
EXPECT_DOUBLE_EQ(resultado.getY(), 4.0);
EXPECT_DOUBLE_EQ(resultado.getZ(), 6.0);
}

// Prueba del operador de producto escalar
TEST(Vector3DTest, OperadorProductoEscalar) {
Vector3D a(1.0, 2.0, 3.0);
Vector3D b(4.0, 5.0, 6.0);
double resultado = a % b;
EXPECT_DOUBLE_EQ(resultado, 32.0);
}

// Prueba del operador de norma
TEST(Vector3DTest, OperadorNorma) {
Vector3D a(1.0, 2.0, 3.0);
double resultado = &a;
EXPECT_DOUBLE_EQ(resultado, 3.7416573867739413);  // Valor de la norma
}
