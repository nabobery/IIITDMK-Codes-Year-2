-- This code was done by CS20B1044 Avinash R Changrani
CREATE DATABASE dblab1;

USE dblab1;
CREATE TABLE Student(
RollNo char(8),
SName varchar(20),
Gender char(1),
City varchar(20),
PRIMARY KEY(RollNo)
);

CREATE TABLE Course(
CCode char(5),
CName varchar(20),
Credit smallint,
PRIMARY KEY(CCode)
);

CREATE TABLE Enrolled(
RollNo char(8),
CCode char(5),
YoE int,
FOREIGN KEY (RollNo) REFERENCES Student(RollNo),
FOREIGN KEY (CCode) REFERENCES Course(CCode)
);

-- INSERTING into TABLE
INSERT INTO Student
VALUES('1901CS99','Jim','M','Chennai');
INSERT INTO Student
VALUES('2000CS01','Jane','F','Delhi');
INSERT INTO Student
VALUES('1999EC01','Diona','F','Delhi');
INSERT INTO Student
VALUES('2000ME01', 'Harsha','M','Bangalore');
INSERT INTO Student
VALUES('2000CS02','Rose','F','Mumbai');
INSERT INTO Student
VALUES('1999EC02','Avinash','M','Chennai');
INSERT INTO Student
VALUES('2000ME02', 'Kamala','F','Bangalore');
INSERT INTO Student
VALUES('1901ME01', 'Sharma','M','Mumbai');
INSERT INTO Student
VALUES('1901EC01', 'Annie','F','Kolkata');
INSERT INTO Student
VALUES('1901CS01', 'Nikhil','M','Delhi');

INSERT INTO Course
VALUES('CS555','DBMS',4);
INSERT INTO Course
VALUES('CS500','TOC',4);
INSERT INTO Course
VALUES('EC100','Circuits',4);
INSERT INTO Course
VALUES('ME120','Electromagnetics',3);
INSERT INTO Course
VALUES('EC250','DLD Practice',2);
INSERT INTO Course
VALUES('CS275','DSA Practice',2);
INSERT INTO Course
VALUES('ME150','EG',4);
INSERT INTO Course
VALUES('EC535','AC',4);
INSERT INTO Course
VALUES('ME420','SPD',3);
INSERT INTO Course
VALUES('CS440','OOPS',4);
INSERT INTO Course
VALUES('EC600','EC',3);

INSERT INTO Enrolled
VALUES('1901CS99','EC100',2018);
INSERT INTO Enrolled
VALUES('1901CS99','ME120',2018);
INSERT INTO Enrolled
VALUES('1901CS99','EC250',2019);
INSERT INTO Enrolled
VALUES('1901CS99','CS275',2019);
INSERT INTO Enrolled
VALUES('1901CS99','CS555',2020);
INSERT INTO Enrolled
VALUES('1901CS99','CS500',2020);
INSERT INTO Enrolled
VALUES('1901CS99','EC600',2020);
INSERT INTO Enrolled
VALUES('1901CS99','EC535',2020);
INSERT INTO Enrolled
VALUES('1901CS99','CS440',2020);
INSERT INTO Enrolled
VALUES('2000CS01','CS275',2020);
INSERT INTO Enrolled
VALUES('2000CS02','CS275',2020);
INSERT INTO Enrolled
VALUES('2000ME01','ME120',2020);
INSERT INTO Enrolled
VALUES('2000ME02','ME150',2020);
INSERT INTO Enrolled
VALUES('1999EC01','EC100',2019);
INSERT INTO Enrolled
VALUES('1999EC01','CS275',2019);
INSERT INTO Enrolled
VALUES('1999EC02','EC100',2019);
INSERT INTO Enrolled
VALUES('1999EC02','CS275',2020);
INSERT INTO Enrolled
VALUES('1999EC02','EC250',2020);
INSERT INTO Enrolled
VALUES('1999EC02','CS500',2020);
INSERT INTO Enrolled
VALUES('1999EC02','CS555',2020);
INSERT INTO Enrolled
VALUES('1901CS01','CS555',2018);
INSERT INTO Enrolled
VALUES('1901EC01','EC535',2019);
INSERT INTO Enrolled
VALUES('1901ME01','EC600',2019);

-- QUERY A
ALTER TABLE Course
ADD CType varchar(20);

UPDATE Course
SET CType = 'CORE'
WHERE CCode = 'CS555';
UPDATE Course
SET CType = 'CORE'
WHERE CCode = 'CS500';
UPDATE Course
SET CType = 'CORE'
WHERE CCode = 'EC100';
UPDATE Course
SET CType = 'Elective'
WHERE CCode = 'ME120';
UPDATE Course
SET CType = 'CORE'
WHERE CCode = 'EC250';
UPDATE Course
SET CType = 'Elective'
WHERE CCode = 'CS275';
UPDATE Course
SET CType = 'CORE'
WHERE CCode = 'ME150';
UPDATE Course
SET CType = 'Elective'
WHERE CCode = 'EC535';
UPDATE Course
SET CType = 'Open Elective'
WHERE CCode = 'ME420';
UPDATE Course
SET CType = 'Open Elective'
WHERE CCode = 'CS440';
UPDATE Course
SET CType = 'Open Elective'
WHERE CCode = 'EC600';

ALTER TABLE Student
ADD Email varchar(30);

UPDATE Student
SET Email = 'jim@gmail.com'
WHERE RollNo = '1901CS99';
UPDATE Student
SET Email = 'jane@gmail.com'
WHERE RollNo = '2000CS01';
UPDATE Student
SET Email = 'diona@gmail.com'
WHERE RollNo = '1999EC01';
UPDATE Student
SET Email = 'harsha@yahoo.com'
WHERE RollNo = '2000ME01';
UPDATE Student
SET Email = 'rose@bing.com'
WHERE RollNo = '2000CS02';
UPDATE Student
SET Email = 'avinash@bing.com'
WHERE RollNo = '1999EC02';
UPDATE Student
SET Email = 'kamala@yahoo.com'
WHERE RollNo = '2000ME02';
UPDATE Student
SET Email = 'sharma@yahoo.com'
WHERE RollNo = '1901ME01';
UPDATE Student
SET Email = 'annie@yahoo.com'
WHERE RollNo = '1901EC01';
UPDATE Student
SET Email = 'nikhil@gmail.com'
WHERE RollNo = '1901CS01';

-- QUERY B
SELECT CCode FROM Course WHERE CCode like 'CS%';

-- QUERY C
SELECT SName FROM Student WHERE SName like '%a%a%' AND Gender = 'M';

-- QUERY D
SELECT * FROM Student WHERE RollNo IN (SELECT DISTINCT RollNo FROM Enrolled WHERE YoE BETWEEN 2018 AND 2019);

-- QUERY E
SELECT CCode FROM Course WHERE Credit = (SELECT MIN(Credit) FROM Course);

-- QUERY F
SELECT * FROM Course WHERE CCode NOT IN (SELECT DISTINCT CCode FROM Enrolled WHERE YoE =2020);

-- QUERY G
SELECT City, count(City) AS `Number of Students` FROM Student
GROUP BY City;

-- QUERY H
SELECT RollNo, count(RollNo) AS `Number of Courses` FROM Enrolled
GROUP BY RollNo HAVING count(*) = 5;

-- QUERY I
SELECT RollNo, count(RollNo) AS `Number of Courses` FROM Enrolled
WHERE RollNo = '1901CS99';

-- QUERY J
SELECT * FROM Course WHERE CCode IN (SELECT CCode FROM Course WHERE CCode LIKE '__5%');

-- QUERY K
SELECT count(*) AS `Number of CS` FROM Student WHERE RollNo like '%CS%';

-- QUERY L
SELECT RollNo FROM Enrolled WHERE YoE = 2020 GROUP BY RollNo HAVING count(RollNo) > 4;

-- QUERY M
SELECT CCode FROM Enrolled WHERE RollNo IN (SELECT RollNo FROM Student WHERE Gender = 'F' AND City = 'Delhi') GROUP BY CCode ORDER BY count(CCode) DESC LIMIT 1;

-- QUERY N
SELECT SName FROM Student WHERE Email LIKE '%gmail.com' OR Email LIKE '%yahoo.com';







