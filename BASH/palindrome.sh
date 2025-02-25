read -p "Enter a string : " s
rev="$(rev <<< "$s")"
if [ $rev == $s ]; then
      echo PAl
else
      echo NOT PAL
fi
