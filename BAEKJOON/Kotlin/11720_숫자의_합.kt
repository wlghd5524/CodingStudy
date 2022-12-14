import java.io.*
import java.util.*
fun main() {
    val input = Scanner(System.`in`)
    var n = input.nextInt()
    var num = input.next()
    var sum = 0
    for(i in 0..n-1) {
        sum += num[i].toInt()-'0'.toInt()
    }
    print(sum)
}