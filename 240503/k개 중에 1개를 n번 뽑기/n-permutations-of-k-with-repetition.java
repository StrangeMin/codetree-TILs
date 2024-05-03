import java.util.*;
import java.io.*;

public class Main {
    public static int K,N;

    public static void go(int index, List<Integer> b){
        if(index == N){
            
            for(int i=0; i<b.size(); i++){
                System.out.print(b.get(i) + " ");
            }
            System.out.println();
            return;
        }

        for(int i=1; i<=K; i++){
            b.add(i);
            go(index + 1, b);
            b.remove(b.size()-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();

        List<Integer> b = new ArrayList<>();
        go(0, b);
    }
}