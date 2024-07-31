## Collection datatype
As we have seen a variable can store only one  value, but there are some datatype which let us store multiple values in a single variable and they are called collection datatypes.

### List
List is a collection datatype created with the `[]` brackets. It can store store duplicate values and it is also mutable(updateable). You can print the entire list with printing the list variable like `print(list_variable)` or you can print a single value with use of index which is the position of the value in the list which starts from 0 and goes on like `print(list_variable[0])`. You can even update a value in list by indexing the value and assigning it a new value with the assignment operator.

#### Example code
```python
x = [10, 20, 30, 40, 50]

# print the entire list
print(x)

# print the type
print(type(x))

# print the fist value in the list
print(x[0])

# print the fifth value in the list
print(x[4])

# update the 3rd value to 100
x[2] = 100

# print the list after update
print(x)
```

The index should be in the limit of list size, you can print the size or length of a list using the `len` function. If you exceed the length you'll get `IndexOutOfBound` error.

Print length of list
```python
x = [10, 20, 30, 40, 50]

# print length using len function
print(len(x))
```

Demo of `IndexOutOfBound` error
```python
x = [10, 20, 30, 40, 50]

# Trying to print the 6th value but the list only has 5 values
print(x[5])
```

#### Error
```python
Traceback (most recent call last):
  File "/home/anurag/test.py", line 4, in <module>
    print(x[5])
IndexError: list index out of range
```

### Method operations in python
We can make use of list operations by first creating a list and then assigning to a variable like `x = [10, 20, 30]`. we can use any operations on it by specifing the name of variable and adding a `.` then the operation name. Syntax: `list_name.operation_name()`

Following are few operations available for list in python, read in details about then [**here**](https://www.w3schools.com/python/python_ref_list.asp)
| Operation | Description |
|-----------|-------------|
|append() | Adds an element at the end of the list |
|clear() | Removes all the elements from the list |
|copy() | Returns a copy of the list |
|count() | Returns the number of elements with the specified value |
|extend() | Add the elements of a list (or any iterable), to the end of the current list |
|index() | Returns the index of the first element with the specified value |
|insert() | Adds an element at the specified position |
|pop() | Removes the element at the specified position |
|remove() | Removes the first item with the specified value |
|reverse() | Reverses the order of the list |
|sort() | Sorts the list |

> Example for operations
```py
x = [10, 30, 50, 40, 20]
print(x)

# You can add new value to end using append
x.append(99)
print(x)

# Add Value at any index using insert
x.insert(2, 99)     # (idx, val)
print(x)

# Remove the last value using pop with no argument
x.pop()
print(x)

# Remove value at any index using pop with index 
x.pop(2)        # (index)
print(x)

# Remove any value using remove
x.remove(50)
print(x)

# Sort the entire array
x.sort()
print(x)
```

### Tuple
Tuple is a collection datatype created with the `()` brackets. It can store store duplicate values and it is also immutable(non updatable) means once it is created it cant be changed. You can print the entire tuple with printing the list variable like `print(tuple_variable)` or you can print a single value with use of index like `print(tuple_variable[0])`.
```python
x = (10, 20, 30, 40, 50)

# print the entire tuple
print(x)

# print the type
print(type(x))

# print the fist value with IndexError
print(x[0])
```

If you try to update any value of tuple you'll get an error
```python
x = (10, 20, 30, 40, 50)

# trying to print the third value to 100, it will produce error
x[2] = 100

# print the entire tuple
print(x)
```
#### Error
```python
Traceback (most recent call last):
  File "/home/anurag/test.py", line 4, in <module>
    x[2] = 100
TypeError: 'tuple' object does not support item assignment
```

### Set
Set is also a collection datatype created with the `{}` brackets. It cannot have duplicate values, it will only hold unique values, and set uses something called `hashing` to store values  and it does not support indexing a value, you can either `iterate` over a set or check if a value exist in set using `membership opearor`

#### Example code
```python
x = {10, 10, 20, 30, 40, 40, 50}

# printing the entire set, and notice the duplicate of 10 and 40 wont be there
print(x)

# print the type
print(type(x))

# print the length of the set
print(len(x))
```
### Error while tyring to access a value using indexing
```python
x = {10, 10, 20, 30, 40, 40, 50}

# trying to index and print the third value
print(x[2])
```
#### Error
```python
Traceback (most recent call last):
  File "/home/anurag/test.py", line 4, in <module>
    print(x[2])
TypeError: 'set' object is not subscriptable
```

### Set Operation
We can do various set operations on two set, we can either use function names or symbols for the operations.

| function | operator |
|----------|----------|
| union    |    \|    |
| intersection |  &   |
| difference  |   -   |
| symmetric_difference |    ^ |

#### Example for set operations
```py
a = {10, 20, 30, 40}
b = {30, 40, 50, 60}

print(a.union(b))
print(a | b)

print(a.intersection(b))
print(a & b)

print(a.difference(b))
print(a - b)

print(a.symmetric_difference(b))
print(a ^ b)
```

### Indexing and slicing
We have already saw indexing which is get a value based on its index in the list or tuple, but we can also do two more thing
1. Reverse Indexing
2. Slicing

Reverse indexing is done to get values from the end and its done using negative index. Like `-1` will give you last value, `-2` will give the second last and so on
```python
x = [10, 20, 30, 40, 50]

# print the last value using the reverse index
print(x[-1])

# print the second last value using the reverse index
print(x[-2])
```

To get a small portion of list we use concept of slicing, it is done by provinding the start and the end index in `[]` seperated by `:` like `list_variable[start_index : end_index]`
```python
x = [10, 20, 30, 40, 50, 60, 70, 80]

# print the sub list from third to fifth value
print(x[2:5])

# if you dont provide start index, it will assume as 0
print(x[:5])    # same as x[0:5]

# if you dont provide end index, it will assume as last index or -1
print(x[2:])    # same as x[2:7]
```

### Indexing and slicing on string
The concept of indexing and sclicing can be also used in string
```python
x = "ABCDEFGHIJ"

# print the first character in string uisng index
print(x[0])

# print the last character in string uisng index -1
print(x[-1])

# perfrom the sclicing concept here 
print(x[4:8])

print(x[:8])

print(x[4:])
```
