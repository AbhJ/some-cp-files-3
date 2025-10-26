# Write your MySQL query statement below

Select (Select Distinct Salary From Employee Order By Salary Desc Limit 1 Offset 1) as SecondHighestSalary