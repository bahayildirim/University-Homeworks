select s.name,c.name
from Students s, Courses c, RegisteredCourses r
where s.Id=r.stu_id and c.code=r.c_id