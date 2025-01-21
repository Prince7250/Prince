public class data_type {
    public static void main(String[] args){
        // Integer data type
        int a = 5;
        int b = 42;
         b = 8;
         final int c = 5;
        System.out.println((a+b)-c);
    
        // Float data type
        // by default floating point literals are double in java thats why we use 'f' to specify the float literal

        float d = 8.33f;
        float e = 9.43f;
        System.out.println(d+e);

        // Double data type
        double f = 23.33;
        double t = 2.5;
        System.out.println(f+t);

        // Char data type
        char x = 'P';
        char y = '4';
        System.out.println(x+y);

        //string data type
        String name = "Prince";
        System.out.println(name);

        // Boolean data type
        boolean m = true;
        boolean n = false;
        System.out.println(m);
    }
}
