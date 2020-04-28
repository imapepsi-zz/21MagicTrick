# 21 Magic Trick
This program based off a magic trick that involves 21 cards.

It was written for BYU Women in CS club's Lazy Hack-a-thon competition for April 2020.

Award: 1st place

# How to play
A user will choose a number between 1-21. The numbers are organized into 3 columns.
```
Welcome to the 21 Magic Trick Program!

  Column A  Column B  Column C
     1         2         3
     4         5         6
     7         8         9
     10        11        12
     13        14        15
     16        17        18
     19        20        21
Pick a number!
Enter 'r' when you have your number: 
I'm going to guess your number by asking you only what column it's in 3 times.
```

The user enters which column they see their number 3 times. Between each time the numbers are shuffled around.
```
  Column A  Column B  Column C
     14        7         4
     11        17        13
     8         9         12
     20        5         6
     19        21        16
     18        2         10
     15        1         3
Enter the column of the number (a, b, c):
```

Afterwards the computer will know what number the user chose.
```
Hmm.....

Your number is ##!
```

If a user wants tp play again they can enter the key `y`
```
Would you like to go again? (y or n):
```
