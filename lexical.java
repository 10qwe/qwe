import java.util.Scanner;
class lexical {


    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
          System.out.println("\nLEXICAL ANALYSER: \n\nENTER INPUT:");


            // Line input & splitting into string array
            String str = sc.nextLine();
            String[] arrString = str.split(" ");
            String[] output = new String[arrString.length];
            String[] noun = new String[arrString.length];


            // count for nouns, total tokens
            int count = 0, index = 0, tokens = 0;


// Check if line begins with "If", then execute else terminate code
            if (arrString[0].equals("If")) {
                for (int i = 0; i < arrString.length; i++) {


                    // Checking for keyword
         if (arrString[i].equals("If") || arrString[i].equals("then")) {
                        output[i] = "(k)";
                        tokens++;
                    }


                    // Checking for verb
  else if (arrString[i].equals("hate") || arrString[i].equals("like")) {
                        output[i] = "(v)";
                        tokens++;
                    }


                    // Checking for action
                    else if (arrString[i].equals("they")) {
                        output[i] = "(a)";
                        tokens++;
                    }


                    // Checking for end of input line
                    else if (arrString[i].equals("$")) {
                        output[i] = "<eof>";
                        break;
                    }


                    // Checking for nouns
                    else {
                        tokens++;


                        // Searching for dot operator
                        String str1 = arrString[i];
                        int j = str1.indexOf(".");


                        // Removing the dot operator from the string
                        if (j > 0) {
                  str1 = str1.substring(0, j) + str1.substring(j + 1);
                        }


                        // Add first noun encountered to nouns array
                        if (count == 0) {
                            noun[count] = arrString[i];
                            count++;
                            output[i] = "(n," + (count) + ")";
                        } else {


                      // Checking if noun has been encountered before
                            for (int r = 0; r < count; r++) {
                                if (noun[r].equals(str1)) {
                                    output[i] = "(n," + (r + 1) + ")";
                                    index++;
                                }
                            }


                            // Adding new nouns to nouns array
                            if (index == 0) {
                                noun[count] = str1;
                                count++;
                                output[i] = "(n," + (count) + ")";
                            } else {
                                index = 0;
                            }
                        }


                        // Operator in line input
                        if (j != -1) {
                            output[i] = output[i] + "(op)";
                            tokens++;
                        }
                    }
                }
                System.out.println("\nNumber of tokens: " + tokens);
                System.out.println("\nOUTPUT:");
                for (int i = 0; i < output.length; i++) {
                    if (output[i] != null) {
                        System.out.print(output[i]);
                    }
                }


                // Printing of symbol table
                System.out.println("\n\nSYMBOL TABLE:");
                for (int i = 0; i < count; i++) {
                    System.out.print(noun[i] + " ");
                }
                System.out.println();
                for (int i = 0; i < count; i++) {
                    System.out.print(" [" + (i + 1) + "] ");
                }
            } else {
                System.out.println("Wrong Input!!!");
            }
        }
    }
}
