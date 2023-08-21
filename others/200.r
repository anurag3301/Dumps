# Define the structure for an AVL tree node
AVLNode <- function(key) {
  list(
    key = key,
    left = NULL,
    right = NULL,
    height = 1
  )
}

# Get the height of a node
get_height <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  return(node$height)
}

# Calculate the balance factor of a node
get_balance_factor <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  return(get_height(node$left) - get_height(node$right))
}

# Update the height of a node
update_height <- function(node) {
  if (!is.null(node)) {
    node$height <- max(get_height(node$left), get_height(node$right)) + 1
  }
}

# Rotate a subtree to the right
rotate_right <- function(y) {
  x <- y$left
  T2 <- x$right
  
  x$right <- y
  y$left <- T2
  
  update_height(y)
  update_height(x)
  
  return(x)
}

# Rotate a subtree to the left
rotate_left <- function(x) {
  y <- x$right
  T2 <- y$left
  
  y$left <- x
  x$right <- T2
  
  update_height(x)
  update_height(y)
  
  return(y)
}

# Rebalance the tree
rebalance <- function(node, key) {
  update_height(node)
  
  balance_factor <- get_balance_factor(node)
  
  # Left heavy
  if (balance_factor > 1 && key < node$left$key) {
    return(rotate_right(node))
  }
  
  # Right heavy
  if (balance_factor < -1 && key > node$right$key) {
    return(rotate_left(node))
  }
  
  # Left-Right case
  if (balance_factor > 1 && key > node$left$key) {
    node$left <- rotate_left(node$left)
    return(rotate_right(node))
  }
  
  # Right-Left case
  if (balance_factor < -1 && key < node$right$key) {
    node$right <- rotate_right(node$right)
    return(rotate_left(node))
  }
  
  return(node)
}

# Insert a key into the AVL tree
insert <- function(root, key) {
  if (is.null(root)) {
    return(AVLNode(key))
  }
  
  if (key < root$key) {
    root$left <- insert(root$left, key)
  } else if (key > root$key) {
    root$right <- insert(root$right, key)
  } else {
    # Duplicate keys are not allowed in this example
    return(root)
  }
  
  return(rebalance(root, key))
}

# In-order traversal
in_order_traversal <- function(root) {
  if (!is.null(root)) {
    in_order_traversal(root$left)
    cat(root$key, " ")
    in_order_traversal(root$right)
  }
}

# Example usage
root <- NULL
keys <- c(5, 3, 7, 2, 4, 6, 8)

for (key in keys) {
  root <- insert(root, key)
}

cat("AVL Tree In-order Traversal:\n")
in_order_traversal(root)
