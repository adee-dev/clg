
/*Name: Aaishwarya Darandale

Roll no.: 71

Title: Interfaces and Packages

Problem statement: G 27 
Write a Java program which will demonstrate a concept of Interfaces and packages: In this assignment design and 
use of customized interfaces and packages for a specific application are expected.*/


package pack3;

public interface RBI1
{
	int getint();
	 void bankname();
}package pack1;

import pack3.*;

	public class SBI1 implements RBI1
	{
		public void bankname()
		{
			System.out.println("SBI");
		}
		
		public int getint()
		{
			return 8;
		}
		
	}
package pack2;

import pack3.*;

class HDFC1 implements RBI1
{
	public void bankname()
	{
		System.out.println("HDFC");
	}
	public int getint()
	{
		return 4;
	}
}
package javapro;
import pack1.*;



public class Test {

	public static void main(String[] args) {
		
		SBI1 o=new SBI1();
		o.bankname();
		System.out.println("Interest= "+ o.getint());
		
		
		
		
	}

}
