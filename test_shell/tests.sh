echo "ls " | valgrind ./sha
echo "/bin/ls" | valgrind ./sha
echo "/bin/ls -l" | valgrind ./sha
echo "ls -l" | valgrind ./sha
echo "ls           -l" | valgrind ./sha
echo "  /bin/ls" | valgrind ./sha
echo "cp /bin/ls ayb" | valgrind ./sha
echo "/bin/ls /var" | valgrind ./sha
echo " cp /bin/ls hbtn_ls" | valgrind ./sha
echo "../hbtn_ls /var" | valgrind ./sha
echo "/bin/command_not_foud" | valgrind ./sha


echo -e "ls \n /bin/ls \n /bin/ls -l \n ls -l \n ls           -l \n command_not_found \n /bin/command_not_foud \n exit" | valgrind ./sha