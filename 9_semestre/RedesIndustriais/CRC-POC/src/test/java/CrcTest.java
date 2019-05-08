import org.junit.Test;

public class CrcTest {
    public Crc crc = new Crc();

    @Test
    public void crcTestArray() {
        System.out.println(crc.addCrcToMessage("ola"));
    }
}
