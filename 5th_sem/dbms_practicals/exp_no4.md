\newpage

# Implementation of Cursor

`this is implementation of cursor in mysql`

## Declare Cursor

**Syntax:**

```sql
declare <cursor name> cursor for select <statement>;
```

## Open Cursor

**Syntax:**

```sql
open <cursor name>;
```

## Fetch cursor

**Syntax:**

```sql
fetch [next[from]] <curor name> into <variable list>;
```

## Close cursor

**Syntax:**

```sql
close <cursor name>;
```

## Demo

Following is the _demo_ for implementation of cursor in mysql

```sql
-- table to operate on
MariaDB [csb]> select * from cursordemo;
+----+----------+--------+
| id | name     | course |
+----+----------+--------+
|  1 | Shristee | MCA    |
|  2 | Ajay     | BCA    |
|  3 | Shweta   | MCA    |
|  4 | Dolly    | BCA    |
|  5 | Heena    | MCA    |
|  6 | Kiran    | BCA    |
|  7 | Sonal    | MCA    |
|  8 | Dimple   | BCA    |
|  9 | Shyam    | MCA    |
| 10 | Mohit    | BCA    |
+----+----------+--------+
10 rows in set (0.001 sec)

-- creation of cursor
MariaDB [csb]> create procedure list_name (inout name_list varchar(4000))
    -> begin
    -> declare is_done integer default 0;
    -> declare s_name varchar(100) default "";
    -> declare stud_cursor cursor for
    -> select name from cursordemo;
    -> declare continue handler for not found set is_done=1;
    -> open stud_cursor;
    -> get_list: loop
    -> fetch stud_cursor into s_name;
    -> if is_done=1 then
    -> leave get_list;
    -> end if;
    -> set name_list=concat(s_name, "; ", name_list);
    -> end loop get_list;
    -> close stud_cursor;
    -> end$$
Query OK, 0 rows affected (0.414 sec)

-- call the cursor
MariaDB [csb]> set @name_list ="";
Query OK, 0 rows affected (0.000 sec)

MariaDB [csb]> call list_name(@name_list);
Query OK, 0 rows affected (0.225 sec)

MariaDB [csb]> select @name_list;
+----------------------------------------------------------------------------+
| @name_list                                                                 |
+----------------------------------------------------------------------------+
| Mohit; Shyam; Dimple; Sonal; Kiran; Heena; Dolly; Shweta; Ajay; Shristee;  |
+----------------------------------------------------------------------------+
1 row in set (0.000 sec)
```
