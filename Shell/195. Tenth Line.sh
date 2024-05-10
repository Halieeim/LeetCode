# Read from the file file.txt and output the tenth line to stdout.
line=$(sed -n "10p" file.txt)
echo $line