// https://www.interviewbit.com/problems/remove-consecutive-characters/

import java.util.Scanner;
public class removeConsecutiveCharacters {
    public static String solve(String s, int n)
    {
        int i, j;
        int count;
        char curr;
        String result = "";
        for(i = 0; i < s.length();)
        {
            curr = s.charAt(i);
            count = 0;
            for(;i < s.length() && s.charAt(i) == curr; i++)
                count += 1;
            if(count != n)
            {
                for(j = 0; j < count; j++)
                    result += s.charAt(i-1);
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = sc.nextInt();
        System.out.println(solve(s, n));
    }
}
