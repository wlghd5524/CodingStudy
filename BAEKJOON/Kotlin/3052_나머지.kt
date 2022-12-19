import java.util.*
fun main() {
    val mod = mutableSetOf<Int>()
    while(true) {
        var num = readLine()
        if(num==null) {
            break
        }
        mod.add(num!!.toInt()%42)
    }
    print(mod.size)
}