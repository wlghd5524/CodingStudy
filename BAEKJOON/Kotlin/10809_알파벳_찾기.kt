import java.io.*
import java.util.*
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val token = StringTokenizer(br.readLine())
    var s = token.nextToken()
    var list = MutableList(26,{-1})
    for(i:Int in 0..s.length-1) {
        if(list[s[i].toInt()-'a'.toInt()] == -1) {
            list[s[i].toInt()-'a'.toInt()] = i
        }
    }
    for(i:Int in list.indices) {
        bw.write(list[i].toString() + " ")
    }
    bw.flush()
    bw.close()
}