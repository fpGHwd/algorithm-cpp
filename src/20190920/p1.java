public class Main {
    public boolean checkNumber(String s){
        if(s.length() < 11 )return false;
        else{
            if(s.indexOf('8')!=-1 && s.indexOf('8') <= s.length()-11)
                return true;
            else
                return false;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String nStr = sc.nextLine(),lenStr;
        int n = Integer.valueOf(nStr), len;
        String str;

        String s;

        Main m = new Main();

        for(int i = 0; i < n; i++){
            lenStr = sc.nextLine();
            len = Integer.valueOf(lenStr);
            str = sc.nextLine();
            if(len < 11)System.out.println("NO");
            else
                if(m.checkNumber(str))
                    System.out.println("YES");
                else
                    System.out.println("NO");
        }
    }
}
