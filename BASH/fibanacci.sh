read -p "Enter  the no. ofd terms : " n
x=0
y=1
i=2
echo finacci series of $n :-
echo $x $y
for (( i=0; i < n-2; i++ )); do
      z=$(( x + y))
      echo $z
      x=$y
      y=$z
done
