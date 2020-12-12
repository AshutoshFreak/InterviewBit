import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
import java.lang.Math;
import java.util.List;
import java.util.stream.Collectors;


public class WoodCuttingMadeEasy {
    public static void main(String[] args) {
        int i, target;
        int height_reached = 0;
        int wood = 0;

        Scanner sc = new Scanner(System.in);
        List<Integer> heights = Arrays.stream(sc.nextLine().split(", ")).mapToInt(Integer::parseInt).boxed().collect(Collectors.toList());
        target = sc.nextInt();

        Collections.sort(heights);
        Collections.reverse(heights);
        // System.out.println(heights);

        for(i=1; i <= heights.size()-1; i++)
        {
            wood += (heights.get(i-1) - heights.get(i))*i;
            height_reached += heights.get(i-1) - heights.get(i);
            if(wood >= target)
            {
            //     System.out.println(wood);
            //     System.out.println(i);
            //     System.out.println(height_reached);
                height_reached -= (wood-target)/i;
                // System.out.println(height_reached);
                // height_reached = (int) Math.ceil(target/i);
                break;
            }
        }
        height_reached = heights.get(0) - height_reached;
        System.out.println(height_reached);
    }
}
