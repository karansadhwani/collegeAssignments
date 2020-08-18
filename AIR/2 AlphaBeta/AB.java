import java.io.*; 
import java.util.Scanner;
  
class AB { 
  
// Initial values of  
// Aplha and Beta 
static int MAX = 1000; 
static int MIN = -1000; 
  
// Returns optimal value for 
// current player (Initially called 
// for root and maximizer) 
static int minimax(int depth, int nodeIndex,  
                   Boolean maximizingPlayer, 
                   int values[], int alpha, 
                   int beta,int h) 
{ 
    // Terminating condition. i.e  
    // leaf node is reached 
    if (depth == h) 
        return values[nodeIndex]; 
  
    if (maximizingPlayer) 
    { 
	int best = MIN; 
  
        // Recur for left and 
        // right children 
        for (int i = 0; i < 2; i++) 
        { 
            int val = minimax(depth + 1, nodeIndex * 2 + i, 
                              false, values, alpha, beta,h); 
            best = Math.max(best, val); 
            alpha = Math.max(alpha, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        return best; 
    } 
    else
    { 
        int best = MAX; 
  
        // Recur for left and 
        // right children 
        for (int i = 0; i < 2; i++) 
        { 
              
            int val = minimax(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta,h); 
            best = Math.min(best, val); 
			beta = Math.min(beta, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        return best; 
    } 
} 

static int log2(int n)
{
return (n==1)?0:1+log2(n/2);
}
  
    // Driver Code 
    public static void main (String[] args) 
    { Scanner sc=new Scanner(System.in);
	System.out.println("Enter the size");
	int n=sc.nextInt();
	int values[]=new int [n];
	int h=log2(n);
	for(int i=0;i<n;i++)
	{
          
        values[i] = sc.nextInt();
	}		
        System.out.println("The optimal value is : " + 
                            minimax(0, 0, true, values, MIN, MAX,h)); 
      
    } 
} 
  