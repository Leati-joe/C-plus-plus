import java.util.Scanner

/*
* Kotlin code to calculate how many times a random number n can be divided by another number less than it
* Divisor should not be equal to 0; it creates and infinite count
*Divider should be greater than one
* */

fun main(args: Array<String>) {
    print("Number, \"n\" to be evaluated : ")
    val reader1= Scanner(System.`in`)
    val n = reader1.nextInt()
    var temp = n                //temporary variable to store n so that the value of n is not altered
    print("\nDivisor to divide the number, \"n\" above : ")
    val reader2= Scanner(System.`in`)
    val divisor =reader2.nextInt()
    var count = 0           //counts how many times n can be divided by the divisor
    while(temp>1 && divisor>1 && temp>divisor)           //divisor should not reduce the number n below 1
                                         // divisor should not be less or equal to one
    {
        temp /=divisor            //int division
        count++
        //println("Success")
    }
    println("\n$n can be divided by $divisor , $count times")
}
