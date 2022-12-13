fun main() {
    var n:Int = readLine()!!.toInt()
    var sum:Int = 0
    for(i:Int in 1..n) {
        sum+=i
    }
    println(sum)
}