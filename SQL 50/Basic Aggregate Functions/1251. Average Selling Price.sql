select Prices.product_id, round(SUM(price * units)::numeric / (Select sum(units)::numeric
    from UnitsSold 
    where Prices.product_id = UnitsSold.product_id
    group by product_id), 2)  as average_price 
from prices, UnitsSold 
where Prices.product_id = UnitsSold.product_id and purchase_date between start_date and end_date 
group by Prices.product_id
union
select Prices.product_id, 0 from Prices, UnitsSold 
where Prices.product_id > (select max(product_id) from UnitsSold);