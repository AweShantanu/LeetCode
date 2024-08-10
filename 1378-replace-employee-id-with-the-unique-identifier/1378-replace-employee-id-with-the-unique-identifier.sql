# Write your MySQL query statement below
select unique_id , name
from employees as e 
left join EmployeeUNI as eq
on e.id=eq.id