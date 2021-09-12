# Transaction-Data-Exercise-Cpp
Write a program that reads in lines of input using scanf or cin, and file redirection, process the data, and then output the results using printf or cout. 
This means you can use C or C++ style I/O as is your personal preference.
Data:
Each line of th named “transactiondata” file begins with an 'e', 'c', or 't'.
Lines beginning with 'e' will have an integer employee ID and an employee name.
Lines beginning with 'c' will have an integer customer ID, customer name, and a floating-
point account balance.
Lines beginning with a 't' will have a customer ID, employee ID, a 'w' or 'd' representing
withdrawal or deposit, and a floating-point transaction amount.
Lines beginning with an 'e' and 'c' may be intermingled, but all 'e' and 'c' lines will come
before lines beginning with 't'.
There will be at most 50 employees and 50 customers, and an unknown number of
transactions. Names will be at most 15 characters long.
Your program should read in the employee and customer information and update the customer
account balance depending on the transaction. For example, t 1 8 w 4924.86 means to
update the balance for customer 1 by withdrawing 4924.86 from Devon's account balance
of 56442.27875. For each transaction, output customer name, the employee name, a plus sign
for deposit or a minus sign for withdrawal, the transaction amount, and the new balance after the
transaction with two decimal places (truncate values; do not worry about rounding).
