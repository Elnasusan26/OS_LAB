echo "Enter the no. :"
read n
if [ $n -lt 0 ]; then
      echo "-ve"
elif [ $n -gt 0 ]; then
      echo "+ve"
else
      echo "Zero"
fi
