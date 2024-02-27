# Write your MySQL query statement below
SELECT euni.unique_id, 
em.name
FROM Employees em
LEFT JOIN EmployeeUNI euni
ON em.id = euni.id;