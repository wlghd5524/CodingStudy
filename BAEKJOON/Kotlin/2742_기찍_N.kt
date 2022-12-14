import java.io.*
import java.util.*
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val token = StringTokenizer(br.readLine())
    var n = token.nextToken().toInt()
    for(i in n downTo 1) {
        bw.write(i.toString() + "\n")
    }
    bw.flush()
    bw.close()
}