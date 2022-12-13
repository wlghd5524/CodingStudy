import java.util.Scanner
fun main() {
    val input = Scanner(System.`in`)
    var n:Int = input.nextInt()
    var x:Int = input.nextInt()
    for(i:Int in 1..n) {
        var a:Int = input.nextInt()
        if(x > a) {
            print("$a ")
        }
    }
}