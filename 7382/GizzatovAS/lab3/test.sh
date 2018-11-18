#!/bin/bash
g++ ./Source/lab3.cpp -o result
echo '          тест#1:'
cat ./Tests/test1.txt
echo 'вывод 1 теста:'
echo ''
./result < ./Tests/test1.txt
echo '______________________'
echo '          тест#2:'
cat ./Tests/test2.txt
echo 'вывод 2 теста:'
echo ''
./result < ./Tests/test2.txt
echo '______________________'
echo '          тест#3:'
cat ./Tests/test3.txt
echo 'вывод 3 теста:'
echo ''
./result < ./Tests/test3.txt
echo '______________________'
echo '          тест#4:'
cat ./Tests/test4.txt
echo 'вывод 4 теста:'
echo ''
./result < ./Tests/test4.txt
echo '______________________'
