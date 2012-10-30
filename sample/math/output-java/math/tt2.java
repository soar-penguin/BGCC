package math;
import java.util.*;
import java.lang.*;
public final class tt2 {
    public static final Set<List<String>> value = create();

    private static Set<List<String>> create() {
        Set<List<String>> tmp_var13 = new HashSet<List<String>>();

        List<String> tmp_var14 = new ArrayList<String>();

        tmp_var14.add("first");

        tmp_var13.add(tmp_var14);
        List<String> tmp_var15 = new ArrayList<String>();

        tmp_var15.add("second");
        tmp_var15.add("third");

        tmp_var13.add(tmp_var15);

        return tmp_var13;
    }
}

