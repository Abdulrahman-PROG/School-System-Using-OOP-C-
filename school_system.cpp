#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string username;
    string password;
    int id;
};

struct Course {
    string name;
    string code;
};

vector<Student> students;
vector<Course> courses;

bool login(const string& user, const string& pass) {
    for (const auto& student : students) {
        if (student.username == user && student.password == pass) {
            return true;
        }
    }
    return false;
}

void signup(const Student& s) {
    students.push_back(s);
}

void addCourse(const Course& c) {
    courses.push_back(c);
}

void display() {
    for (const auto& course : courses) {
        cout << course.name << " " << course.code << endl;
    }
}

bool dropCourse(const string& code) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->code == code) {
            courses.erase(it);
            return true;
        }
    }
    return false;
}

bool updateUser(const string& username, const string& newPass) {
    for (auto& student : students) {
        if (student.username == username) {
            student.password = newPass;
            return true;
        }
    }
    return false;
}

bool searchByCode(const string& code) {
    for (const auto& course : courses) {
        if (course.code == code) {
            return true;
        }
    }
    return false;
}

bool searchByName(const string& name) {
    for (const auto& course : courses) {
        if (course.name == name) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    string username, password;
    Course course;
    Student student;

    while (true) {
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter username and password: ";
            cin >> username >> password;
            if (login(username, password)) {
                cout << "Login successful!" << endl;
                while (true) {
                    cout << "1. Add course" << endl;
                    cout << "2. Drop course" << endl;
                    cout << "3. Display all courses" << endl;
                    cout << "4. Search" << endl;
                    cout << "5. Change password" << endl;
                    cout << "6. Logout" << endl;
                    cin >> choice;
                    if (choice == 1) {
                        cout << "Enter course name and code: ";
                        cin >> course.name >> course.code;
                        addCourse(course);
                        cout << "Course added successfully!" << endl;
                    } else if (choice == 2) {
                        cout << "Enter course code to drop: ";
                        cin >> course.code;
                        if (dropCourse(course.code)) {
                            cout << "Course dropped successfully!" << endl;
                        } else {
                            cout << "Course not found!" << endl;
                        }
                    } else if (choice == 3) {
                        display();
                    } else if (choice == 4) {
                        cout << "1. Search by name" << endl;
                        cout << "2. Search by code" << endl;
                        cin >> choice;
                        if (choice == 1) {
                            cout << "Enter course name: ";
                            cin >> course.name;
                            if (searchByName(course.name)) {
                                cout << "Course found!" << endl;
                            } else {
                                cout << "Course not found!" << endl;
                            }
                        } else if (choice == 2) {
                            cout << "Enter course code: ";
                            cin >> course.code;
                            if (searchByCode(course.code)) {
                                cout << "Course found!" << endl;
                            } else {
                                cout << "Course not found!" << endl;
                            }
                        }
                    } else if (choice == 5) {
                        string newPass;
                        cout << "Enter new password: ";
                        cin >> newPass;
                        if (updateUser(username, newPass)) {
                            cout << "Password updated successfully!" << endl;
                        } else {
                            cout << "User not found!" << endl;
                        }
                    } else if (choice == 6) {
                        break;  // Logout and go back to the login/signup options
                    }
                }
            } else {
                cout << "Invalid username or password!" << endl;
            }
        } else if (choice == 2) {
            cout << "Enter details to signup: " << endl;
            cin >> student.username >> student.password >> student.id;
            signup(student);
            cout << "Signup successful!" << endl;
        } else if (choice == 3) {
            break;  // Exit the program
        }
    }

    return 0;
}
