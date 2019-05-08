public class App {


    public static void main(String[] args) {

        Crc crc = new Crc();

        System.out.println("Resultado: " + crc.addCrcToMessage("a"));

        crc.getMessageFromCrc(crc.addCrcToMessage("H"));

    }
}