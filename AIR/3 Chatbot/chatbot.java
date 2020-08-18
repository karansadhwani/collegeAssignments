//package chatbot;


import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.lang.*;

//// run in eclipse 

public class chatbot
{

	
	Map<String,String>nouns=new HashMap<String, String>();
	Map<String,String>welcome=new HashMap<String, String>();
	Map<String,String>farewell=new HashMap<String, String>();

	
	public chatbot()
	{
		
		welcome.put("hii","Welcome! How can I help you??");
		welcome.put("hey","hey,how I can help you??");
		welcome.put("hello","hello,How can I help you??");
		welcome.put("Thank U", "Welcome");
		
		farewell.put("bye","bye");
		farewell.put("bbye","bbye");
		farewell.put("exit","exit");
		
		
	}
	
	public static void main(String[] args)
	{
		
		Scanner s=new Scanner(System.in);
		chatbot c=new  chatbot();
		
		while(true)
		{
			String input=s.nextLine();
			
			String output=c.giveans(input);
			
			System.out.println(output);
			
			if(output=="exit")
			{
				System.exit(0);
			}
			
			
			
		}
	}
	public String giveans(String input)
	{
		//  \\s means split for one or more whitespaces
		
		String tokens[]=input.split("\\s");
		
		
		for(int i=0;i<tokens.length;i++)
		{
		
			if(welcome.containsKey(tokens[i].toLowerCase()))
			{
				return welcome.get(tokens[i]);
				
			}
			else if(farewell.containsKey(tokens[i].toLowerCase()))
			{
				return farewell.get(tokens[i]);
			}
			else if(nouns.containsKey(tokens[i].toLowerCase()))
			{
				return nouns.get(tokens[i]);
				
			}
			
		}
		
		return ("I am sorry. I don't get this.");		
		
	}

}
