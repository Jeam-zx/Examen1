JAVAC = javac
JAVA = java

# Rutas a los archivos fuente
SRC_DIR = ./pregunta-1b/src
MAIN_SRC = $(SRC_DIR)/Main.java
ROTAR_SRC = $(SRC_DIR)/Rotar.java
PRODUCTO_SRC = $(SRC_DIR)/ProductoPorTranspuesta.java

all: Main.class

Main.class: $(MAIN_SRC) Rotar.class ProductoPorTranspuesta.class
	$(JAVAC) -cp $(SRC_DIR) $(MAIN_SRC)

Rotar.class: $(ROTAR_SRC)
	$(JAVAC) -cp $(SRC_DIR) $(ROTAR_SRC)

ProductoPorTranspuesta.class: $(PRODUCTO_SRC)
	$(JAVAC) -cp $(SRC_DIR) $(PRODUCTO_SRC)

run: Main.class
	$(JAVA) -cp $(SRC_DIR) Main

clean:
	rm -f $(SRC_DIR)/*.class

.PHONY: all run clean
