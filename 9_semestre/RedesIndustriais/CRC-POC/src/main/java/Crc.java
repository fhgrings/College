
import java.util.ArrayList;

public class Crc {

    private static String KEY = "101";

    private ArrayList<String> key = new ArrayList<>();
    private ArrayList<String> operator = new ArrayList<>();
    private ArrayList<String> messageBitsList = new ArrayList<>();
    private ArrayList<String> result = new ArrayList<>();



    public String addCrcToMessage(String message) {
        return ArrayToString(StringToBitArrayList(message)) + ArrayToString(CalculateCrc(message));

    }



    private ArrayList<String> StringToBitArrayList(String message) {

        byte[] bytes = message.getBytes();
        ArrayList<String> bitMessage = new ArrayList<>();

        for (byte bit : bytes) {
            int value = bit;

            for(int i = 0; i < 8; i++) {
                bitMessage.add(String.valueOf((value & 128) == 0 ? 0 : 1));
                value <<= 1;
            }
        }
        System.out.println("Message Bits: " + bitMessage.toString());

        return bitMessage;
    }

    public String ArrayToString(ArrayList<String> array) {
        StringBuffer result = new StringBuffer();
        for (String caracter : array) {
            result.append(caracter);
        }

        return result.toString();
    }


    private ArrayList<String> TransformKey(String message) {

        ArrayList<String> arrayMessage = new ArrayList<>();
        for (char caracter : message.toCharArray()) {
            arrayMessage.add(Character.toString(caracter));
        }

        return arrayMessage;
    }

    private ArrayList<String> CalculateCrc(String message){
        messageBitsList = StringToBitArrayList(message);
        key = TransformKey(KEY);

        for(int i = 0; i < key.size(); i++){
            if(messageBitsList.size() == 0)
                break;

            operator.add(messageBitsList.get(0));
            messageBitsList.remove(0);
        }

        while(messageBitsList.size() >= 0) {
            result.clear();

            System.out.println("Op: " + operator.toString());
            System.out.println("Key: " + key.toString());

            for(int i = 0; i < key.size(); i++) {
                if(operator.get(i).equals(key.get(i)))
                    result.add("1");
                else
                    result.add("0");
            }
            operator.clear();

            System.out.println("Result: " + result.toString() + "\n\n");

            for (int i  = 0; i < result.size(); i++) {
                operator.add(result.get(i));
            }
            operator.remove(0);


            if(messageBitsList.isEmpty())
                return result;

            operator.add(messageBitsList.get(0));
            messageBitsList.remove(0);
        }

        System.out.println("Operator: " + operator.toString());
        return result;
    }



    public String getMessageFromCrc(String crcMessage) {
        String crcRecieved = crcMessage.substring(crcMessage.length() - KEY.length());
        String messageBits = crcMessage.substring(0,crcMessage.length() - KEY.length());

        byte[] messageBytes = {Byte.parseByte(messageBits, 2)};
        String message = new String(messageBytes);

        String crcCalculated = ArrayToString(CalculateCrc(message));

        if(crcRecieved.equals(crcCalculated))
            System.out.println("CRC Correct");
        else
            System.out.println("CRC Incorrect");


        System.out.println("CRC recieved: " + crcRecieved);
        System.out.println("CRC calculated: " + crcCalculated);
        System.out.println("Message recieved: " + message);


        return message;

    }

}
