#include "../headers/BuddySystem.hpp"
#include "../ext/googletest/googletest/include/gtest/gtest.h"

TEST(BuddySystemTest, Construccion) {
    BuddySystem sistema(32);
    // Agrega algunas aserciones para comprobar si el constructor funciona como se espera
    EXPECT_EQ(sistema.getMaxPotencia(), 5);
    EXPECT_EQ(sistema.getFreeBlocks().size(), 6);
}

TEST(BuddySystemTest, ReservaYLiberaRightMerge) {
    BuddySystem sistema(32);

    // Prueba de reserva exitosa
    EXPECT_TRUE(sistema.reservar("Bloque1", 16));

    // Prueba de reserva duplicada (debería fallar)
    EXPECT_FALSE(sistema.reservar("Bloque1", 8));

    // Prueba de liberación
    EXPECT_TRUE(sistema.liberar("Bloque1"));

    // Prueba de liberación de un bloque que no existe (debe fallar)
    EXPECT_FALSE(sistema.liberar("BloqueNoExistente"));

    // Prueba de reserva de un bloque negativo
    EXPECT_FALSE(sistema.reservar("Bloque2", -1));

    // Prueba de reserva de un bloque que no cabe en memoria (debería fallar)
    EXPECT_FALSE(sistema.reservar("Bloque2", 64));
}

TEST(BuddySystemTest, ReservaYLiberaLeftMerge) {
    BuddySystem sistema(32);

    // Prueba de reserva exitosa
    EXPECT_TRUE(sistema.reservar("Bloque1", 8));

    // Prueba de reserva exitosa
    EXPECT_TRUE(sistema.reservar("Bloque2", 8));

    // Prueba de liberación
    EXPECT_TRUE(sistema.liberar("Bloque1"));

    // Prueba de liberación
    EXPECT_TRUE(sistema.liberar("Bloque2"));
}


TEST(BuddySystemTest, RepresentacionDeMemoria) {
    BuddySystem sistema(64);

    // Realiza algunas reservas y liberaciones para probar la representación de la memoria
    sistema.reservar("Bloque1", 8);
    sistema.reservar("Bloque2", 16);
    // Representación de memoria esperada
    string memoriaEsperada = "| R | R | R | R | R | R | R | R | F | F | F | F | F | F | F | F | R | R | R | R | R | R | R | R | R | R | R | R | R | R | R | R | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F |";
    EXPECT_EQ(sistema.getMemoryRepresentation(), memoriaEsperada);

    sistema.liberar("Bloque1");

    // Representación de memoria esperada
    memoriaEsperada = "| F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | R | R | R | R | R | R | R | R | R | R | R | R | R | R | R | R | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F | F |";
    EXPECT_EQ(sistema.getMemoryRepresentation(), memoriaEsperada);

    sistema.mostrar();
}



