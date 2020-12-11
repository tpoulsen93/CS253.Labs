class Int { int val; Int(int i) { val=i; }}

public class T {
    public static void swap(Int x, Int y) {
	int t=y.val;
	y.val=x.val;
	x.val=t;
    }
    public static void main(String[] args) {
	Int x=new Int(1);
	Int y=new Int(2);
	System.out.println(x.val+" "+y.val);
	swap(x,y);
	System.out.println(x.val+" "+y.val);
    }
}

	
				     
