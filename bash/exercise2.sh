####################################################################################################################
#       __  ___      ___  _______   _______        __       _______    _______   _______   
#      /""\|"  \    /"  |/"     "| /"      \      /""\     /" _   "|  /"     "| /"      \  
#     /    \\   \  //  /(: ______)|:        |    /    \   (: ( \___) (: ______)|:        | 
#    /' /\  \\\  \/. ./  \/    |  |_____/   )   /' /\  \   \/ \       \/    |  |_____/   ) 
#   //  __'  \\.    //   // ___)_  //      /   //  __'  \  //  \ ___  // ___)_  //      /  
#  /   /  \\  \\\   /   (:      "||:  __   \  /   /  \\  \(:   _(  _|(:      "||:  __   \  
# (___/    \___)\__/     \_______)|__|  \___)(___/    \___)\_______)  \_______)|__|  \___) 
#                                                                                          
# Create a shell script able to accept as an input a file with one number per line and return their average.
# It must support an arbitrary file length.
#
# Bonus: in case the lines are CSV (comma-separed values) treat each column as a different file, returning the 
#        averages as a single CSV line.
# 
####################################################################################################################
#!/bin/bash  
filename=$1  
let sum=0
i=0
while read line || [ -n "$line" ]; do
sum=$(expr $sum +  $line )
i=$((i+1))  
done < $filename
python -c "print($sum/$i)" # I used python interactive shell as floating point division is not supported in bash if int division is required echo $(($sum/$i)) can be used
