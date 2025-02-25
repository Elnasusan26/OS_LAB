read -p "Enter the size of the array : " n
echo Enter the elements 
for (( i=0; i < n; i++)); do
      read a[$i]
done
read -p "Enter the element to be search : " s
for (( i=0; i < n; i++)) do
      if [ ${a[$i]} -eq $s ]; then
            echo element found
            break
      fi
done
