select DISTINCT A.num AS ConsecutiveNums FROM Logs A
JOIN Logs B ON A.id = B.id+1 AND A.num = B.num
JOIN Logs C ON B.id = C.id+1 AND B.num = C.num;