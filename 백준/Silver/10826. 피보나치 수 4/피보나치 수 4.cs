using System.Numerics;
class Program
{
    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        if(n==0) {
            Console.Write(0);
        }
        else {
            BigInteger[] arr = new BigInteger[n+1];
            arr[0] = 0;
            arr[1] = 1;
            for(int i = 2; i <= n; i++) {
                arr[i] = arr[i-1] + arr[i-2];
            }
            Console.Write(arr[n]);
        }
    }
}