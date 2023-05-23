tests=(
    "env"
    "ls"
    "/bin/ls"
    "/bin/ls -l"
    "ls -l"
    "ls           -l"
    "  /bin/ls"
    "cp /bin/ls ayb"
    "/bin/ls /var"
    " cp /bin/ls hbtn_ls"
    "../hbtn_ls /var"
    "/bin/command_not_foud"
    "ls \n /bin/ls \n /bin/ls -l \n ls -l \n ls           -l \n  cp /bin/ls ayb \n /bin/ls /var \n cp /bin/ls hbtn_ls \n command_not_found \n /bin/command_not_foud"
)

echo "Compiling..."
gcc *.c -o hsh_test

# Iterate over the tests
for test in "${tests[@]}"; do
    # Run the test command and pipe the output to valgrind
    echo -e "$test \n exit" | valgrind ./hsh_test >valgrind_output_tmp.txt 2>&1

    # Check if there are any lines containing "definitely lost" in the valgrind output
    if grep -q "definitely lost" valgrind_output_tmp.txt; then
        echo "Memory leaks found in the test: $test"
        start_line=$(grep -n "HEAP SUMMARY:" valgrind_output_tmp.txt | cut -d ':' -f 1)
        tail -n +$start_line valgrind_output_tmp.txt
        leak_tests=$((leak_tests + 1))
    else
        echo "No memory leaks found in the test: $test"
    fi

    echo -e "$test \n exit" | ./hsh_test 


    echo "=============================="
    total_tests=$((total_tests + 1))

    rm valgrind_output_tmp.txt
done

echo -e "\n\n"
# Clean up the temporary file
rm -rf hsh_test

# Print summary
echo "===== SUMMARY ====="
echo "Total tests: $total_tests"
echo "Tests with memory leaks: $leak_tests"
echo "=================="