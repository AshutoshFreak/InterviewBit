import java.util.Scanner;
class ConvertToPalindrome
{
    public static int solve(String s)
    {
        int l = (int) s.length()/2;
        boolean changed = false;
        int i = 0;
        int j = s.length()-1;
        for(; j > i; i++,j--)
        {
            if (s.charAt(i) != s.charAt(j))
            {
                if(changed == false)
                {
                    if(s.charAt(i+1) == s.charAt(j))
                        i++;
                    else if(s.charAt(i) == s.charAt(j-1))
                        j++;
                    else
                    {
                        // System.out.println("Statement1");
                        return(0);
                    }
                    changed = true;
                    // System.out.println(i);
                    // System.out.println(j);
                }
                else
                {
                    // System.out.println("Statement2");
                    return(0);
                }
            }
        }
        if(changed == true)
        {
            // System.out.println("Statement3");
            return(1);
        }
        else
        {
            if (s.length() % 2 == 0)
            {
                // System.out.println("Statement4");
                return(0);
            }
            else
            {
                // System.out.println("Statement5");
                return(1);
            }
        }
    } 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(solve(s));
    }
}