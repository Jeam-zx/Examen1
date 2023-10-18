#include "../headers/DiagramaT.hpp"
#include "../ext/googletest/googletest/include/gtest/gtest.h"

TEST(DiagramaTTest, ejemploExamen) {
    DiagramaT diagrama;
    // Prueba de ejemplo del examen
    EXPECT_TRUE(diagrama.definirPrograma("fibonacci", "LOCAL"));
    EXPECT_TRUE(diagrama.ejecutarPrograma("fibonacci"));
    EXPECT_TRUE(diagrama.definirPrograma("factorial", "Java"));
    EXPECT_FALSE(diagrama.ejecutarPrograma("factorial"));
    EXPECT_TRUE(diagrama.definirInterprete("C", "Java"));
    EXPECT_TRUE(diagrama.definirTraductor("C", "Java", "C"));
    EXPECT_TRUE(diagrama.definirInterprete("LOCAL", "C"));
    EXPECT_TRUE(diagrama.ejecutarPrograma("factorial"));
    EXPECT_TRUE(diagrama.definirPrograma("holamundo", "Python"));
    EXPECT_TRUE(diagrama.definirTraductor("wtf42", "Python", "LOCAL"));
    EXPECT_FALSE(diagrama.ejecutarPrograma("holamundo"));
    EXPECT_TRUE(diagrama.definirTraductor("C", "wtf42", "Java"));
    EXPECT_TRUE(diagrama.ejecutarPrograma("holamundo"));
}

TEST(DiagramaTTest, PuedeEjecutarse) {
    // Prueba de ejecucion
    DiagramaT diagrama;

    GTEST_EXPECT_FALSE(diagrama.ejecutarPrograma("numaleatorio"));
}

TEST(DiagramaTTest, DefinirInterprete) {
    // Prueba de definicion de interprete
    DiagramaT diagrama;
    GTEST_EXPECT_TRUE(diagrama.definirInterprete("Python", "JavaScript"));
    GTEST_EXPECT_FALSE(diagrama.definirInterprete("Python", "JavaScript"));
}

TEST(DiagramaTTest, DefinirPrograma) {
    // Prueba de definicion de programa
    DiagramaT diagrama;
    GTEST_EXPECT_TRUE(diagrama.definirPrograma("MiPrograma", "C++"));
    GTEST_EXPECT_FALSE(diagrama.definirPrograma("MiPrograma", "C++"));

}

TEST(DiagramaTTest, DefinirTraductor) {
    // Prueba de definicion de traductor
    DiagramaT diagrama;
    GTEST_EXPECT_TRUE(diagrama.definirTraductor("C++", "C", "Python"));
    GTEST_EXPECT_FALSE(diagrama.definirTraductor("C++", "C", "Python"));
}