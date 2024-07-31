## Looping Statements
Loopin statements are used in python to execute a block of code over and over to repeat a task for number of time.
## while loop
Using while loop we can run a block of code over an over till the provided condition is `True`. As soon as it gets `False` the loop stops and come out of the while block.
### Syntax
Write the keyword `while` followed by a condition which is check on each iteration and then the while block starts with an indentation like we had in `if` statements.
```python
while condition:
    statement1
    statement2
    ...
    <while block>

<outside while block>
```
#### Example
In the following block of code we start by creating a variable `x` and we assign 0 to it. Then we have the `while` keyword which shows the start of while loop then followed by a condition `x < 10` which means the loop will be keep iterating till `x` is less than 10. 

Then we see the while block where  the block is indented with the four spaces. In the while block first we have a print statement which print the value of `x` in each iteration and in the second line we add 1 to x

In each iteration the value of x is incremented by 1 and print it and keep doing it till x become 10
```python
x = 0
while x < 10:
    print(x)
    x = x + 1
```

### Warning
You have to be very careful while giving a condition, it should terminate in the desired time, if you make a mistake while giving a condition and the condition forever true, you will endup in something we call `infinite loop` where your code will be stuck in that loop doing the thing over and over and never come out
#### Example
```python
x = 0
while x < 10:
    print(x)
    x = x - 1
```

---
#### Print each number from start variable to end variable
```python
start = 10
end = 20

while start <= end:
    print(start)
    start += 1
```
---
#### Print each number from start variable to end variable in reverse
```python
start = 10
end = 20

while end >= start:
    print(end)
    end -= 1
```
---
#### Print each even number between start and end variable
```python
start = 10
end = 20

while start <= end:
    if start % 2 == 0:
        print(start)
        
    start += 1
```
---
#### Print each value of a list using index and len() function
```python
nums = [10, 20, 30, 40, 50, 60]
idx = 0

while idx < len(nums):
    print(nums[idx])
    idx = idx + 1
```

---
#### Find sum of all numbers in a list using while loop
```python
nums = [10, 20, 30, 40, 50, 60]
idx = 0
sum = 0

while idx < len(nums):
    sum = sum + nums[idx]
    idx = idx + 1

print("Sum of all numbers in list is", sum)
```
---
#### Find average of all numbers in a list using while loop
```python
nums = [10, 20, 30, 40, 50, 60]
idx = 0
sum = 0

while idx < len(nums):
    sum = sum + nums[idx]
    idx = idx + 1

avg = sum / len(nums)

print("Average of all numbers in list is", avg)
```
---
#### From a list of ages, find the count of age between 18 and 25
```python
ages = [18, 16, 22, 18, 19, 14, 29, 18, 20, 15]
count = 0
idx = 0

while idx < len(ages):
    age = ages[idx]
    if age >= 18 and age <= 25:
        count = count + 1
    idx = idx + 1

print(f"There are total {count} people between age 18 and 25")
```

#### From a list of prices, find the lowest price and print it
```python
price = [18, 16, 22, 18, 19, 14, 29, 18, 20, 15]
count = 0
idx = 0

while idx < len(ages):
    age = ages[idx]
    if age >= 18 and age <= 25:
        count = count + 1
    idx = idx + 1

print(f"There are total {count} people between age 18 and 25")
```
