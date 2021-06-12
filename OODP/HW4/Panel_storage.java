// use the singleton pattern

import java.awt.*;
import java.util.HashMap;
import java.util.Map;

public class Panel_storage {
    private Map<Integer, Solar_panel> storage = new HashMap<Integer, Solar_panel>();
    private static Panel_storage panel_storage = new Panel_storage();

    // constructor
    private Panel_storage() {};

    // return the instance
    public static Panel_storage getInstance() {
        return panel_storage;
    }

    Solar_panel lookup(int capacity) {
        if(!storage.containsKey(capacity)) {
            storage.put(capacity, new Solar_panel(0, capacity));
            System.out.println("Making a New Solar Panel : " + capacity + " KW Panel");
        }
        return storage.get(capacity);
    }
}
