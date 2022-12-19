import java.util.*
fun main() {
    val input = Scanner(System.`in`)
    var list = mutableListOf<Int>()
    for(i in 0..4) {
        var num = input.nextInt()
        list.add(num)
    }
    var result = 1
    while(true) {
        var cnt = 0
        for(i in list) {
            if(result % i != 0) {
                continue
            }
            else {
                cnt++
            }
        }
        if(cnt>=3) {
            break
        }
        else {
            cnt = 0.toInt()
        }
        result++
    }
    println(result)
}