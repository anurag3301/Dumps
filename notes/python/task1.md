# Task

## Task 1
Take varible `num` store any number to it. Print `Number <num> is divible by 19` if number `num` is divible by 19, if not print `Number <num> is not divible by 19`
#### Test 1: num = 361
```
Number 361 is divisible by 19
```
#### Test 1: num = 119
```
Number 119 is not divisible by 19
```
## Task 2
Create three varible `s1`, `s2` and `s3` and store any marks between 1-100.
1. If `s1` is highest then print `Student 1 has highest marks with <s1> marks`
2. If `s2` is highest then print `Student 2 has highest marks with <s2> marks`
2. If `s3` is highest then print `Student 3 has highest marks with <s3> marks`

#### Test 1: s1=30, s2=50, s3=70
```
Student 3 has highest marks with 70 marks
```

#### Test 2: s1=30, s2=70, s3=50
```
Student 2 has highest marks with 70 marks
```

#### Test 3: s1=70, s2=20, s3=50
```
Student 1 has highest marks with 70 marks
```

## Task 3
Given a list `nums` with four numeric value. Find Sum of all numbers and print `Sum of list <sum>`
#### Test 1: nums = [10, 20, 30, 40, 50]
```
Sum of list 100
```

#### Test 2: nums = [11, 14, 7, 99]
```
Sum of list 131
```

## Task 4
Given a list `nums` with five number values. Find average/mean of all number and print `Average of list <avg>`

#### Test 1: nums = [10, 20, 30, 40, 50]
```
Average of list 25.0
```

#### Test 2: nums = [11, 14, 7, 99]
```
Average of list 32.75
```


# Solutions
## Task 1
```python
num = 361

if num % 19 == 0:
    print(f"Number {num} is divisible by 19")
else:
    print(f"Number {num} is not divisible by 19")
```

## Task 2
```python
s1 = 30
s2 = 50
s3 = 70


if s1 > s2 and s1 > s3:
    print(f"Student 1 has highest marks with {s1} marks")
elif s2 > s1 and s2 > s3:
    print(f"Student 2 has highest marks with {s2} marks")
else:
    print(f"Student 3 has highest marks with {s3} marks")
```

#### Task 3
```python
nums = [11, 14, 7, 99]

sums = nums[0] + nums[1] + nums[2] + nums[3]

print("Sum of list", sums)
```

#### Task 4
```python
nums = [10, 20, 30, 40, 50]

sums = nums[0] + nums[1] + nums[2] + nums[3]
avg = sums / 4

print("Average of list", avg)
```
