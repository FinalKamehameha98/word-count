#!/bin/bash


# Setup Executable
make clean -s
make -s


# Testing with No Files (AKA Using stdin)
echo "Testing with No Files"
echo "---------------------"
./simple_wc < test_files/lorem1.txt
wc < test_files/lorem1.txt
echo

# Testing with 1 File
echo "Testing with 1 File"
echo "-------------------"
./simple_wc test_files/lorem1.txt
wc test_files/lorem1.txt
echo

# Testing with >1 Files
echo "Testing with >1 Files"
echo "---------------------"
./simple_wc test_files/*.txt
wc test_files/*.txt
echo
