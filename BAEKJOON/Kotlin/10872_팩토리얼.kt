import java.io.*
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val token = StringTokenizer(br.readLine())
    var n = token.nextToken().toInt()
    var result = 1
    for(i:Int in 1..n) {
        result *= i
    }
    bw.write(result.toString())
    bw.flush()
    bw.close()
}