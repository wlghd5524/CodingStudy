import java.util.*
fun main() {
    val input = Scanner(System.`in`)
    var n = input.nextInt()
    var cnt = 1;
    for(i in 1..n*2-1) {
        for(j in 1..cnt) {
            print("*")
        }
        if(i<n) {
            cnt++
        }
        else {
            cnt--
        }
        println()
    }
}