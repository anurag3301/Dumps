### Type casting
Type casting basically means converting one type to another type. The datatypes we have seen : `int`, `float`, `str`, `bool`, `list`, `set`, `tuple`, these datatypes can also be treated as a function and if you pass a value from another type, it will convert to the corresponding type.

#### Converting int to other types
```python
x = 10
print(x)
print(type(x))

# convert to float
print(float(x))

# convert to str
print(str(x))

# convert to bool
print(bool(x))
```

#### Converting float to other types
```python
x = 10.12
print(x)
print(type(x))

# convert to int
print(int(x))

# convert to str
print(str(x))

# convert to bool
print(bool(x))
```

#### Converting str to other types
```python
x = "12"
print(x)
print(type(x))

# convert to int
print(int(x))

# convert to float
print(float(x))
```
If you try to convert a string to int with non digit character it will give error
```python
x = "123hello"
print(x)

# convert to int
print(int(x))
```

#### Error
```python
123hello
Traceback (most recent call last):
  File "/home/anurag/test/test.py", line 5, in <module>
    print(int(x))
ValueError: invalid literal for int() with base 10: '123hello'
```

Same converstion goes to collection datatype also
#### Converting list to other datatypes
```python
x = [1, 2, 3, 4]

# convert to tuple
print(tuple(x))

# convert to set
print(set(x))
```

#### Converting tuple to other datatypes
```python
x = (1, 2, 3, 4)

# convert to list
print(list(x))

# convert to set
print(set(x))
```

#### Converting set to other datatypes
```python
x = {1, 2, 3, 4}

# convert to list
print(list(x))

# convert to tuple
print(tuple(x))
```

We can make use of this concept to solve a problem, lets say you perfromed a survey and people entered their ages and you stored those ages in a list. Now many people could have given the survey with the same age and thats why you have duplicate age entry in the list, now its your job to remove the duplicate age and have only the uniques. We can solve it using type convertion. First we will take the ages list and convert to `set` to remove all the duplicates and then convert the set back to list
#### Solution
```python
ages = [18, 18, 21, 20, 21, 18, 19, 23, 19]
print("Current age list: ")
print(ages)

age_set = set(ages)
print("\nConverted ages list to set")
print(age_set)

ages = list(age_set)
print("\nList after duplicate removed")
print(ages)
```

## Other way or printing
So far we were only normal way of print but we can actually print multiple values in one print statement, we just have to selerate them by `,`
#### Multple values in one print statement
```python
x = 10
y = 20
z = 30

print(x, y, z)
```
You can even have multiple string and variables printed, just seperate them with `,`
```python
name = "Mahdi"
age = 40

print("Hi my name is", name, "and my age is", age)
```
### Injecting variables in string using `f` string
Insted of print multiple variables using lot of comma and quotes, we can directly inject variables in a string using the `f` string concept. Just add a character `f` before starting the `"` of string and now you can print variables in a string by imbedding a variable in `{}`
####
```python
name = "Mahdi"
age = 40

print(f"Hi my name is {name} and my age is {age}")
```
## Conditionals in python
In python we can make decisions and make a part of code to execute or not execute based on some condition. For such situtation we use `if` statements. We have three keywords for this `if`, `elif`(else if), `else`.

#### Syntax
the keywords `if` is followed by a condition which should result in either `True` or `False` after evaluation then the condition if followed by a `:` symbol representing start of `if` block or body from next line. The if body is represented by giving an `indentation` or space of `4 spaces` in front. **Indentations** are very important. Till you follow the indentation it will be considered if block, as you remove the indentation you come out of the if body.

When the condition is true then then only the if body is executed
```python
if condition:
    statement 1
    statement 2
    .
    .
    .
    <if block>

outside if block
```

#### Example
```python
x = 12


if x > 10:
    print("x is greater than 10")


if x < 10:
    print("x is less tan 10")
```
### if-else
Here one if block is followed by a `else` block. Here when the if condition becomes false then the the else block is executed
#### Syntax
First write the if block as it is then come out of if block by removing the indentation and type keywords `else` followed by `:` and the else block with the indentation
```python
if condition:
    statement 1
    ...
    <if block>
else:
    statement 1
    ...
    <else block>

```

#### Example
```python
age = 16

if age > 18:
    print("You are allowed")
else:
    print("You are not allowed, age less than 18")
```
### if-elif-else
This is used when you wanna have different execution block for different condition. You start by a `if` block then followed by any number of `elif` which stands for `else if` block each having a condition then followed by an `else block. The else block at the end is not compulsory
#### Syntax
First write the if block as it is then come out of if block by removing the indentation and type keywords `elif` followed by a condition then a `:` and start the else if block with the indentation.

Here python will start to check from top level if condition, if its false it check for next elif condition and it keeps checking next elif till it any condition gets true.
```python
if condition1:
    statement 1
    ...
    <if block>
elif condition2:
    statement 1
    ...
    <elif block>
else:
    statement 1
    ...
    <else block>
```

#### Example
```python
x = 55

if x < 10:
    print("x is smaller than 10")
elif x < 30:
    print("x is smaller than 30")
elif x < 50:
    print("x is smaller than 50")
elif x < 70:
    print("x is smaller than 70")
else:
    print("x is too big")
```
### Some more examples

#### Check if number is odd or even
```python
num = 15
if num % 2 == 0:
    print(f"Number {num} is even")
else:
    print(f"Number {num} is odd")
```

#### Show grade based on marks
```python
score = 11

if score > 80:
    print("grade A")
elif score > 60:
    print("grade B")
elif score > 40:
    print("grade C")
elif score > 20:
    print("grade D")
else:
    print("failed")
```

#### lowest potato price supplier
```python
potato_supplier_1 = 12
potato_supplier_2 = 10
potato_supplier_3 = 14

if potato_supplier_1 < potato_supplier_2 and potato_supplier_1 < potato_supplier_3:
    print(f"Potato supplier 1 is the lowest price at {potato_supplier_1}")

elif potato_supplier_2 < potato_supplier_1 and potato_supplier_2 < potato_supplier_3: 
    print(f"Potato supplier 2 is the lowest price at {potato_supplier_2}")

else:
    print(f"Potato supplier 3 is the lowest price at {potato_supplier_3}")
```

#### Classic fizzbuzz
```python
# 3 -> fizz
# 5 -> buzz
# 3&5 -> fizzbuzz

num = 15

if num % 3 == 0 and num % 5 == 0:
    print("fizzbuzz")
elif num % 3 == 0:
    print("fizz")
elif num % 5 == 0:
    print("buzz")
```
