CREATE DATABASE `iiit`;
USE iiit;
CREATE TABLE `iiitdm` (
`Faculty name` varchar(5) DEFAULT NULL,
`Student_Id` varchar(5) DEFAULT NULL,
`Building name` varchar(10) DEFAULT NULL
);
INSERT INTO `iiit`.`iiitdm`
(`Faculty name`,
`Student_Id`,
`Building name`)
VALUES
(<{Faculty name: }>,
<{Student_Id: }>,
<{Building name: }>);
CREATE TABLE `faculty` (
`Faculty_id` varchar(5) DEFAULT NULL,
`Faculty_name` varchar(10) DEFAULT NULL,
`department` varchar(5) DEFAULT NULL,
`Subject` varchar(35) DEFAULT NULL
);
INSERT INTO `iiit`.`faculty`
(`Faculty_id`,
`Faculty_name`,
`department`,
`Subject`)
VALUES
(<{Faculty_id: }>,
<{Faculty_name: }>,
<{department: }>,
<{Subject: }>);
CREATE TABLE `student` (
`Student_id` varchar(5) DEFAULT NULL,
`Student_name` varchar(10) DEFAULT NULL,
`department` varchar(5) DEFAULT NULL,
`course` varchar(35) DEFAULT NULL,
`Building_name` varchar(10) DEFAULT NULL
);
INSERT INTO `iiit`.`student`
(`Student_id`,
`Student_name`,
`department`,
`course`,
`Building_name`)
VALUES
(<{Student_id: }>,
<{Student_name: }>,
<{department: }>,
<{course: }>,
<{Building_name: }>);
CREATE TABLE `building` (
`Building_name` varchar(10) DEFAULT NULL,
`Room_no` int DEFAULT NULL,
`Floor` int DEFAULT NULL
);
INSERT INTO `iiit`.`building`
(`Building_name`,
`Room_no`,
`Floor`)
VALUES
(<{Building_name: }>,
<{Room_no: }>,
<{Floor: }>);
CREATE TABLE `course` (
`department` varchar(5) DEFAULT NULL,
`subject` varchar(5) DEFAULT NULL,
`course_id` varchar(30) DEFAULT NULL
);
INSERT INTO `iiit`.`course`
(`department`,
`subject`,
`course_id`)
VALUES
(<{department: }>,
<{subject: }>,
<{course_id: }>);