import java.util.*
fun main() {
    val input = Scanner(System.`in`)
    while(true) {
        var a = input.nextInt()
        var b = input.nextInt()
        if(a==0&&b==0) {
            break;
        }
        if(b%a==0) {
            println("factor")
        }
        else if(a%b==0) {
            println("multiple")
        }
        else {
            println("neither")
        }
    }
    
}