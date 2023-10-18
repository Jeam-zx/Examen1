import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Programa a ejecutar
        System.out.println("Ingrese el numero del programa a ejecutar:");
        System.out.println("1. Rotar");
        System.out.println("2. Producto por transpuesta");
        int programa = scanner.nextInt();
         if(programa == 1){
            // Rotar
            scanner = new Scanner(System.in);
            System.out.println("Ingrese una palabra: ");
            String palabra = scanner.nextLine();
            if(palabra != null)  {
                System.out.println("Ingrese el número de rotaciones: ");
                int rotaciones = scanner.nextInt();

                if (rotaciones < 0) {
                    return;
                }
                String resultadoRotacion = Rotar.rotar(palabra, rotaciones);
                System.out.println("Resultado de la rotación: " + resultadoRotacion);
            } else {
                return;
            }

        } else if(programa == 2) {
            // Producto por transpuesta
            scanner = new Scanner(System.in);
            System.out.println("Ingrese el tamaño de la matriz cuadrada: ");
            int n = scanner.nextInt();

            System.out.println("Ingrese los elementos de la matriz:");
            double[][] matriz = new double[n][n];
            for (int i = 0; i < n; i++) {
                 for (int j = 0; j < n; j++) {
                      matriz[i][j] = scanner.nextDouble();
                }
            }

            if (matriz == null) {
                return;
            }

            System.out.println("La matriz dada es:");
            for (double[] row : matriz) {
                for (double elem : row) {
                    System.out.print(elem + " ");
                }
                System.out.println();
            }

            double[][] resultadoProducto = ProductoPorTranspuesta.productoPorTranspuesta(matriz);
            System.out.println("Resultado del producto por transpuesta: ");
            for (double[] row : resultadoProducto) {
                for (double elem : row) {
                    System.out.print(elem + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("Opción inválida");
        }
    }
}
