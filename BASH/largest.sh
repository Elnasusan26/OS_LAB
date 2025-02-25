read -p "Enter 3 no. :" a b c
if [ $a -gt $b ] && [ $a -gt $c ]; then
      echo "$a is the grreatest"
elif [ $b -gt $a ] && [ $b -gt $c ]; then
      echo "$b is the largest"
else
      echo "$c is the largest"
fi
