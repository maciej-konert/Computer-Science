import java.util.Arrays;

public class Sito {
    public static void Symulacja(int n) {
        System.out.println("Liczby pierwsze mniejsze od " + n + " to:");
        boolean[] tab = new boolean[n];
        Arrays.fill(tab, true);
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (tab[i])
                for (int j = 2 * i; j < tab.length; j += i) {
                    tab[j] = false;
                }
        }
        for (int ind = 2; ind < tab.length; ind++) {
            if (tab[ind])
                System.out.println(ind);
        }
    }
