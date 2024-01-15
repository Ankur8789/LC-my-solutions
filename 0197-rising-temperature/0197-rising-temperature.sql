# Write your MySQL query statement below
select w1.id 
from Weather as w1, Weather as w2
where datediff(w1.recorddate,w2.recorddate) = 1 and w1.temperature > w2.temperature   ;