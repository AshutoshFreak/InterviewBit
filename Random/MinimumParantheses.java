import java.util.Scanner;
public class MinimumParantheses {
    
    public static int solve(String s)
    {
        int stack = 0;
        int i;
        int count = 0;
        for(i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(')
                stack += 1;
            else
                stack -= 1;
            if(stack == -1)
            {
                stack = 0;
                count += 1;
            }
        }
        count += stack;
        return count;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(solve(s));
    }
}
