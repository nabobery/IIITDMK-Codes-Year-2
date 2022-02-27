-- This Program was done BY CS20B1044 Avinash R Changrani
CREATE DATABASE dblab;

-- Creation of Tables
USE dblab;
CREATE TABLE Student(
Rollno varchar(10),
SName varchar(10),
City varchar(10)
);

USE dblab;
CREATE TABLE Course(
CID varchar(10),
CName varchar(10),
Credit int(100)
);

-- (i) Insert at least 10 entries in the above two tables where entries cannot be null.
USE dblab;
INSERT INTO Student(Rollno,SName,City)
VALUES ('CS1','A','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('CS2','B','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('CS3','C','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('CS4','D','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('EC1','E','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('EC2','F','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('EC3','G','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('ME1','H','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('ME2','I','Chennai');
INSERT INTO Student(Rollno,SName,City)
VALUES ('ME3','J','Chennai');

USE dblab;
INSERT INTO Course(CID,CName,Credit) 
VALUES('CS2001', 'PSP',20);
INSERT INTO Course(CID,CName,Credit) 
VALUES('CS2002', 'DSA',25);
INSERT INTO Course(CID,CName,Credit) 
VALUES('CS2004', 'TOC',30);
INSERT INTO Course(CID,CName,Credit) 
VALUES('CS2005', 'DBMS',35);
INSERT INTO Course(CID,CName,Credit) 
VALUES('EC2001', 'ECE',20);
INSERT INTO Course(CID,CName,Credit) 
VALUES('EC2003', 'DLD',30);
INSERT INTO Course(CID,CName,Credit) 
VALUES('EC2008', 'DSP',50);
INSERT INTO Course(CID,CName,Credit) 
VALUES('ME2002', 'EE',25);
INSERT INTO Course(CID,CName,Credit) 
VALUES('ME2004', 'EG',35);
INSERT INTO Course(CID,CName,Credit) 
VALUES('ME2006', 'HT',45);

-- (ii) Display all the entries of the tables.
SELECT * FROM dblab.student;
SELECT * FROM dblab.course;

-- (iii) Add department and marks column to Student table.
USE dblab;
ALTER TABLE Student
ADD department varchar(10), 
ADD marks int(100);

USE dblab;
UPDATE Student 
SET department = 'CSE' , marks = 90
WHERE Rollno = 'CS1';
UPDATE Student
SET department = 'CSE' , marks = 85
WHERE Rollno = 'CS2';
UPDATE Student
SET department = 'CSE' , marks = 95
WHERE Rollno = 'CS3';
UPDATE Student
SET department = 'CSE' , marks = 99
WHERE Rollno = 'CS4';
UPDATE Student
SET department = 'ECE' , marks = 80
WHERE Rollno = 'EC1';
UPDATE Student
SET department = 'ECE' , marks = 90
WHERE Rollno = 'EC2';
UPDATE Student
SET department = 'ECE' , marks = 75
WHERE Rollno = 'EC3';
UPDATE Student
SET department = 'Mechanical' , marks = 60
WHERE Rollno = 'ME1';
UPDATE Student
SET department = 'Mechanical' , marks = 75
WHERE Rollno = 'ME2';
UPDATE Student
SET department = 'Mechanical' , marks = 80
WHERE Rollno = 'ME3';

-- (iv) Update the marks=70 having department = Mechanical.
USE dblab;
UPDATE Student
SET marks = 70
WHERE department = 'Mechanical';

-- (v) Modify the datatype of credit to string.
USE dblab;
ALTER TABLE Course
MODIFY COLUMN Credit varchar(3);

-- (vi) Add course-admission-date to table Course.
USE dblab;
ALTER TABLE Course
ADD `course-admission-date` varchar(15);

use dblab;
UPDATE Course
SET `course-admission-date` = '2021-09-09'
WHERE CID = 'CS2001';
UPDATE Course
SET `course-admission-date` = '2021-08-24'
WHERE CID = 'CS2002';
UPDATE Course
SET `course-admission-date` = '2021-06-21'
WHERE CID = 'CS2004';
UPDATE Course
SET `course-admission-date` = '2021-05-24'
WHERE CID = 'CS2005';
UPDATE Course
SET `course-admission-date` = '2020-10-01'
WHERE CID = 'EC2001';
UPDATE Course
SET `course-admission-date` = '2020-09-02'
WHERE CID = 'EC2003';
UPDATE Course
SET `course-admission-date` = '2020-04-09'
WHERE CID = 'EC2008';
UPDATE Course
SET `course-admission-date` = '2019-03-06'
WHERE CID = 'ME2002';
UPDATE Course
SET `course-admission-date` = '2019-04-26'
WHERE CID = 'ME2004';
UPDATE Course
SET `course-admission-date` = '2019-11-27'
WHERE CID = 'ME2006';






