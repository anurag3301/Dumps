# Functions
**Defination:** In computer programming, a function or subroutine is a sequence of program instructions that performs a specific task, packaged as a unit.

In simple terms Functions is set of programming statements which can be use over and over. Lets take an example. Assume you have a problem where you need to check weather a number is prime or not multiple places, the code will look like this

```py
num1 = int(input("Enter a number 1: "))

is_prime = True
for i in range(2, int(num1**0.5) + 1):
    if num1 % i == 0:
        is_prime = False
        break
if is_prime:
    print(f"{num1} is a prime number.")
else:
    print(f"{num1} is not a prime number.")


num2 = int(input("Enter a number 2: "))

is_prime = True
for i in range(2, int(num2**0.5) + 1):
    if num2 % i == 0:
        is_prime = False
        break
if is_prime:
    print(f"{num2} is a prime number.")
else:
    print(f"{num2} is not a prime number.")


num3 = int(input("Enter a number 3: "))

is_prime = True
for i in range(2, int(num3**0.5) + 1):
    if num3 % i == 0:
        is_prime = False
        break
if is_prime:
    print(f"{num3} is a prime number.")
else:
    print(f"{num3} is not a prime number.")
```

Now you see, its bad. We needed to check if a number is prime or not three time, so we had to write the entire code for prime check three times, its wastage of programming lines, imagine checking for prime 10 or 100 places meaning 100 copies.

We can fix by using funtion, the code will look like this
```py
def isPrime(num):
    is_prime = True
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            is_prime = False
            break
    if is_prime:
        print(f"{num} is a prime number.")
    else:
        print(f"{num} is not a prime number.")
    num = int(input("Enter a number 1: "))


num1 = int(input("Enter a number 2: "))
isPrime(num1)

num2 = int(input("Enter a number 2: "))
isPrime(num2)

num3 = int(input("Enter a number 3: "))
isPrime(num3)
```

Now you see, the program is much better, we dont have to copy paste the entire code over and over, we can just make use of the funtion. And this is the biggest advantage of function called `Reusability`.

### Syntax
Following is a general syntax of funtion starting with `def` keyword which says you are defining a new funtion, followed by a function_name which will be used to call(use) the funtion and we have Parentheses in which we specify the space seperated arguments. Then a `:` which specifies upcomming funtion block. We use indentation to specify the function block and then finally we have a return statement.
```py
def function_name(arguments):
    body statements
    ...
    return value
```

#### Usage
The useage of funtion involve two parts:
1. Declaring of funtion
2. Calling a funtion

`Declaring a function` is when we create a funtion. Just declaring a function dont do anything, it just tell the program that this function exists. we do that using the def keyword, it contains the entire body of the function
```py
def add(num1, num2):
    result = num1 + num2
    return result
```
Now to actually use the funtion we need to `call` it. We call a funtion by writing the function_name and then the argument values in the Parentheses. We can also store the value returned by the funtion in a vairable.
```py
res1 = add(10, 20)
res2 = add(1.4, 5.8)
```
After a funtion is created or `declared` we can use it as many time we want by giving all sort of different values.

#### Arguments
Arguments also known as `input` or `parameter` are set of values which is used by the function to perform its task, for example a add funtion will take two number which is suppose to add, the `sqrt` funtion will take a number. So the arguments depends on the requirement.
```py
def add(num1, num2):
        ^^^^^^^^^^^
```
You are suppose to give the values for the argument while `calling` the funtion.
```py
add(10, 20);
```

#### Optionals
`Arguments` and `return` is optional for a function, we can add then if we need it. There are some funtion which dont take any arguement like `exit()` and there are funtion which dont return anything like `print()`

When a funtion returns a value, we are suppose to capture it in a variable.
```py
print("hello")      # print dont return anything

res = add(10, 20)   # Add does return, so we capture
```

### Example problems

1. Write a function that takes two numbers as parameters and returns their average.

```py
def calculate_average(num1, num2):
    return (num1 + num2) / 2

print(calculate_average(10, 20))
```

2. Create a function that checks whether a given number is even or odd.
```py
def is_even_or_odd(number):
    if number % 2 == 0:
        return "Even"
    else:
        return "Odd"
```

3. Write a Python function that takes a list of numbers and returns the minimum element.
```py
def list_min(nums):
    min = nums[0]
    for i in nums:
        if i < min:
            min = i
    return min

nums = [10, 4, 4, 2, 9]
print(list_sum(nums))
```

4. Write a Python function that takes a list of numbers and returns the sum of all the elements.
```py
def list_sum(nums):
    sum = 0
    for i in nums:
        sum += i
    return sum

nums = [10, 20, 30, 40]
print(list_sum(nums))
```

5. Write a Python function to check if a given year is a leap year.
```py
def is_leap_year(year):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        return True
    else:
        return False

print(is_leap_year(2024))
print(is_leap_year(2023))
```

6. Write a function which takes a list of elements and a `target` value, return `True` if the target is in the list else return `False`
```py
def search(ele_list, target):
    for i in ele_list:
        if i == target:
            return True

    return False

ele_list = [10, 20, 30, 40, 50]
print(search(ele_list, 10))
print(search(ele_list, 70))
```

