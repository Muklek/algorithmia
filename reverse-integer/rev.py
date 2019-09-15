""" check cpp for problem statement """

def reverse(number):
    reverse=0
    numberToRev=number
    while(numberToRev > 0):
        lastDigit = numberToRev % 10
        reverse = (reverse * 10) + lastDigit
        numberToRev = int(numberToRev / 10)
        print("number bein reversed " + str(number))
        print("reverse number " + str(reverse))

if __name__ == '__main__':
    reverse(1233450)
