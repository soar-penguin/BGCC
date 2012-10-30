package math;

public enum Color {

    RED(0, "Color::RED"),

    GREEN(1, "Color::GREEN"),

    BLUE(2, "Color::BLUE");

    private final int value;

    private final java.lang.String desc;

    private Color(int value, java.lang.String desc) {
        this.value = value;
        this.desc = desc;
    }

    public int getValue() {
        return value;
    }

    public java.lang.String getDescription() {
        return desc;
    }

    public static Color findByValue(int value) {
        for (Color temp : Color.values()) {
            if (value == temp.getValue()) {
                return temp;
            }
        }
        return null;
    }

}

