/*NAME: Aaishwarya Darandale

ROLL NO: 71
Problem statement :G29
Write a program on template and exception handling in Java: in this assignment multiple templates are to be designed as a pattern and these patterns to be used to take decisions.*/



package exceptionhandling;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class Exceptiondemo {

	public  void add( )
	{
		int a=5,b=0,c;
		c=a/b;
		System.out.print("addition is:"+c);
	}
	public void array()
	{
           int a[]={1,2,3,4,5};
		for(int i=0;i<50;i++)
		{
		System.out.println(a[i]);
		}
		
	}
	
	public static void main(String[] args) {
		Exceptiondemo a=new Exceptiondemo();
		try
		{
			a.add();
		}
		catch(ArithmeticException e)
		{
			System.out.println("caught an exception in case of divide by zero");
		}
		try
		{
			a.array();
		}
		catch(ArrayIndexOutOfBoundsException x)
		{
			System.out.println("caught an exception in case of array out of bounds");
		}
		
		finally
		{
			
		}
		
	}

}
