#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <locale>

using namespace std;

class IsoscelesTriangle {
private:
    double base;    // основание
    double side;    // боковая сторона
    const double PI = 3.14; // число PI

public:
    IsoscelesTriangle() : base(0), side(0) {}

    // Метод установки свойств
    bool setProperties(double b, double s) {
        if (b <= 0 || s <= 0) {
            cout << "Ошибка: основание и боковая сторона должны быть положительными." << endl;
            return false;
        }
        if (b >= 2 * s) {
            cout << "Ошибка: основание должно быть меньше чем удвоенная боковая сторона." << endl;
            return false;
        }
        base = b;
        side = s;
        return true;
    }

    // Увеличение/уменьшение размера на процент
    void resize(double percent) {
        base *= (1 + percent / 100);
        side *= (1 + percent / 100);
    }

    // Вычисление длины медианы
    double median() const {
        return sqrt(2 * side * side + 2 * (base / 2) * (base / 2) - base * base) / 2;
    }

    // Вычисление периметра
    double perimeter() const {
        return base + 2 * side;
    }

    // Вычисление площади
    double area() const {
        double height = sqrt(side * side - (base / 2) * (base / 2));
        return (base * height) / 2;
    }

    // Определение углов
    void angles(double& angleA, double& angleB, double& angleC) const {
        angleA = angleB = acos(base / (2 * side)) * (180 / PI);
        angleC = 180 - 2 * angleA;
    }

    // Вывод свойств треугольника
    void print() const {
        cout << "Основание: " << base << ", Боковая сторона: " << side << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Площадь: " << area() << endl;
        cout << "Длина медианы: " << median() << endl;

        double angleA, angleB, angleC;
        angles(angleA, angleB, angleC);
        cout << "Углы: A = " << angleA << ", B = " << angleB << ", C = " << angleC << endl;
    }
    double getBase() const { return base; }
    double getSide() const { return side; }
};

int main() {
    // Установка русской локали
    setlocale(LC_ALL, "Russian");

    vector<IsoscelesTriangle> triangles;
    int n;

    cout << "Введите количество треугольников: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double base, side;
        cout << "Введите основание и боковую сторону треугольника " << i + 1 << ": ";
        cin >> base >> side;
        IsoscelesTriangle triangle;

        if (triangle.setProperties(base, side)) {
            triangles.push_back(triangle);
        }
    }

    int choice;
    while (true) {
        cout << "\nВыберите треугольник (1-" << triangles.size() << ") для выполнения операции или 0 для выхода: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice < 1 || choice > triangles.size()) {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            continue;
        }
        IsoscelesTriangle& triangle = triangles[choice - 1];

        cout << "Выбранный треугольник: ";
        cout << "Основание = " << triangle.getBase() << ", Боковая сторона = " << triangle.getSide() << endl;
        cout << "Выберите операцию:\n";
        cout << "1. Увеличить размер на процент\n";
        cout << "2. Вычислить длину медианы\n";
        cout << "3. Вычислить периметр и площадь\n";
        cout << "4. Определить значения углов\n";
        int operation;
        cin >> operation;

       

        switch (operation) {
        case 1: {
            double percent;
            cout << "Введите процент: ";
            cin >> percent;
            triangle.resize(percent);
            cout << "Размеры треугольника изменены." << endl;
            break;
        }
        case 2: {
            cout << "Длина медианы: " << triangle.median() << endl;
            break;
        }
        case 3: {
            triangle.print();
            break;
        }
        case 4: {
            double angleA, angleB, angleC;
            triangle.angles(angleA, angleB, angleC);
            cout << "Углы: A = " << angleA << ", B = " << angleB << ", C = " << angleC << endl;
            break;
        }
        default:
            cout << "Неверная операция." << endl;
        }
    }

    return 0;
}
