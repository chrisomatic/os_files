result=$(pacman -Qu | grep -Fcv "[ignored]" | sed "s/^/ /;s/^0$//g")
if [[ $result ]]; then
    echo $result
else
    echo  0
fi
