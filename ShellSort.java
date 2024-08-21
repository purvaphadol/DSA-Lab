/*
Que. Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data structure with modularity of programming language.
*/

import java.io.*;
import java.util.Scanner;

class ShellSort 
{    
    static int num[]= new int[10];
    static int total=0;
    
    public static void getarray()
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter total no. of elements : ");
        total=s.nextInt();
        System.out.print("Enter elements : ");
        for (int i=0;i<total; i++)
        {
            num[i]=s.nextInt();
        }
    }
    
    public static void displayarray()
    {
        System.out.println("\nSoreted array is");
        for (int i=0; i<total; i++)
        {
            System.out.print("\t" + num[i]);
        }
        System.out.println();
    }
    
    public static void shell()
    {
        int count=0;
        int gap;
        
        for (gap=total/2; gap>0; gap=gap/2)
        {
            for (int i=gap; i<total; i++)
            {
                for (int j=i-gap; j>=0; j=j-gap)
                {
                    if (num[j] > num[j+gap])
                    {
                        int temp=num[j];
                        num[j]=num[j+gap];
                        num[j+gap]=temp;
                    }
                    
                }
                System.out.print("Pass : " + (++count) + " : " );
                for (int k=0; k<total; k++)
                {
                    System.out.print(num[k]+ " ");
                }
                System.out.println(" ");
            }
        }
        displayarray();
    }
    
    public static void heapify(int n, int j)
    {
        int largest=j;
        int l=2*j+1;
        int r=2*j+2;
        
        if (l<n && num[l] > num[largest])
        {
            largest=l;
        }
        if (r<n && num[r] > num[largest])
        {
            largest=r;
        }
        
        if (largest != j)
        {
            int temp=num[j];
            num[j]=num[largest];
            num[largest]=temp;
            heapify(n,largest);
        }
    }
    
    public static void heapsort()
    {
        int count=0;
        for (int i=total/2-1; i>=0; i--)
        {
            heapify(total,i);
        }
        
        for (int i=total-1; i>=0; i--)
        {
            int temp=num[0];
            num[0]=num[i];
            num[i]=temp;
            heapify(i,0);
            System.out.print("Pass : " + (++count) + " : " );
            for (int k=0; k<total; k++)
            {
                System.out.print(num[k]+ " ");
            }
            System.out.println();
        }
        displayarray();
    }
    
    public static void main(String args[]) 
    {
        
        int ch;
        getarray();
        
        do
        {
            Scanner s = new Scanner(System.in);
            System.out.println("\t--------------");
            System.out.println("\t1.Shell Sort \n\t2.Heap Sort \n\t3.Exit");
            System.out.println("\t--------------");
            System.out.print("Enter your choice : ");
            ch=s.nextInt();
            
            switch(ch)
            {
                case 1:
                    System.out.println("---SHELL SORT---");
                    shell();
                    break;
                    
                case 2:
                    System.out.println("---HEAP SORT---");
                    heapsort();
                    break;
                    
                case 3:
                    System.out.println("Exit");
                    break;
                    
                default:
                    System.out.println("Invalid choice\n");
                    break;
            }
        }
        while (ch!=3);
    }
}

/*
OUTPUT
Enter total no. of elements : 8
Enter elements : 87
89
78
67
80
7
23
5
        --------------
        1.Shell Sort
        2.Heap Sort
        3.Exit
        --------------
Enter your choice : 1
---SHELL SORT---
Pass : 1 : 80 89 78 67 87 7 23 5
Pass : 2 : 80 7 78 67 87 89 23 5  
Pass : 3 : 80 7 23 67 87 89 78 5
Pass : 4 : 80 7 23 5 87 89 78 67
Pass : 5 : 23 7 80 5 87 89 78 67
Pass : 6 : 23 5 80 7 87 89 78 67
Pass : 7 : 23 5 80 7 87 89 78 67
Pass : 8 : 23 5 80 7 87 89 78 67
Pass : 9 : 23 5 78 7 80 89 87 67
Pass : 10 : 23 5 78 7 80 67 87 89
Pass : 11 : 5 23 78 7 80 67 87 89
Pass : 12 : 5 23 78 7 80 67 87 89
Pass : 13 : 5 7 23 78 80 67 87 89
Pass : 14 : 5 7 23 78 80 67 87 89  
Pass : 15 : 5 7 23 67 78 80 87 89
Pass : 16 : 5 7 23 67 78 80 87 89
Pass : 17 : 5 7 23 67 78 80 87 89

Soreted array is
        5       7       23      67      78      80      87      89
        --------------
        1.Shell Sort
        2.Heap Sort
        3.Exit
        --------------
Enter your choice : 2
---HEAP SORT---
Pass : 1 : 87 78 80 67 5 7 23 89
Pass : 2 : 80 78 23 67 5 7 87 89
Pass : 3 : 78 67 23 7 5 80 87 89
Pass : 4 : 67 7 23 5 78 80 87 89
Pass : 5 : 23 7 5 67 78 80 87 89
Pass : 6 : 7 5 23 67 78 80 87 89 
Pass : 7 : 5 7 23 67 78 80 87 89
Pass : 8 : 5 7 23 67 78 80 87 89

Soreted array is
        5       7       23      67      78      80      87      89
        --------------
        1.Shell Sort
        2.Heap Sort
        3.Exit
        --------------
Enter your choice : 4
Invalid choice

        --------------
        1.Shell Sort
        2.Heap Sort
        3.Exit
        --------------
Enter your choice : 3
Exit
*/
