package math;
import java.util.*;
import java.lang.*;
public final class tt1 {
    public static final List<Set<Integer>> value = create();

    private static List<Set<Integer>> create() {
        List<Set<Integer>> tmp_var5 = new ArrayList<Set<Integer>>();

        Set<Integer> tmp_var6 = new HashSet<Integer>();

        tmp_var6.add(1);

        tmp_var5.add(tmp_var6);
        Set<Integer> tmp_var7 = new HashSet<Integer>();

        tmp_var7.add(2);

        tmp_var5.add(tmp_var7);
        Set<Integer> tmp_var8 = new HashSet<Integer>();

        tmp_var8.add(3);

        tmp_var5.add(tmp_var8);

        return tmp_var5;
    }
}

