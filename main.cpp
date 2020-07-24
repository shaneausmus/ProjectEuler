#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <set>

void Problem1();
void Problem2();
size_t fibonacci(size_t n);
void Problem3();
void Problem4();
void Problem5();
void Problem6();
void Problem7();
void Problem8();
void Problem9();
void Problem10();
void Problem12();
void Problem13();
void Problem14();
void Problem15();
long countTheWays(int n, int m);
void Problem16();
void Problem17();
void Problem18();
void Problem19();
void Problem20();
void Problem21();
int findProperDivs(int num); // partner function to Problem21()
void Problem22();
void Problem23();
void Problem24();
void Problem25();
void Problem26();
void Problem27();
bool isPrime(long num); // partner function to Problem27()
void Problem28();
void Problem30();
void Problem31();
void Problem32();
void Problem33();
void Problem35();
void Problem37();
void Problem38();
void Problem39();
void Problem40();
void Problem41();
void Problem42();
void Problem44();
void Problem45();
void Problem46();
void Problem47();
void Problem49();
void Problem50();
void Problem51();
void Problem52();
void Problem54();
void Problem58();
void Problem59();
bool royalFlush(std::vector<int> cards);
int straightFlush(std::vector<int> cards);
int fourOfAKind(std::vector<int> cards);
int fullHouse(std::vector<int> cards);
int flush(std::vector<int> cards);
int straight(std::vector<int> cards);
int threeOfAKind(std::vector<int> cards);
int twoPairs(std::vector<int> cards);
int onePair(std::vector<int> cards);
int highCard(std::vector<int> cards);
std::vector<int> processHand(std::string hand);
int compare(std::vector<int> cards1, std::vector<int> cards2);
void Problem60();
void Problem65();
void Problem66();
void Problem67();
void Problem69();
void Problem76();
void Problem77();
void Problem78();
void Problem81();
const std::string PROBLEM_8 = "73167176531330624919225119674426574742355349194934"
                              "96983520312774506326239578318016984801869478851843"
                              "85861560789112949495459501737958331952853208805511"
                              "12540698747158523863050715693290963295227443043557"
                              "66896648950445244523161731856403098711121722383113"
                              "62229893423380308135336276614282806444486645238749"
                              "30358907296290491560440772390713810515859307960866"
                              "70172427121883998797908792274921901699720888093776"
                              "65727333001053367881220235421809751254540594752243"
                              "52584907711670556013604839586446706324415722155397"
                              "53697817977846174064955149290862569321978468622482"
                              "83972241375657056057490261407972968652414535100474"
                              "82166370484403199890008895243450658541227588666881"
                              "16427171479924442928230863465674813919123162824586"
                              "17866458359124566529476545682848912883142607690042"
                              "24219022671055626321111109370544217506941658960408"
                              "07198403850962455444362981230987879927244284909188"
                              "84580156166097919133875499200524063689912560717606"
                              "05886116467109405077541002256983155200055935729725"
                              "71636269561882670428252483600823257530420752963450";
const int P18_SIZE = 15;
const int P67_SIZE = 100;
const int ABUND_NUM_LIM = 28124;
const int CURRENCY_VALS[8] = {1, 2, 5, 10, 20, 50, 100, 200};
const int P80_SIZE = 80;

int main() {
    Problem81();
    return 0;
}

void Problem1() {
    size_t sum3and5 = 0;
    for (size_t i = 0; i < 1000; ++i) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum3and5 += i;
        }
    }
    std::cout << sum3and5 << std::endl;
}


void Problem2() {
    size_t sumEvenFibs = 0;
    for (size_t i = 1; i < 33; ++i) {
        size_t num = fibonacci(i);
        if (num % 2 == 0) {
            sumEvenFibs += num;
        }
    }
    std::cout << sumEvenFibs << std::endl;

}

size_t fibonacci(size_t n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void Problem3() {
    long long prime = 600851475143;
    while (prime % 2 == 0) {
        prime /= 2;
        std::cout << 2 << std::endl;
    }
    // iterate over set of odd numbers up until the square root of the prime.
    for (long long i = 3; i <= prime / 2 - 1; i = i + 2) {
        while (prime % i == 0) {
            prime /= i;
            std::cout << i << std::endl;
        }
    }
    // the final number printed will be the largest prime factor
    // because prime wouldn't become 1 by the above 2 steps
    std::cout << prime << std::endl;
}

void Problem4() {
    bool stop = false;
    for (int i = 999; i >= 700 && !stop; --i) {
        for (int j = 999; j >= 700 && !stop; --j) {
            std::string num = std::to_string(i * j);

            if ((num.at(0) == num.at(5)) && (num.at(1) == num.at(4))
                && (num.at(2) == num.at(3))) {
                std::cout << i << " * " << j << " = " << num << std::endl;
                stop = true;
            }

        }
    }
}

void Problem5() {
    int num = 2520;
    bool stop = false;
    while (!stop) {
        if ((num % 3 == 0) && (num % 4 == 0) && (num % 5 == 0) && (num % 7 == 0) && (num % 8 == 0)
            && (num % 9 == 0) && (num % 11 == 0) && (num % 13 == 0) && (num % 16 == 0) && (num % 17 == 0)
            && (num % 19 == 0)) {
            stop = true;
        } else {
            num += 2;
        }
    }
    std::cout << num << " is the smallest positive number"
                        " evenly divisible by all of the numbers from 1 to 20." << std::endl;
}


void Problem6() {
    int sumOfSquares = 0, squareOfSum = 0;
    for (size_t i = 1; i < 101; ++i) {
        sumOfSquares += pow(i, 2);
        squareOfSum += i;
    }
    squareOfSum = pow(squareOfSum, 2);
    std::cout << squareOfSum - sumOfSquares << std::endl;
}

void Problem7() {
    int primes[10001];
    primes[0] = 2, primes[1] = 3, primes[2] = 5, primes[3] = 7;
    int primeCount = 4, currNumber = 11; // skipping single-digit numbers
    bool check = true;
    while (primeCount != 10001) {
        for (size_t i = 0; i < (size_t) primeCount; ++i) {
            if (currNumber % primes[i] == 0) {
                check = false;
            }
            if (!check) { break; }
        }
        if (check) {
            ++primeCount;
            primes[primeCount - 1] = currNumber;
        }
        currNumber += 2;
        check = true;
    }
    std::cout << currNumber - 2; // accounting for additional 2 added at the end

}

void Problem8() {
    // numbers get BIG here so using long long for product values, otherwise numbers are incorrect
    long long product = 0, newProduct = 1;
    for (int i = 0; i < (int) PROBLEM_8.size() - 13; ++i) {
        std::string length13 = PROBLEM_8.substr(i, 13);
        for (char j : length13) {
            newProduct *= (j - '0');
        }
        if (newProduct > product) {
            product = newProduct;
        }
        newProduct = 1;
    }
    std::cout << product;
}

void Problem137() {
    double x = (10.0 / 11);
    double fibNums[42], sum = 0;
    for (size_t i = 0; i < 42; ++i) {
        fibNums[i] = fibonacci(i + 1);
    }
    for (size_t i = 0; i < 42; ++i) {
        sum += pow(x, i + 1) * fibNums[i];
    }
    std::cout << sum;
}

void Problem9() {
    int a = 100, b = 101, c = 102;
    bool stop = false;
    for (a = 100; a <= 500 && !stop; ++a) {
        for (b = a + 1; b <= 500 && !stop; ++b) {
            for (c = a + 2; c <= 500 && !stop; ++c) {
                if (a + b + c == 1000) {
                    if ((pow(a, 2) + pow(b, 2) == pow(c, 2))) {
                        stop = true;
                    }
                }
            }
        }
    }
    a = a - 1, b = b - 1, c = c - 1;
    std::cout << a << " * " << b << " * " << c << " = " << a * b * c << std::endl;
}

void Problem10() {
    int primes[200000];
    primes[0] = 2, primes[1] = 3, primes[2] = 5, primes[3] = 7;
    int primeCount = 4, currNumber = 11;
    long sum = 0; // have to use a long to hold the number
    bool check = true;
    while (currNumber < 2000000) {
        for (size_t i = 0; i < (size_t) primeCount; ++i) {
            if (currNumber % primes[i] == 0) {
                check = false;
            }
            if (!check) { break; }
        }
        if (check) {
            ++primeCount;
            primes[primeCount - 1] = currNumber;
        }
        currNumber += 2;
        check = true;
    }
    std::cout << "The sum of all primes less than 2 million is " << sum << "." << std::endl;
}

// Problem 11 is solved in a separate file

void Problem12() {
    // starting at first actual number with over 500 divisors
    // 500 = 2*2*5*5*5 by prime number decomposition theorem
    // 62370000 = 7 * 11 * 5^4 * 3^4 * 2^4, where (1+1) + (1+1) + 3(4 + 1) = 500
    // now we have to find first triangular number larger than this
    // after some experimentation, using the triangular numbers formula where (n)(n+1)/2 = Tn,
    // first triangular number above this is 62378865 = T(11169), so let's start here
    long triNumber = 62367696, tempTriNum;
    int numDivisors = 1, triNumStep = 11169, currNumber, primeCount = 4, total = 0;
    int primes[1000000];
    primes[0] = 2, primes[1] = 3, primes[2] = 5, primes[3] = 7;
    while (numDivisors <= 500) {
        numDivisors = 1;
        triNumber += triNumStep;
        tempTriNum = triNumber;
        ++triNumStep;
        bool check = true;
        currNumber = primes[primeCount - 1] + 2;
        while (currNumber <= sqrt(triNumber)) {
            for (size_t i = 0; i < (size_t) primeCount; ++i) {
                if (currNumber % primes[i] == 0) {
                    check = false;
                }
                if (!check) { break; }
            }
            if (check) {
                ++primeCount;
                primes[primeCount - 1] = currNumber;
            }
            currNumber += 2;
            check = true;
        }
        for (size_t i = 0; i < (size_t) primeCount; ++i) {
            if (triNumber % primes[i] == 0) {
                while (triNumber % primes[i] == 0) {
                    triNumber = triNumber / primes[i];
                    ++total;
                }
                numDivisors *= (total + 1);
                total = 0;
            }
        }
        triNumber = tempTriNum; // reassigns triNumber to original value so it can print
        // when it has > 500 divisors
    }
    std::cout << triNumber;
}


void Problem13() {

    std::ifstream infile;
    std::string filename = "PEProblem13.txt", nextNum;
    int num[100];
    infile.open(filename.c_str());
    if (infile.fail()) {
        throw std::invalid_argument("This file name doesn't work");
    } else {
        while (infile >> nextNum) {
            for (int i = 0; i < (int) nextNum.size(); ++i) {
                num[i + 50] += (nextNum.at(i) - '0');
                if ((num[i + 50] + (nextNum.at(i) - '0')) >= 10) {
                    int j = i + 50;
                    while (num[j] >= 10) {
                        int tmp = num[j];
                        num[j] = num[j] % 10;
                        num[j - 1] += tmp / 10;
                        --j;
                    }
                }
            }
        }
        infile.close();
        for (size_t i = 48; i < 100; ++i) {
            std::cout << num[i];
        }
    }
}

void Problem14() {
    // going to make the bold assumption that the largest sequence lies somewhere
    // between 800,000 and 1,000,000 to limit search space
    size_t i, largestNum = 0;
    long maxCollatzTerms = 0, numTermsCollatz = 0;
    for (i = 800000; i < 1000000; ++i) {
        size_t num = i;
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = (3 * num) + 1;
            }
            ++numTermsCollatz;
        }
        if (maxCollatzTerms < numTermsCollatz) {
            maxCollatzTerms = numTermsCollatz;
            largestNum = i;
        }
        numTermsCollatz = 0;
    }
    std::cout << largestNum << " has a Collatz sequence of " << maxCollatzTerms << " terms.";
}

void Problem15() {
    std::cout << "There are " << countTheWays(20, 20) << " routes through a 20x20 board.";
}

long countTheWays(int n, int m) {
    if ((n == 0) || (m == 0)) { // recursive method taken from an old programming assignment
        return 1;
    } else {
        return countTheWays(n - 1, m) + countTheWays(n, m - 1);
    }
}

void Problem16() {
    int powOf2[350], stopInt = 349;
    for (int i = 1; i <= 1000; ++i) {
        for (int k = 1; k <= stopInt; ++i) {
            powOf2[350 - i] = powOf2[350 - i] * 2;
            if ((powOf2[350 - i] * 2 >= 10)) {
                int j = 350 - i;
                while (powOf2[j] >= 10) {
                    int tmp = powOf2[j];
                    powOf2[j] = powOf2[j] % 10;
                    powOf2[j - 1] += tmp / 10;
                    --j;
                }
                stopInt = j;
            }
        }
        for (i = 0; i < 350; ++i) {
            std::cout << powOf2[i];
        }
    }
}

void Problem17() {
    size_t charCount = 0;
    for (size_t num = 1; num <= 1000; ++num) {
        std::string number;
        if (num == 1000) { number = "onethousand"; }
        if (num >= 100 && ((num / 100) > 0) && ((num / 100) <= 9)) {
            if (num / 100 == 1) {
                number += "one";
            } else if (num / 100 == 2) {
                number += "two";
            } else if (num / 100 == 3) {
                number += "three";
            } else if (num / 100 == 4) {
                number += "four";
            } else if (num / 100 == 5) {
                number += "five";
            } else if (num / 100 == 6) {
                number += "six";
            } else if (num / 100 == 7) {
                number += "seven";
            } else if (num / 100 == 8) {
                number += "eight";
            } else if (num / 100 == 9) {
                number += "nine";
            }
            number += "hundred";
        }
        if ((num % 100 > 0) && ((num % 100) / 10) > 0) {
            if (num > 100) { number += "and"; }
            if ((num % 100) / 10 == 1) {
                if (num % 100 == 10) {
                    number += "ten";
                } else if (num % 100 == 11) {
                    number += "eleven";
                } else if (num % 100 == 12) {
                    number += "twelve";
                } else if (num % 100 == 13) {
                    number += "thirteen";
                } else if (num % 100 == 14) {
                    number += "fourteen";
                } else if (num % 100 == 15) {
                    number += "fifteen";
                } else if (num % 100 == 16) {
                    number += "sixteen";
                } else if (num % 100 == 17) {
                    number += "seventeen";
                } else if (num % 100 == 18) {
                    number += "eighteen";
                } else if (num % 100 == 19) {
                    number += "nineteen";
                }
            } else if ((num % 100) / 10 == 2) {
                number += "twenty";
            } else if ((num % 100) / 10 == 3) {
                number += "thirty";
            } else if ((num % 100) / 10 == 4) {
                number += "forty";
            } else if ((num % 100) / 10 == 5) {
                number += "fifty";
            } else if ((num % 100) / 10 == 6) {
                number += "sixty";
            } else if ((num % 100) / 10 == 7) {
                number += "seventy";
            } else if ((num % 100) / 10 == 8) {
                number += "eighty";
            } else if ((num % 100) / 10 == 9) {
                number += "ninety";
            }
        }
        if ((num % 10 > 0) && (num % 100 / 10) != 1) {
            if ((num % 100 / 10) == 0 && num > 100) { number += "and"; }
            if (num % 10 == 1) {
                number += "one";
            } else if (num % 10 == 2) {
                number += "two";
            } else if (num % 10 == 3) {
                number += "three";
            } else if (num % 10 == 4) {
                number += "four";
            } else if (num % 10 == 5) {
                number += "five";
            } else if (num % 10 == 6) {
                number += "six";
            } else if (num % 10 == 7) {
                number += "seven";
            } else if (num % 10 == 8) {
                number += "eight";
            } else if (num % 10 == 9) {
                number += "nine";
            }
        }
        charCount += number.length();
    }
    std::cout << "The number of letters used to spell out 1 - 1000 is " << charCount;
}

bool royalFlush(std::vector<int> cards) {
    bool checkSameSuit = false;
    for (int i = 15; i < (int)cards.size(); ++i) {
        if (cards[i] == 5) {
            checkSameSuit = true;
        }
    }

    if (!checkSameSuit){
        return false;
    } else {
        for (int i = 10; i < 15; ++i) {
            if (cards[i] != 1) {
                return false;
            }
        }
        return true;
    }
}

int straightFlush(std::vector<int> cards) {
    int counter = 0;
    bool checkSameSuit = false;
    for (int i = 15; i < (int)cards.size(); ++i) {
        if (cards[i] == 5) {
            checkSameSuit = true;
        }
    }

    if (!checkSameSuit){
        return -1;
    } else {
        int i;
        for (i = 0; i < 15; ++i) {
            if (counter == 5) {
                break;
            } else if (cards[i] == 1) {
                ++counter;
            } else {
                counter = 0;
            }
        }
        if (counter != 5) {
            return -1;
        } else {
            return i - 1;
        }
    }
}

int fourOfAKind(std::vector<int> cards) {
    for (int i = 0; i < 15; ++i) {
        if (cards[i] == 4) {
            return i;
        }
    }
    return -1;
}

int fullHouse(std::vector<int> cards) {
    int three = 0, two = 0;
    bool check3 = false, check2 = false;
    for (int i = 0; i < 15; ++i) {
        if (cards[i] == 3) {
            check3 = true;
            three = i;
        } else if (cards[i] == 2) {
            check2 = true;
            two = i;
        }
    }
    if (check3 && check2) {
        if (three > two) {
            return three;
        } else {
            return two;
        }
    } else {
        return -1;
    }
}

int flush(std::vector<int> cards) {
    for (int i = 15; i < 15; ++i) {
        if (cards[i] == 5) {
            return i;
        }
    }
    return -1;
}

int straight(std::vector<int> cards) {
    int i, counter = 0;
    for (i = 0; i < 15; ++i) {
        if (counter == 5) {
            break;
        } else if (cards[i] == 1) {
            ++counter;
        } else {
            counter = 0;
        }
    }
    if (counter != 5) {
        return -1;
    } else {
        return i - 1;
    }
}

int threeOfAKind(std::vector<int> cards) {
    for (int i = 0; i < 15; ++i) {
        if (cards[i] == 3) {
            return i;
        }
    }
    return -1;
}

int twoPairs(std::vector<int> cards) {
    int pairCount = 0;
    for (int i = 0; i < 15; ++i) {
        if (cards[i] == 2) {
            ++pairCount;
        }
        if (pairCount == 2) {
            return i;
        }
    }
    return -1;
}

int onePair(std::vector<int> cards) {
    for (int i = 0; i < 15; ++i) {
        if (cards[i] == 2) {
            return i;
        }
    }
    return -1;
}

int highCard(std::vector<int> cards) {
    int highestCard = -1;
    for (int i = 0; i < 15; ++i) {
        if (cards[i] > 0 && i > highestCard) {
            highestCard = i;
        }
    }
    return highestCard;
}

std::vector<int> processHand(std::string hand) {
    std::vector<int> numsPlayer(19, 0);
    for (int i = 0; i < (int)hand.size(); ++i){
        if (hand[i]==' ') {
        } else if (hand[i]-'0' < 10) {
            ++numsPlayer[hand[i]-'0'];
        } else if (hand[i] == 'T') {
            ++numsPlayer[10];
        } else if (hand[i] == 'J') {
            ++numsPlayer[11];
        } else if (hand[i] == 'Q') {
            ++numsPlayer[12];
        } else if (hand[i] == 'K') {
            ++numsPlayer[13];
        } else if (hand[i] == 'A') {
            ++numsPlayer[14];
        } else if (hand[i] == 'C') {
            ++numsPlayer[15];
        } else if (hand[i] == 'S') {
            ++numsPlayer[16];
        } else if (hand[i] == 'D') {
            ++numsPlayer[17];
        } else if (hand[i] == 'H') {
            ++numsPlayer[18];
        }
    }
    return numsPlayer;
}

int compare(std::vector<int> cards1, std::vector<int> cards2) {
    int highestCard[2] = {0, 0};
    for (int i = 0; i < 15; ++i) {
        if (cards1[i] > 0 && i > highestCard[0] && cards2[i] == 0) {
            highestCard[0] = i;
            highestCard[1] = 1;
        }
        if (cards2[i] > 0 && i > highestCard[0] && cards1[i] == 0) {
            highestCard[0] = i;
            highestCard[1] = 2;
        }
    }
    return highestCard[1];
}

void Problem18() {
    int arr[P18_SIZE][P18_SIZE] = {
            {75},
            {95, 64},
            {17, 47, 82},
            {18, 35, 87, 10},
            {20, 04, 82, 47, 65},
            {19, 01, 23, 75, 03, 34},
            {88, 02, 77, 73, 07, 63, 67},
            {99, 65, 04, 28, 06, 16, 70, 92},
            {41, 41, 26, 56, 83, 40, 80, 70, 33},
            {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
            {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
            {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
            {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
            {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
            {04, 62, 98, 27, 23, 9,  70, 98, 73, 93, 38, 53, 60, 04, 23}
    };

    for (int row = P18_SIZE - 2; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            if (arr[row + 1][col] >= arr[row + 1][col + 1]) {
                arr[row][col] += arr[row + 1][col];
            } else {
                arr[row][col] += arr[row + 1][col + 1];
            }
        }
    }
    std::cout << "The sum of the largest pathway is " << arr[0][0];
}

void Problem19() {
    // sample size of days = (365 * 100) + 25 days (for leap years = 36525)
    // Jan 1st 1901 was a Tuesday, so day = 2
    int dayCount = 2, totalFirstSundays = 0;
    for (int year = 1901; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            int numDays;
            if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
                numDays = 30;
            } else if (month == 2) {
                numDays = 28;
                if (year % 4 == 0) { ++numDays; }
            } else {
                numDays = 31;
            }
            for (int day = 1; day <= numDays; ++day, ++dayCount) {
                if (dayCount > 7) {
                    dayCount = 1;
                }
                if (dayCount == 7 && day == 1) {
                    ++totalFirstSundays;
                } // 7 is a Sunday;
                // increment totalFirstSundays if it is the first of the month and a Sunday
            }
        }
    }
    std::cout << "The number of Sundays falling on the first of the month is " << totalFirstSundays << ".";
}

void Problem20() {
    int num[200];
    int arrSize = 200, sum = 0;
    for (int &i : num) {
        i = 0;
    }
    std::string fact10 = "3628800";
    for (int i = 0; i < (int)fact10.size(); ++i) {
        num[150 + i] = fact10.at(i) - '0';
    }
    // already gives us 10! so we'll use this as a jumping point to calculate 100!
    for (int i = 11; i <= 100; ++i) {
        for (int j = 0; j < arrSize; ++j) {
            num[j] *= i;
        }
        for (int j = arrSize - 1; j >= 0; --j) { // 199 = size of array
            if ((num[j] >= 10)) {
                while (num[j] >= 10) {
                    int tmp = num[j];
                    num[j] = num[j] % 10;
                    num[j - 1] += tmp / 10;
                    --j;
                }
            }
        }
    }
    for (int i : num) {
        std::cout << i;
        sum += i;
    }
    std::cout << "\nTotal sum of the digits in the factorial: " << sum;
}

void Problem21() {
    int sumAmNums = 0, num, index = 0;
    int AmNums[20];

    for (int i = 0; i < 20; ++i) {
        AmNums[i] = 0;
    }

    for (num = 1; num <= 10000; ++num) {
        int sumDivs = findProperDivs(num), potentialAmNum = findProperDivs(sumDivs);
        // excluding perfect numbers below (i.e. sum of num's divisors shouldn't equal itself)
        if (potentialAmNum == num && num != sumDivs) {
            sumAmNums += num;
            AmNums[index] = num;
            ++index;
        }
    }

    std::cout << "The sum of the amicable numbers <= to 10000 is: ";
    std::cout << sumAmNums;

    int i = 0;
    std::cout << "\nThe amicable numbers below 10000 are: ";
    while (AmNums[i] != 0) {
        std::cout << AmNums[i] << " ";
        ++i;
    }
}

int findProperDivs(int num) {
    int divSum = 0;
    for (int div = 1; div <= num/2; ++div) {
        if (num % div == 0) {
            divSum += div;
        }
    }
    return divSum;
}



void Problem22() {
    std::ifstream infile;
    std::string filetext, filename = "names.txt", currName;
    infile.open(filename.c_str());
    std::vector<std::string> names;

    infile >> filetext;
    for (int i = 0; i < (int)filetext.size(); ++i) {
        if ((filetext.at(i) == '\"') && ((i == (int)filetext.size() - 1) || (filetext.at(i + 1)) != ',')) {
            names.push_back(currName);
            currName = "";
        } else if (filetext.at(i) == '\"' || filetext.at(i) == ',') {
        } else {
             currName += filetext.at(i);
        }
    }

    infile.close();

    std::sort(names.begin(), names.end()); // sorts through vector of names

    int nameNum = 0, nameSum = 0; // starts at 0 to get rid of empty string at beginning
    long long totalScore = 0;
    std::vector<std::string>::iterator it;
    for (it = names.begin(); it != names.end(); ++it) {
        for (char i : *it) {
            nameSum += (i - '@'); // gives each character its proper ASCII int value
        }
        totalScore += (nameSum * nameNum);
        ++nameNum;
        nameSum = 0;
    }


    std::cout << "The total name score is " << totalScore << ".";
}


void Problem23() {
    int index = 1, sumDivs = 0;
    int abundantNums[7000], range[ABUND_NUM_LIM];
    long total = 0;
    for (int & num : abundantNums) {
        num = 0; // initializing each index to 0
    }

    for (int & num : range) {
        num = index;
        ++index;
    }

    index = 0;

    for (int num = 1; num < ABUND_NUM_LIM; ++num) {
        sumDivs = findProperDivs(num);
        if (sumDivs > num) {
            abundantNums[index] = num;
            ++index;
        }
    }

    for (int i = 0; abundantNums[i] != 0; ++i) {
        int j = i;
        while (abundantNums[j] != 0) {
            int tmpSum = abundantNums[i] + abundantNums[j];
            if (tmpSum <= ABUND_NUM_LIM) {
                range[tmpSum - 1] = 0;
            }
            ++j;
        }
    }

    for (int i : range) {
        total += i;
    }

    std::cout << "The total sum of numbers unable to be formed";
    std::cout << "\nby adding 2 abundant numbers is " << total << ".";
}

void Problem24() {
    // 10! / 10 = 3628800 / 10 = 362880 * 2 = 725760
    // To hit the millionth lexicographical permutation of digits 0-9, the first
    // digit will be two. We can iterate over all possible permutations where 2 begins
    // 1000000 - 2(10! / 10) = 274240, and 274240 / 8! rounds to 7; thus, the second digit
    // of the number must be 7
    // 1000000 - 967680 = 32320
    int counter = 967681;
    std::string starter = "2701345689", finalPerm; // smallest permutation starting w/ 2
    int permutation[10], copier[10]; // will be easier to work with loading characters into array

    for (size_t i = 0; i < starter.size(); ++i) {
        permutation[i] = copier[i] = starter[i]-'0';
    }

    int final = (int)starter.size();
    for (int i = final - 1; counter <= 1000000; --i) {
        for (size_t j = 0; j < starter.size(); ++j) {
            permutation[j] = copier[j];
        }
        while (std::next_permutation(permutation + i, permutation + final)) {
            ++counter;
            for (size_t j = 0; j < starter.size(); ++j) {
                copier[j] = permutation[j];
            }
            if (counter == 1000000) {
                for (size_t j = 0; j < starter.size(); ++j) {
                    finalPerm += std::to_string(permutation[j]);
                }
            }
        }
    }

    std::cout << "The millionth permutation is " << finalPerm << ".";
}

void Problem25() {
    std::vector<int> tmp, fib1, fib2;
    int index = 2;
    tmp.push_back(0);
    fib1.push_back(1); // F1
    fib2.push_back(1); // F2

    while (fib2.size() != 1000) {
        for (size_t i = 0; i < fib2.size(); ++i) {
            if (i >= tmp.size()) {
                tmp.push_back(fib2.at(i));
            } else {
                tmp.at(i) = fib2.at(i);
            }
        }
        for (size_t i = 0; i < fib1.size(); ++i) {
            if (i >= fib1.size()) {
                fib2.push_back(fib1.at(i));
            } else {
                fib2.at(i) += fib1.at(i);
            }
            if ((fib2.at(i) >= 10)) {
                size_t j = i;
                while (fib2.at(j) >= 10) {
                    int tmp2 = fib2.at(j) / 10;
                    fib2.at(j) = fib2.at(j) % 10;
                    if (j + 1 >= fib2.size()) {
                        fib2.push_back(tmp2);
                    } else {
                        fib2.at(j + 1) += tmp2;
                    }
                    ++j;
                }
            }
        }
        for (size_t i = 0; i < tmp.size(); ++i) {
            if (i >= fib1.size()) {
                fib1.push_back(tmp.at(i));
            } else {
                fib1.at(i) = tmp.at(i);
            }
        }
        ++index;
    }
    std::cout << "The index of the first Fib. number to have 1000 digits is " << index << ".";
}

void Problem26() {
    int maxCycle = 0;
    bool checkPrime = true, checkReptend = true;
    for (int i = 1000; i >= 1; --i) {
        for (int j = 2; j < sqrt(i); ++j) {
            if (i % j == 0) {
                checkPrime = false;
                break;
            }
        }
        if (checkPrime) {
           
        }
        if (maxCycle != 0) {
            break;
        }
        checkPrime = checkReptend = true;
    }
    std::cout << maxCycle;
}

void Problem27() {
    std::vector<int> primes;
    int quadPrimeFormula[2] = {0, 0};
    int primeCounter = 0, temp = 0;
    for (int i = -999; i < 1001; ++i) { // tests all prime numbers including the negative ones
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    bool checkPrimes = true;
    for (int a = -999; a <= 1000; ++a) {
        for (int prime : primes) {
            temp = 0;
            for (int n = 0; checkPrimes; ++n) {
                int potPrime = (int)pow(n, 2) + (a * n) + prime;
                if (isPrime(potPrime)) {
                    ++temp;
                } else {
                    checkPrimes = false;
                }
            }
            checkPrimes = true;
            if (temp > primeCounter) {
                primeCounter = temp;
                quadPrimeFormula[0] = a;
                quadPrimeFormula[1] = prime;
            }
        }
    }

    std::cout << "The product of the values of a and b that produce the most\n";
    std::cout << "primes is " << (quadPrimeFormula[0] * quadPrimeFormula[1]);

}

bool isPrime(long num) {
    bool prime = true;
    int testNum = abs(num); // must be absolute value
    if (testNum / 10 == 0) {
        return ((testNum == 2) || (testNum == 3) || (testNum == 5) || (testNum == 7));
    } else {
        for (int i = 2; i <= sqrt(num); ++i) {
            if (testNum % i == 0) {
                prime = false;
            }
        }
    }
    return prime;
}

void Problem28() {
    // the corner numbers in the spiral are all odd numbers that increase by 2 * i,
    // where i is some integer corresponding to the row
    // only need to look at 500 rows because we're looking at the edges of a square;
    // cuts our number of observable rows down by 2
    int row;
    long count = 1, sum = 1;
    for (row = 1; row <= 500; ++row) {
        for (int i = 1; i <= 4; ++i) {
            count += (row * 2);
            sum += count;
        }
    }
    std::cout << "The total sum of all diagonals in a 1001x1001 spiral is " << sum;
}

void Problem30() {
    // Credit to Robert Eisele's blog for helping me with the bounds here for the for loop below
    // You can find his solution and notes here: https://www.xarg.org/puzzle/project-euler/problem-30/
    size_t sum5thPowers = 0, check5thPowers = 0;
    for (size_t i = 2; i < 6*pow(9, 5); ++i) {
        std::string num = std::to_string(i);
        for (size_t j = 0; j < num.size(); ++j) {
            check5thPowers += pow((num.at(j)-'0'), 5);
        }
        if (check5thPowers == i) {
            sum5thPowers += i;
        }
        check5thPowers = 0;
    }
    std::cout << "The sum of all numbers that can be written as\n";
    std::cout << "5th powers of their digits is: " << sum5thPowers;
}

void Problem31() {
    std::vector<std::vector<int>> colNums;
    colNums.emplace_back(8, 1);
    for (int num = 1; num <= 200; ++num) {
        if (num != 1) {
            colNums.emplace_back(8);
            for (int i = 0; i < 8; ++i) {
                colNums[num - 1][i] = colNums[num - 2][i];
            }
        }
        for (int i = 0; i < 8; ++i) {
            if (i == 0) {
                colNums[num - 1][i] = 1;
            } else {
                if (i > 0 && num > 1) {
                    if (num < CURRENCY_VALS[i]) {
                        colNums[num - 1][i] = colNums[num - 1][i -1];
                    } else {
                        if (num - 1 - CURRENCY_VALS[i] >= 0) {
                            colNums[num - 1][i] = colNums[num - 1][i - 1] + colNums[num - 1- CURRENCY_VALS[i]][i];
                        } else {
                            colNums[num - 1][i] = colNums[num - 1][i - 1] + colNums[0][i];
                        }
                    }
                }
            }
        }
    }
    std::cout << "The number of ways to get 2 pounds is " << colNums[199][7];
}

void Problem32() {
    long sumPanProducts = 0;
    bool panProduct = true;
    std::string num = "";
    std::set<int> panProducts, digits;
    for (int i = 1; i <= 999; ++i) {
        for (int j = 1; j <= 9499; ++j) {
            num += std::to_string(i) + std::to_string(j) + std::to_string(i * j);
            if (num.size() >= 10 || num.size() < 9) {
                num = "";
                continue;
            } else {
                for (size_t k = 0; k < num.size(); ++k) {
                    if (num[k]-'0' == 0 || digits.count(num[k]-'0') > 0) {
                        panProduct = false;
                        break;
                    }
                    digits.insert(num[k]-'0');
                }
                if (panProduct && panProducts.count(i*j) <= 0) {
                    panProducts.insert(i * j);
                }
            }
            num = "";
            digits.clear();
            panProduct = true;
        }
    }

    for (std::set<int>::const_iterator it = panProducts.begin(); it != panProducts.end(); ++it) {
        sumPanProducts += *it;
    }

    std::cout << "The sum of all products whose multiplication expressions are pandigital is " << sumPanProducts;
}

void Problem33() {
    // even values of the vector will be numerators; odd values will be denominators
    // it'll work sorta like a hashing function
    std::vector<int> fractions;
    for (int denominator = 10; denominator < 100; ++denominator) {
        for (int numerator = 10; numerator < denominator; ++numerator) {
            if (numerator % 10 == denominator / 10) {
                int num2 = denominator % 10, num1 = numerator / 10;
                if (((double)num1 / num2) == ((double)numerator / denominator) && (num1 / num2 < 1)) {
                    fractions.push_back(numerator);
                    fractions.push_back(denominator);
                }
            } else if (denominator % 10 == numerator / 10) {
                int num2 = denominator / 10, num1 = numerator % 10;
                if (((double)num1 / num2) == ((double)numerator / denominator) && (num1 / num2 < 1)) {
                    fractions.push_back(numerator);
                    fractions.push_back(denominator);
                }
            }
        }
    }
    int numerator = 1, denominator = 1;
    for (int i = 0; i < (int)fractions.size(); ++i) {
        if (i % 2 == 0) {
            numerator *= fractions.at(i);
        } else {
            denominator *= fractions.at(i);
        }
    }
    std::cout << numerator << " / " << denominator << " equals " << (double)numerator / denominator;
}

void Problem35() {
    int circPrimeCount = 0;
    bool checkCirc = true;
    std::set<int> primes, circPrimes;
    primes.insert(2);
    for (int i = 3; i < 1000000; i += 2) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }

    for (std::set<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        checkCirc = true;
        int counter = 0;
        std::string num = std::to_string(*it);
        if (num.length() == 1) {
            circPrimeCount += 1;
            circPrimes.insert(std::stoi(num));
        } else {
            while (counter != (int)num.length() || !checkCirc) {
                int test = std::stoi(num);
                if (primes.count(test) > 0 && circPrimes.count(test) <= 0) {
                    ++counter;
                    circPrimes.insert(test);
                } else {
                    checkCirc = false;
                }
                num = num.substr(num.length() - 1) + num.substr(0, num.length() - 1);
                if (num == std::to_string(*it)) {
                    break;
                }
            }
            if (checkCirc) {
                circPrimeCount += counter;
            }
        }
    }
    std::cout << "The number of circular primes below 1 million is " << circPrimeCount;
}

void Problem37() {
    bool truncPrime = true;
    int sum = 0;
    std::set<int> primes;
    primes.insert(2);
    for (int i = 3; i < 1000000; i += 2) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }

    for (std::set<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        truncPrime = true;
        std::string num = std::to_string(*it);
        if (num.size() != 1) {
            int currPrime = *it;
            for (size_t i = 0; i < num.size() && truncPrime; ++i) {
                if (primes.count(currPrime) > 0 && currPrime != 1) {
                    currPrime = currPrime / 10;
                } else {
                    truncPrime = false;
                }
            }
            currPrime = *it;
            for (size_t i = 0; i < num.size() && truncPrime; ++i) {
                if (primes.count(currPrime) > 0 && currPrime != 1) {
                    currPrime = currPrime % (int) pow(10, num.size() - i - 1);
                } else {
                    truncPrime = false;
                }
            }
            if (truncPrime) {
                sum += *it;
                std::cout << *it << "\n";;
            }
        }
    }
    std::cout << "The sum of the 11 truncatable primes is " << sum;
}


void Problem38() {
    long currNum = 0, tmpNum = 0;
    std::string strCurrNum;
    std::set<int> nums;
    for (int i = 2; i < 90000; ++i) {
        int counter = 1;
        while (strCurrNum.size() < 9) {
            strCurrNum += std::to_string(i * counter);
            ++counter;
        }
        if (strCurrNum.size() > 9) {
            strCurrNum = "";
            continue;
        }
        for (char j : strCurrNum) {
            if (nums.count(j-'0') > 0 || j == '0') {
                break;
            } else {
                nums.insert(j-'0');
            }
        }
        if (nums.size() == 9) {
            tmpNum = std::stol(strCurrNum);
            if (currNum < tmpNum) {
                currNum = tmpNum;
            }
        }
        strCurrNum = "";
        nums.clear();
    }
    std::cout << "The largest 9-digit pandigital number formed here is " << currNum;
}

/*
 * had some help from mathblog.dk with the mathematical logic behind this problem;
 * their explanation can be found here: https://www.mathblog.dk/project-euler-39-perimeter-right-angle-triangle/
 */

void Problem39() {
    int a, p;
    int maxSolns = 0, numSolns = 0, maxP = 0;
    for (p = 1; p <= 1000; ++p) {
        for (a = 1; a <= p / 3; ++a) {
            if ((p * (p - (2 * a))) % (2 * (p - a)) == 0) {
                ++numSolns;
            }
        }
        if (maxSolns < numSolns) {
            maxSolns = numSolns;
            maxP = p;
        }
        numSolns = 0;
    }
    std::cout << "The solutions are maximized for p <= 1000 at " << maxSolns << "\n";
    std::cout << "The max p value is " << maxP;
}

void Problem40() {
    int champerowneMult = 1, tensCounter = 1, totDigits = 0;
    for (int i = 1; i < 250000 && tensCounter < 1000000; ++i) {
        std::string num = std::to_string(i);
        if ((totDigits < tensCounter) && (totDigits + (int)num.size() >= tensCounter)) {
            for (int j = 0; j < (int)num.size(); ++j) {
                ++totDigits;
                if (totDigits == tensCounter) {
                    champerowneMult *= (num[j] - '0');
                    tensCounter *= 10;
                }
            }
        } else {
            totDigits += num.size();
        }
    }
    std::cout << "The value of the expression for this problem is " << champerowneMult;
}

void Problem41() {
    // final number couldn't be one where sum of digits is divisible by 3 which rules out 8 and 9
    // sum of the range of 1-8 is 36, which is divisible by 3
    // sum of the range of 1-9 is 45, which is divisible by 3
    // if sum of digits in a number is divisible by 3, so is the number itself
    // we should try the 7-digit pandigital numbers instead, starting with 1234567
    long pandigitalPrime = 1234567, maxPrime = 0;
    std::string num = std::to_string(pandigitalPrime);
    while (std::next_permutation(num.begin(), num.end())) {
        pandigitalPrime = std::stol(num);
        if (isPrime(pandigitalPrime) && pandigitalPrime > maxPrime) {
            maxPrime = pandigitalPrime;
        }
    }
    std::cout << "The largest pandigital prime is " << maxPrime;
}

void Problem42() {
    int triNum, countTriNum = 0, wordValue = 0, counter = 1;
    std::set<int> triNums;
    for (triNum = 1; triNum < 1000; ++counter, triNum += counter) {
        triNums.insert(triNum);
    }

    std::ifstream infile;
    std::string filetext, filename = "p042_words.txt";
    infile.open(filename.c_str());

    infile >> filetext;
    for (int i = 0; i < (int)filetext.size(); ++i) {
        if ((filetext.at(i) == '\"') && ((i == (int)filetext.size() - 1) || (filetext.at(i + 1)) != ',')) {
            if (triNums.count(wordValue) > 0) {
                ++countTriNum;
            }
            wordValue = 0;
        } else if (filetext.at(i) == '\"' || filetext.at(i) == ',') {
        } else {
            wordValue += filetext.at(i) - '@';
        }
    }
    infile.close();
    std::cout << "The number of triangle words in the list is " << countTriNum;
}

void Problem44() {
    std::vector<long> pentNums(5000);
    std::set<long> pentNumsList, differences;
    for (int i = 0; i < 50000; ++i) {
        long pentNum = (i+1) * (3*(i + 1) - 1) / 2;
        pentNums.at(i) = pentNum;
        pentNumsList.insert(pentNum);
    }

    for (int i = 0; i < (int)pentNums.size(); ++i) {
        for (int j = i + 1; j < (int)pentNums.size(); ++j) {
            if (pentNumsList.count(pentNums.at(j) - pentNums.at(i)) > 0 && pentNumsList.count(pentNums.at(i) + pentNums.at(j)) > 0){
                differences.insert(pentNums.at(j) - pentNums.at(i));
            }
        }
    }

    for (std::set<long>::const_iterator it = differences.begin(); it != differences.end(); ++it) {
        std::cout << *it << "\n";
    }
}

void Problem45() {
    long long nextTriNum = 0;
    std::set<long long> triNums, pentNums, hexNums;
    for (long long i = 1; i <= 70000; ++i) {
        triNums.insert(i * (i + 1) / 2);
        pentNums.insert(i * ((3 * i) - 1) / 2);
        hexNums.insert(i * ((2 * i) - 1));
    }

    for (std::set<long long>::const_iterator it = triNums.begin(); it != triNums.end(); ++it) {
        std::cout << *it << "\n";
        if (*it != 40755 && *it != 1 && pentNums.count(*it) > 0 && hexNums.count(*it) > 0) {
            nextTriNum = *it;
            break;
        }
    }

    std::cout << "The next triangle number that's also pentagonal and hexagonal is " << nextTriNum;
}

void Problem46() {
    std::set<long> primes, doubleSquares;
    primes.insert(2);
    for (int i = 3; i < 50000; i += 2) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }

    for (int i = 1; i < (int)sqrt(50000); i += 1) {
        doubleSquares.insert(2 * (long) pow(i, 2));
    }

    bool checkGoldbach = true;
    long startOdd = 9;
    while (checkGoldbach) {
        bool check = false;
        if (primes.count(startOdd) <= 0) {
            for (std::set<long>::const_iterator it = doubleSquares.begin();
                 *it < startOdd && it != doubleSquares.end(); ++it) {
                if (primes.count(startOdd - *it) > 0) {
                    check = true;
                }
            }
        }
        if (check || primes.count(startOdd) > 0) {
            startOdd += 2;
        } else {
            checkGoldbach = false;
        }
    }
    std::cout << "The smallest odd composite that disproves the second Goldbach conjecture is " << startOdd;
}

void Problem47() {
    std::vector<int> primes, addIns;
    std::set<int> sharedFactors;
    primes.emplace_back(2);
    for (int i = 3; i < 300000; i += 2) {
        int j = 0;
        while (j < (int)primes.size() && i % primes[j] != 0) {
            ++j;
        }
        if (j == (int)primes.size()) {
            primes.emplace_back(i);
        }
    }

    int chainPrimes = 0;
    int multFactor = 0, primeNums = 0;
    for (int j = 1000; j < 300000; ++j) {
        int tempNum = j;
        for (int k = 0; primes[k] < j/2; ++k) {
            while (tempNum % primes[k] == 0) {
                tempNum /= primes[k];
                ++multFactor;
            }
            if (multFactor > 0) {
                if (multFactor == 1) {
                    addIns.push_back(primes[k]);
                } else if (multFactor > 1) {
                    addIns.push_back((int)pow(primes[k], multFactor));
                }
                ++primeNums;
            }
            multFactor = 0;
        }
        for (int k = 0; k < (int)addIns.size(); ++k) {
            if (sharedFactors.count(addIns[k]) > 0) {
                sharedFactors.clear();
                chainPrimes = 0;
            }
        }

        for (int k = 0; k < (int)addIns.size(); ++k) {
            sharedFactors.insert(addIns[k]);
        }

        if (primeNums == 4) {
            ++chainPrimes;
            if (chainPrimes == 4) {
                std::cout << "The first of the first 4 consecutive numbers to have 4 unique ";
                std::cout << "prime factors is " << j - 3;
                break;
            }
        } else {
            sharedFactors.clear();
            chainPrimes = 0;
        }
        primeNums = 0;
        addIns.clear();
    }
}

void Problem49() {
    std::string totNum;
    std::set<int> primes;
    for (int i = 1001; i < 10000; i += 2) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }

    for (std::set<int>::const_iterator it = primes.begin(); *it < 5000; ++it) {
        std::string num = std::to_string(*it);
        while (std::next_permutation(num.begin(), num.end())) {
            if (primes.count(std::stoi(num)) > 0) {
                totNum += num;
            }

        }
        if (totNum.size() == 12) {
            if (std::stoi(totNum.substr(4, 4)) - std::stoi(totNum.substr(0, 4)) ==
            std::stoi(totNum.substr(8, 4)) - std::stoi(totNum.substr(4, 4))) {
                std::cout << "The 12-digit number is " << totNum;
                break;
            }
        }
        totNum = "";
    }
}

void Problem50() {
    std::vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < 250000; i += 2) {
        int j = 0;
        while (j < (int)primes.size() && i % primes[j] != 0) {
            ++j;
        }
        if (j == (int)primes.size()) {
            primes.emplace_back(i);
        }
    }

    int savePlace = 1, counter = 0, maxCount = 0, maxCountSum = 0;
    long consecSum = 0;
    for (int i = 0; i < (int)primes.size(); ++i) {
        consecSum += primes[i];
        ++counter;
        if (consecSum > 1000000) {
            i = savePlace;
            ++savePlace;
            consecSum = 0;
            counter = 0;
        } else if (consecSum % 2 == 1 && isPrime(consecSum)) {
            if (counter > maxCount) {
                maxCount = counter;
                maxCountSum = consecSum;
            }
        }
    }
    std::cout << "The prime number that can be made as the longest consecutive sum of\n";
    std::cout << "prime numbers is " << maxCountSum;
}

int checkNums(std::string num) {
    int arr[3] = {0, 0, 0};
    for (size_t i = 0; i < num.size() - 1; ++i) {
        if (num[i] - '0' == 0) {
            ++arr[0];
            if (arr[0] == 3) {
                return 0;
            }
        } else if (num[i] - '0' == 1) {
            ++arr[1];
            if (arr[1] == 3) {
                return 1;
            }
        } else if (num[i] - '0' == 2) {
            ++arr[2];
            if (arr[2] == 3) {
                return 2;
            }
        }
    }
    return -1;
}

void Problem51() {
    std::vector<int> primes;
    std::set<int> primesSet;
    primes.push_back(2);
    primesSet.insert(2);
    for (int i = 3; i < 1000000; i += 2) {
        int j = 0;
        while (j < (int) primes.size() && i % primes[j] != 0) {
            ++j;
        }
        if (j == (int) primes.size()) {
            primes.emplace_back(i);
            primesSet.insert(i);
        }
    }

    for (int i = 0; i < (int)primes.size(); ++i) {
        int arr[3] = {-1, -1, -1};
        if (primes[i] < 10000) {
        } else {
            std::string num = std::to_string(primes[i]);
            std::string origNum = std::to_string(primes[i]);
            int startNum = checkNums(num);
            if (startNum == -1) {
                continue;
            } else {
                size_t counter = 0;
                for (int j = 0; j < (int)num.size() - 1; ++j) {
                    if (num[j]-'0' == startNum && counter < 3) {
                        arr[counter] = j;
                        ++counter;
                    }
                }
                counter = 1;
                while (startNum <= 9) {
                    std::string startNumStr = std::to_string(startNum);

                    for (int j = 0; j < 3; ++j) {
                        num.replace(arr[j], 1, std::to_string(startNum + 1));
                    }
                    if (primesSet.count(std::stoi(num)) > 0) {
                        ++counter;
                    }
                    ++startNum;
                }
                if (counter == 8) {
                    std::cout << origNum;
                    break;
                }
            }
        }
    }
}

void Problem52() {
    bool endLoop = false;
    std::set<int> digits, doubleCheck;
    for (long i = 100000; i < 200000; ++i) {
        long tempNum = i;
        std::string num = std::to_string(i);
        for (size_t j = 0; !endLoop && j <= num.size(); ++j) {
            if (digits.count(num[j]-'0') > 0) {
                digits.clear();
                endLoop = true;
            } else {
                digits.insert(num[j]-'0');
            }
        }

        if (endLoop) {
            endLoop = false;
            continue;
        }

        for (int j = 2; !endLoop && j <= 6; ++j) {
            tempNum = i*j;
            num = std::to_string(tempNum);
            for (size_t k = 0; !endLoop && k <= num.size(); ++k) {
                if (digits.count(num[k]-'0') > 0 && doubleCheck.count(num[k]-'0') <= 0) {
                    doubleCheck.insert(num[k]-'0');
                } else {
                    endLoop = true;
                }
            }
            doubleCheck.clear();
        }
        if (!endLoop) {
            std::cout << "The smallest number containing the same digits for multipliers 1x-6x is " << i;
            break;
        }
        endLoop = false;
        digits.clear();
        doubleCheck.clear();
    }
}

void Problem54() {
    // for cards; index[0] is clubs, 1 is spades, 2 is diamonds, 3 is hearts
    std::vector<int> numsPlayer1(19, 0), numsPlayer2(19, 0);
    int player1Wins = 0, player2Wins = 0;
    std::ifstream infile;
    std::string filetext, filename = "p054_poker.txt", currGame;
    infile.open(filename.c_str());
    while (getline(infile, currGame)) {
        numsPlayer1.clear();
        numsPlayer2.clear();
        std::string player1 = currGame.substr(0, 14);
        std::string player2 = currGame.substr(15);
        numsPlayer1 = processHand(player1);
        numsPlayer2 = processHand(player2);
        bool check1 = royalFlush(numsPlayer1), check2 = royalFlush(numsPlayer2);
        if (check1 || check2) {
            if (check1 && check2) {
            } if (check1) {
                ++player1Wins;
            } else {
                ++player2Wins;
            }
            continue;
        }

        int checkOne = straightFlush(numsPlayer1), checkTwo = straightFlush(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = fourOfAKind(numsPlayer1);
        checkTwo = fourOfAKind(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = fullHouse(numsPlayer1);
        checkTwo = fullHouse(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }


        checkOne = flush(numsPlayer1);
        checkTwo = flush(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = straight(numsPlayer1);
        checkTwo = straight(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = threeOfAKind(numsPlayer1);
        checkTwo = threeOfAKind(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = twoPairs(numsPlayer1);
        checkTwo = twoPairs(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = onePair(numsPlayer1);
        checkTwo = onePair(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

        checkOne = highCard(numsPlayer1);
        checkTwo = highCard(numsPlayer2);
        if (checkOne > -1 || checkTwo > -1) {
            if (checkOne > -1 && checkTwo > -1 && checkOne == checkTwo) {
                int result = compare(numsPlayer1, numsPlayer2);
                if (result == 1) {
                    ++player1Wins;
                } else {
                    ++player2Wins;
                }
            } else if (checkOne > checkTwo) {
                ++player1Wins;
            } else if (checkTwo > checkOne) {
                ++player2Wins;
            }
            continue;
        }

    }
    infile.close();
    std::cout << "Player 1 wins: " << player1Wins << "\n";
    std::cout << "Player 2 wins: " << player2Wins;
}

std::vector<int> findConcatPrimes(const std::vector<int>& listPrimes, std::vector<int> primes) {
    std::vector<int> tmpList = primes;
    for (int i = 0; i < (int)listPrimes.size(); ++i) {
        bool cont = true;
        for (int j = 0; j < (int)tmpList.size(); ++j) {
            if (listPrimes[i] == tmpList[j] ||
            !isPrime(std::stol(std::to_string(listPrimes[i]) + std::to_string(tmpList[j])))
            || !isPrime(std::stol(std::to_string(tmpList[j]) + std::to_string(listPrimes[i])))) {
                cont = false;
            }
        }
        if (cont) {
            tmpList.push_back(listPrimes[i]);
            if (tmpList.size() == 5) {
                return tmpList;
            } else {

                std::vector<int> test = findConcatPrimes(listPrimes, tmpList);
                if (test.size() == 0) {
                    tmpList.pop_back();
                    continue;
                }
            }
        }
    }
    return {};
}

void Problem58() {
    long count = 1;
    int numPrimes = 0, numOdds = 1, row = 1;
    while (((double)numPrimes / numOdds) > .10 || (numPrimes == 0 || numOdds == 0)) {
        for (int i = 1; i <= 4; ++i) {
            count += (row * 2);
            ++numOdds;
            if (isPrime(count)) {
                ++numPrimes;
            }
        }
        ++row;
    }

    --row;
    std::cout << "The size of the side for which the ratio of primes to odds falls\n";
    std::cout << "below 10% is " << 2 * row + 1;
}

void Problem59() {
    std::ifstream infile;
    std::string filetext, filename = "p059_cipher.txt";
    infile.open(filename.c_str());
    infile >> filetext;
    int counter = 0, i = 0;
    std::vector<int> codeCracker;
    while (i < (int)filetext.size()) {
        std::string num = "";
        while (i < (int)filetext.size() && filetext[i] != ',') {
            num += std::to_string(filetext[i]-'0');
            ++i;
        }
        ++i; // adjustment to get past comma
        codeCracker.push_back(std::stoi(num));
        ++counter;
    }
    infile.close();

    std::vector<std::string> code = {"", "", ""};
    int firstChar, secondChar, thirdChar;
    for (int k = 97; k <= 122; ++k) {

        for (firstChar = 0; firstChar < (int)codeCracker.size(); firstChar += 3) {
            int test = codeCracker[firstChar] ^ k;
            if (!((test >= 32 && test <= 93) || (test >= 97 && test <= 122))) {
                break;
            }
        }
        if (firstChar >= (int)codeCracker.size()) {
            code[0].push_back(static_cast<char>(k));
        }

        for (secondChar = 1; secondChar < (int)codeCracker.size(); secondChar += 3) {
            int test = codeCracker[secondChar] ^ k;
            if (!((test >= 32 && test <= 93) || (test >= 97 && test <= 122))) {
                break;
            }
        }
        if (secondChar >= (int)codeCracker.size()) {
            code[1].push_back(static_cast<char>(k));
        }

        for (thirdChar = 2; thirdChar < (int)codeCracker.size(); thirdChar += 3) {
            int test = codeCracker[thirdChar] ^ k;
            if (!((test >= 32 && test <= 93) || (test >= 97 && test <= 122))) {
                break;
            }
        }
        if (thirdChar >= (int)codeCracker.size()) {
            code[2].push_back(static_cast<char>(k));
        }
    }

    std::string key, decryptedSentence;
    int asciiSum = 0;
    for (size_t l = 0; l < code.size(); ++l) {
        key += code[l];
    }

    for (int j = 0; j < (int)codeCracker.size(); ++j) {
        char test;
        if ((j + 3) % 3 == 0) {
            test = codeCracker[j] ^ key[0];
        } else if ((j + 3) % 3 == 1) {
            test = codeCracker[j] ^ key[1];
        } else {
            test = codeCracker[j] ^ key[2];
        }
        asciiSum += test;
        decryptedSentence.push_back(static_cast<char>(test));
    }

    std::cout << "The decoded sentence is:\n\n" << decryptedSentence << "\n";
    std::cout << "The total ASCII sum is " << asciiSum;
}

void Problem60() {
    std::vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < 10000; i += 2) {
        int j = 0;
        while (j < (int) primes.size() && i % primes[j] != 0) {
            ++j;
        }
        if (j == (int) primes.size()) {
            primes.emplace_back(i);
        }
    }

    int lowestSum = 50000;
    for (int i = 0; i < (int)sqrt(primes.size()); ++i) {
        std::vector<int> intro = {primes[i]};
        std::vector<int> test = findConcatPrimes(primes, intro);
        if (test.size() == 5) {
            int sum = 0;
            for (int j = 0; j < (int)test.size(); ++j) {
                sum += test[j];
            }
            if (sum < lowestSum) {
                lowestSum = sum;
            }
        }
    }

    std::cout << "The smallest sum of a set of five primes for which any\n";
    std::cout << "two primes concatenate to produce another prime is " << lowestSum;
}

void Problem67() {
    int arr[100][100];
    std::ifstream infile;
    std::string filename = "p067_triangle.txt", currRow;
    infile.open(filename.c_str());
    int rowNum = 0;
    while (getline(infile, currRow)) {
        int counter = 0;
        for (size_t i = 0; i < currRow.size(); ++i) {
            if (currRow[i] == ' ') {
            } else {
                int currNum = (10*(currRow[i]-'0')) + (currRow[i + 1]-'0');
                arr[rowNum][counter] = currNum;
                ++i;
                ++counter;
            }
        }
        ++rowNum;
    }

    infile.close();

    for (int row = P67_SIZE - 2; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            if (arr[row + 1][col] >= arr[row + 1][col + 1]) {
                arr[row][col] += arr[row + 1][col];
            } else {
                arr[row][col] += arr[row + 1][col + 1];
            }
        }
    }
    std::cout << "The sum of the largest pathway is " << arr[0][0];
}


void Problem69() {
    double maxPhiRatio = 0;
    int max_n = 0;
    std::set<int> primes;
    primes.insert(2);
    for (int i = 3; i <= (int)sqrt(1000000); i += 2) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }

    for (int i = 1; i <= 1000000; ++i) {
        double phi = i, phiRatio = 0;
        int temp_i = i;
        for (int j = 1; j <= sqrt(i); ++j) {
            if (primes.count(j) > 0 && temp_i % j == 0) {
                while (temp_i % j == 0) {
                    temp_i /= j;
                }
                phi *= (1.0 - (1.0 / j));
            }
        }
        if (temp_i > 1) {
            phi *= (1.0 - (1.0 / temp_i));
        }
        phiRatio = (double)i / phi;
        if (phiRatio > maxPhiRatio) {
            maxPhiRatio = phiRatio;
            max_n = i;
        }
    }

    std::cout << "The max n/phi(n) ratio occurs at the n value " << max_n;
}


void Problem76() {
    int sum = 100;
    std::vector<long> nums(sum + 1, 0);
    nums[0] = 1;

    for (long i = 1; i <= 99; ++i) {
        for (long j = i; j <= sum; ++j) {
            nums[j] += nums[j - i];
        }
    }

    std::cout << "The number of ways to write 100 as a sum of at least 2 positive integers is " << nums[100];
}

/*
 * Problem 76:
 *
 * I honestly did this without coding, but wanted to provide an explanation. The rules are pretty
 * simple; all the values within each 3-digit passcode segment come before each other in the actual
 * password. You can just do trial and error by looking at each 3-digit segment and seeing the order
 * of the digits, while making sure all of them are represented. By looking at the first half
 * of the inputs, I noticed that the digits used were limited to 7, 3, 1, 6, 2, 8, 9, and 0, and they
 * seemed to appear in that order exclusively. So, I tried this combination (73162890) and it worked.
 * Trust your intuiton!
 */

void Problem77() {
    std::vector<int> primes;
    primes.emplace_back(2);
    for (int i = 3; i < 200; i += 2) {
        int j = 0;
        while (j < (int)primes.size() && i % primes[j] != 0) {
            ++j;
        }
        if (j == (int)primes.size()) {
            primes.emplace_back(i);
        }
    }
    int sum = 2;
    std::vector<int> nums(sum + 1);
    while (nums[nums.size() - 1] < 5000) {
        nums[0] = 1;
        for (int i = 0; primes[i] < sum; ++i) {
            for (int j = primes[i]; j <= sum; ++j) {
                nums[j] += nums[j - primes[i]];
            }
        }
        if (nums[nums.size() - 1] < 5000) {
            nums.push_back(0);
            for (size_t j = 0; j < nums.size(); ++j) {
                nums[j] = 0;
            }
            ++sum;
        }
    }

    std::cout << "The value which can be written as the sum of primes\n";
    std::cout << "in over five thousand different ways is " << sum;
}

void Problem78() {
    int sum = 1;
    std::vector<int> nums(sum + 1, 0);
    while (nums[nums.size() - 1] % 1000000 > 0) {
        nums[0] = 1;
        for (int i = 0; i < sum; ++i) {
            for (int j = i; j <= sum; ++j) {
                nums[j] += nums[j - i];
            }
        }
        if (nums[nums.size() - 1] % 1000000 > 0) {
            nums.push_back(0);
            for (size_t j = 0; j < nums.size(); ++j) {
                nums[j] = 0;
            }
            ++sum;
        }
    }

    std::cout << "The least value of n for which p(n) is divisible by 1000000 is " << sum;
}

void Problem81() {
    std::ifstream infile;
    std::string line, filename = "p081_matrix.txt";
    infile.open(filename.c_str());
    int arr[P80_SIZE][P80_SIZE];

    for (int i = 0; i < P80_SIZE; ++i) {
        infile >> line;
        std::string currNum;
        int numCounter = 0;
        for (int j = 0; j < (int)line.size(); ++j) {
            if ((j == (int)line.size() - 1) || (line.at(j + 1)) == ',') {
                currNum.push_back(line.at(j));
                arr[i][numCounter] = std::stoi(currNum);
                ++numCounter;
                currNum = "";
            } else if (line.at(j) == ',') {
            } else {
                currNum.push_back(line.at(j));
            }
        }
    }

    for (int x = P80_SIZE - 2; x >= 0; --x) {
        arr[x][P80_SIZE - 1] += arr[x + 1][P80_SIZE - 1];
        arr[P80_SIZE - 1][x] += arr[P80_SIZE - 1][x + 1];
    }

    for (int x = P80_SIZE - 2; x >= 0; --x) {
        for (int y = P80_SIZE - 2; y >= 0; --y) {
            arr[x][y] += std::min(arr[x + 1][y], arr[x][y + 1]);
        }
    }

    std::cout << "The min path sum only going right and down is " << arr[0][0];
}