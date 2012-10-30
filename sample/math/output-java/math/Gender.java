package math;

public enum Gender {

    MALE(0, "Gender::MALE"),

    FEMALE(1, "Gender::FEMALE");

    private final int value;

    private final java.lang.String desc;

    private Gender(int value, java.lang.String desc) {
        this.value = value;
        this.desc = desc;
    }

    public int getValue() {
        return value;
    }

    public java.lang.String getDescription() {
        return desc;
    }

    public static Gender findByValue(int value) {
        for (Gender temp : Gender.values()) {
            if (value == temp.getValue()) {
                return temp;
            }
        }
        return null;
    }

}

