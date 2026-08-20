

class Student:

    count = 0
    total_gap = 0

    def __init__(self, name, gpa):
        self.name = name
        self.gpa = gpa
        Student.count += 1
        Student.total_gap += gpa

    # INSTANCE METHOD
    def get_info(self):
        return f"{self.name} {self.gpa}"

    @classmethod
    def get_count(cls):
        return f"Total num of students: {cls.count}"

    @classmethod
    def get_average_gpa(cls):
        if cls.count == 0:
            return 0
        else:
            return f"{cls.total_gap / cls.count:.2f}"

student1 = Student("Spongebob", 3.2)
student2 = Student("Spongebob", 2.2)
student3 = Student("Spongebob", 4.0)

print(Student.get_count())

print(Student.get_average_gpa())