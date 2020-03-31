# README #

assign4.cpp & assign4.h -> tokenize text file and make json format output

gtest.cpp -> test assign4.cpp

assign4.py -> Using json format output draw CDF & PDF graph nd make graph pdf file 

-----Google Test-----

(1) Get the googletest framework

-> $ wget https://github.com/google/googletest/archive/release-1.7.0.tar.gz

(2) Unpack and build google test

-> $ tar xf release-1.7.0.tar.gz

->   $ cd googletest-release-1.7.0
   
->   $ cmake -DBUILD_SHARED_LIBS=ON .
   
->   $ make

(3) "Install" the headers and libs on your system.

-> $ sudo cp -a include/gtest /usr/include

->  $ sudo cp -a libgtest_main.so libgtest.so /usr/lib/

(4) Update the cache of the linker

-> $ sudo ldconfig -v | grep gtest

(if output is 

libgtest.so.0 -> libgtest.so.0.0.0

libgtest_main.so.0 -> libgtest_main.so.0.0.0

that is OK.)

(5) Compile gtest.cpp (directory is assignment folder)

-> $ g++ -o gtest gtest.cpp -lgtest

(6) Run

-> $./gtest

Then you can test it

First test is checking value descending order.

Second test is checking key.

Third test is checking value.

-----Jason assignment-----

(1) Install Json

-> $ sudo apt-get install libjsoncpp-dev

(2) Compile assign4.cpp (directory is assignment folder)

-> $ g++ -o assign4 assign4.cpp -ljsoncpp


(3) Run it 

-> $ ./assign4 Aladdin.txt | python assign4.py


Then, you can make json output (standard Output) & json format file

If you want to make CDF, PDF using json format (Standard Input)

Then, you can plot CDF, PDF graph & make pdf file named Graph_pdf
