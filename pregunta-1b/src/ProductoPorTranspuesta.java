public class ProductoPorTranspuesta {
    public static double[][] productoPorTranspuesta(double[][] A) {
        if (A == null) {
            System.out.println("La matriz no puede ser nula");
            return null;
        }

        // A.length es el número de filas
        for (double[] row : A) {
            if (row.length != A.length) {
                System.out.println("La matriz debe ser cuadrada");
                return null;
            }
        }

        // Declaramos la matriz resultado
        double[][] B = new double[A.length][A.length];
        // Calculamos el producto por transpuesta
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                // Inicializamos B[i][j] a 0
                B[i][j] = 0;
                // B[i][j] = A[i] * A[j]^T = sum_k A[i][k] * A^T[k][j] = sum_k A[i][k] * A[j][k]
                for (int k = 0; k < A.length; k++) {
                    B[i][j] += A[i][k] * A[j][k];
                }
            }
        }
        return B;
    }
}
