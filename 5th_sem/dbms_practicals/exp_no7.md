\newpage

# Procedures

## create procedures

```sql
MariaDB [csb]> create table emp1(id numeric(3), first_name varchar(20))
;
Query OK, 0 rows affected (0.107 sec)

MariaDB [csb]> insert into emp1 values(101, 'Nithya');
Query OK, 1 row affected (0.018 sec)

MariaDB [csb]> insert into emp1 values(102, 'Maya');
Query OK, 1 row affected (0.010 sec)

MariaDB [csb]> select * from emp1;
+------+------------+
| id   | first_name |
+------+------------+
|  101 | Nithya     |
|  102 | Maya       |
+------+------------+
2 rows in set (0.001 sec)

-- create procedure
MariaDB [csb]> delimiter //;
MariaDB [csb]> create procedure get_persons()
    -> begin
    -> select * from emp1;
    -> end //;
Query OK, 0 rows affected (0.072 sec)

-- call procedure
MariaDB [csb]> call get_persons();
+------+------------+
| id   | first_name |
+------+------------+
|  101 | Nithya     |
|  102 | Maya       |
+------+------------+
2 rows in set (0.001 sec)

Query OK, 0 rows affected (0.001 sec)
```

## delete procedure

```sql
MariaDB [csb]> drop procedure if exists get_persons;
Query OK, 0 rows affected (0.093 sec)
-- if exists is not necessary
```
