
# PushSwap

PushSwap is a sorting algorithm and coding challenge from the 42 school curriculum. It requires sorting a stack of integers using only a limited set of operations and a second stack, in as few moves as possible.

Key concepts: Handles input validation (duplicates, non-integers, overflows)
| Adaptive sorting strategy based on input size:
| Simple hardcoded sort for 2–5 numbers
| customized sorting based logic for larger sets, based on dividing into chunks and checking for a certain range
| Optimized for performance and minimal operation count


## Usage

Use the Makefile to compile:
```javascript
make
```

Run the program:
```javascript
./push_swap <n>

```
Example input:
```javascript
./push_swap 16183 48068 49165 52673 3371 24499 1309 42283 30987 57417 26453 13981 44027 9793 45391 49972 6279 46635 35139 10627 48092 3827 5887 26230 9147 7635 47986 50965 41792 36981 52005 53191 57994 831 43296 50698 7802 1721 49929 38786 15200 21406 31115 36368 35324 3235 27154 57433 47645 27330 29536 15692 43300 28816 3143 41038 31869 47452 56925 22640 38966 19998 1040 25722 44429 53057 12789 21348 19618 59872 32486 2676 40754 36399 40615 20406 28499 10087 5406 58295

```



## Authors

- [@Joana Wardenga](https://www.github.com/YunShenMiao)

