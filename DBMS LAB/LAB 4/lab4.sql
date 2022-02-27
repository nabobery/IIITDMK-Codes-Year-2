-- This Program is done by CS20B1044 Avinash R Changrani
CREATE DATABASE lab4;

USE lab4;
-- QUESTION 1
CREATE TABLE STUDENTACCOUNT(
id int,
Person_Name varchar(10),
Department varchar(2),
Birth varchar(10)
);

INSERT INTO studentaccount
VALUES(1,'Ramesh', 'CS','2001-01-12');
INSERT INTO studentaccount
VALUES(2,'Suresh', 'IT','2020-02-20');
INSERT INTO studentaccount
VALUES(3,'Jomin', 'CS','1996-02-29');
INSERT INTO studentaccount
VALUES(4,'Shree', 'IT','2012-12-18');
INSERT INTO studentaccount
VALUES(5,'Hemanth', 'CS','2022-02-07');

-- OPERATION A
SELECT id, Person_name, department, Birth, 
CONCAT( 
FLOOR((TIMESTAMPDIFF(MONTH, Birth, CURDATE()) / 12)), ' Years and ', 
MOD(TIMESTAMPDIFF(MONTH, Birth, CURDATE()), 12) , ' Months') 
AS Age FROM studentaccount WHERE department = 'CS';

-- OPERATION B
SELECT * FROM studentaccount WHERE Person_name LIKE '%s%';

-- OPERATION C
SELECT * FROM studentaccount WHERE CHAR_LENGTH(Person_name) = 5;

-- OPERATION D
-- ODD ROWS 
SELECT * FROM studentaccount GROUP BY id having mod(id,2)=1;
-- EVEN ROWS
SELECT * FROM studentaccount GROUP BY id having mod(id,2)=0;

-- QUESTION 2
CREATE TABLE Employees(
Employee_id int,
First_name varchar(10),
Last_name varchar(10),
Salary int,
Joining_date varchar(10),
Department varchar(10)
);

INSERT INTO Employees
VALUES(1,'Boby', 'Rathod',1000000,'2020-12-20','Finance' );
INSERT INTO Employees
VALUES(2,'Jasmin', 'Jose',6000000,'2015-02-07','IT' );
INSERT INTO Employees
VALUES(3,'Pratap', 'Mathew',8900000,'2014-03-09','Banking' );
INSERT INTO Employees
VALUES(4,'John', 'Michel',2000000,'1999-03-17','Insurance' );
INSERT INTO Employees
VALUES(5,'Alex', 'Kinto',2200000,'1987-02-25','Finance' );
INSERT INTO Employees
VALUES(6,'Jaswanth', 'Kumar',1230000,'2021-07-23','IT' );

-- OPERATION A
SELECT * FROM Employees WHERE Salary between 2000000 AND 5000000;

-- OPERATION B
SELECT Last_name FROM Employees WHERE TIMESTAMPDIFF(YEAR,Joining_date,CURDATE()) > 3 and First_name like '%a%';

-- OPERATION C
SELECT Joining_date FROM Employees WHERE  Salary > (SELECT AVG(Salary) FROM Employees) AND Department = 'IT';

-- OPERATION D
SELECT * FROM Employees WHERE  Salary < (SELECT AVG(Salary) FROM Employees WHERE Department = 'IT') AND Department = 'Finance';
-- SELECT * FROM Employees WHERE  Salary < (SELECT AVG(Salary) FROM Employees GROUP BY Department HAVING department = 'IT') AND Department = 'Finance';



