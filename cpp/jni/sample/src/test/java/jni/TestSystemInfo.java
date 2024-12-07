package jni;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class TestSystemInfo {
    @Test
    public void testSystemInfo() {
        System.out.println(SystemInfo.getMemoryInfo());
    }
}
