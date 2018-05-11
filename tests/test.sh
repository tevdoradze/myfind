# !/bin/sh

./myfind 1>myfind.txt
./myfind qdsqdqsd 1>myfind.txt
./myfind . 1>myfind.txt
./myfind -d 1>myfind.txt
./myfind -P 1>myfind.txt
./myfind -L 1>myfind.txt
./myfind -H 1>myfind.txt
./myfind - 1>myfind.txt
./myfind . tests/test_folder/ 1>myfind.txt

find 1>f.txt
find qdsqdqsd 1>f.txt
find . 1>f.txt
find 1>f.txt -d
find -P 1>f.txt
find -L 1>f.txt
find -H 1>f.txt
find - 1>f.txt
find . tests/test_folder/ 1>f.txt

diff myfind.txt f.txt
