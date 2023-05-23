echo "ls " | valgrind ./hsh
echo "/bin/ls" | valgrind ./hsh
echo "/bin/ls -l" | valgrind ./hsh
echo "ls -l" | valgrind ./hsh
echo "ls           -l" | valgrind ./hsh
echo "  /bin/ls" | valgrind ./hsh
echo "cp /bin/ls ayb" | valgrind ./hsh
echo "/bin/ls /var" | valgrind ./hsh
echo " cp /bin/ls hbtn_ls" | valgrind ./hsh
echo "../hbtn_ls /var" | valgrind ./hsh
echo "/bin/command_not_foud" | valgrind ./hsh


echo -e "ls \n /bin/ls \n /bin/ls -l \n ls -l \n ls           -l \n  cp /bin/ls ayb \n /bin/ls /var \n cp /bin/ls hbtn_ls \n command_not_found \n /bin/command_not_foud \n exit" | valgrind ./hsh
