#pragma once
#include <iostream>
#include <string>
#include "Point.h"

/**
 * @brief Класс шара в трехмерном пространстве
 */
class Sphere
{
private:
    Point center;  // центр шара
    double radius; // радиус шара

public:
    /**
     * @brief Конструктор шара
     * @param center центр шара
     * @param radius радиус шара
     * @throw std::invalid_argument если радиус <= 0
     */
    Sphere(const Point& center = Point(), const double radius = 1);

    /**
     * @brief Конструктор копирования
     * @param other объект для копирования
     */
    Sphere(const Sphere& other);

    /**
     * @brief Конструктор перемещения
     * @param other объект для перемещения
     */
    Sphere(Sphere&& other);

    /**
     * @brief Деструктор
     */
    ~Sphere() = default;

    /**
     * @brief Оператор присваивания копированием
     * @param other объект для копирования
     * @return текущий объект
     */
    Sphere& operator=(const Sphere& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other объект для перемещения
     * @return текущий объект
     */
    Sphere& operator=(Sphere&& other);

    /**
     * @brief Получить центр шара
     * @return центр шара
     */
    Point GetCenter() const;

    /**
     * @brief Получить радиус шара
     * @return радиус шара
     */
    double GetRadius() const;

    /**
     * @brief Вычислить площадь поверхности шара
     * @return площадь поверхности
     */
    double SurfaceArea() const;

    /**
     * @brief Вычислить объем шара
     * @return объем шара
     */
    double Volume() const;

    /**
     * @brief Получить строковое представление шара
     * @return строка с описанием шара
     */
    std::string ToString() const;

    /**
     * @brief Считать шар из потока
     * @param in поток ввода
     * @return объект Sphere
     * @throw std::runtime_error если данные некорректны
     */
    static Sphere Read(std::istream& in);

    /**
     * @brief Оператор вывода шара в поток
     * @param os поток вывода
     * @param sphere шар
     * @return поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Sphere& sphere);
};
