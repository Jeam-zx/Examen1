public class Rotar {
    public static String rotar(String w, int k) {
        if (w == null || k < 0) {
            System.out.println("La cadena no puede ser nula y el número de rotaciones no puede ser negativo");
            return null;
        }

        // Caso base
        if (k == 0 || w.isEmpty()) return w;
        // Caso recursivo
        return rotar(w.substring(1) + w.charAt(0), k - 1);
    }
}
