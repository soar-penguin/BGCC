package math;
import java.util.*;
import java.lang.*;
public final class tt3 {
    public static final Map<List<Integer>, Set<String>> value = create();

    private static Map<List<Integer>, Set<String>> create() {
        Map<List<Integer>, Set<String>> tmp_var17 = new HashMap<List<Integer>, Set<String>>();

        List<Integer> tmp_var18 = new ArrayList<Integer>();

        tmp_var18.add(1);

        Set<String> tmp_var19 = new HashSet<String>();

        tmp_var19.add("first");

        tmp_var17.put(tmp_var18, tmp_var19);
        List<Integer> tmp_var20 = new ArrayList<Integer>();

        tmp_var20.add(2);

        Set<String> tmp_var21 = new HashSet<String>();

        tmp_var21.add("second");

        tmp_var17.put(tmp_var20, tmp_var21);

        return tmp_var17;
    }
}

