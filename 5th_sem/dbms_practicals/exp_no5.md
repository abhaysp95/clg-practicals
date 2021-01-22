\newpage

# Implementation of Triggers

`this is implementation of triggers in mysql. MySQL doesn't support statement-level triggers, only support row-level triggers`

### table for demo

```sql
MariaDB [csb]> select * from employee;
+---------+------------+--------------+---------------+
| name    | occupation | working_date | working_hours |
+---------+------------+--------------+---------------+
| Robin   | Scientist  | 2020-10-04   | 12            |
| Warner  | Engineer   | 2020-10-04   | 10            |
| Peter   | Actor      | 2020-10-04   | 13            |
| Marco   | Doctor     | 2020-10-04   | 14            |
| Brayden | Teacher    | 2020-10-04   | 12            |
| Antonio | Business   | 2020-10-04   | 11            |
+---------+------------+--------------+---------------+
6 rows in set (0.001 sec)
```

## Create Trigger

```sql
MariaDB [csb]> create trigger before_insert_empworkinghours
    -> before insert on employee for each row
    -> begin
    -> if new.working_hours < 0 then set new.working_hours = 0;
    -> end if;
    -> end //;
Query OK, 0 rows affected (0.118 sec)

-- invoke the trigger
MariaDB [csb]> insert into employee values('Markus', 'Former', '2020-10-08', 14);
Query OK, 1 row affected (0.090 sec)

MariaDB [csb]> insert into employee values('Alexander', 'Actor', '2020-12-10', -13);
Query OK, 1 row affected (0.011 sec)

MariaDB [csb]> select * from employee;
+-----------+------------+--------------+---------------+
| name      | occupation | working_date | working_hours |
+-----------+------------+--------------+---------------+
| Robin     | Scientist  | 2020-10-04   | 12            |
| Warner    | Engineer   | 2020-10-04   | 10            |
| Peter     | Actor      | 2020-10-04   | 13            |
| Marco     | Doctor     | 2020-10-04   | 14            |
| Brayden   | Teacher    | 2020-10-04   | 12            |
| Antonio   | Business   | 2020-10-04   | 11            |
| Markus    | Former     | 2020-10-08   | 14            |
| Alexander | Actor      | 2020-12-10   | 0             |
+-----------+------------+--------------+---------------+
8 rows in set (0.001 sec)

-- in above output pay attention to last person's working_hours, -ve value is set to 0
```

## Show/List Triggers MySQL

```sql
MariaDB [(none)]> show triggers;
ERROR 1046 (3D000): No database selected
MariaDB [(none)]> use csb;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [csb]> show triggers;
+-------------------------------+--------+----------+----------------------------------------------------------------------------+--------+------------------------+-------------------------------------------------------------------------------------------+--------------------+----------------------+----------------------+--------------------+
| Trigger                       | Event  | Table    | Statement                                                                  | Timing | Created                | sql_mode                                                                                  | Definer            | character_set_client | collation_connection | Database Collation |
+-------------------------------+--------+----------+----------------------------------------------------------------------------+--------+------------------------+-------------------------------------------------------------------------------------------+--------------------+----------------------+----------------------+--------------------+
| before_insert_empworkinghours | INSERT | employee | begin
if new.working_hours < 0 then set new.working_hours = 0;
end if;
end | BEFORE | 2021-01-21 22:08:33.85 | STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION | clg_prac@localhost | utf8                 | utf8_general_ci      | utf8mb4_unicode_ci |
+-------------------------------+--------+----------+----------------------------------------------------------------------------+--------+------------------------+-------------------------------------------------------------------------------------------+--------------------+----------------------+----------------------+--------------------+
1 row in set (0.073 sec)
-- you can also list out triggers with patterns
```

## Drop Triggers

```sql
MariaDB [csb]> drop trigger before_insert_empworkinghours;
Query OK, 0 rows affected (0.001 sec)

MariaDB [csb]> drop trigger before_insert_empworkinghours;
ERROR 1360 (HY000): Trigger does not exist

-- if trigger doesn't exist in db this command will throw an error
-- you can use 'if exists' to check for existance

MariaDB [csb]> drop trigger if exists before_insert_empworkinghours;
Query OK, 0 rows affected, 1 warning (0.000 sec)
```

## before insert trigger

```sql
MariaDB [csb]> delimiter //;
MariaDB [csb]> create trigger before_insert_occupation
    -> before insert on employee for each row
    -> begin
    -> if new.occupation = 'Scientist' then set new.occupation = 'Doctor';
    -> end if;
    -> end //;
Query OK, 0 rows affected (0.078 sec)

MariaDB [csb]> insert into employee values('Daniel', 'Scientist', '2017
-05-23', 8);
Query OK, 1 row affected (0.113 sec)

MariaDB [csb]> select * from employee;
+-----------+------------+--------------+---------------+
| name      | occupation | working_date | working_hours |
+-----------+------------+--------------+---------------+
| Robin     | Scientist  | 2020-10-04   | 12            |
| Warner    | Engineer   | 2020-10-04   | 10            |
| Peter     | Actor      | 2020-10-04   | 13            |
| Marco     | Doctor     | 2020-10-04   | 14            |
| Brayden   | Teacher    | 2020-10-04   | 12            |
| Antonio   | Business   | 2020-10-04   | 11            |
| Markus    | Former     | 2020-10-08   | 14            |
| Alexander | Actor      | 2020-12-10   | 0             |
| Daniel    | Doctor     | 2017-05-23   | 8             |
+-----------+------------+--------------+---------------+
9 rows in set (0.001 sec)
-- notice the last tuple, 'Daniel is Doctor not Scientist'
```

## after insert trigger

```sql
MariaDB [csb]> create table employee_detail(name varchar(45), occupatio
n varchar(35), working_date date, working_hours varchar(10), last_inser
ted time);
Query OK, 0 rows affected (0.225 sec)

MariaDB [csb]> select * from employee_detail;
Empty set (0.001 sec)

MariaDB [csb]> delimiter //;
MariaDB [csb]> create trigger after_insert_details
    -> after insert on employee for each row
    -> begin
    -> insert into employee_detail values(
    -> new.name,
    -> new.occupation,
    -> new.working_date,
    -> new.working_hours,
    -> curtime());
    -> end//;
Query OK, 0 rows affected (0.135 sec)

MariaDB [csb]> insert into employee values('Jacob', 'Zoologist', '2019-07-28', 11);
Query OK, 1 row affected (0.016 sec)

MariaDB [csb]> select * from employee_detail;
+-------+------------+--------------+---------------+---------------+
| name  | occupation | working_date | working_hours | last_inserted |
+-------+------------+--------------+---------------+---------------+
| Jacob | Zoologist  | 2019-07-28   | 11            | 22:32:04      |
+-------+------------+--------------+---------------+---------------+
1 row in set (0.001 sec)
-- you may notice that insert into employee also filled employee_detail after filling up employee table
```

In same way there's also `before update`, `after update`, `before delete` & `after delete` trigger operations supported by MySQL.
