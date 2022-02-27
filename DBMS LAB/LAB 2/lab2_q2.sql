-- This program was done by CS20B1044 Avinash Changrani
-- Creating the database and the tables
CREATE DATABASE IIITDM;

USE iiitdm;
CREATE TABLE Student(
student_id varchar(10),
first_name varchar(10),
last_name varchar(10),
parent_name varchar(10),
Age int
);

CREATE TABLE Faculty(
Faculty_id varchar(10),
Name varchar(15),
Age int,
department varchar(10),
Date_of_joining varchar(15)
);

CREATE TABLE Building(
Building_name varchar(10),
building_id varchar(10),
Capacity_of_student int,
no_of_floors int,
Date_of_inauguration varchar(10)
);

-- Operation 1
USE iiitdm;
ALTER TABLE Student
ADD PRIMARY KEY (student_id);
ALTER TABLE Faculty
ADD PRIMARY KEY (Faculty_id);
ALTER TABLE Building
ADD PRIMARY KEY (Building_name);

USE iiitdm;
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CS1', 'Shattesh', 'Sethi', 'Ram',18);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CS2', 'Isar', 'Kaushik', 'Raj',18);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CS3', 'Mahish', 'Chandra', 'Sudir',19);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CS4', 'Sudhish', 'Kateel', 'Aslesh',19);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CS5', 'Pival', 'Richa', 'Tariq',18);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('EC1', 'Ricky', 'Gates', 'Bill',17);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('EC2', 'Nora', 'Nilani', 'Sadiq',18);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('EC3', 'Aditya', 'Tendulkar', 'Anil',19);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('ME1', 'Vijay ', 'Niveda', 'Ujala',18);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('ME2', 'Prateek', 'Sharma', 'Rohit',19);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('ME3', 'Neeraf', 'Yogesh', 'Girish',20);

INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F1','A',45,'CS','2008-01-18');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F2','B',40,'CS','2009-04-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F3','C',39,'CS','2012-05-09');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F4','D',35,'CS','2016-08-04');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F5','E',45,'Electrical','2008-05-30');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F6','F',40,'Electrical','2011-04-19');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F7','G',35,'Electrical','2019-05-13');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F8','H',45,'Mechanical','2007-05-30');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F9','I',40,'Mechanical','2012-06-19');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F10','J',35,'Mechanical','2019-08-27');

INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BA','B1', 200,10,'2008-02-14');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BB','B2', 400,15,'2009-02-13');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BC','B3', 200,12,'2011-01-06');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BD','B4', 500,14,'2011-12-13');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BE','B5', 100,5,'2012-11-14');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BF','B6', 200,8,'2013-06-07');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BG','B7', 300,10,'2015-02-19');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BH','B8', 400,12,'2017-12-07');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BI','B9', 500,14,'2018-09-12');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BJ','B10', 600,15,'2020-06-17');

SELECT * FROM iiitdm.student;
SELECT * FROM iiitdm.faculty;
SELECT * FROM iiitdm.building;

-- Operation 2 and 3
-- operation 2 insertions
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F11','K',30,'CS','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F12','L',25,'CS','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F13','M',28,'CS','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F14','N',35,'CS','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F15','O',37,'CS','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F16','P',32,'CS','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F17','Q',27,'Electrical','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F18','R',29,'Electrical','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F19','S',30,'Electrical','2020-02-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F20','T',36,'Electrical','2020-02-27');

INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CSD1', 'Dinesh', 'Shan', 'Kamal',18);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('CSD2', 'Gagan', 'Panikkar', 'Abhinav',19);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('MED1', 'Gopal', 'Divekar', 'Ajay',19);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('MED2', 'Arpit', 'Kumar', 'Abhi',20);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age)
VALUES ('MED3', 'Chhotu', 'Bagchi', 'Sam',20);

INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BK','B11', 400,12,'2020-02-27');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BL','B12', 300,10,'2020-02-27');
INSERT INTO Building(Building_name, building_id, Capacity_of_student, no_of_floors,
Date_of_inauguration) VALUES('BM','B13', 250,8,'2020-02-27');

SELECT * FROM iiitdm.student;
SELECT * FROM iiitdm.faculty;
SELECT * FROM iiitdm.building;

-- OPERATION 3 Corrections and Insertions
USE iiitdm;
ALTER TABLE Student
ADD department varchar(10);

UPDATE Student
SET department = 'CSE'
WHERE student_id = 'CS1';
UPDATE Student
SET department = 'CSE'
WHERE student_id = 'CS2';
UPDATE Student
SET department = 'Math'
WHERE student_id = 'CS3';
UPDATE Student
SET department = 'Math'
WHERE student_id = 'CS4';
UPDATE Student
SET department = 'CSE'
WHERE student_id = 'CS5';
UPDATE Student
SET department = 'CSE'
WHERE student_id = 'CSD1';
UPDATE Student
SET department = 'CSE'
WHERE student_id = 'CSD2';
UPDATE Student
SET department = 'Electrical'
WHERE student_id = 'EC1';
UPDATE Student
SET department = 'Physics'
WHERE student_id = 'EC2';
UPDATE Student
SET department = 'Electrical'
WHERE student_id = 'EC3';
UPDATE Student
SET department = 'Mechanical'
WHERE student_id = 'ME1';
UPDATE Student
SET department = 'Mechanical'
WHERE student_id = 'ME2';
UPDATE Student
SET department = 'Mechanical'
WHERE student_id = 'ME3';
UPDATE Student
SET department = 'Mechanical'
WHERE student_id = 'MED1';
UPDATE Student
SET department = 'Mechanical'
WHERE student_id = 'MED2';
UPDATE Student
SET department = 'Mechanical'
WHERE student_id = 'MED3';

UPDATE faculty
SET department = 'Mechanical'
WHERE department = 'Electrical' AND Date_of_joining = '2020-02-27';

SELECT * FROM iiitdm.student;
SELECT * FROM iiitdm.faculty;
SELECT * FROM iiitdm.building;

-- OPERATION 4 
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F21','U',38,'Electrical','2020-05-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F22','V',35,'Electrical','2020-05-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F23','W',40,'Electrical','2020-05-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F24','X',26,'Electrical','2020-05-27');
INSERT INTO Faculty(Faculty_id, Name, Age, department, Date_of_joining)
VALUES('F25','Y',34,'Electrical','2020-05-27');

DELETE FROM Student WHERE department = 'Math';
DELETE FROM Student WHERE department = 'Physics';

DELETE FROM Building WHERE Building_name = 'BE';

SELECT * FROM iiitdm.student;
SELECT * FROM iiitdm.faculty;
SELECT * FROM iiitdm.building;

-- OPERATION 5
ALTER TABLE Student
ADD Marks float;

INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S1', 'Extra', 'Student', 'Lord',18,'CSE', 99.9);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S2', 'Extra', 'Student', 'Lord',18,'CSE', 99.8);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S3', 'Extra', 'Student', 'Lord',18,'CSE', 99.7);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S4', 'Extra', 'Student', 'Lord',18,'CSE', 99.6);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S5', 'Extra', 'Student', 'Lord',18,'CSE', 99.5);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S6', 'Extra', 'Student', 'Lord',18,'CSE', 99.4);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S7', 'Extra', 'Student', 'Lord',18,'CSE', 99.3);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S8', 'Extra', 'Student', 'Lord',18,'CSE', 99.2);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S9', 'Extra', 'Student', 'Lord',18,'CSE', 99.1);
INSERT INTO Student(student_id, first_name, last_name, parent_name, Age,Marks)
VALUES ('S10', 'Extra', 'Student', 'Lord',18,'CSE', 99.0);

ALTER TABLE Building
DROP COLUMN Date_of_inauguration;

ALTER TABLE Building
ADD staff_id varchar(10);

SELECT * FROM iiitdm.student;
SELECT * FROM iiitdm.faculty;
SELECT * FROM iiitdm.building;







