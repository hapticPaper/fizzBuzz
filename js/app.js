max = 1000000

fbDict = {
    0:'FizzBuzz',
    1:'',
    2:'',
    3:'Fizz',
    4:'',
    5:'Buzz',
    6:'',
    7:'',
    8:'',
    9:'Fizz',
    10:'',
    11:'',
    12:'Fizz',
    13:'',
    14:''
}

function dur(startTime){
	var endT = new Date()
    return (endT - startTime)
};

function fizzDict(n){
    return `${n}. ${fbDict[n % 15]}\n`
}    

function fizzIf(n){
    if (n % 15 === 0){
        return `${n}. FizzBuzz\n`
    }
    else if (n % 5 === 0){
        return `${n}. Buzz\n`
    }
    else if (n % 3 === 0){
        return `${n}. Fizz\n`
    }
    return `${n}.\n`
}

function hashBuzz(n){
    return `${['FizzBuzz', '--', '--', 'Fizz', '--', 'Buzz', 'Fizz', '--',
            '--', 'Fizz', 'Buzz', '--', 'Fizz', '--', '--'][n % 15]}`
}


BUZZSET = ["--","Buzz","Fizz","FizzBuzz"]
function shortBuzz(n){return BUZZSET[2*(n%3==0)+(n%5==0)]}






function fizzCase(n){
    
    switch(0){
        case n % 15:
            return 'FizzBuzz'
        case n % 5:
            return 'Buzz'
        case n % 3:
            return 'Fizz'
        default: 
            return '--'

    };
}


st = new Date()
output = ""
for (i=0; i<=max; i++){
    output+=`${i}. ${hashBuzz(i)}\n`
}
done = new Date()
console.log(output.slice(0,99))
console.log(`...\nCompleted in ${done - st} ms`)
console.log(`${(max/((done - st)/1000)).toFixed(0).toLocaleString()} numbers per second`)
console.log(`${(done - st)/1000} ms per number`)