class Program {
    static void Main(String[] args) {
        int[] black = {1,1,2,2,2,8};       
        String[] white = Console.ReadLine().Split();
        String answer = "";
        for(int i = 0;i<6;i++) {
            answer += black[i] - Convert.ToInt32(white[i]) + " ";
        }
        Console.WriteLine(answer);
    }
}