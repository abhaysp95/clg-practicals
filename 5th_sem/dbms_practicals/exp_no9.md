\newpage

# Subquery MySQL

## simple select operation

```sql
-- emp table already created and filled before
MariaDB [csb]> select * from emp ;
+-------+---------+------+--------+-------+
| Empno | Ename   | Job  | Deptno | Sal   |
+-------+---------+------+--------+-------+
|     1 | Mathi   | AP   |      1 | 10000 |
|     2 | Arjun   | ASP  |      2 | 15000 |
|     3 | Gugan   | ASP  |      1 | 15000 |
|     4 | Karthik | Proj |      2 | 30000 |
|     5 | Akalya  | AP   |      1 | 10000 |
+-------+---------+------+--------+-------+
5 rows in set (0.001 sec)

-- simple select subquery execution
MariaDB [csb]> select Ename,Job,Deptno from emp
	-> where Empno in (select Empno from emp);
+---------+------+--------+
| Ename   | Job  | Deptno |
+---------+------+--------+
| Mathi   | AP   |      1 |
| Arjun   | ASP  |      2 |
| Gugan   | ASP  |      1 |
| Karthik | Proj |      2 |
| Akalya  | AP   |      1 |
+---------+------+--------+
5 rows in set (0.145 sec)
```

## Subquery with comparision operator

```sql
MariaDB [csb]> select Ename,Job,Deptno from emp
	-> where Empno in ( select Empno from emp where sal >= 15000);
+---------+------+--------+
| Ename   | Job  | Deptno |
+---------+------+--------+
| Arjun   | ASP  |      2 |
| Gugan   | ASP  |      1 |
| Karthik | Proj |      2 |
+---------+------+--------+
3 rows in set (0.001 sec)

-- or

MariaDB [csb]> select Ename,Job,Deptno from emp where sal = (select max(sal) from emp);
+---------+------+--------+
| Ename   | Job  | Deptno |
+---------+------+--------+
| Karthik | Proj |      2 |
+---------+------+--------+
1 row in set (0.033 sec)
```

## Subquery with IN and NOT IN operator

```sql
-- tables
MariaDB [csb]> select * from student1;
+----+------+-------------+---------+
| id | name | email       | city    |
+----+------+-------------+---------+
|  1 | abc  | abc@xyz.com | cityabc |
|  2 | bcd  | bcd@xyz.com | citybcd |
|  3 | cde  | cde@xyz.com | citycde |
|  4 | def  | def@xyz.com | citydef |
|  5 | efg  | efg@xyz.com | cityefg |
+----+------+-------------+---------+
5 rows in set (0.001 sec)

MariaDB [csb]> select * from student2;
+----+------+-------------+---------+
| id | name | email       | city    |
+----+------+-------------+---------+
|  1 | fgh  | fgh@xyz.com | cityabc |
|  2 | cde  | cde@xyz.com | citydef |
|  3 | abc  | abc@xyz.com | citybcd |
|  4 | ghi  | ghi@xyz.com | cityefg |
|  5 | hij  | hij@xyz.com | citydef |
+----+------+-------------+---------+
5 rows in set (0.001 sec)

-- not in operator
MariaDB [csb]> select name, city from student1
	-> where city not in
	-> ( select city from student2 where city='citydef');
+------+---------+
| name | city    |
+------+---------+
| abc  | cityabc |
| bcd  | citybcd |
| cde  | citycde |
| efg  | cityefg |
+------+---------+
4 rows in set (0.026 sec)
```

Some other operators for `subquery` are: `from`, `exists`, `not exists`, `all`, `any`, `some` etc.
