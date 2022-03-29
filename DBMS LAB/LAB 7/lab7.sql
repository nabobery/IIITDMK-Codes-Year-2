-- This program is done by CS20B1044 Avinash R Changrani
CREATE DATABASE lab7;
USE lab7;

-- CREATION of Tables
CREATE TABLE Bank(Bank_name varchar(5),State varchar(15));
CREATE TABLE Account_holder(Account_name varchar(10) ,Bank_name varchar(5),State_name varchar(15));
                 
-- INSERTION Into Tables
INSERT INTO Bank VALUES ('SBI','Andhra Pradesh'),
                        ('SBI','TamilNadu'),
                        ('SBI','Karnataka'),
                        ('ICICI','TamilNadu'),
                        ('ICICI','Karnataka');
                        
INSERT INTO Account_holder  VALUES ('Ramesh','ICICI','TamilNadu'),
                                  ('Dinesh','SBI','Andhra Pradesh'),
                                  ('Robert','SBI','TamilNadu'),
                                  ('Robert','ICICI','Karnataka'),
                                  ('Robert','SBI','Andhra Pradesh'),
                                  ('Karthik','SBI','Andhra Pradesh');

-- QUERY I
-- Get all the Banks
CREATE TABLE allBanks AS SELECT DISTINCT Bank_name FROM Bank;
-- Get all the account names
CREATE TABLE names AS SELECT DISTINCT Account_name FROM Account_holder;
-- Get the crossproduct between  all account names and  all banks
CREATE TABLE namesAndBanks AS SELECT * FROM allBanks CROSS JOIN names;
-- Get the account holders who don't have an account in all banks
CREATE TABLE notHolders AS SELECT * FROM namesAndBanks WHERE NOT EXISTS (SELECT * FROM Account_holder WHERE namesAndBanks.Bank_name = Account_holder.Bank_name AND namesAndBanks.Account_name = Account_holder.Account_name);
-- Get the account holder names who have an account in all banks by selecting account names who are not in notHolders
CREATE TABLE q1 AS SELECT * FROM names WHERE NOT EXISTS (SELECT * FROM notHolders WHERE notHolders.Account_name = names.Account_name);
-- display the result
SELECT * FROM q1;

-- QUERY II
-- Get all the States
CREATE TABLE allStates AS SELECT DISTINCT State FROM Bank;
-- Get the crossproduct between  all states and  all banks
CREATE TABLE statesAndBanks AS SELECT * FROM allBanks CROSS JOIN allStates;
-- Get the banks that don't have a branch in all states
CREATE TABLE notAllStates AS SELECT * FROM statesAndBanks WHERE NOT EXISTS (SELECT * FROM Bank WHERE statesAndBanks.Bank_name = Bank.Bank_name AND statesAndBanks.State = Bank.State);
-- Get the banks that have a branch in all states by selecting banks from allBanks who are not in notAllStates
CREATE TABLE q2 AS SELECT * FROM allBanks WHERE NOT EXISTS (SELECT * FROM notAllStates WHERE notAllStates.Bank_name = allBanks.Bank_name);
-- display the result
SELECT * FROM q2;

-- QUERY III
-- To get banks that do not have branches in allStates which is already computed
SELECT Bank_name FROM notAllStates;

-- QUERY IV
-- Get the crossproduct between  all account_names and  all banks
CREATE TABLE namesAndStates AS SELECT * FROM allStates CROSS JOIN names;
-- Get the account holders that don't have an account  in all states
CREATE TABLE notHoldersStates AS SELECT * FROM namesAndStates WHERE NOT EXISTS (SELECT * FROM Account_holder WHERE namesAndStates.State = Account_holder.State_name AND namesAndStates.Account_name = Account_holder.Account_name);
-- Get the account holders that have an account in all states by selecting account names from all account names who are not in notHoldersStates
CREATE TABLE q4 AS SELECT * FROM names WHERE NOT EXISTS (SELECT * FROM notHoldersStates WHERE notHoldersStates.Account_name = names.Account_name);
-- display the result
SELECT * FROM q4;
