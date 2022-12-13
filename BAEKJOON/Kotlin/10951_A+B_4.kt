import java.util.Scanner
fun main() {
    val input = Scanner(System.`in`)
    while(input.hasNextInt()) {
        var a:Int = input.nextInt()
        var b:Int = input.nextInt()
        println(a+b)
    }
}