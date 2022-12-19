import java.util.*
fun main() {
    val input = Scanner(System.`in`)
    var n = input.nextInt()
    for(i in 0 until n) {
        for(j in 0..i) {
            print("*")
        }
        for(j in 0 until (n-i)*2-2) {
            print(" ")
        }
        for(j in 0..i) {
            print("*")
        }
        println()
    }
    for(i in 0 until n-1) {
        for(j in 0 until n-i-1) {
            print("*")
        }
        for(j in 0..i*2+1) {
            print(" ")
        }
        for(j in 0 until n-i-1) {
            print("*")
        }
        println()
    }
}