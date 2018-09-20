#!/bin/bash
gcc ./Source/lab1_test.c -o result
echo '		тест#1:'
cat ./Tests/test1.txt
echo 'вывод 1 теста:'
echo ''
./result < ./Tests/test1.txt
echo '______________________'
echo '		тест#2:'
cat ./Tests/test2.txt
echo 'вывод 2 теста:'
echo ''
./result < ./Tests/test2.txt
echo '______________________'
echo '		тест#3:'
cat ./Tests/test3.txt
echo 'вывод 3 теста:'
echo ''
./result < ./Tests/test3.txt
echo '______________________'
echo '		тест#4:'
cat ./Tests/test4.txt
echo 'вывод 4 теста:'
echo ''
./result < ./Tests/test4.txt
echo '______________________'
echo '		тест#5:'
cat ./Tests/test5.txt
echo 'вывод 5 теста:'
echo ''
./result < ./Tests/test5.txt
echo '______________________'
echo '		тест#6:'
cat ./Tests/test6.txt
echo 'вывод 6 теста:'
echo ''
./result < ./Tests/test6.txt
echo '______________________'
echo '		тест#7:'
cat ./Tests/test7.txt
echo 'вывод 7 теста:'
echo ''
./result < ./Tests/test7.txt
echo '______________________'
echo '		тест#8:'
cat ./Tests/test8.txt
echo 'вывод 8 теста:'
echo ''
./result < ./Tests/test8.txt
echo '______________________'
echo '		тест#9:'
cat ./Tests/test9.txt
echo 'вывод 9 теста:'
echo ''
./result < ./Tests/test9.txt
echo '______________________'
echo '		тест#10:'
cat ./Tests/test10.txt
echo 'вывод 10 теста:'
echo ''
./result < ./Tests/test10.txt
echo ''

