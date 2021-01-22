\newpage

<!------->
<!--mainfont: JetBrains Mono-->
<!--mainfontoptions:-->
<!--- BoldFont=JetBrains Mono Bold-->
<!--- ItalicFont=JetBrains Mono Italic-->
<!--- BoldItalicFont=JetBrains Mono Bold Italic-->
<!--numbersections: true-->
<!------->
<!--- ItalicFont=UbuntuMono Nerd Font Mono Italic-->
<!--- BoldItalicFont=UbuntuMono Nerd Font Mono Bold Italic-->
<!------->

# To study various DML commands


## Insert a single record into dept table

```sql
MariaDB [csb]> insert into dept values(1, 'IT', 'Tholudur');
Query OK, 1 row affected (0.015 sec)

MariaDB [csb]> select * from dept;
+----+-----------+----------+
| ID | Dept_name | Emp_name |
+----+-----------+----------+
|  1 | IT        | Tholudur |
+----+-----------+----------+
1 row in set (0.001 sec)
```

## Insert more than a recored into emp table using a single insert command

```sql
MariaDB [csb]> insert into emp values
    -> ( 1, 'Mathi', 'AP', 1, 10000 ),
    -> ( 2, 'Arjun', 'ASP', 2, 12000 ),
    -> ( 3, 'Gugan', 'ASP', 1, 12000 );
Query OK, 3 rows affected (0.022 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [csb]> select * from emp;
+-------+-------+------+--------+-------+
| Empno | Ename | Job  | Deptno | Sal   |
+-------+-------+------+--------+-------+
|     1 | Mathi | AP   |      1 | 10000 |
|     2 | Arjun | ASP  |      2 | 12000 |
|     3 | Gugan | ASP  |      1 | 12000 |
+-------+-------+------+--------+-------+
3 rows in set (0.001 sec)
```

## Update the emp table to set the salary of all the employees to Rs 15000/- who are working as ASP

```sql
MariaDB [csb]> select * from emp;
+-------+-------+------+--------+-------+
| Empno | Ename | Job  | Deptno | Sal   |
+-------+-------+------+--------+-------+
|     1 | Mathi | AP   |      1 | 10000 |
|     2 | Arjun | ASP  |      2 | 12000 |
|     3 | Gugan | ASP  |      1 | 12000 |
+-------+-------+------+--------+-------+
3 rows in set (0.001 sec)

MariaDB [csb]> update emp set Sal=15000 where job='ASP';
Query OK, 2 rows affected (0.049 sec)
Rows matched: 2  Changed: 2  Warnings: 0

MariaDB [csb]> select * from emp;
+-------+-------+------+--------+-------+
| Empno | Ename | Job  | Deptno | Sal   |
+-------+-------+------+--------+-------+
|     1 | Mathi | AP   |      1 | 10000 |
|     2 | Arjun | ASP  |      2 | 15000 |
|     3 | Gugan | ASP  |      1 | 15000 |
+-------+-------+------+--------+-------+
3 rows in set (0.001 sec)
```

## Create a pseudo table employee with the same structure as the table emp and insert rows into the table using select clauses.

```sql
MariaDB [csb]> create table employee as select * from emp;
Query OK, 3 rows affected (0.147 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [csb]> desc employee;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| Empno  | int(11)     | NO   |     | NULL    |       |
| Ename  | varchar(32) | YES  |     | NULL    |       |
| Job    | varchar(40) | YES  |     | NULL    |       |
| Deptno | int(11)     | YES  |     | NULL    |       |
| Sal    | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
5 rows in set (0.001 sec)
```

## Select employee name, job from the emp table

```sql
MariaDB [csb]> select ename, job from emp;
+-------+------+
| ename | job  |
+-------+------+
| Mathi | AP   |
| Arjun | ASP  |
| Gugan | ASP  |
+-------+------+
3 rows in set (0.001 sec)
```

## Delete only those who are working as lecturer

```sql
MariaDB [csb]> select * from emp;
+-------+--------+------+--------+-------+
| Empno | Ename  | Job  | Deptno | Sal   |
+-------+--------+------+--------+-------+
|     1 | Mathi  | AP   |      1 | 10000 |
|     2 | Arjun  | ASP  |      2 | 15000 |
|     3 | Gugan  | ASP  |      1 | 15000 |
|     6 | Suresh | lect |      1 |  8000 |
+-------+--------+------+--------+-------+
4 rows in set (0.001 sec)

MariaDB [csb]> delete from emp where job="lect";
Query OK, 1 row affected (0.017 sec)

MariaDB [csb]> select * from emp;
+-------+-------+------+--------+-------+
| Empno | Ename | Job  | Deptno | Sal   |
+-------+-------+------+--------+-------+
|     1 | Mathi | AP   |      1 | 10000 |
|     2 | Arjun | ASP  |      2 | 15000 |
|     3 | Gugan | ASP  |      1 | 15000 |
+-------+-------+------+--------+-------+
3 rows in set (0.001 sec)
```

## List the records in the emp table orderby salary in ascending order

```sql
MariaDB [csb]> select * from emp order by sal;
+-------+---------+------+--------+-------+
| Empno | Ename   | Job  | Deptno | Sal   |
+-------+---------+------+--------+-------+
|     1 | Mathi   | AP   |      1 | 10000 |
|     5 | Akalya  | AP   |      1 | 10000 |
|     2 | Arjun   | ASP  |      2 | 15000 |
|     3 | Gugan   | ASP  |      1 | 15000 |
|     4 | Karthik | Proj |      2 | 30000 |
+-------+---------+------+--------+-------+
5 rows in set (0.001 sec)
```

## List the records in the emp table order by salary in descending order

```sql
MariaDB [csb]> select * from emp order by sal desc;
+-------+---------+------+--------+-------+
| Empno | Ename   | Job  | Deptno | Sal   |
+-------+---------+------+--------+-------+
|     4 | Karthik | Proj |      2 | 30000 |
|     2 | Arjun   | ASP  |      2 | 15000 |
|     3 | Gugan   | ASP  |      1 | 15000 |
|     1 | Mathi   | AP   |      1 | 10000 |
|     5 | Akalya  | AP   |      1 | 10000 |
+-------+---------+------+--------+-------+
5 rows in set (0.001 sec)
```

## Display only those employees whose deptno is 1

```sql
MariaDB [csb]> select * from emp where Deptno=1;
+-------+--------+------+--------+-------+
| Empno | Ename  | Job  | Deptno | Sal   |
+-------+--------+------+--------+-------+
|     1 | Mathi  | AP   |      1 | 10000 |
|     3 | Gugan  | ASP  |      1 | 15000 |
|     5 | Akalya | AP   |      1 | 10000 |
+-------+--------+------+--------+-------+
3 rows in set (0.001 sec)
```

## Display deptno from the table employee avoiding the duplicated values

```sql
MariaDB [csb]> select distinct Deptno from emp;
+--------+
| Deptno |
+--------+
|      1 |
|      2 |
+--------+
2 rows in set (0.001 sec)
```
