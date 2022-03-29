/*NAME: Aaishwarya Darandale

ROLL NO: 71
Problem statement :G28
Write a Java program which will demonstrate a concept of cohesion and coupling of the various modules in the program. */



package exceptionhandling;

public class CohesionCoupling <T> {

	public void swaping(T a,T b)
	{
		System.out.println("before swapping a="+a+"  b="+b);
		T temp;
		temp=a;
		a=b;
		b=temp;
		System.out.println("After swapping a="+a+" b="+b);
	}
	public static void main(String[] args)
	{
		//for integer
		CohesionCoupling <Integer> x=new    CohesionCoupling <>();
		x.swaping(45, 60);
		
		//for float
		CohesionCoupling <Float> y=new CohesionCoupling <>();
	 	y.swaping(45.55f, 69.33f);


	 	CohesionCoupling <String> z=new CohesionCoupling <>();
	 	z.swaping("sourabh", "khaire");
	}
}


