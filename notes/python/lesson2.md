## Operators
Operators are symbols used to perfrom some operation on variables or values.

It is divided into following group
+ Arithmetic operators
+ Assignment operators
+ Comparison operators
+ Logical operators
+ Identity operators
+ Membership operators
+ Bitwise operators

### Arithmetic Operators
It is used to perfrom Arithmetic operations on numerical values

| Operator	| Name	            | Exampl| 
|-----------|-------------------|-------|
| +	        | Addition	        | x + y	| 
| -	        | Subtraction	    | x - y	| 
| *	        | Multiplication	| x * y	| 
| /	        | Division	        | x / y	| 
| %	        | Modulus	        | x % y	| 
| **	    | Exponentiation	| x ** y| 
| //	    | Floor division	| x // y| 

#### Example code
```python
x = 2
y = 5

print(x + y)
print(x - y)
print(x * y)
print(x / y)
print(x % y)
print(x ** y)
print(x // y)
```
You can store output of one arithmetic operation to a variable like this

```python
x = 2
y = 5
z = x + y

print(z)
```

### Assignment Operators
These operators are used to assign values to variables

| Operator	| Example	| Same As    |
|-----------|-----------|------------|
| =         | x = 5     | x = 5      |
| +=	    | x += 3	| x = x + 3  |
| -=	    | x -= 3	| x = x - 3	 |
| *=	    | x *= 3	| x = x * 3	 |
| /=	    | x /= 3	| x = x / 3	 |
| %=	    | x %= 3	| x = x % 3	 |
| //=	    | x //= 3	| x = x // 3 |	
| **=	    | x **= 3	| x = x ** 3 |	
| &=	    | x &= 3	| x = x & 3	 |
| \|=	    | x \|= 3	| x = x \| 3	 |
| ^=	    | x ^= 3	| x = x ^ 3	 |
| >>=	    | x >>= 3	| x = x >> 3 |	
| <<=	    | x <<= 3	| x = x << 3 |	

```python
x = 5
print(x)

x += 5
print(x)

x /= 5
print(x)
```

### Comparison Operators
Comparison operators are used to compare two values or variables


| Operator	| Name	                    | Example	
|-----------|---------------------------|--------
| ==	    | Equal	                    | x == y	
| !=	    | Not equal	                | x != y	
| >	        | Greater than	            | x > y	
| <	        | Less than	                | x < y	
| >=	    | Greater than or equal to	| x >= y	
| <=	    | Less than or equal to	    | x <= y

#### Example code
```python
x = 5
y = 10

print(x == y)
print(x != y)
print(x > y)
print(x < y)
print(x >= y)
print(x <= y)
```

### Logical Operators
Logical operators are used to combine conditional statements:

| Operator	| Description	                                            | Example
|-----------|-----------------------------------------------------------|----------------------
| and 	    | Returns True if both statements are true	                | x < 5 and  x < 10	
| or	    | Returns True if one of the statements is true	            | x < 5 or x < 4	
| not	    | Reverse the result, returns False if the result is true	| not(x < 5 and x < 10)

```python
age = 19
print(age > 18 and age < 21)
```

