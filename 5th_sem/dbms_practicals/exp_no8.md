\newpage

# Functions

## function to find factorial of a number

```sql
-- create function 'factorial'
MariaDB [csb]> delimiter //;
MariaDB [csb]> create function factorial(num int)
    -> returns int(12);
    -> begin
    -> declare factorial int;
    -> set factorial = num;
    -> if num <= 0 then
    -> return 1;
    -> end if;
    ->
    -> bucle: loop
    -> set num=num-1;
    -> if num < 1 then
    -> leave bucle;
    -> end if;
    -> set factorial = factorial * num;
    -> end loop bucle;
    -> return factorial;
    -> end//;
Query OK, 0 rows affected (0.071 sec)

delimiter ;  -- set to default delimiter

-- execute the function
MariaDB [csb]> select factorial(5);
+--------------+
| factorial(5) |
+--------------+
|          120 |
+--------------+
1 row in set (0.058 sec)

MariaDB [csb]> select factorial(10);
+---------------+
| factorial(10) |
+---------------+
|       3628800 |
+---------------+
1 row in set (0.001 sec)
```

## drop function

```sql
MariaDB [csb]> drop function if exists factorial;
Query OK, 0 rows affected (0.074 sec)
```
