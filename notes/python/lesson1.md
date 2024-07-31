## Python Installation and setup

## Introduction
+ A program is made up of two components: `Data` and `Instruction`
+ `Instruction` can be represented in two ways, `operators` and `function`
+ A program is made using `source code` the code programmer write and `binary` which is executed by the computer
+ A `source code` is written in a programming language like python, c++, java etc. and every language has its own grammar rules called syntax. The programmer has to follow those rules
+ When you make a mistake in the syntax you get and error.

## Very basic program
The most basic program in python is to print something, it is done using the print function. The syntax for print function is as follow

1. First write the word `print`
2. Then add a `(` representing start of function body like this: `print(`
3. Add a `"` representing start of english text also called `string` like this: `print("`
4. Type the message you wanna print after `"` like this: `print("Hello world`
5. After you are done writing the message end the english text or `string` with `"` like this `print("Hello world"`
6. finally end the function body with `)` like this `print("Hello world")`

### Simple print examples
```python
print("Hello world")
```

```python
print("My name is Mahdi")
```

```python
print("I write python program")
```

### Your first error
We are going have our first error by not following the syntax aka the grammar and python will give us an error.

We will get an error if we forget the function ending with `)`
#### Code
```python
print("Hello world"
```
#### Error
```python
  File "/home/anurag/repo/Assignments/Mahdi/test.py", line 1
    print("Hello World"
         ^
SyntaxError: '(' was never closed
```
We can see the error clearly says we havent closed the function with `)`, People get scared of error, but error are you best friend, it tells you what mistake you have done, so relax, read and try to understand the error

We can try anoter error by not ending the engligh text with `"`
#### Code
```python
print("Hello world)
```
#### Error
```python
  File "/home/anurag/repo/Assignments/Mahdi/test.py", line 1
    print("Hello World)
          ^
SyntaxError: unterminated string literal (detected at line 1)
```
Sometime it can be hard to understand error, but its all about experience, keep doing and understanding will come and make google you second best friend

### Comments
Every thing you write in the source code will be read by python and it will try to check for synatx and try to run it. Sometime you want to add some text which you dont want to run, it can be some explainaiton or some message. For this we use a thing called `comments` and it represented and started with the `#` symbol. If you type `#` symbol, everything after that symbol on that line will be ignored by python
#### code
```python
# I am a comment, ignore me
print("Running this line")
```
Even if you write a code in comment it will be ignored by python
#### code
```python
# print("First line ignored")
print("Second line runned")
```

### Variables
Variables are just human readable names we give to some data so we can use the data and perform operations on it. A variable is created by wrigint a word as identifier followed by a `=` symbol also called `assignment operator` then followed by the data you wanna store

#### Example code
```python
x = 10
```
Here variable name is `x` then its followed by `=` symbol followed by the value which is `10`

You can print the value of variable by passing the variable to the print function like follow
```python
x = 10
print(x)
```
Here are some rules for variable creation
+ A variable name must start with a letter or the underscore character
+ A variable name cannot start with a number
+ A variable name can only contain alpha-numeric characters and underscores (A-z, 0-9, and _ )
+ Variable names are case-sensitive (age, Age and AGE are three different variables)

```python
#Legal variable names:
myvar = "John"
my_var = "John"
_my_var = "John"
myVar = "John"
MYVAR = "John"
myvar2 = "John"

#Illegal variable names:
2myvar = "John"
my-var = "John"
my var = "John"
```

### IMPORTANT NOTE
Do not put the `""` sign while printing a variable, `""` is used to represent english text aka string, if you do so you wont be able to print the value of variable name, instead you will print the variable name
#### Wrong way of printing variable value
```python
x = 10
print("x")
```
Output:
```
x
```
#### Correct way of printing variable value
```python
x = 10
print(x)
```
Output:
```
10
```

#### DataTypes
Data in python are represented with different datatypes. There are two types of datatypes:

+ `Inbuilt Datatypes:` These datatypes are inbuilt in python and comes by defult 
+ `Userdefined Datatypes:` These datatypes doest come by default, it is created by the programmer

#### Inbuilt Datatypes
We have following basic inbuilt datatypes
+ `Text Type:`	str
+ `Numeric Types:`	int, float, complex
+ `Boolean Type:` bool
+ `Collection Types:`	list, tuple, set
+ `Mapping Type:`	dict

#### The str or string datatype
This datatype is used to store engligh text, It is enclosed in `""`
```python
x = "Hi"
y = "I have 10 chocolates"
z = "Just a random text"
print(x)
print(y)
print(z)
```

#### The int datatype
This datatype is used to store integral values [Video](https://www.youtube.com/watch?v=OSfDRqxmXAE)
```python
x = 100
y = 12
z = 1
print(x)
print(y)
print(z)
```

#### The float datatype
This datatype is used to store decimal point values [Video](https://www.youtube.com/watch?v=guBVW5PiHLs)
```python
x = 3.14
y = 1.5
z = 0.5
print(x)
print(y)
print(z)
```

#### The bool datatype
This datatype is used to store boolean type which are only `True` or `False`
```python
y = True
z = False
print(y)
print(z)
```

#### Printing type of a variable
We can print type of varible by using the `type` function. Instead of passing the variable directly in print function, pass it in `type` function first the pass in print function.

```
print(type(x))
 |     |   ↓
 |     ↓   x
 ↓    type( )
print(       )
```


```python
a = "hello"
b = 10
c = 1.5
d = True
print(type(a))
print(type(b))
print(type(c))
print(type(d))
```
