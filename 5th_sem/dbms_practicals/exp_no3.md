\newpage
<!--% Practical No. 3-->
<!--% Abhay Shanker Pathak-->
<!--% 2021-01-21-->

<!------->
<!--mainfont: JetBrains Mono-->
<!--mainfontoptions:-->
<!--- BoldFont=JetBrains Mono Bold-->
<!--- ItalicFont=JetBrains Mono Italic-->
<!--- BoldItalicFont=JetBrains Mono Bold Italic-->
<!--numbersections: true-->
<!------->

# To implement DCL and TCL Commands

## DCL Commands

### Develop a query to grant all privileges of employees table into departments table

```sql
MariaDB [csb]> create table departments
	-> (dept_no int primary key, dept_name varchar(24), dept_location varchar(32));
Query OK, 0 rows affected (0.166 sec)

MariaDB [csb]> create table employees
	-> (emp_id int primary key, emp_name varchar(24), emp_salary numeric(10, 2));
Query OK, 0 rows affected (0.134 sec)

MariaDB [csb]> Grant all on employees to departments;
Grant Succeeded
```

### Develop a query to grant some privileges of employees table into department table

```sql
MariaDB [csb]> grant select, update, insert on departments to departments with grant option;
Grant succeeded
```

### Develop a query to revoke all privileges of employees table from departments table

```sql
MariaDB [csb]> revoke all on employees from departments;
Revoke succeeded
```

## TCL commands

### Develop a query to revoke some privileges of employees table from departments table

```sql
MariaDB [csb]> revoke select, update, insert on departments from departments;
Revoke succeeded
```


### Write a query to implement the save point

```sql
MariaDB [csb]> savepoint s1;
Query OK, 0 rows affected (0.000 sec)

MariaDB [csb]> select * from emp;
+-------+---------+------+--------+-------+
| Empno | Ename   | Job  | Deptno | Sal   |
+-------+---------+------+--------+-------+
|     1 | Mathi   | AP   |      1 | 10000 |
|     2 | Arjun   | ASP  |      2 | 15000 |
|     3 | Gugan   | ASP  |      1 | 15000 |
|     4 | Karthik | Proj |      2 | 30000 |
|     5 | Akalya  | AP   |      1 | 10000 |
+-------+---------+------+--------+-------+
5 rows in set (0.000 sec)

MariaDB [csb]> insert into emp values(6, 'Darpan', 'Proj', 1, 28000);
Query OK, 1 row affected (0.030 sec)

MariaDB [csb]> select * from emp;
+-------+---------+------+--------+-------+
| Empno | Ename   | Job  | Deptno | Sal   |
+-------+---------+------+--------+-------+
|     1 | Mathi   | AP   |      1 | 10000 |
|     2 | Arjun   | ASP  |      2 | 15000 |
|     3 | Gugan   | ASP  |      1 | 15000 |
|     4 | Karthik | Proj |      2 | 30000 |
|     5 | Akalya  | AP   |      1 | 10000 |
|     6 | Darpan  | Proj |      1 | 28000 |
+-------+---------+------+--------+-------+
6 rows in set (0.000 sec)
```

### Write a query to implement the rollback

```sql
MariaDB [csb]> savepoint s1;
Query OK, 0 rows affected (0.000 sec)

MariaDB [csb]> select * from emp;
+-------+---------+------+--------+-------+
| Empno | Ename   | Job  | Deptno | Sal   |
+-------+---------+------+--------+-------+
|     1 | Mathi   | AP   |      1 | 10000 |
|     2 | Arjun   | ASP  |      2 | 15000 |
|     3 | Gugan   | ASP  |      1 | 15000 |
|     4 | Karthik | Proj |      2 | 30000 |
|     5 | Akalya  | AP   |      1 | 10000 |
+-------+---------+------+--------+-------+
5 rows in set (0.000 sec)
```

### Write a query to implement the commit

```sql
MariaDB [csb]> commit;
Query OK, 0 rows affected (0.000 sec)
```
