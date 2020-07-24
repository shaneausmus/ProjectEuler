import sys
from math import sqrt, floor, factorial
from itertools import permutations
from decimal import getcontext, localcontext, Decimal, ROUND_DOWN, ROUND_FLOOR


def convert_binary(num):
    binary = ""
    if (num == 0) or (num == 1):
        binary += str(num)
    else:
        binary += convert_binary(int(num / 2)) + str(num % 2)
    return binary


def is_palindrome(word):
    word = str(word)
    return word == word[::-1]


def get_reverse(data):
    return int(str(data)[::-1])


def is_prime_list(num, list_primes):
    for prime in list_primes:
        if prime > sqrt(num):
            break
        if num % prime == 0:
            return False
    return True


def is_prime(num):
    if num % 2 == 0:
        return False
    for i in range(3, int(sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


def get_triangle_nums(num):
    n = 1
    next_tri_num = int(n * (n + 1) / 2)
    triangle_nums = set()
    while next_tri_num < num:
        if next_tri_num >= 1000:
            triangle_nums.add(next_tri_num)
        n += 1
        next_tri_num = int(n * (n + 1) / 2)
    return triangle_nums


def get_square_nums(num):
    n = 1
    next_square_num = int(pow(n, 2))
    square_nums = set()
    while next_square_num < num:
        if next_square_num >= 1000:
            square_nums.add(next_square_num)
        n += 1
        next_square_num = int(pow(n, 2))
    return square_nums


def get_pentagonal_nums(num):
    n = 1
    next_pent_num = int(n * ((3 * n) - 1) / 2)
    pent_nums = set()
    while next_pent_num < num:
        if next_pent_num >= 1000:
            pent_nums.add(next_pent_num)
        n += 1
        next_pent_num = int(n * ((3 * n) - 1) / 2)
    return pent_nums


def return_pent_num(n):
    return int(n * ((3 * n) - 1) / 2)


def get_hexagonal_nums(num):
    n = 1
    next_hex_num = n * ((2 * n) - 1)
    hex_nums = set()
    while next_hex_num < num:
        if next_hex_num >= 1000:
            hex_nums.add(next_hex_num)
        n += 1
        next_hex_num = n * ((2 * n) - 1)
    return hex_nums


def get_heptagonal_nums(num):
    n = 1
    next_hept_num = int(n * ((5 * n) - 3) / 2)
    hept_nums = set()
    while next_hept_num < num:
        if next_hept_num >= 1000:
            hept_nums.add(next_hept_num)
        n += 1
        next_hept_num = int(n * ((5 * n) - 3) / 2)
    return hept_nums


def get_octagonal_nums(num):
    n = 1
    next_oct_num = n * ((3 * n) - 2)
    oct_nums = set()
    while next_oct_num < num:
        if next_oct_num >= 1000:
            oct_nums.add(next_oct_num)
        n += 1
        next_oct_num = n * ((3 * n) - 2)
    return oct_nums


def Problem26():
    end_loop = False
    check_reptend = 0
    for i in range(1000, 0, -1):
        check_prime = True
        if end_loop:
            break
        j = 2
        while j < floor(sqrt(i)) and check_prime:
            if i % j == 0:
                check_prime = False
            j = j + 1
        if check_prime:
            for k in range(1, i):
                if pow(10, k) % i == 1:
                    # need the only value under i that is k that where
                    # 10^k mod i = 1 is where k = i - 1
                    check_reptend = k
                    break
            if check_reptend == i - 1:
                end_loop = True
            else:
                check_reptend = 0

    print(check_reptend + 1)


def Problem29():
    myset = set()
    for i in range(2, 101):
        for j in range(2, 101):
            myset.add(pow(i, j))

    print('The total number of distinct terms is ' + str(len(myset)))


def Problem34():
    sum_factorions = 0
    list_factorials = []
    for i in range(0, 10):
        list_factorials.append(factorial(i))

    for num in range(3, factorial(9)):
        fact_total = 0
        temp_num = str(num)
        for i in range(0, len(temp_num)):
            fact_total += list_factorials[int(temp_num[i])]
        if fact_total == num:
            sum_factorions += num

    print("The sum of all factorions is " + str(sum_factorions))


def Problem36():
    sum_double_base = 0
    # uses helper is_palindrome and convert_binary methods
    for i in range(1, 1000000):
        if is_palindrome(i) and is_palindrome(convert_binary(i)):
            sum_double_base += i

    print("The sum of all double-base palindromes in base 2 and base 10 is " + str(sum_double_base))


def Problem43():
    num = "1406357289"
    sum = 0
    check = True
    pandigital_list = list("".join(perm) for perm in permutations(num))

    primes = [2, 3, 5, 7, 11, 13, 17]
    for pan_num in pandigital_list:
        for i in range(0, len(primes)):
            if int(pan_num[i + 1:i + 4]) % primes[i] != 0:
                check = False
                break
        if check:
            sum += int(pan_num)
        else:
            check = True
    print("The sum of all pandigital numbers with the listed property is " + str(sum))


def Problem48():
    sum = 0
    for i in range(1, 1001):
        sum += pow(i, i)
    sum = sum % 10000000000
    print("The last ten digits of the series of self powers is " + str(sum))


def Problem50():
    num_terms_over_million = 0
    for n in range(23, 101):
        for r in range(0, n + 1):
            term = factorial(n) / (factorial(r) * factorial(n - r))
            if term > 1000000:
                num_terms_over_million += (n + 1) - (2 * r)
                break
    print("The number of binomial terms over a million in the range of 0 - 100 is " + str(num_terms_over_million))


def Problem55():
    num_non_lychrels = 0
    for i in range(1, 10000):
        counter = 0
        temp_num = i
        while counter < 50:
            reverse = get_reverse(temp_num)
            check_palindrome = temp_num + reverse
            temp_num = check_palindrome
            if is_palindrome(check_palindrome):
                num_non_lychrels += 1
                break
            counter += 1

    # looking for all lychrel numbers less than 10000, so can subtract by 9999
    print("The number of lychrel numbers below 10000 is " + str(9999 - num_non_lychrels))


def Problem56():
    max_sum = 0
    for i in range(50, 101):
        for j in range(50, 101):
            sum = 0
            num = int(pow(i, j))
            while num != 0:
                sum += int(num % 10)
                num = num // 10  # allows floor division
            if sum > max_sum:
                max_sum = sum
    print("The largest digit sum is " + str(max_sum))


def Problem57():
    p = q = 1
    counter = 0
    for i in range(2, 1001):
        temp1 = p
        temp2 = q
        p = temp1 + (2 * temp2)
        q = temp1 + temp2
        if len(str(p)) > len(str(q)):
            counter += 1
    print("The number of expansions for which the numerator had more digits than the denom. was " + str(counter))


def check_if_num_present(first_num, sum, num, check_sets, used_nums):
    if len(check_sets) == 0 and str(first_num)[:2] == str(num)[-2:]:
        return sum
    elif len(check_sets) == 0:
        return -1

    prev_size = len(check_sets)
    last_two_digits = str(num)[-2:]
    for j in range(0, len(check_sets)):
        for element in check_sets[j]:
            if str(element)[:2] == last_two_digits and element not in used_nums:
                new_kinds_of_nums = check_sets.copy()
                new_used_nums = used_nums.copy()
                new_used_nums.add(element)
                new_kinds_of_nums.pop(j)
                check = check_if_num_present(first_num, (sum + element), element, new_kinds_of_nums, new_used_nums)
                if check > -1:
                    return check

    if prev_size == len(check_sets):
        return -1


def Problem61():
    # getting set of all geometric numbers under 10000 for each of the required sets
    sum = 0
    tri_nums = get_triangle_nums(10000)
    square_nums = get_square_nums(10000)
    pent_nums = get_pentagonal_nums(10000)
    hex_nums = get_hexagonal_nums(10000)
    hept_nums = get_heptagonal_nums(10000)
    oct_nums = get_octagonal_nums(10000)
    for i in range(1000, 10000):
        sum = 0
        kinds_of_nums = [oct_nums, hept_nums, hex_nums, pent_nums, square_nums, tri_nums]
        prev_size = len(kinds_of_nums)
        last_two_digits = str(i)[-2:]
        for j in range(0, len(kinds_of_nums)):
            for element in kinds_of_nums[j]:
                if element == i:
                    sum += i
                    kinds_of_nums.pop(j)
                    break
            if prev_size > len(kinds_of_nums):
                break

        used_nums = set()
        used_nums.add(i)
        if prev_size > len(kinds_of_nums):
            sum = i
            for j in range(0, len(kinds_of_nums)):
                for element in kinds_of_nums[j]:
                    if str(element)[:2] == last_two_digits and element not in used_nums:
                        new_kinds_of_nums = kinds_of_nums.copy()
                        new_used_nums = used_nums.copy()
                        new_used_nums.add(element)
                        new_kinds_of_nums.pop(j)
                        result = check_if_num_present(i, (i + element), element, new_kinds_of_nums, new_used_nums)
                        if result == -1:
                            continue
                        else:
                            sum = result
                            break
                if sum > i:
                    break
            if sum > i:
                break

    print("The sum is " + str(sum))


def Problem62():
    # taking a stab at the range here; we know it must start at 345 based on the problem
    cubes = {}
    save_cube = ""
    for i in range(1, 40000):
        nums_in_cube = ''.join(sorted(str(int(pow(i, 3)))))
        if nums_in_cube in cubes.keys():
            cubes[nums_in_cube] += 1
        else:
            cubes[nums_in_cube] = 1

    for i in range(1, 40000):
        power = int(pow(i, 3))
        nums_in_i = ''.join(sorted(str(power)))
        if cubes[nums_in_i] == 5:
            save_cube = str(power)
            break

    print("The first cube for which 5 of its permutations are cubes is " + save_cube)


def Problem63():
    count = 0
    check = False
    for i in range(1, 5000):
        j = 1
        while j < 5000:
            num = int(pow(i, j))
            length = len(str(num))
            if length > j:
                break
            elif length == j:
                count += 1
            j += 1
        check = False

    print("The number n-digit positive integers that exist which are also nth powers is " + str(count))


def Problem64():
    squares = set()
    i = 1
    while pow(i, 2) <= 10000:
        squares.add(pow(i, 2))
        i += 1

    num_odd_periods = 0
    maxX = D = 0
    for d in range(1, 10001):
        if d not in squares:
            period_length = 0
            a = floor(sqrt(d))
            p = a_init = a
            q = 1
            P = 0
            Q = 1
            counter = 0
            #              0  1  2  3  4  5  6  7  8  9,10,11
            prev_values = [a, a, p, p, p, q, q, q, P, P, Q, Q]
            while prev_values[0] != (2 * a_init):
                counter += 1
                if counter != 1:
                    prev_values[9] = prev_values[8]
                    prev_values[11] = prev_values[10]
                    prev_values[1] = prev_values[0]
                    P = prev_values[8] = (prev_values[1] * prev_values[11]) - prev_values[9]
                    Q = prev_values[10] = (d - pow(P, 2)) / prev_values[11]
                    a = prev_values[0] = floor((a_init + P) / Q)
                    prev_values[4] = prev_values[3]
                    prev_values[3] = prev_values[2]
                    p = prev_values[2] = (a * prev_values[3]) + prev_values[4]
                    prev_values[7] = prev_values[6]
                    prev_values[6] = prev_values[5]
                    q = prev_values[5] = (a * prev_values[6]) + prev_values[7]
                else:
                    P = prev_values[8] = a
                    Q = prev_values[10] = d - pow(a, 2)
                    a = prev_values[0] = floor((a_init + P) / Q)
                    p = prev_values[2] = prev_values[1] * a + 1
                    q = prev_values[5] = a
                period_length += 1
            if period_length % 2 == 1:
                num_odd_periods += 1

    print("The number of odd periods below 10000 is " + str(num_odd_periods))


def Problem65():
    twosCounter = numerator = 0
    counter = oneIterationsBack = 2
    twoIterationsBack = multFactor = 1
    for i in range(1, 100):
        numerator = (multFactor * oneIterationsBack) + twoIterationsBack
        twoIterationsBack = oneIterationsBack
        oneIterationsBack = numerator
        counter += 1
        if counter == 3:
            twosCounter += 2
            multFactor = twosCounter
            counter = 0
        else:
            multFactor = 1

    charSum = 0
    numeratorStr = str(numerator)
    print(numeratorStr + "\n")
    for i in range(0, len(numeratorStr)):
        charSum += int(numeratorStr[i])
    print("The sum of the digits in the numerator of the 100th convergent is " + str(charSum))


def Problem66():
    squares = set()
    i = 1
    while pow(i, 2) <= 1000:
        squares.add(pow(i, 2))
        i += 1

    maxX = D = 0
    for d in range(1, 1001):
        if d not in squares:
            a = floor(sqrt(d))
            p = a_init = a
            q = 1
            P = 0
            Q = 1
            counter = 0
            #              0  1  2  3  4  5  6  7  8  9,10,11
            prev_values = [a, a, p, p, p, q, q, q, P, P, Q, Q]
            while pow(p, 2) - (d * pow(q, 2)) != 1:
                counter += 1
                if counter != 1:
                    prev_values[9] = prev_values[8]
                    prev_values[11] = prev_values[10]
                    prev_values[1] = prev_values[0]
                    P = prev_values[8] = (prev_values[1] * prev_values[11]) - prev_values[9]
                    Q = prev_values[10] = (d - pow(P, 2)) / prev_values[11]
                    a = prev_values[0] = floor((a_init + P) / Q)
                    prev_values[4] = prev_values[3]
                    prev_values[3] = prev_values[2]
                    p = prev_values[2] = (a * prev_values[3]) + prev_values[4]
                    prev_values[7] = prev_values[6]
                    prev_values[6] = prev_values[5]
                    q = prev_values[5] = (a * prev_values[6]) + prev_values[7]
                else:
                    P = prev_values[8] = a
                    Q = prev_values[10] = d - pow(a, 2)
                    a = prev_values[0] = floor((a_init + P) / Q)
                    p = prev_values[2] = prev_values[1] * a + 1
                    q = prev_values[5] = a
            if p > maxX:
                maxX = p
                D = d

    print("The largest x under D <= 1000 is obtained when D = " + str(D))


# creds to mathblog.dk for helping with this solution
def Problem68():
    num_list = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']
    fivegon_list = list(permutations(num_list))

    max_fivegon = 0
    for fivegon in fivegon_list:
        # checks to see if all linear clockwise segments of the 5-gon
        # have the same sum
        sum = int(fivegon[0]) + int(fivegon[1]) + int(fivegon[2])
        if sum != int(fivegon[3]) + int(fivegon[2]) + int(fivegon[4]) or \
                sum != int(fivegon[5]) + int(fivegon[4]) + int(fivegon[6]) \
                or sum != int(fivegon[7]) + int(fivegon[6]) + int(fivegon[8]) \
                or sum != int(fivegon[9]) + int(fivegon[8]) + int(fivegon[1]):
            continue
        # checks to see if fivegon[0] is the lowest external node
        if int(fivegon[0]) >= int(fivegon[3]) or int(fivegon[0]) >= int(fivegon[5]) \
                or int(fivegon[0]) >= int(fivegon[7]) or int(fivegon[0]) >= int(fivegon[9]):
            continue
        # checks to see that 10 won't be repeated twice, allowing for a 16-digit sum
        if fivegon[1] == '10' or fivegon[2] == '10' or fivegon[4] == '10' or fivegon[6] == '10' or fivegon[8] == '10':
            continue

        curr_fivegon = fivegon[0] + fivegon[1] + fivegon[2] + fivegon[3] + fivegon[2] + fivegon[4] + \
                       fivegon[5] + fivegon[4] + fivegon[6] + fivegon[7] + fivegon[6] + fivegon[8] + \
                       fivegon[9] + fivegon[8] + fivegon[1]
        if int(curr_fivegon) > max_fivegon:
            max_fivegon = int(curr_fivegon)

    print("The maximum 16-digit fivegon is " + str(max_fivegon))


# this implementation could be improved on; takes a while to run but I
# did what I could to reduce the search space
def Problem70():
    minPhiRatio = 50  # arbitrary number
    min_n = 0
    primes = set()
    primes.add(2)
    for i in range(3, int(sqrt(10000000)), 2):
        if is_prime(i):
            primes.add(i)

    for i in range(5000001, 10000000, 2):
        phi = i
        temp_i = i
        for j in range(2, int(sqrt(i))):
            if j in primes and temp_i % j == 0:
                while temp_i % j == 0:
                    temp_i /= j
                phi *= (1.0 - (1.0 / j))
        if temp_i > 1:
            phi *= (1.0 - (1.0 / temp_i))
        sort_phi = ''.join(sorted(str(int(phi))))
        sort_i = ''.join(sorted(str(i)))
        if sort_phi == sort_i:
            phiRatio = i / phi
            if phiRatio < minPhiRatio:
                minPhiRatio = phiRatio
                min_n = i

    print("The max n/phi(n) ratio occurs at the n value " + str(min_n))
    print("This gives us the ratio " + str(minPhiRatio))


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def Problem71():
    a = 2
    b = 5
    c = 3
    d = 7
    # squeezing the sample space between 2/5 and 3/7 by calculating the medians until the
    # denominator is larger than 1000000 --> this approach gets us the right answer quickly
    while b + d < 1000000:
        print(str(a) + "/" + str(b) + " < " + str(a + c) + "/" + str(b + d) + " < " + str(c) + "/" + str(d))
        a = a + c
        b = b + d

    print("The numerator immediately to the left of 3/7 is " + str(a))


def get_totient(i, primes):
    phi = i
    temp_i = i
    for j in range(2, int(sqrt(i)) + 1):
        if j in primes and temp_i % j == 0:
            while temp_i % j == 0:
                temp_i /= j
            phi *= (1.0 - (1.0 / j))
    if temp_i > 1:
        phi *= (1.0 - (1.0 / temp_i))

    return phi


def Problem72():
    primes = set()
    primes.add(2)
    for i in range(3, int(sqrt(10000000)), 2):
        if is_prime(i):
            primes.add(i)

    farey_length = 0
    n = 2
    while n < 1000001:
        # Project Euler ignores the first two terms (0/1 and 1/1) that are in sequence F[1]
        # Therefore, all you need to do is add together all the totients until n == 1000000
        farey_length += get_totient(n, primes)
        n += 1

    print("The length of a farey sequence with n == 1000000 is " + str(farey_length))


# the counter below will begin as soon as x == start_num and y == start_denom;
# once x == stop_num and y == stop_denom, the counter will stop incrementing
# and the while loop will break, returning the number of terms in the Farey
# sequence in between start_num/start_denom and stop_num/stop_denom
def gen_farey_list(n, start_num, start_denom, stop_num, stop_denom):
    x1 = x = y = counter = 0
    y1 = x2 = 1
    y2 = n
    record_numbers = False
    while not (x == stop_num and y == stop_denom):
        x = floor((y1 + n) / y2) * x2 - x1
        y = floor((y1 + n) / y2) * y2 - y1
        x1 = x2
        x2 = x
        y1 = y2
        y2 = y
        if record_numbers and x != stop_num and y != stop_denom:
            counter += 1
        if x == start_num and y == start_denom:
            record_numbers = True
    return counter


def Problem73():
    num_terms = gen_farey_list(12000, 1, 3, 1, 2)
    print("The number of terms between 1/3 and 1/2 for d <= 12000 is " + str(num_terms))


def Problem74():
    num_60s = 0
    nums_in_chain = set()
    for i in range(1, 1000001):
        tmp1 = i
        counter = 1
        fact_sum = 0
        nums_in_chain.add(tmp1)
        while tmp1:
            fact_sum += factorial(int(tmp1 % 10))
            tmp1 //= 10
        while fact_sum not in nums_in_chain:
            nums_in_chain.add(fact_sum)
            counter += 1
            tmp1 = fact_sum
            fact_sum = 0
            while tmp1:
                fact_sum += factorial(int(tmp1 % 10))
                tmp1 //= 10
        if counter == 60:
            num_60s += 1
        nums_in_chain.clear()

    print("There are " + str(num_60s) + " numbers below 1000000 with a chain of 60")


def Problem75():
    triple_sums = dict()
    top = 1500001
    for m in range(1, int(sqrt(top / 2))):
        for n in range(1, m):
            if gcd(m, n) == 1 and (m - n) % 2 == 1:
                a = pow(m, 2) - pow(n, 2)
                b = 2 * m * n
                c = pow(m, 2) + pow(n, 2)
                num = a + b + c
                while num < top:
                    if num not in triple_sums.keys():
                        triple_sums.update({num: 0})
                    triple_sums[num] += 1
                    num += a + b + c

    counter = 0
    for key in triple_sums.keys():
        if triple_sums[key] == 1:
            counter += 1

    print("The number of pythagorean triples summing to a number")
    print("from 1 to 1500000 only once is " + str(counter))


# based on recurrence relation from pentagonal numbers stating that
# p(n) = sum(k)[(-1)**(k-1) * p(n - g sub k)], where g_{k} is the kth generalized pentagonal number
def Problem78():
    n = i = 1
    num_partitions = [1]
    while i <= n:
        num_partitions.append(0)
        for j in range(1, i + 1):
            mult = (-1) ** (j + 1)
            for pent in [return_pent_num(j), return_pent_num(-j)]:
                if i - pent >= 0:
                    num_partitions[i] = num_partitions[i] + mult * num_partitions[i - pent]
        i += 1
        if i >= n:
            if num_partitions[len(num_partitions) - 1] % 1000000 == 0:
                break
            else:
                n += 1

    print("The least value of n for which 1000000 | p(n) is " + str(n))


def Problem80():
    squares = set()
    for i in range(1, 11):
        squares.add(pow(i, 2))

    digit_sum = 0
    for i in range(1, 101):
        if i not in squares:
            with localcontext() as c:
                c.prec = 102
                num = Decimal(i).sqrt()
                num = str(num)
                for j in range(0, len(num) - 2):
                    if num[j] == '.':
                        pass
                    else:
                        digit_sum += int(num[j])

    print("The total digit sum to 100 places for irrational square roots below 100 is " + str(digit_sum))


def main():
    # call any one of the above functions here!
    pass

if __name__ == '__main__':
    main()
