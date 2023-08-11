# TowerBreakers

## Description

Two players are playing a game of Tower Breakers! Player _1_ always moves first, and both players always play optimally. The rules of the game are as follows:

- Initially there are _n_ towers.
- Each tower is of height _m_.
- The players move in alternating turns.
- In each turn, a player can choose a tower of height _x_ and reduce its height to _y_, where _1 ≤ y < x_ and _y_ evenly divides _x_.
- If the current player is unable to make a move, they lose the game.

Given the values of _n_ and _m_, determine which player will win. If the first player wins, return _1_. Otherwise, return _1_. 

## Returns

- int: the winner of the game

## Input
- The first line contains a single integer _t_, the number of test cases.
- Each of the next _t_ lines describes a test case in the form of _2_ space-separated integers, _n_ and _m_.
