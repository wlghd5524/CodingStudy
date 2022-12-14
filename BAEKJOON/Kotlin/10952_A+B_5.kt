import java.io.*
import java.util.*
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    while(true) {
        val token = StringTokenizer(br.readLine())
        var a = token.nextToken().toInt()
        var b = token.nextToken().toInt()
        if(a==0 && b==0) {
            break;
        }
        bw.write((a+b).toString() + "\n")
    }
    bw.flush()
    bw.close()
}