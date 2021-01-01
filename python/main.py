import time, logging as l

l.basicConfig(  level=l.INFO,
                format='%(asctime)-18s %(name)-5s %(levelname)-8s||   %(message)s',
            #datefmt='%d'
            )


def genBuzzList(n=15):
    buzz = ["0"]
    for i in range(1,n+1):
        if i % 15 == 0:
            buzz.append("FizzBuzz")
        elif i % 5 == 0:
            buzz.append("Buzz")
        elif i % 3 == 0:
            buzz.append("Fizz")
        else:
            buzz.append("-")
    return buzz


l.info(f"Making {'15'} cached FizzBuzz terms ")
st = time.time_ns()
cachedFizz = genBuzzList()
ed=time.time_ns()
l.info(f"Cached {cachedFizz} - {cachedFizz.__sizeof__()} bytes in {ed-st} nanoseconds ")



st = time.time_ns()
fizzDict = {i:v for i, v in enumerate(cachedFizz) }
ed=time.time_ns()
l.info(f"Cached {fizzDict} - {fizzDict.__sizeof__()} bytes in {ed-st} nanoseconds ")




def headerReporting(func, iterations)->str:
    return f"Testing {func} with {str(iterations)}"


def cachedLookup(l=cachedFizz,n=1000001):
    return [l[i % 15] for i in range(n)]


def fizzBuzzTimer(func, n=None, label=None):      
    if label:
        l.info(f"Testing {label}")
    else:
        l.info(headerReporting(func,n)) 

    st = time.time_ns()
    if n:
        memSize=[func(i) for i in range(n+1)].__sizeof__()
    else:
        t = func()
        memSize=t.__sizeof__()
        n = n or len(t)
    ed=time.time_ns()
    l.info(f"{((ed-st)/n):0.4f} ms")
    l.info(f"{(ed-st) / n:0.6f} ns per iteration. Resultant size: {memSize}")
    return 


lfizzBuzz = lambda  n: ['FizzBuzz', '----', '----', 'Fizz', '----', 'Buzz', 'Fizz', '----', '----', 'Fizz', 'Buzz', '----', 'Fizz', '----', '----'][n % 15]
cLambda = lambda  n: cachedFizz[n % 15]


def listBuzz(n):
    return cachedFizz[n % 15]

fizzBuzzTimer(lfizzBuzz, 1000001)
fizzBuzzTimer(listBuzz, 1000001)
fizzBuzzTimer(cachedLookup, label="Direct Cache")




fizzBuzzTimer(lfizzBuzz, 10000)

st = time.time_ns()

ed=time.time_ns()
print(f"{(ed-st)/1000000:0.4f} ms")

print(f"{(ed-st) / 1000000} ns per iteration")