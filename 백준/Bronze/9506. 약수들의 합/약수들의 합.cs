class Program {
    static void Main(String[] args) {
        while(true) {
            String tmp = Console.ReadLine();
            int n = Convert.ToInt32(tmp);
            if(n == -1) {
                break;
            }
            int sum = 0;
            List<int> list = new List<int>();
            for(int i = 1;i<=n/2;i++) {
                if(n%i==0) {
                    sum += i;
                    list.Add(i);
                }
            }
            if(sum==n) {
                Console.Write(n + " = " + list[0]);
                for(int i = 1;i<list.Count;i++) {
                    Console.Write(" + " + list[i]);
                }
            }
            else {
                Console.Write(n+" is NOT perfect.");
            }
            Console.Write("\n");
        }
        
    }
}