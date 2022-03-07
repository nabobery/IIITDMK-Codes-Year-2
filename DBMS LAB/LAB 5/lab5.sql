-- This Program is done by CS20B1044 Avinash R Changrani
CREATE DATABASE lab5;

USE lab5;
-- QUESTION 1
-- Creation of Tables
CREATE TABLE orders (
Ord_num varchar(3),
Ord_amount int,
Advance_amount int,
Ord_date varchar(30),
Cust_code varchar(4),
Agent_code varchar(5),
Description varchar(20)
);

CREATE TABLE Agent(
Agent_code varchar(5),
Agent_name varchar(15),
Working_area varchar(15),
Commision varchar(5),
Phone_no varchar(10),
Country varchar(15)
);

-- Inserting into Tables
INSERT INTO orders
VALUES('004',200,3000,'15-aug-2020','C004','Ac001','Masala Kulcha');
INSERT INTO orders
VALUES('007',600,5000,'17-sept-2020','C006','Ac003','Biriyani');
INSERT INTO orders
VALUES('008',700,100,'19-feb-2019','C007','Ac005','');
INSERT INTO orders
VALUES('009',10000,600,'21-march-2010','C009','Ac008','Masala dosa');
INSERT INTO orders
VALUES('010',20,600,'21-april-2012','C006','Ac005','');

INSERT INTO Agent
VALUES('Ac001','Ramesh','Bangalore','.15', '0331234567','India');
INSERT INTO Agent
VALUES('Ac002','Dinesh','Bangalore','.25', '0331234568','');
INSERT INTO Agent
VALUES('Ac003','Suresh','Mumbai','.35', '0331234569','London');
INSERT INTO Agent
VALUES('Ac004','Kamlesh','New Jersey','.68', '0331234564','');
INSERT INTO Agent
VALUES('Ac005','Kartik','Chennai','.73', '0331234563','India');

-- PART A
SELECT ord_num, ord_amount, ord_date, cust_code, agent_code FROM orders WHERE agent_code IN (SELECT agent_code FROM Agent WHERE Working_area = 'Bangalore');

-- PART B
-- As it will result in only one code I'm using = instead of IN
SELECT ord_num, ord_amount, cust_code, agent_code FROM orders WHERE agent_code = (SELECT agent_code FROM Agent WHERE Agent_name = 'Ramesh');

-- QUESTION 2
-- Creation of Tables
CREATE TABLE salesman (
Salesman_id varchar(8),
Name varchar(15),
City varchar(15),
commission varchar(5)
);

-- Creating it as orders2 as 2 tables with same names isn't allowed in a database
CREATE TABLE orders2 (
ord_no varchar(3),
Purch_amt int,
Ord_date varchar(15),
Customer_id varchar(5),
Salesman_id varchar(8)
);

-- Inserting into Tables
INSERT INTO salesman
VALUES('si123@06','Lakshmi','Kolkata','.5');
INSERT INTO salesman
VALUES('si123@09','Ganesh','London','.6');
INSERT INTO salesman
VALUES('si123@90','Dinesh','London','.3');
INSERT INTO salesman
VALUES('si123@10','Joseph','Chennai','.6');
INSERT INTO salesman
VALUES('si123@19','Mahesh','Hyderabad','.65');
INSERT INTO salesman
VALUES('si123@26','Paul Adam','London','.1');
INSERT INTO salesman
VALUES('si123@67','Rahul','Delhi','.4');

INSERT INTO orders2
VALUES('123',600,'20-aug-2010','003cd','si123@19');
INSERT INTO orders2
VALUES('576',750,'20-feb-2018','004cd','si123@19');
INSERT INTO orders2
VALUES('579',800,'20-may-2012','004cd','si123@26');
INSERT INTO orders2
VALUES('600',60000,'20-jan-2021','006cd','si123@10');
INSERT INTO orders2
VALUES('700',745,'26-jan-2021','007cd','si123@09');
INSERT INTO orders2
VALUES('800',860,'29-jan-2019','007cd','si123@26');

-- PART A
SELECT * FROM orders2 WHERE Salesman_id = (SELECT Salesman_id  FROM salesman WHERE Name = 'Paul Adam');

-- PART B
SELECT * FROM orders2 WHERE Salesman_id IN (SELECT Salesman_id  FROM salesman WHERE City = 'London');


