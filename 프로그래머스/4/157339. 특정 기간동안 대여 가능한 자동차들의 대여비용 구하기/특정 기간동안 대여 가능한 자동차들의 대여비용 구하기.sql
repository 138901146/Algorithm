-- 코드를 입력하세요
SELECT C.CAR_ID, C.CAR_TYPE, ROUND((C.DAILY_FEE*30*(100-D.DISCOUNT_RATE))/100) FEE
FROM CAR_RENTAL_COMPANY_CAR C, CAR_RENTAL_COMPANY_RENTAL_HISTORY H, CAR_RENTAL_COMPANY_DISCOUNT_PLAN D
WHERE (C.car_type='SUV' OR C.car_type='세단')
AND D.DURATION_TYPE='30일 이상'
AND C.CAR_TYPE=D.CAR_TYPE
AND C.CAR_ID=H.CAR_ID
AND H.CAR_ID NOT IN
  (SELECT CAR_ID FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
  WHERE (END_DATE >= '2022-11-01' AND END_DATE < '2022-12-01')
  OR (START_DATE >= '2022-11-01' AND START_DATE < '2022-12-01')
  OR (START_DATE < '2022-11-01' AND END_DATE > '2022-11-30'))
AND C.DAILY_FEE*30>=500000
AND C.DAILY_FEE*30<2000000
GROUP BY C.CAR_ID
ORDER BY FEE DESC, C.CAR_TYPE ASC, C.CAR_ID DESC;