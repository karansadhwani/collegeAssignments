/*
Pr No: 13
Title: Write a program on template and exception handling in Java: in this assignment multiple templates are to be designed as a pattern and these patterns to be used to take decisions.
*/

import java.io.*;
import java.util.*;



public class Pr_13ABCD
{
                           // generic method printArray   
                          
   public static < E > void printArray( E[] inputArray ) 
   {
                        // Display array elements
      for(E element : inputArray) 
      {
         System.out.printf("%s ", element);
      }
      System.out.println();
   } 

   public static void main(String args[]) 
   {
             //Template Demonstration:-------------
      
      System.out.println("\n Template Demonstration: -------------");
      
                  // Create arrays of Integer, Double and Character
      Integer[] intArray = { 1, 2, 3, 4, 5 };
      Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
      Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };

      System.out.println("Array integerArray contains:");
      printArray(intArray);   // pass an Integer array

      System.out.println("\nArray doubleArray contains:");
      printArray(doubleArray);   // pass a Double array

      System.out.println("\nArray characterArray contains:");
      printArray(charArray);   // pass a Character array
      
      
      
      
               //Exception Demonstration:-------------
      
      System.out.println("\n Exception Demonstration: -------------");
      
      try 
      {
            int ary[] = {1,2,3,4,5};
            ary[6] = 999;            // cannot divide by zero
            System.out.println ("Result = " + ary[6]);
      }
      catch(ArrayIndexOutOfBoundsException e)
      {
            System.out.println ("Exception: Array index Out of bound !!!"+e);
      }
      
      int a = 30, b = 0;
      int c = a/b;
      System.out.println ("Result = " + c);
      
      
      
   }
}


/*
student@IOE-L1LAB:~$ javac Pr_13ABCD.java
student@IOE-L1LAB:~$ java Pr_13ABCD

 Template Demonstration: -------------
 
Array integerArray contains:
1 2 3 4 5 

Array doubleArray contains:
1.1 2.2 3.3 4.4 

Array characterArray contains:
H E L L O 

 Exception Demonstration: -------------
 
Exception: Array index Out of bound !!!

Exception in thread "main" java.lang.ArithmeticException: / by zero
	at Pr_13ABCD.main(Pr_13ABCD.java:64)
student@IOE-L1LAB:~$ 
*/
