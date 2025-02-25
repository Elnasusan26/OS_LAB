read -p "ENter a no : " n
fact=1
i=1
while (( i <= n )); do
      fact=$(( fact * i ))
      i=$(( i + 1 ))
done
echo "$fact"
