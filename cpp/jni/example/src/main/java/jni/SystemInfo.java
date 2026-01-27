package jni;

public class SystemInfo {
    static {
        System.loadLibrary("system_info");
    }

    public native static String getMemoryInfo();
}
