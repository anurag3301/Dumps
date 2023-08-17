factorial<- function(n) {
  if (n == 0 || n == 1) {
    return(1)
  } else {
    return(n * factorial(n - 1))
  }
}

num <- 5
result <- factorial(num)
cat("Factorial of", num, "is", result, "\n")
