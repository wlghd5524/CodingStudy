import java.util.Scanner
fun main() {
    val input = Scanner(System.`in`)
    var t = input.nextInt()
    for(i:Int in 1..t) {
        var a = input.nextInt()
        var b = input.nextInt()
        println(a+b)
    }
}