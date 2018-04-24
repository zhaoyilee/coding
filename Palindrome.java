package test.jingdong;

public class Palindrome {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "ABA";
		char[] chars = s.toCharArray();
		// System.out.println(palin(chars,0,chars.length-1));
		System.out.println(palin2(chars));

	}
	
	/**
	 * RECURSION
	 * @param chars
	 * @param p
	 * @param q
	 * @return
	 */
	public static int palin(char[] chars,int p,int q){
		int num = 0;
		if (p<=q){
				if (p==q){
					num = 1;
				}else{
					if (chars[p]==chars[q]){
						num = palin(chars,p+1,q)+palin(chars,p,q-1)+1;
					}else{
						num = palin(chars,p+1,q)+palin(chars,p,q-1)-palin(chars,p+1,q-1);
					}
				}
			
		}
		
		return num;
	}
	
	/**
	 * ITERATION
	 */
	static int[][] dp = new int[50][50];
	public static int palin2(char[] chars){
		int n = chars.length;
		
		for (int len=0;len<n;len++){
			for (int i=0;i+len<n;i++){
				int j=i+len;
				if (j==i){
					dp[i][j]=1;
				}else{
					if (chars[i]==chars[j]){
						dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
					}else{
						dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
					}
				}
			}
		}
		return dp[0][chars.length-1];
	}

}
