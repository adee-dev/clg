/*NAME: Aaishwarya Darandale

ROLL NO: 71
Problem statement : G26
Any application defining scope of Formal parameter, Global parameter, Local parameter accessing mechanism and 
also relevance to private, public and protected access.
Write a Java program which demonstrates the scope rules of the programming mechanism.*/


package AccessDemo;

public class Class1 {
	public int a=1;
	private int b =2;
	protected int c =3;
	int d=4;
	public static void main(String[] args) {
		Class1 c = new Class1();
		
		System.out.println("In same class: \n"+c.a+c.b+c.c+c.d);
	}
}
package AccessDemo;

public class SubClass extends Class1{
public static void main(String[] args) {
	Class1 ob = new Class1();
	System.out.println("In sub class: \n"+ ob.a +ob.c+ ob.d );
	System.out.println("Private access not allowed in sub class");
}
}
package pack2;

import AccessDemo.Class1;

public class PackClass {
	public static void main(String[] args) {
		Class1 ob = new Class1();
		System.out.println("In different package [Not subclass]\n"+ob.a);
		System.out.println("Only public access allowed");
	}
	
	
}
package pack2;

import AccessDemo.Class1;

public class PackSubClass extends Class1{
 public static void main(String[] args) {
	
	 Class1 ob = new Class1();
	 System.out.println("In other package's subclass\n"+ob.a);
	 System.out.println("Only public allowed");
}
	
 
}
