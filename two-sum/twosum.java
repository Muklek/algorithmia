import java.util.HashMap;

// problem statement at twosum.cpp

static int[] findPairs(int[] numberList, int numToEqual){
    HashMap<int, int> = dict new Hashmaps<>();
    for(int number : numberList){
        int calc = numToEqual - number;
        if(dict.containsKey(calc)){
            return new int[]{dict.get(calc), number};
        }
        dict.put(calc, number);
    }
}

public static main(String[] args){
    int[] numbers{1,2,3,4,5,6};
    int[] solution = findPairs(numbers, 5);
    System.out.println(solution);
}
