public class array {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5};
        int start = 0;
        int end = arr.length - 1;
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i] + " ");
        }
        // int[] arr = { 1, 2, 3, 4, 5, 6 };
        // int value = 0;
        // int index = 2; // Example index
        // for (int i = arr.length - 1; i >= index; i--) {
        // arr[i] = arr[i - 1];
        // }
        // arr[index] = value;
        // for (int i = 0; i < arr.length; i++) {
        // System.out.println(arr[i]);
        // }
    }
}
