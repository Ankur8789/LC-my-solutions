# Write your MySQL query statement below
select Department ,Employee,Salary 
from 
   (
       select   
       d.name as Department ,
       e.name as Employee  ,
       e.salary as Salary ,
       DENSE_RANK() OVER (partition by  d.id order by salary desc) as rnk
       from Employee e 
       inner join Department d
       on e.departmentId  = d.id
       
   )
   as tbl
   where rnk<=3;