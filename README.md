# Advent of Code 2024
My solutions and devlog in C++ for Advent of Code 2024.

CMake configuring and building in `/build` directory:
```
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER="cl.exe" ..
cmake --build . -j6
```

## Day 1
### Part 1
I first had to get a workflow for using Neovim/clangd + CMake + Ninja + MSVC working.
I tried to use std::ranges, left fold and lambdas to do this solution in as much modern C++ as I can think of.
Running looks like so:
```
.\day1.exe ..\input\day1.txt
Sum of total differences: 1646452
```
### Part 2
I used an unordered_map for this part to keep a tally of both tables, then multiplied the number by frequency in both tables.
```
.\day1.exe ..\input\day1.txt
Sum of total differences: 1646452
Similarity score: 23609874
```
Speed (both parts): 17ms

## Day 2
For this I tried to solve it as quick as possible so I went for a straightforward array approach without any clever ranges/folds/lambdas. The part of the puzzle that took me the longest was in part 2 for thinking of the case to remove the first element which may flip the sequence direction.
```
.\day2.exe ..\day2\day2.txt
Total safe levels: 287
Total damp safe levels: 354
```
Speed (both parts): 33ms
