
if [ $1>0 ]; then 
    b=$1
else 
    b=21
fi


st=`date +%s%N`
fizzbuzz() {
    printf "$1. "
    if [ $(($1 % 15)) = 0 ]; then 
        printf Fizz
    fi
    if [ $(($1 % 5)) = 0 ]; then 
        printf Buzz
    fi
    echo
}

for (( n=0; n<=$b; n++ ))
    do fizzbuzz $n;
    done


ed=`date +%s%N`
echo Completed in $(( (ed - st)/1000000 )) ms
echo Each iteration took `awk "BEGIN {print (($ed - $st)/1000000)/$b }"` ms
echo `awk "BEGIN {printf \"%.4f\n\", $b/(($ed - $st)/1000000)}"` numbers per ms
