import time, logging as l

ITERATIONS = 10000
FULLSET = ['FizzBuzz', '----', '----', 'Fizz', '----', 'Buzz', 'Fizz', '----', '----', 'Fizz', 'Buzz', '----', 'Fizz', '----', '----']

l.basicConfig(  level=l.INFO,
                format='%(asctime)-18s %(name)-5s %(levelname)-8s||   %(message)s',
            #datefmt='%d'
            )
st = time.time_ns()
FIZZDICT = {i:v for i, v in enumerate(FULLSET) }
ed=time.time_ns()
l.info(f"Cached dict: {FIZZDICT.__sizeof__()} bytes in {ed-st} nanoseconds ")



def genBuzzList(n=15):
    buzz = []
    for i in range(0,n):
        if i % 15 == 0:
            buzz.append("FizzBuzz")
        elif i % 3 == 0:
            buzz.append("Fizz")
        elif i % 5 == 0:
            buzz.append("Buzz")
        else:
            buzz.append("-")
    return buzz



def headerReporting(func, iterations)->str:
    return f"Testing {func} with {str(iterations)}  |   "



def fizzBuzzTimer(func, n=None, label=None):
    report = ""  
    if n:
        report+=headerReporting(label,n)
        st = time.time_ns()
        a=[func(i) for i in range(n+1)]
        ed=time.time_ns()
    else:
        report+=f"Testing {label}  |"
        st = time.time_ns()
        b = func()
        ed=time.time_ns()

    report+=f"{((ed-st)/1000):0.4f} μs   | "
    report+=f"{(ed-st):0.6f} ns per iteration."
    l.info(report)
    return 


def runAlgo(func, iterations=1000):
    return [func(i) for i in range(iterations)]

def dictBuzz(iterations=1000):
    return [FIZZDICT[i % 15] for i in range(iterations)]

def listBuzz(n):
    return FULLSET[n % 15]

def cachedLookup(n=ITERATIONS):
    return [FULLSET[i % 15] for i in range(n)]


if __name__=='__main__':
    stt=time.time_ns()
    ett=time.time_ns()
    l.info(f"Time test - {ett-stt}")
    cLambda = lambda  n: FULLSET[n % 15]
    staticBuzz = lambda  n: ['FizzBuzz', '----', '----', 'Fizz', '----', 'Buzz', 'Fizz', '----', '----', 'Fizz', 'Buzz', '----', 'Fizz', '----', '----'][n % 15]

    fizzBuzzTimer(cLambda, ITERATIONS, label="Var Lambda")
    fizzBuzzTimer(staticBuzz, ITERATIONS, label="staticBuzz Lambda")
    #fizzBuzzTimer(dictBuzz, ITERATIONS, label="Dict Buzz")
    fizzBuzzTimer(listBuzz, ITERATIONS, label="List Buzz")
    fizzBuzzTimer(cachedLookup, label="Direct Cache")
    #fizzBuzzTimer(genBuzzList,  ITERATIONS, label='Ifs')




