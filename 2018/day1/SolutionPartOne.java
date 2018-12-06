import java.io.*;

class SolutionPartOne {

  public static void main(String[] args) {
    File file = new File(args[0]);

    String input = null;
    int frequency = 0;
    try {
      BufferedReader br = new BufferedReader(new FileReader(file));
      while ((input = br.readLine()) != null) {
        if (input.charAt(0) == '+') {
          frequency += Integer.parseInt(input.substring(1));  
        }
        else {
          frequency -= Integer.parseInt(input.substring(1));  
        }
      }
    } catch (FileNotFoundException e) {
      System.out.println(args[0] + "does not exist!");
    } catch (IOException e) {
      System.out.println("Something went wrong while reading!");
      System.out.println("Error Message:");
      System.out.println(e.getStackTrace());
    }
    System.out.println(String.format("Frequency %d", frequency)); 
  }

}
