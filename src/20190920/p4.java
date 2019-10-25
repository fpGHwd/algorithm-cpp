import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        SortedSet<Integer> set = new TreeSet<>();
        for (int i = 1; i <= n; i++) {
            set.add(sc.nextInt());
        }

        Iterator<Integer> it = set.iterator();
        int first = 0;
        if (it.hasNext()) {
            first = it.next();
            k--;
        }
        System.out.println(first);
        int prev = first;
        while (it.hasNext() && k > 0){
            int cur = it.next();
            System.out.println(cur - prev);
            prev = cur;
            k--;
        }
        while (k > 0) {
            System.out.println(0);
            k--;
        }
    }
}