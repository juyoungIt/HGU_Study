second = int(input("시간을 초 단위로 입력하시오. : "))
hour = second / (60*60)
R_hour = second % (60*60)
minute = R_hour / 60
R_minute = R_hour % 60
R_second = R_minute

print(second,"초는", int(hour),"시간", int(minute), "분", int(R_second),"초입니다.")
