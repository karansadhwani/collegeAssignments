/*
Pr No: 11
Title: Any application defining scope of Formal parameter, Global parameter, Local parameter accessing mechanism and also relevance to private, public and protected access. Write a Java program which demonstrates the scope rules of the programming mechanism.
*/

class Scope_demo
{
   private:
         int a, b;
   
   protected: 
              Scope_demo()
              {
                 a = 10;
                 b = 20;
              }
              int minus()
              {
                  return a - b;  //Scope of Private Members
              }
   
   public  void showab()
           {
              System.out.println("\n\t a is: "+a);
              System.out.println("\n\t b is: "+b);              
           } 
           int add()
           {
              return a + b;   //Scope of Private Members
           }   
}

class derived extends Scope_demo
{
    void show()
    {                   //Scope of Protected & Public Members...
       System.out.println("\n Addition of (a+b) : "+add());
       System.out.println("\n Substraction of (a-b) : "+minus());
    }
}

public class Pr_11ABCD
{
   public static void main(String args[])
   {
      Scope_demo Obj1 = new Scope_demo(); 
      derived Obj2 = new derived();
      
      Obj1.showab();    //Scope of Public Members...
      Obj2.show();      //Scope of Public Members...
       
      System.out.println("\n");      
   }
}

/*
student@IOE-L1LAB:~$ javac Pr_11ABCD.java
student@IOE-L1LAB:~$ java Pr_11ABCD

	 a is: 10

	 b is: 20

 Addition of (a+b) : 30

 Substraction of (a-b) : -10


student@IOE-L1LAB:~$ 

*/





















