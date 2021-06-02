package jssc;

import org.junit.Ignore;
import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.not;
import static org.hamcrest.CoreMatchers.nullValue;
import static org.junit.Assert.assertThat;
import static org.junit.Assert.fail;

public class SerialNativeInterfaceTest {


    @Test
    @Ignore("Cannot run this test, as we have no lib for windoof and there's also no tty on windoof.")
    public void testInitNativeInterface() {
        SerialNativeInterface serial = new SerialNativeInterface();

        long handle = -1;
        try {
            handle = serial.openPort("ttyS0",false);
            assertThat(handle, is(not(-1L)));
        } finally {
            if (handle != -1) {
                serial.closePort(handle);
            }
        }
    }

    @Test
    @Ignore("Cannot run this test, as we have no lib for windoof.")
    public void testPrintVersion() {
        try {
            final String nativeLibraryVersion = SerialNativeInterface.getNativeLibraryVersion();
            assertThat(nativeLibraryVersion, is(not(nullValue())));
            assertThat(nativeLibraryVersion, is(not("")));
        } catch (UnsatisfiedLinkError linkError) {
            linkError.printStackTrace();
            fail("Should be able to call method!");
        }

    }

}
