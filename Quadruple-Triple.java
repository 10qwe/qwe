import java.util.*;

public class QuadTrip {
	public static void qQuadruple (String expression[]) {
		System.out.println("op\targ1\targ2\tresult");
		for (int i=0;i<expression.length;i++) {
			String[] expR= expression[i].split("");
			System.out.println(expR[3]+"\t"+expR[2]+"\t"+expR[4]+"\t"+expR[0]);
			
		}
	}
	
	public static void tTriple (String expression[]) {
		System.out.println("op\targ1\targ2");
		for (int i=0;i<expression.length;i++) {
			String[] expR= expression[i].split("");
			System.out.println(expR[3]+"\t"+expR[2]+"\t"+expR[4]);
			
		}
	}
	
	public static void main (String arg[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no of expressions: ");
		int n=sc.nextInt();
		System.out.println("Enter the expressions: ");
		sc.nextLine();
		String exp[]=new String[n];
		for(int i=0;i<n;i++) {
			exp[i]=sc.nextLine();
		}
		
		System.out.println("\n\n\tQuadruples");	
		System.out.println();
		qQuadruple(exp);
		System.out.println("\n\n\tTriple");	
		System.out.println();
		tTriple(exp);
		
	}
}
