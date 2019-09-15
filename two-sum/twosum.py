def findPairs(numberList, numberToCheck):
    numberDict={}
    for number in numberList:
        calc = numberToCheck - number
        if(number in numberDict):
            return [numberDict[number], number]
        numberDict[calc] = number

def main():
    numbers=[1,2,3,4,5,6]
    print(findPairs(numbers, 5))

if __name__ == '__main__':
    main()
