
if [ $1>0 ]; then 
    b=$1
else 
    b=21
fi
if [ $2>0 ]; then 
    output=$2
else 
    output=fizzbuzz.txt
fi

printf "">$output


st=`date +%s`
fizzbuzz() {
    m=""
    printf "$1. ">>$output
    if [ $(($1 % 3)) = 0 ]; then 
        m= Fizz
    fi
    if [ $(($1 % 5)) = 0 ]; then 
        m=${m}Buzz
    fi
    return $m
}

for (( n=0; n<=$b; n++ ))
    do p=`fizzbuzz $n`;
       printf $p
    done


ed=`date +%s`
echo Completed in $(( (ed - st)/1000000 )) ms
echo Each iteration took `awk "BEGIN {print (($ed - $st))/$b }"` s
echo `awk "BEGIN {printf \"%.4f\n\", $b/(($ed - $st))}"` numbers per s
