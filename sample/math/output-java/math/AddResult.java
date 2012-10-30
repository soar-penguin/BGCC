package math;

public enum AddResult {

    E_SUCCESS(0, "AddResult::E_SUCCESS"),

    E_OVERFLOW(1, "AddResult::E_OVERFLOW"),

    E_DOWNFLOW(2, "AddResult::E_DOWNFLOW");

    private final int value;

    private final java.lang.String desc;

    private AddResult(int value, java.lang.String desc) {
        this.value = value;
        this.desc = desc;
    }

    public int getValue() {
        return value;
    }

    public java.lang.String getDescription() {
        return desc;
    }

    public static AddResult findByValue(int value) {
        for (AddResult temp : AddResult.values()) {
            if (value == temp.getValue()) {
                return temp;
            }
        }
        return null;
    }

}

