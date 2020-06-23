import time 

def genBuzzList():
    buzz15 = []
    for i in range(0,15):
        if i % 15 == 0:
            buzz15.append("FizzBuzz")
        elif i % 5 == 0:
            buzz15.append("Buzz")
        elif i % 3 == 0:
            buzz15.append("Fizz")
        else:
            buzz15.append("----")
    return buzz15


#print(genBuzzList())

buzzList = ['FizzBuzz', '----', '----', 'Fizz', '----', 'Buzz', 'Fizz', '----', '----', 'Fizz', 'Buzz', '----', 'Fizz', '----', '----']

def listBuzz(n):
    return buzzList[n % 15]


st = time.time_ns()

[listBuzz(i) for i in range(1000001)]
ed=time.time_ns()
print(f"{(ed-st)/1000000:0.4f} ms")

print(f"{(ed-st) / 1000000} ns per iteration")