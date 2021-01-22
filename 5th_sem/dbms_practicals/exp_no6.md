\newpage

# Implementation of Aggregate Functions

### prepare database

```sql
MariaDB [csb]> create table movierent(
	-> ref_no int primary key,
	-> trans_date date,
	-> return_date date,
	-> membership_number int,
	-> movie_id int,
	-> movie_returned int);
Query OK, 0 rows affected (0.122 sec)

-- data inserted in table movierent

MariaDB [csb]> select * from movierent;
+--------+------------+-------------+-------------------+----------+----------------+
| ref_no | trans_date | return_date | membership_number | movie_id | movie_returned |
+--------+------------+-------------+-------------------+----------+----------------+
|     11 | 2020-06-20 | NULL        |                 1 |        1 |              0 |
|     12 | 2020-06-21 | 2020-06-22  |                 1 |        2 |              0 |
|     13 | 2020-06-22 | 2020-06-23  |                 3 |        2 |              0 |
|     14 | 2020-06-23 | 2020-06-24  |                 2 |        2 |              0 |
|     15 | 2020-06-24 | NULL        |                 3 |        3 |              0 |
+--------+------------+-------------+-------------------+----------+----------------+
5 rows in set (0.000 sec)
```

## count function

```sql
MariaDB [csb]> select count(movie_id) from movierent where movie_id=2;
+-----------------+
| count(movie_id) |
+-----------------+
|               3 |
+-----------------+
1 row in set (0.001 sec)
```

## distinct keyword

To check the concept of `distinct`, lets execute a simple query first:

```sql
MariaDB [csb]> select movie_id from movierent;
+----------+
| movie_id |
+----------+
|        1 |
|        2 |
|        2 |
|        2 |
|        3 |
+----------+
5 rows in set (0.001 sec)
```

Now, let's execute same query with `distinct` keyword

```sql
MariaDB [csb]> select distinct movie_id from movierent;
+----------+
| movie_id |
+----------+
|        1 |
|        2 |
|        3 |
+----------+
3 rows in set (0.066 sec)
```

## min function

```sql
MariaDB [csb]> select min(trans_date) from movierent;
+-----------------+
| min(trans_date) |
+-----------------+
| 2020-06-20      |
+-----------------+
1 row in set (0.029 sec)
```

## max function

```sql
MariaDB [csb]> select max(return_date) from movierent;
+------------------+
| max(return_date) |
+------------------+
| 2020-06-24       |
+------------------+
1 row in set (0.001 sec)
```

## sum function

```sql
MariaDB [csb]> select sum(membership_number) from movierent;
+------------------------+
| sum(membership_number) |
+------------------------+
|                     10 |
+------------------------+
1 row in set (0.001 sec)
```

## avg function

```sql
MariaDB [csb]> select avg(membership_number) from movierent;
+------------------------+
| avg(membership_number) |
+------------------------+
|                 2.0000 |
+------------------------+
1 row in set (0.022 sec)
```
