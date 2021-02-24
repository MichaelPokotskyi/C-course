#pragma once

#include <string>
#include <iostream>
using namespace std;


int Stars() {
	
    string letters{};

    cout << "Enter a string : ";
    cin >> letters;

    size_t num_letters = letters.length();
    int position{ 0 };

    // for each letter in the string
    for (int c{ 0 }; c <= num_letters; ++c) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j = 0; j < position; j++) {
            cout << letters.at(j);
        }

        // Display the current 'center' character

        if (c < num_letters) { cout << letters.at(c); }
        if (c > num_letters) { cout << letters.at(c - num_letters); }

        // Display the remaining characters in reverse order
        for (int j = position - 1; j >= 0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            cout << letters.at(k);
        }
    }
 
        return 0;
    }
        

/*
* So let's go through the solution, Lets say we enter in "ABC"

First the variables:

letters = "ABC" 
num_letters = 3
position = 0
1st Iteration:

Then we enter the ranged based for-loop:

for(char c: letters)
Now we have:

letters = "ABC" 
num_letters = 3
position = 0
c = 'A'
num_spaces = 3
Then we enter the while loop:

while(num_spaces > 0)
and we print out to the console 3 spaces, then we enter into the first for loop:

for(size_t j=0; j < position; j++)
Since position is equal to 0 and j is equal to 0 the for-loop exits as the condition (0 < 0) returns false. We then we print out the current character c: 'A'

So the output looks like:

   A
Now we enter the second for-loop:

for(int j = position-1; j >=0; --j){
    /* auto specifier automatically deduces the variable k 
       to be of type size_t as it is statically casted to j 
auto k = static_cast<size_t>(j);
std::cout << letters.at(k);
}
Since j is equal to - 1 and the condition - 1 >= 0 is false we exit the for - loop.Then we print out a new line and increment position and move on to the next character in letters.

2nd Iteration :

So now we have :

letters = "ABC"
num_letters = 3
position = 1
Then we iterate the Ranged based for - loop :

    for (char c : letters)
        Now we have :

letters = "ABC"
num_letters = 3
position = 1
c = 'B'
num_spaces = 2
Then we enter the while loop:

while (num_spaces > 0)
and we print out to the console 2 spaces, and then we enter into the first for loop :

    for (size_t j = 0; j < position; j++)
        Since position is equal to 1 and j is equal to 0 the for - loop we output the element at letters.at(0) which is 'A';

So now the output looks like :

A
A
then we print out the current character c : 'B'

So the output now looks like :

A
AB
Now we enter the second for - loop :

    for (int j = position - 1; j >= 0; --j) {
        /* auto specifier automatically deduces the variable k
           to be of type size_t as it is statically casted to j 
        auto k = static_cast<size_t>(j);
        std::cout << letters.at(k);
    }
Since j is equal to 0 and the condition 0 >= 0 is true we then have k which is equal to j which is 0. Then we print out the element at letters.at(k) which is 'A'.

So now our output looks like :

A
ABA
We then print out a new line and increment position and move on to the next character in letters :

3rd Iteration :

So now we have :

letters = "ABC"
num_letters = 3
position = 2
Then we iterate the Ranged based for - loop :

    for (char c : letters)
        Now we have :

letters = "ABC"
num_letters = 3
position = 2
c = 'C'
num_spaces = 1
Then we enter the while loop:

while (num_spaces > 0)
and we print out to the console 1 space, and then we enter into the first for loop :

    for (size_t j = 0; j < position; j++)
        Since position is equal to 2 and j is equal to 0 the for - loop we output the element at letters.at(0) which is 'A';

So the output looks like :

A
ABA
A
Then we increment j.Now we have j equal to 1 and position equal to 2 and the condition 1 < 2 is true so we output the element at letters.at(1) which is 'B' :

    So now the output looks like :

A
ABA
AB
Then we increment j again.Now we have j equal to 2 and position equal to 2 and the condition 2 < 2 is false so we exit the for - loop.

    We then print out the current character c : 'C'

    So our output now looks like :

A
ABA
ABC
Now we enter the second for - loop :

    for (int j = position - 1; j >= 0; --j) {
        /* auto specifier automatically deduces the variable k
           to be of type size_t as it is statically casted to j 
        auto k = static_cast<size_t>(j);
        std::cout << letters.at(k);
    }
Since j is equal to 1 and the condition 1 >= 0 is true we then have k which is equal to j which is 1. Then we print out the element at letters.at(k) which is 'B'.

So our output is now :

A
ABA
ABCB
Then we decrement j.Now j equal to 0 and the condition 0 >= 0 is true we then have k which is equal to j which is 0. Then we print out the element at letters.at(k) which is 'A'

So our output is now :

A
ABA
ABCBA
Then we print out a new line and increment position and move on to the next character in letters.Since there are no more characters in the string letters we exit the Ranged based for - loop and our final output would be :

A
ABA
ABCBA
=======
#pragma once

#include <string>
#include <iostream>
using namespace std;


int Stars() {
	
    string letters{};

    cout <<"Enter a string : ";
    cin >> letters;

    size_t num_letters = letters.length();
    int position{ 0 };

    // for each letter in the string
    for (int c{ 0 }; c <= num_letters; ++c) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j = 0; j < position; j++) {
            cout << letters.at(j);
        }

        // Display the current 'center' character

        if (c < num_letters) { cout << letters.at(c); }
        if (c > num_letters) { cout << letters.at(c - num_letters); }

        // Display the remaining characters in reverse order
        for (int j = position - 1; j >= 0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            cout << letters.at(k);
        }
        return 0;
    }
        

/*
* So let's go through the solution, Lets say we enter in "ABC"

First the variables:

letters = "ABC" 
num_letters = 3
position = 0
1st Iteration:

Then we enter the ranged based for-loop:

for(char c: letters)
Now we have:

letters = "ABC" 
num_letters = 3
position = 0
c = 'A'
num_spaces = 3
Then we enter the while loop:

while(num_spaces > 0)
and we print out to the console 3 spaces, then we enter into the first for loop:

for(size_t j=0; j < position; j++)
Since position is equal to 0 and j is equal to 0 the for-loop exits as the condition (0 < 0) returns false. We then we print out the current character c: 'A'

So the output looks like:

   A
Now we enter the second for-loop:

for(int j = position-1; j >=0; --j){
    /* auto specifier automatically deduces the variable k 
       to be of type size_t as it is statically casted to j 
auto k = static_cast<size_t>(j);
std::cout << letters.at(k);
}
Since j is equal to - 1 and the condition - 1 >= 0 is false we exit the for - loop.Then we print out a new line and increment position and move on to the next character in letters.

2nd Iteration :

So now we have :

letters = "ABC"
num_letters = 3
position = 1
Then we iterate the Ranged based for - loop :

    for (char c : letters)
        Now we have :

letters = "ABC"
num_letters = 3
position = 1
c = 'B'
num_spaces = 2
Then we enter the while loop:

while (num_spaces > 0)
and we print out to the console 2 spaces, and then we enter into the first for loop :

    for (size_t j = 0; j < position; j++)
        Since position is equal to 1 and j is equal to 0 the for - loop we output the element at letters.at(0) which is 'A';

So now the output looks like :

A
A
then we print out the current character c : 'B'

So the output now looks like :

A
AB
Now we enter the second for - loop :

    for (int j = position - 1; j >= 0; --j) {
        /* auto specifier automatically deduces the variable k
           to be of type size_t as it is statically casted to j 
        auto k = static_cast<size_t>(j);
        std::cout << letters.at(k);
    }
Since j is equal to 0 and the condition 0 >= 0 is true we then have k which is equal to j which is 0. Then we print out the element at letters.at(k) which is 'A'.

So now our output looks like :

A
ABA
We then print out a new line and increment position and move on to the next character in letters :

3rd Iteration :

So now we have :

letters = "ABC"
num_letters = 3
position = 2
Then we iterate the Ranged based for - loop :

    for (char c : letters)
        Now we have :

letters = "ABC"
num_letters = 3
position = 2
c = 'C'
num_spaces = 1
Then we enter the while loop:

while (num_spaces > 0)
and we print out to the console 1 space, and then we enter into the first for loop :

    for (size_t j = 0; j < position; j++)
        Since position is equal to 2 and j is equal to 0 the for - loop we output the element at letters.at(0) which is 'A';

So the output looks like :

A
ABA
A
Then we increment j.Now we have j equal to 1 and position equal to 2 and the condition 1 < 2 is true so we output the element at letters.at(1) which is 'B' :

    So now the output looks like :

A
ABA
AB
Then we increment j again.Now we have j equal to 2 and position equal to 2 and the condition 2 < 2 is false so we exit the for - loop.

    We then print out the current character c : 'C'

    So our output now looks like :

A
ABA
ABC
Now we enter the second for - loop :

    for (int j = position - 1; j >= 0; --j) {
        /* auto specifier automatically deduces the variable k
           to be of type size_t as it is statically casted to j 
        auto k = static_cast<size_t>(j);
        std::cout << letters.at(k);
    }
Since j is equal to 1 and the condition 1 >= 0 is true we then have k which is equal to j which is 1. Then we print out the element at letters.at(k) which is 'B'.

So our output is now :

A
ABA
ABCB
Then we decrement j.Now j equal to 0 and the condition 0 >= 0 is true we then have k which is equal to j which is 0. Then we print out the element at letters.at(k) which is 'A'

So our output is now :

A
ABA
ABCBA
Then we print out a new line and increment position and move on to the next character in letters.Since there are no more characters in the string letters we exit the Ranged based for - loop and our final output would be :

A
ABA
ABCBA
>>>>>>> e2c3dcde4fb9ef7d3722bd57bc1c7653b077e322
*/