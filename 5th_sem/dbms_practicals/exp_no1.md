% DBMS Practical
% Abhay Shanker Pathak
% 2021-01-20

---
mainfont: JetBrains Mono
mainfontoptions:
- BoldFont=JetBrains Mono Bold
- ItalicFont=JetBrains Mono Italic
- BoldItalicFont=JetBrains Mono Bold Italic
pagesize: a4
fontsize: 9pt
numbersections: true
---

\newpage

# To create a DDL to perform creation of table, alter, modify and drop column

## The Create Table Command

**Syntax:**

```sql
Create table <table name> (<col1> <datatype>(<size>), <col2> <datatype> (<size>));
-- demo
MariaDB [csb]> create table emptemp(empno int primary key, ename char(10));
Query OK, 0 rows affected (0.192 sec)

MariaDB [csb]> describe emptemp;
+-------+----------+------+-----+---------+-------+
| Field | Type     | Null | Key | Default | Extra |
+-------+----------+------+-----+---------+-------+
| empno | int(11)  | NO   | PRI | NULL    |       |
| ename | char(10) | YES  |     | NULL    |       |
+-------+----------+------+-----+---------+-------+
2 rows in set (0.002 sec)
```

## Modify the structure of table

### Add new column

**Syntax:**

```sql
Alter table <tablename> add(<new col><datatype>(size), <newcol>datatype(size));
--demo
MariaDB [csb]> alter table emptemp add(sal numeric(7, 2));
Query OK, 0 rows affected (0.064 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [csb]> describe emptemp;
+-------+--------------+------+-----+---------+-------+
| Field | Type         | Null | Key | Default | Extra |
+-------+--------------+------+-----+---------+-------+
| empno | int(11)      | NO   | PRI | NULL    |       |
| ename | char(10)     | YES  |     | NULL    |       |
| sal   | decimal(7,2) | YES  |     | NULL    |       |
+-------+--------------+------+-----+---------+-------+
3 rows in set (0.002 sec)
```

## Dropping a column from a table

**Syntax:**

```sql
Alter table <tablename> drop column <col>;
--demo
MariaDB [csb]> alter table emptemp drop column sal;
Query OK, 0 rows affected (0.044 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [csb]> describe emptemp;
+-------+----------+------+-----+---------+-------+
| Field | Type     | Null | Key | Default | Extra |
+-------+----------+------+-----+---------+-------+
| empno | int(11)  | NO   | PRI | NULL    |       |
| ename | char(10) | YES  |     | NULL    |       |
+-------+----------+------+-----+---------+-------+
2 rows in set (0.002 sec)
```

## Modify existing column

**Syntax:**

```sql
Alter table <tablename> modify <col> <datatype>(<size>);
--demo
MariaDB [csb]> alter table emptemp modify ename varchar(15);
Query OK, 0 rows affected (0.370 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [csb]> describe emptemp;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| empno | int(11)     | NO   | PRI | NULL    |       |
| ename | varchar(15) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.001 sec)
```

## Renaming the table

**Syntax:**

```sql
rename table <old_table_name> to <new_table_name>;
--demo
MariaDB [csb]> rename table emptemp to emptmp;
Query OK, 0 rows affected (0.068 sec)

MariaDB [csb]> describe emptmp;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| empno | int(11)     | NO   | PRI | NULL    |       |
| ename | varchar(15) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.001 sec)
```

## Destroying table

**Syntax:**

```sql
Drop table <tablename>;
--demo
MariaDB [csb]> drop table emptmp;
Query OK, 0 rows affected (0.064 sec)

MariaDB [csb]> describe emptmp;
ERROR 1146 (42S02): Table 'csb.emptmp' doesn't exist
```
