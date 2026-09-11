# Write your MySQL query statement below
select name , sum(amount) AS balance from Users u INNER JOIN Transactions t ON u.account=t.account group by name having balance>10000;    