# Write your MySQL query statement below
select product_name ,
       year  ,
       price 
from Sales as sa
inner join Product as pr
on sa.product_id  = pr.product_id ;
