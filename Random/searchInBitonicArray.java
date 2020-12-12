import java.util.Scanner;
import java.util.Arrays;
// import java.math.*;

import javax.lang.model.util.ElementScanner14;

public class searchInBitonicArray {
    
    public static int searchLargest(int[] numbers, int start, int end)
    {
        int middle, left, right, half;
        half = (int)Math.floor((start+end)/2);
        if (start == end)
            return start;
        else if (end == start+1)
        {
            if (numbers[start] > numbers[end])
                return start;
            else
                return end;
        }
        middle = numbers[half];
        left = numbers[half-1];
        right = numbers[half+1];
        if (left > middle && middle > right)
            return searchLargest(numbers, start, half-1);
        else if (right > middle && middle > left)
            return searchLargest(numbers, half, end);
        else
            return half;
    }


    public static int binarySearch(int[] numbers, int start, int end, int key)
    {
        int half, middle;
        half = (int)(start+end)/2;
        middle = numbers[half];
        if (start > end)
            return -1;
        if (middle == key)
            return half;
        else if (middle > key)
            return binarySearch(numbers, start, half-1, key);
        else
            return binarySearch(numbers, half+1, end, key);
    }


    public static int revBinarySearch(int[] numbers, int start, int end, int key)
    {
        int half, middle;
        half = (int)(start+end)/2;
        middle = numbers[half];
        if (start > end)
            return -1;
        if (middle == key)
            return half;
        else if (middle > key)
            return revBinarySearch(numbers, half+1, end, key);
        else
            return revBinarySearch(numbers, start, half-1, key);
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] numbers = Arrays.stream(sc.nextLine().split(", ")).mapToInt(Integer::parseInt).toArray();
        int key, ind;
        key = sc.nextInt();
        int largest = searchLargest(numbers, 0, numbers.length-1);
        System.out.println(largest);
        ind = binarySearch(numbers, 0, largest, key);
        if (ind == -1)
            ind = revBinarySearch(numbers, largest, numbers.length-1, key);
        System.out.println(ind);
    }
}
